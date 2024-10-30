//
// Created by 20212 on 24-10-30.
//

#ifndef BSTRESS_H
#define BSTRESS_H

#endif //BSTRESS_H
#pragma once
using namespace std;
#include <iostream>

template <class K>
struct BTreeNode
{
    BTreeNode<K>* _left;
    BTreeNode<K>* _right;

    K _key;

    BTreeNode(const K& key): _left(nullptr), _right(nullptr), _key(key)
    {
    }
};

template <class K>
class BTree
{
    typedef BTreeNode<K> Node;

public:
    bool Insert(const K& key)
    {
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur)
        {
            if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false;
            }
            cur = new Node(key);
            return true;
        }
    }

    void _InOrder(Node* root)
    {
        if (root == nullptr)
            return;
        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }

    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

private:
    Node* _root = nullptr;
};

void TestBSTree()
{
    BTree<int> t;
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
    for (auto e : a)
    {
        t.Insert(e);
    }
    t.InOrder();
}
