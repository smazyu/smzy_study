import os
import scrapy
import re
import json
class WxSpider(scrapy.Spider):
    name = 'wx'
    # allowed_domains = ['ks.wangxiao.cn']
    start_urls = ['http://ks.wangxiao.cn/']

    def parse(self, response, **kwargs):
        # 每个一级标题的li的列表
        li_list = response.xpath('//ul[@class="first-title"]/li')
        for li in li_list:
            # 获取到一级标题
            one_title = li.xpath('./p/span/text()').extract_first()  # 对于当前的每一个一级标题再次进行xpath提取数据
            # print(one_title)
            # 获取二级标题的a标签的列表
            two_title_a_list = li.xpath('./div[@class="send-title"]/a')
            for a in two_title_a_list:
                two_title = a.xpath('./text()').extract_first()  # 获取的为二级标题
                # 拼凑成完整的二级标题的url 并替换url为考点练习的url
                two_title_url = response.urljoin(a.xpath('./@href').extract_first()).replace('TestPaper', 'exampoint')  # 二级标题的url
                '''
                http://ks.wangxiao.cn/TestPaper/list?sign=jz1
                http://ks.wangxiao.cn/exampoint/list?sign=jz1  # 考点练习的url
                '''
                # print(one_title, two_title, two_title_url)
                # yield scrapy.Request(two_title_url, meta={'one_title': one_title, 'two_title': two_title}, callback=self.two_parse)
        yield scrapy.Request('https://ks.wangxiao.cn/exampoint/list?sign=jz1', meta={'one_title': '工程类', 'two_title': '一级建造师'}, callback=self.two_parse)
    # 对于二级url的解析处理
    def two_parse(self, response):
        # 通过meta传递  获取到一级标题
        one_title = response.meta['one_title']
        # 通过meta传递 获取到二级标题
        two_title = response.meta['two_title']
        # 返回三级标题的超链接
        a_list = response.xpath('//div[@class="filter-item"]/a')
        for a in a_list:
            # 通过二级标题的超链接 抓取到了三级标题的url和标题
            three_title = a.xpath('./text()').extract_first()
            # 抓取三级标题的url
            three_title_url = response.urljoin(a.xpath('./@href').extract_first())
            # print(one_title, two_title, three_title, three_title_url)
            yield scrapy.Request(three_title_url, meta={'one_title': '工程类', 'two_title': '一级建造师','three_title':'建设工程经济'}, callback=self.three_parse)


    # 三级菜单的请求
    def three_parse(self,response):
        # 通过meta传递  获取到一级标题
        one_title = response.meta['one_title']
        # 通过meta传递 获取到二级标题
        two_title = response.meta['two_title']
        # 通过meta传递 获取三级标题
        three_title = response.meta['three_title']
        # print(one_title,three_title,two_title)
        chapter_item = response.xpath('.//ul[@class="chapter-item"]')
        for ul in chapter_item:
            chapter_fl = re.sub('\s','',''.join(ul.xpath('./li[1]//text()').extract()))
            # print(chapter_fl)
            session_item = ul.xpath('.//ul[@class="section-item"]')
            if session_item:
                for session in session_item:
                    session_fl = re.sub('\s','',''.join(session.xpath('./li[1]//text()').extract()))
                    # print(session_fl)
                    # class="section-point-item"
                    session_point_item = session.xpath('./ul[@class="section-point-item"]')
                    filepath = os.path.join(one_title,two_title,three_title,chapter_fl,session_fl)
                    if session_point_item:
                        for session_point in session_point_item:
                            session_point_fl = re.sub('\s','',''.join(session_point.xpath('./li[1]//text()').extract()))
                            # print(session_point_fl)
                            # 因为在此所调用函数为yield，生成器
                            # 它用于在生成器函数中委托子生成器的执行，并等待子生成器完成后获取其结果。
                            yield from self.send_post(session_point, filepath, session_point_fl)
                        # pass
                    else:
                        # print('该路径下没有子标签')
                        pass
            else:
                # print('该路径下没有子标签')
                pass
    def send_post(self,res,path,filename):
        url = 'https://ks.wangxiao.cn/practice/listQuestions'
        sign = res.xpath('./li[3]/span/@data_sign').extract_first()
        subsign = res.xpath('./li[3]/span/@data_subsign').extract_first()
        top = res.xpath('./li[2]/text()').extract_first().split('/')[1]  # 获取题目数量
        data = {
            'examPointType': "",
            'practiceType': "2",
            'questionType': "",
            'sign': sign,
            'subsign': subsign,
            'top': top
        }
        yield scrapy.Request(url, method='POST', body=json.dumps(data), headers={'Content-Type': 'application/json;charset=UTF-8'}, callback=self.parse_subject, meta={'path': path, 'filename': filename})

    def parse_subject(self, response):
        path = response.meta['path']
        filename = response.meta['filename']
        data = response.json()['Data']  # 取出数据
        if data:
            for item in data:
                # 题目
                questions = item.get('questions')
                if questions:
                    for question in questions:
                        # 对于每个题取值的处理的方法
                        subject = self.parse_questions(question)
                        # print(subject)
                        yield {
                            'file_path': path,
                            'filename': filename,
                            'subject': subject,
                        }
    def parse_questions(self, question):
        content = question['content']  # 题目
        options = question['options']  # 选项  列表 里面多个字典
        opt_all = ''
        right_name = ''
        for opt in options:
            opt_name = opt['name']  # 题目的选项列表 A  B C D
            opt_content = opt['content']  # 选项内容
            opt_all = opt_all + opt_name + ':' + opt_content + '\n'  # 拼接选项
            if opt['isRight'] == 1:
                right_name = opt_name

        textAnalysis = '正确答案为：'+ right_name + question['textAnalysis']  # 答案解析
        subject = '题目：' + content + '\n' + opt_all + textAnalysis  # 把题目和选项以及答案解析全部返回
        return subject



"""
工程类
    一级工程
        建设工程经济
            1z101000
                1z101000时间金钱价值的计算
                    1.时间价值观念.txt
                    2.时间价值观念.txt
                    3.时间价值观念.txt
    二级工程
    ...
"""