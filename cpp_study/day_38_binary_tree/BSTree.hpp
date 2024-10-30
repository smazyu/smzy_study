#ifndef BSTRESS_H
#define BSTRESS_H

#include <iostream>
using namespace std;

template <class K>
struct BTreeNode
{
    BTreeNode<K>* _left;
    BTreeNode<K>* _right;
    K _key;

    BTreeNode(const K& key) : _left(nullptr), _right(nullptr), _key(key) {}
};

template <class K>
class BTree
{
    typedef BTreeNode<K> Node;

public:
    BTree() : _root(nullptr) {}

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
            parent = cur; // 每次循环更新父节点
            if (cur->_key > key)
            {
                cur = cur->_left;
            }
            else if (cur->_key < key)
            {
                cur = cur->_right;
            }
            else
            {
                return false; // 键值已存在
            }
        }

        // 创建新节点并连接到父节点
        Node* newNode = new Node(key);
        if (parent->_key > key)
        {
            parent->_left = newNode;
        }
        else
        {
            parent->_right = newNode;
        }
        return true; // 成功插入
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

#endif // BSTRESS_H
