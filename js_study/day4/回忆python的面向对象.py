class person:
    # 构建了这个对象...构造方法
    def __init__(self,name,age):
        self.name = name;
        self.age = age;
    def chi(self):
        print("chi")

    def play(self):
        print("play")

p1 = person("张三",18)
p2 = person("李四",20)
p1.chi()
p2.chi()