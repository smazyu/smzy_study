//
// Created by 20212 on 24-10-19.
//
//适配器模式
//生活中我们使用的适配器是用来进行电压转化的

//stack queue 叫做容器适配器
//通过容器转换出来的

#pragma once
namespace stack_study
{
    template<class T,class Container>
    class stack
    { 
    public:
        void push(const T& x)
        {
            _con.push_back(x);
        }
    private:
        Container _con;
    };
}