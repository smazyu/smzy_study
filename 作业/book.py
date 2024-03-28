import click
class books:
    def __init__(self, book_info: list[list]):
        self.book_info_list = book_info

    def input_book_info(self, book_info: list):
        self.book_info_list.append(book_info)
        click.echo(f'现在的书籍列表是{self.book_info_list}')

    def get_book(self, input_str: str):
        values = input_str.split()
        num, name, price = None, None, None

        # 根据输入的值来赋值，跳过用_表示的值
        if len(values) >= 1 and values[0] != '_':
            num = eval(values[0])
        if len(values) >= 2 and values[1] != '_':
            name = values[1]
        if len(values) >= 3 and values[2] != '_':
            price = eval(values[2])

        # print(f"num: {num}, name: {name}, price: {price}")
        for book in self.book_info_list:
            if book[0] == num or book[1] == name or book[2] == price:
                click.echo(f"找到 book: num: {book[0]}, name: {book[1]}, price: {book[2]}")
                return book
        click.echo("没有发现书本.")
        return None

    def find_book_by_num(self, num):
        for book in self.book_info_list:
            if int(book[0]) == num:
                click.echo(f"通过num找到book: num: {book[0]}, name: {book[1]}, price: {book[2]}")
                return book
        click.echo("没有通过num找到.")
        return None

    def insert_book(self, book_info):
        self.book_info_list.append(book_info)
        click.echo("Book插入成功.")

    def delete_book(self, num):
        for i, book in enumerate(self.book_info_list):
            if int(book[0]) == num:
                del self.book_info_list[i]
                click.echo(f"Book 通过num {num} 删除成功.")
                return
        click.echo("没有书本被找到.")
    def print_books(self):
        for book in self.book_info_list:
            click.echo(f"num: {book[0]}, name: {book[1]}, price: {book[2]}")
def get_books_infor_list():
    with open('books.txt','r',encoding='utf-8') as file:
        books_infor = []
        for line in file:
            books_infor.append(line.strip().split())
    return books_infor
import click
@click.group(invoke_without_command=True)
@click.pass_context
def cli(ctx):
    """书籍管理系统。使用这个命令行工具来管理你的书籍集合。"""
    if ctx.invoked_subcommand is None:
        click.echo('欢迎使用书籍管理系统 CLI！\n作者: 漳毓')
        click.echo(ctx.get_help())

@cli.command()
@click.argument('input_str')
def get(input_str):
    """
    查找书籍。

    INPUT_STR: 书籍信息的字符串，格式为 "num name price"，其中num是书籍的编号。
    """
    book = books(get_books_infor_list())
    book.get_book(input_str)

@cli.command()
@click.argument('num', type=int)
def find(num):
    """
    通过num查找书籍。

    NUM: 要查找的书籍的编号。
    """
    book = books(get_books_infor_list())
    book.find_book_by_num(num)

@cli.command()
@click.argument('num', type=int)
def delete(num):
    """
    删除书籍。

    NUM: 要删除的书籍的编号。
    """
    book = books(get_books_infor_list())
    book.delete_book(num)

@cli.command()
def print():
    """打印所有书籍的信息。"""
    book = books(get_books_infor_list())
    book.print_books()

@cli.command()
@click.argument('num', type=int)
@click.argument('name')
@click.argument('price', type=float)
def insert(num, name, price):
    """
    插入书籍。

    NUM: 书籍的编号。
    NAME: 书籍的名称。
    PRICE: 书籍的价格。
    """
    book_info = [num, name, price]
    book = books(get_books_infor_list())
    book.insert_book(book_info)

if __name__ == '__main__':
    cli()




    # print('你想要做什么?')
    # a = None
    # while not a:
    #     a = input('1. 查找书籍\n2. 通过num查找书籍\n3. 插入书籍\n4. 删除书籍\n5. 打印书籍\n现在请输入你想要进行的操作:')
    #     if a:
    #         book = books(get_books_infor_list())
    #         if a == '1':
    #             book.get_book(input('请输入num name price: '))
    #         elif a == '2':
    #             book.find_book_by_num(eval(input('请输入num: ')))
    #         elif a == '3':
    #             book.insert_book(eval(input('请输入num name price: ')))
    #         elif a == '4':
    #             book.delete_book(eval(input('请输入num: ')))
    #         elif a == '5':
    #             book.print_books()
    #     a = None
    #     a = input('是否继续?')
    #     if a == 'n':
    #         break
    #     else:
    #         a = None
        # print(books_infor)
        # book = books(books_infor)
        # book.get_book("29")
        # book.find_book_by_num(9787302257646)
        # book.insert_book([3, '围城', 120])
        # book.delete_book(1)

