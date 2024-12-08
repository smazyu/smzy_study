//
// Created by 20212 on 24-12-6.
//
//位图 既节省空间 效率又高
#pragma once
#include <vector>
#include <iostream>
namespace bit
{
    class bitset
    {
    public:
        bitset(size_t N)
        {
            //位图应该存位
            //一个整形有32位 所以N/32就可以存N个数据 因为是按位存储的
            _bits.resize(N/32 + 1,0);
            _num = 0;
            
        }
        void set(size_t x)
        {
            size_t index = x/32;//算出x映射的位置在第几个整形 即第几个数据 因为是按位存储的 一个整形有32位
            size_t pos = x%32;//算出x映射的位置在整形的第几位
//左移是向高位移 右移是向低位移
            _bits[index] |= (1<<pos);//将第pos位置1 |= 是或等于 1<<pos是将1左移pos位 异或是不同为1 相同为0 这里用异或将第pos位置1
        }

        void reset(size_t x)
        {
            size_t index = x/32;
            size_t pos = x%32;
            _bits[index] &= ~(1<<pos);//将第pos位置0 &=是与等于 ~(1<<pos)是将1左移pos位取反 0的取反是1 1的取反是0 与是同为1才为1 不然就是0
        }

        bool test (size_t x)
        {
            size_t index = x/32;
            size_t pos = x%32;
            return _bits[index] & (1<<pos);//将第pos位置1 然后与运算 如果是1就是1 不然就是0 全为1才为1
        }
    private:
        // int* _bits;
        std::vector<int> _bits;
        size_t _num;//映射存储的多少个数据
    };
    void test_bitset()
    {
        bitset bs(100);
        bs.set(88);
        bs.set(99);
        bs.set(96);
        bs.reset(88);

        for (size_t i = 0; i< 100; ++i)
        {
            if (bs.test(i))
            {
               printf("[%d] : %d",i,bs.test(i));
                std::cout << std::endl;
            }
        }
    }
}

int main()
{
    bit :: test_bitset();
    return 0;
}