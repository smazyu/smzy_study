import os

def generate_blog_list():
    articles_directory = 'articles/'  # 文章目录路径，请根据实际情况修改
    articles = os.listdir(articles_directory)
    articles = [article for article in articles if article.endswith('.html')]  # 只选择 HTML 格式的文章
    blog_list_html = ''
    for article in articles:
        with open(os.path.join(articles_directory, article), 'r', encoding='utf-8') as f:
            content = f.read()
            blog_list_html += f'<article class="post">{content}</article>\n'

    return blog_list_html

if __name__ == "__main__":
    blog_list_html = generate_blog_list()
    print(blog_list_html)
