#include <iostream>
using namespace std;
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}  TreeNode(int x) : val(x), left(nullptr), right(nullptr){}  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right){}
        
};
class Solution
{
public:
    TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int &prei,
                         int inbegin, int inend)
    {
        if (inbegin > inend)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[prei]);

        int rooti = inbegin;
        while (rooti <= inend)
        {
            if (inorder[rooti] == preorder[prei])
                break;
            else
                ++rooti;
        }
        //[inbein,rooti - 1] rooti [rooti + 1,inend]
        if (inbegin <= rooti - 1)
            root->left =
                _buildTree(preorder, inorder, ++prei, inbegin, rooti - 1);
        else
            root->left = NULL;

        if (rooti + 1 <= inend)
            root->right =
                _buildTree(preorder, inorder, ++prei, rooti + 1, inend);
        else
            root->right = NULL;

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // preorder 前序 根 左子树 右子树
        // inorder 中序 左子树 根 右子树

        // 1.前序确定根
        // 2.中序确定左子树的中序区间 和 右子树的中序区间

        // 使用左子树的前序+左子树的中序区间递归构建左子树
        // 使用右子树的前序+右子树的中序区间递归构建右子树
        int prei = 0;
        int inbegin = 0, inend = inorder.size() - 1;

        return _buildTree(preorder, inorder, prei, inbegin, inend);
    }
};