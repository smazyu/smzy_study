//
// Created by 20212 on 24-9-23.
//
//模板 -> 泛型编程
//编写与类型无关的的通用代码，是一种代码复用的手段
//template <typename T> 模板参数 -> 类型
template<class T>
void Swap(T &x1, T &x2) {
    T x = x1;
    x1 = x2;
    x2 = x;
}

int main() {
    int a = 0, b = 1;
    Swap(a, b);
    double c = 1.11, d = 2.22;
    Swap(c, d);
    char e = 'a', f = 'b';
    Swap(e, f);
    return 0;
}
