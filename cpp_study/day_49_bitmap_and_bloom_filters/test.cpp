//
// Created by 20212 on 24-12-6.
//
//位图 既节省空间 效率又高
#pragma once
#include <vector>
namespace bit
{
    class bitset
    {
    public:
        bitset(size_t N)
        {
            //位图应该存位
            _bits.resize(N/32 + 1,0);
            _num = 0;
        }
    private:
        // int* _bits;
        std::vector<int> _bits;
        size_t _num;//映射存储的多少个数据
    };
}