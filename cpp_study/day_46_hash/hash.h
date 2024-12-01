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
    // int KeyOfT(const T& d)
    // {
    //     if (typeof(K) == typeof(T))
    //     {
    //         return
    //     }
    // }
    bool Insert(const T& d)
    {
        KeyOfT kt;
        //计算d中的key在表中映射的位置
        size_t index = kt(d) % _tables.size();
        while (_tables[index]._state == EXIST)
        {
            if (_tables[index]._data == kt(d))
            {
                return false;
            }
            ++index;
            if (index == _tables.size())
            {
                index = 0;
            }
        }
        _tables[index]._data = kt(d);
        _tables[index]._state = EXIST;
        _nums++;
        return true;
    }

    HashData* Find(const K& key)
    {
        KeyOfT kt;
        size_t index = key % _tables.size();
        while (_tables[index]._state != EMPTY)
        {
            if (kt(_tables[index]._data) == key)
            {
                if (_tables[index]._state == EXIST)
                {
                    return &_tables[index];
                }
                else
                {
                    return nullptr;
                }
                return &_tables[index];
            }
            ++index;
            if (index == _tables.size())
            {
                index = 0;
            }
        }
    }
    bool Erase(const K& key)
    {
        HashData* ret = Find(key);
        if (ret)
        {
            ret->_state = DELETE;
            return true;
        }
        return false;
    }
private:
    vector<T> _tables;
    size_t _num; //存了几个有效数据
};
