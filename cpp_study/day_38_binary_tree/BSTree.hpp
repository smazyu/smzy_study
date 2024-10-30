//
// Created by 20212 on 24-10-30.
//

#ifndef BSTRESS_H
#define BSTRESS_H

#endif //BSTRESS_H
#pragma once
template <class K>
class BTreeNode
{
    BTreeNode<K>* _left;
    BTreeNode<K>* _right;

    K _key;
};

template <class K>
class BTree
{   typedef BTreeNode<K> Node;
public:
    bool Insert(const K& key)
    {
        if(_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }
        Node* cur = _root;
        while (cur)
        {
            if(cur -> _key > key)
            {
                cur = cur -> _left;
            }else if(cur -> _key < key)
            {
                cur = cur -> _right;
            }else
            {
                return false;
            }
            cur = new Node(key);
            return true;
        }
    }
private:
    Node* _root = nullptr;
};
