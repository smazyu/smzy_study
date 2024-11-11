//  给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
#if 0
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;

        TreeNode* cur = root;
        while(cur || !st.empty()){
            //左路节点
            //访问左路节点的右子树

            while(cur){
                ret.push_back(cur -> val);
                st.push(cur);
                cur = cur -> left;
            }
            //取栈中的右子树出来访问
            TreeNode* top = st.top();
            st.pop();

            cur = top -> right;
        }
        return ret;
    }
};
#endif