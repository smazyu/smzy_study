#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace bit
{
    class bitset
    {
    public:
        // 构造函数，初始化位图
        bitset(size_t N)
        {
            // 位图应该存位
            // 一个整形有32位，所以N/32就可以存N个数据，因为是按位存储的
            _bits.resize(N / 32 + 1, 0);
            _num = 0;
        }

        // 将x位置设为1
        void set(size_t x)
        {
            size_t index = x / 32; // 计算x映射的位置在第几个整形
            size_t pos = x % 32;   // 计算x映射的位置在整形的第几位
            _bits[index] |= (1 << pos); // 将第pos位置1
            ++_num;
        }

        // 将x位置设为0
        void reset(size_t x)
        {
            size_t index = x / 32;
            size_t pos = x % 32;
            _bits[index] &= ~(1 << pos); // 将第pos位置0
            --_num;
        }

        // 检查x位置是否为1
        bool test(size_t x)
        {
            size_t index = x / 32;
            size_t pos = x % 32;
            return _bits[index] & (1 << pos); // 将第pos位置1，进行与运算
        }

    private:
        std::vector<int> _bits; // 位图
        size_t _num;            // 映射存储的多少个数据
    };

    // 测试 bitset
    void test_bitset()
    {
        bitset bs(100);
        bs.set(88);
        bs.set(99);
        bs.set(96);
        bs.reset(88);

        for (size_t i = 0; i < 100; ++i)
        {
            if (bs.test(i))
            {
                printf("[%d] : %d", i, bs.test(i));
                std::cout << std::endl;
            }
        }
    }
}

namespace study
{
    // 哈希函数 1
    struct HashStr1
    {
        size_t operator()(const std::string& str)
        {
            size_t hash = 0;
            for (size_t i = 0; i < str.size(); ++i)
            {
                hash = hash * 131 + str[i]; // 使用131的常数来计算哈希值
            }
            return hash;
        }
    };

    // 哈希函数 2
    struct HashStr2
    {
        size_t operator()(const std::string& str)
        {
            size_t hash = 0;
            for (size_t i = 0; i < str.size(); ++i)
            {
                hash = hash * 65599 + str[i]; // 使用65599的常数来计算哈希值
            }
            return hash;
        }
    };

    // 哈希函数 3
    struct HashStr3
    {
        size_t operator()(const std::string& str)
        {
            size_t hash = 0;
            for (size_t i = 0; i < str.size(); ++i)
            {
                hash = hash * 137 + str[i]; // 使用137的常数来计算哈希值
            }
            return hash;
        }
    };

    // 布隆过滤器模板类
    template <class K, class Hash1 = HashStr1, class Hash2 = HashStr2, class Hash3 = HashStr3>
    class bloomfilter
    {
    public:
        // 构造函数，传入位图的大小
        bloomfilter(size_t size) : _bs(size * 5),_N(5*size) {}  // 初始化位图

        // 将键添加到布隆过滤器
        void set(const K& key)
        {
            size_t index1 = Hash1()(key) % _N; // 使用 Hash1 函数计算哈希值
            size_t index2 = Hash2()(key) % _N; // 使用 Hash2 函数计算哈希值
            size_t index3 = Hash3()(key) % _N; // 使用 Hash3 函数计算哈希值

            _bs.set(index1); // 将对应位置设为1
            _bs.set(index2);
            _bs.set(index3);
        }

        // 检查一个键是否存在于布隆过滤器中
        bool test(const K& key)
        {
            size_t index1 = Hash1()(key); // 计算哈希值
            if (!_bs.test(index1)) return false; // 如果对应位置为0，返回 false

            size_t index2 = Hash2()(key); // 计算哈希值
            if (!_bs.test(index2)) return false; // 如果对应位置为0，返回 false

            size_t index3 = Hash3()(key); // 计算哈希值
            if (!_bs.test(index3)) return false; // 如果对应位置为0，返回 false

            return true; // 如果所有对应位置都为1，返回true（可能是误报）
        }

    private:
        bit::bitset _bs; // 位图对象，用于存储布隆过滤器的数据
        size_t _N;
    };
    void test_bloomfilter()
    {
        bloomfilter<std::string> bf(100);
        bf.set("hello");
        bf.set("world");
        bf.set("bloom");
        bf.set("abcd");
        bf.set("bcad");
        cout << bf.test("hello") << endl;
        cout << bf.test("world") << endl;
        cout << bf.test("bloom") << endl;
        cout << bf.test("abcd") << endl;
        cout << bf.test("bcad") << endl;
    }

}

#endif //BLOOMFILTER_H

