#pragma once
#include <iostream>

namespace study_list
{
    template <class T>
    struct __list_node
    {
        __list_node<T>* prev; // 修改为prev
        __list_node<T>* next; // 修改为next
        T _data;
    };

    template <class T>
    class list
    {
        typedef __list_node<T> Node;

    public:
        struct __list_iterator // 迭代器结构
        {
            Node* _node;

            __list_iterator(Node* node) : _node(node) {}

            T& operator*()
            {
                return _node->_data;
            }

            __list_iterator& operator++()
            {
                _node = _node->next; // 修改为next
                return *this;
            }

            bool operator!=(const __list_iterator& it) const
            {
                return _node != it._node;
            }
        };

        typedef __list_iterator iterator; // 移除<T>

        // 带头双向循环链表
        list()
        {
            _head = new Node();
            _head->next = _head; // 修改为next
            _head->prev = _head; // 修改为prev
        }

        ~list()
        {
            clear();
            delete _head;
        }

        void push_back(const T& data)
        {
            Node* tail = _head->prev; // 修改为prev
            Node* new_node = new Node();
            new_node->_data = data; // 初始化数据
            tail->next = new_node; // 修改为next
            new_node->prev = tail; // 修改为prev
            new_node->next = _head; // 修改为next
            _head->prev = new_node; // 修改为prev
        }

        iterator begin() { return iterator(_head->next); } // 修改为next
        iterator end() { return iterator(_head); }

        void clear()
        {
            Node* current = _head->next; // 修改为next
            while (current != _head)
            {
                Node* next_node = current->next; // 修改为next
                delete current;
                current = next_node;
            }
            _head->next = _head; // 修改为next
            _head->prev = _head; // 修改为prev
        }

    private:
        Node* _head;
    };

    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        lt.push_back(6);

        for (auto it = lt.begin(); it != lt.end(); ++it)
        {
            std::cout << *it << " "; // 使用迭代器遍历
        }
        std::cout << std::endl;
    }
}
