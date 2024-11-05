//
// Created by 20212 on 24-11-5.
//
#include <iostream>
using namespace std;
#include <string>

template <class K, class V>
struct BStreeNode //Binary Search Tree Node
{
    BStreeNode<K,V>* _left;
    BStreeNode<K,V>* _right;

    K _key;
    V _val;

    BStreeNode(const K&key):_left(nullptr),_right(nullptr),_key(key)
,_val(value)
    {}

};
