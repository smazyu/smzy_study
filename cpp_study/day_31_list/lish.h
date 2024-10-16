//
// Created by 20212 on 24-10-16.
//
//一个类型去封装节点的指针构成一个自定义类型
//然后重载*,++等运算符,就可以达到我们的行为
#pragma once
namespace study_list
{
    template <class T>
    struct __list_node
    {
        __list_node<T>* prev;
        __list_node<T>* next;
        T _data;
    };

    template <class T>
    class list
    {
        typedef __list_node<T> Node;

    public:
        //带头双向循环链表
        list()
        {
            _head = new Node();
            _head->_next = _head;
            _head->_prev = _head;
        }


        void push_back(const T& data)
        {
            Node* tail = _head->_prev;
            Node* new_node = new Node();
            tail->_next = new_node;
            new_node->_prev = tail;
            new_node->_next = _head;
            _head->_prev = new_node;
        }
        
    private:
        Node* _head;
    };
}

//迭代器失效总结
//1.vector的迭代器失效 iterator insert erase都会导致失效
//push_back增容失效
//2.list的iterator,erase会导致失效
