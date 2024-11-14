//
// Created by 20212 on 24-11-14.
//

#ifndef AVLTREE_H
#define AVLTREE_H

#endif //AVLTREE_H

#pragme once
template <class K, class V>
struct AVLTreeNode
{
    AVLTreeNode<K, V>* _left;
    AVLTreeNode<K, V>* _right;
    AVLTreeNode<K, V>* _parent;

    int _bf; // balance factor 平衡因子

    pair<K, V> _kv;
};

class AVLTree
{
    typedef AVLTreeNode<K, V> Node;

public:
    bool Insert(const pair<K, V>& kv)
    {
        //1.先按搜索树的规则进行插入
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }
    }

    Node* parent = nullptr;
    Node* cur = _root;

    while (cur)
    {
        if (cur->_kv.first > kv.first)//_kv.first 当前左树
        //插入的左树
        {
            parent = cur;
            cur = cur->_left;
        }

        else if (cur->_kv.first < kv.first)
        {
            parent = cur;
            cur = cur->_right;
        }
        else
        {
            return false;
        }
    }
    cur = new Node(kv);
    if(parent -> _kv.first < kv.first)
    {
        parent -> _right = cur;
    }else
    {
        parent -> _left = cur;
    }


private:
    Node* _root;
};
