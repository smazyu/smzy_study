//
// Created by 20212 on 19/8/2024.
//
//引用是给已经存在的变量取别名

#include <iostream>
int a = 10;
int& b = a;
int& c = b;
int& e = c;
//引用必须初始化，引用一个实体之后不能再引用别的