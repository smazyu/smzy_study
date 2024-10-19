//
// Created by 20212 on 24-10-19.
//
//适配器模式
//生活中我们使用的适配器是用来进行电压转化的

//stack queue 叫做容器适配器
//通过容器转换出来的

#pragma once
#include <vector>

namespace stack_study
{
    template <class T, class Container>
    class stack
    {
    public:
        void push(const T& x)
        {
            _con.push_back(x);
        }

        void pop()
        {
            _con.pop_back();
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

        T& top()
        {
            return _con.back();
        }

    private:
        Container _con;
    };

    void test_stack()
    {
        stack<int, std::vector<int>> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        st.push(6);
        while(!st.empty())
        {
            std::cout << st.top() << " ";
            st.pop();
        }
        std::cout << std:: endl;
    }
}
