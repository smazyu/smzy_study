#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

namespace study_priority_queue
{
    template <class T, class Container = vector<T>>
    class priority_queue
    {
    public:
        void AdjustUp(int child)
        {
            int parent = (child - 1) / 2;
            while (child > 0)
            {
                if (_con[child] > _con[parent])
                {
                    std::swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }

        void AdjustDown(int root)
        {
            int parent = root;
            int child = parent * 2 + 1;
            while (child < _con.size())
            {
                if (child + 1 < _con.size() && _con[child + 1] > _con[child])
                {
                    ++child;
                }
                if (_con[child] > _con[parent])
                {
                    std::swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        void push(const T& x)
        {
            _con.push_back(x);
            // 设父节点为i (i*2+1)为左节点 (i*2+2)为右节点
            AdjustUp(_con.size() - 1);
        }

        void pop()
        {
            std::swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            AdjustDown(0);
        }

        T& top()
        {
            return _con[0];
        }

        size_t size() const
        {
            return _con.size();
        }

        bool empty() const
        {
            return _con.empty();
        }

    private:
        Container _con;
    };

    void test_priority_queue()
    {
        priority_queue<int> pq;
        pq.push(3);
        pq.push(1);
        pq.push(9);
        pq.push(4);
        pq.push(2);
        while(!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
}
