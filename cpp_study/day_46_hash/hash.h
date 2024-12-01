//
// Created by 20212 on 24-11-30.
//
//unordered_map -> HashTable<K, T>
//unordered_set -> HashSet<K,K>
#pragma once
#include <vector>

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
};

template <class K, class T>
class HashTable
{
public:
    bool Insert(const T& d)
    {
        //计算d中的key在表中映射的位置
        size_t index = d % _tables.size();
        while (_tables[index]._state == EXIST)
        {
            ++index;
            if (index == _tables.size())
            {
                index = 0;
            }
        }
        _tables[index]._data = d;
        _tables[index]._state = EXIST;
        _nums++;
    }

private:
    vector<T> _tables;
    size_t _num; //存了几个有效数据
};
