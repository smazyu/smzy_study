//
// Created by 20212 on 23/7/2024.
//

BTNode *BinaryTreeFind(BTNode*root,BTDataType x){
    if(root == NULL){
        return NULL;
    }
    if(root -> _data == x){
        return root;
    }
    BTNode* node = BinaryTreeFind(root -> _left,x){
        if(node){
            return node;
        }
    }
    BTNode* node = BinaryTreeFind(root -> _right,x){
        if(node){
            return node;
        }
    }
    return NULL;
}