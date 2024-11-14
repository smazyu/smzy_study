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
        //2.更新平衡因子
        //3.如果更新完了，没有出现违反规则，则插入结束
        //如果有违反规则，则旋转处理
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }
    }

    Node* parent = nullptr;
    Node* cur = _root;

    while(cur)
    {
        if (cur->_kv.first > kv.first) //_kv.first 当前左树
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
//cur是parent的左 parent->bf-- ,cur是parent的右,parent ->bf++
    //更新完parent的bf，如果parent->bf == 0,说明parent高度不变,更新结束,插入完成
    //说明插入前,parent的bf是1or -1,现在变为0,说明把矮的那边补上了。说明我的高度不变，对上层没有影响


    //更新完parent的bf,如果parent->bf == 1or -1,说明parent的高度变了,对上层有影响,继续往上更新
    cur=new Node (kv);
    if(parent->_kv.first<kv.first)
          {
              parent->_right = cur;
              cur->_parent = parent;
          }else
          {
              parent->_left = cur;
              cur->_parent = parent;
          }
    return true;

private:
    Node* _root;
};
