//
// Created by 20212 on 29/6/2024.
//
typedef char BTDataType;
typedef struct BinaryTreeNode{
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;
void PrevOrder(BTNode* root){
    if(root == NULL)
        return;
    printf("%d",root ->_data);
    PrevOrder(root->_left);
    PrevOrder(root ->_right);
}
int TreeSize(BTNode* root){
    return 0;
}
int main(){
    return 0;
}