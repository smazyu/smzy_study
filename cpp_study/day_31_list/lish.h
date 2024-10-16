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
        typedef __list_iterator<T> iterator;

        // 带头双向循环链表
        list()
        {
            _head = new Node();
            _head->_next = _head;
            _head->_prev = _head;
        }

        ~list() // 添加析构函数
        {
            clear();
            delete _head;
        }

        void push_back(const T& data)
        {
            Node* tail = _head->_prev;
            Node* new_node = new Node();
            new_node->_data = data; // 初始化数据
            tail->_next = new_node;
            new_node->_prev = tail;
            new_node->_next = _head;
            _head->_prev = new_node;
        }

        iterator begin() { return iterator(_head->_next); }
        iterator end() { return iterator(_head); }

        void clear() // 清空链表的实现
        {
            Node* current = _head->_next;
            while (current != _head)
            {
                Node* next_node = current->_next;
                delete current;
                current = next_node;
            }
            _head->_next = _head;
            _head->_prev = _head;
        }

        struct __list_iterator
        {
            typedef __list_node<T> Node;
            Node* _node;

            __list_iterator(Node* node) : _node(node) {}

            T& operator*()
            {
                return _node->_data;
            }

            __list_iterator& operator++()
            {
                _node = _node->_next;
                return *this;
            }

            bool operator!=(const __list_iterator& it) const
            {
                return _node != it._node;
            }
        };

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
