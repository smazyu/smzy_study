# Define here the models for your spider middleware
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/spider-middleware.html
import time
from scrapy import signals
from scrapy.http import HtmlResponse
import random
from wangyi.settings import USER_AGENTS_LIST
# useful for handling different item types with a single interface
from itemadapter import is_item, ItemAdapter


class WangyiSpiderMiddleware:
    # Not all methods need to be defined. If a method is not defined,
    # scrapy acts as if the spider middleware does not modify the
    # passed objects.

    @classmethod
    def from_crawler(cls, crawler):
        # This method is used by Scrapy to create your spiders.
        s = cls()
        crawler.signals.connect(s.spider_opened, signal=signals.spider_opened)
        return s

    def process_spider_input(self, response, spider):
        # Called for each response that goes through the spider
        # middleware and into the spider.

        # Should return None or raise an exception.
        return None

    def process_spider_output(self, response, result, spider):
        # Called with the results returned from the Spider, after
        # it has processed the response.

        # Must return an iterable of Request, or item objects.
        for i in result:
            yield i

    def process_spider_exception(self, response, exception, spider):
        # Called when a spider or process_spider_input() method
        # (from other spider middleware) raises an exception.

        # Should return either None or an iterable of Request or item objects.
        pass

    def process_start_requests(self, start_requests, spider):
        # Called with the start requests of the spider, and works
        # similarly to the process_spider_output() method, except
        # that it doesn’t have a response associated.

        # Must return only requests (not items).
        for r in start_requests:
            yield r

    def spider_opened(self, spider):
        spider.logger.info("Spider opened: %s" % spider.name)


class WangyiDownloaderMiddleware:
    # Not all methods need to be defined. If a method is not defined,
    # scrapy acts as if the downloader middleware does not modify the
    # passed objects.

    @classmethod
    def from_crawler(cls, crawler):
        # This method is used by Scrapy to create your spiders.
        s = cls()
        crawler.signals.connect(s.spider_opened, signal=signals.spider_opened)
        return s

    def process_request(self, request, spider):
        # Called for each request that goes through the downloader
        # middleware.
        ua = random.choice(USER_AGENTS_LIST)  #每次的请求头都不同
        request.headers['User-Agent'] = ua
        # Must either:
        # - return None: continue processing this request
        # - or return a Response object
        # - or return a Request object
        # - or raise IgnoreRequest: process_exception() methods of
        #   installed downloader middleware will be called
        print('process_request')
        return None

    def process_response(self, request, response, spider):
        # Called with the response returned from the downloader.
# 响应时
# 如果是版块的url我们就进行抓取
          driver = spider.driver  # 获取到selenium
          if request.url in spider.page_url:
              driver.get(request.url)
              # 滚动条滚动到最下方
              driver.execute_script('window.scrollTo(0, document.body.scrollHeight)')
              time.sleep(1)
              # 拖动两次
              driver.execute_script('window.scrollTo(0, document.body.scrollHeight)')
              time.sleep(1)
              text = driver.page_source#获取页面源代码
              # 篡改响应对象并返回
              return HtmlResponse(url=request.url, body=text, encoding='UTF-8', request=request)
          return response
         

    def process_exception(self, request, exception, spider):
        # Called when a download handler or a process_request()
        # (from other downloader middleware) raises an exception.

        # Must either:
        # - return None: continue processing this exception
        # - return a Response object: stops process_exception() chain
        # - return a Request object: stops process_exception() chain
        print('process_exception')
        # return request

    def spider_opened(self, spider):
        spider.logger.info("Spider opened: %s" % spider.name)
