//
// Created by 20212 on 24-11-5.
//
/*给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。

空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。*/
using  namespace std;
#include <iostream>
#if 0
class Solution {
public:
    string tree2str(TreeNode* root) {
        TreeNode* t = root;
        string str;
        if(t == NULL)
            return str;
        str += to_string(t->val);
        if(t -> left){
            str += '(';
            str += tree2str(t -> left);
            str += ')';
        }else if(t -> right){
            str += "()";
        }
        if(t -> right){
            str += '(';
            str += tree2str(t->right);
            str += ')';
        }
        return str;
    }
};
#endif
