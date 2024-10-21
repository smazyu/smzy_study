//
// Created by 20212 on 24-10-21.
//
#pragma once;
#include <vector>
using namespace std;

//函数全大写 变量小大写
namespace bit
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
                    swap(_con[child], _con[parent]);
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
                    swap(_con[child] > _con[parent]);
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
            //设父节点为i (i*2+1)为左节点 (i*2+2)为右节点
            AdjustUp(_con.size() - 1);
        }

        void pop()
        {
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            AdjustDown(0);
        }

        T& top()
        {

        };



        
        //优先级最高的
        size_t size()
        {
            return _con.size();
        }

        bool empty();

    private:
        Container _con;
    };
}
