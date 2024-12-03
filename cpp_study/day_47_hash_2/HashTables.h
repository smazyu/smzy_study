#pragma once
#include <vector>
#include <functional>
using namespace std;
namespace CLOSED_HASE
{
    enum State
{
    EMPTY,
    EXIST,
    DELETE
};

template <class T>
struct HashData
{
    T _data;
    State _state;

    HashData() : _state(EMPTY) {}
};

template <class K, class T>
class HashTable
{
public:
    typedef std::function<K(const T &)> KeyOfT;

    HashTable(size_t initialSize = 8) : _tables(initialSize), _num(0) {}

    bool Insert(const T &d)
    {
        KeyOfT kt;
        // 计算d中的key在表中映射的位置
        size_t index = kt(d) % _tables.size();

        // 如果负载因子过大，需要扩容
        if (_num > 0.7 * _tables.size())
        {
            Rehash();                       // 扩展表
            index = kt(d) % _tables.size(); // 重新计算索引
        }

        while (_tables[index]._state == EXIST)
        {
            if (_tables[index]._data == d)
            {
                return false; // 如果已经存在
            }
            ++index;
            if (index == _tables.size())
            {
                index = 0; // 循环访问
            }
        }

        _tables[index]._data = d;
        _tables[index]._state = EXIST;
        _num++;
        return true;
    }

    HashData<T> *Find(const K &key)
    {
        KeyOfT kt;
        size_t index = key % _tables.size();

        while (_tables[index]._state != EMPTY)
        {
            if (_tables[index]._state == EXIST && kt(_tables[index]._data) == key)
            {
                return &_tables[index]; // 找到并且是有效状态
            }
            ++index;
            if (index == _tables.size())
            {
                index = 0; // 循环访问
            }
        }
        return nullptr; // 未找到
    }

    bool Erase(const K &key)
    {
        HashData<T> *ret = Find(key);
        if (ret)
        {
            ret->_state = DELETE;
            _num--;
            return true;
        }
        return false;
    }

private:
    std::vector<HashData<T>> _tables;
    size_t _num = 0; // 存了几个有效数据

    void Rehash()
    {
        std::vector<HashData<T>> oldTables = _tables;
        _tables.resize( oldTables.size() * 2); // 扩容
        for (auto &entry : _tables)
        {
            entry._state = EMPTY; // 清空新的哈希表
        }
        _num = 0; // 重置计数

        for (const auto &oldEntry : oldTables)
        {
            if (oldEntry._state == EXIST)
            {

                Insert(oldEntry._data); // 重新插入
            }
        }
    }
};
// 一般情况下负载因子越小，冲突概率越低，效率越高
// 但是负载因子过小，会导致空间浪费，所以一般取0.7左右
template <class K>
struct SetKeyOfT
{
    const K &operator()(const K &key)
    {
        return key;
    }
};
//闭散列中线性探测存在什么问题
//线性探测思路就是我的位置被占了，然后我就挨着往后去占别人的位置，可能会导致一片一片的冲突，洪水效应

//闭散列-开放定值法不是一种好的解决方式，因为他是一种我的位置被占，就去抢别人的位置的思路
//所以他的哈希冲突会互相影响
}
namespace OPEON_HASH
{
    template<class T>
    struct HaseNode
    {
        T _data;
        HaseNode<T>* _next;
    };
    template<class K,class T,class KeyOfT>
    class HashTable
    {
        typedef HaseNode<T> *Node;
    private:
        vector<Node*> _tables;
        size_t _num;//记录表中存储的数据个数
    };
}