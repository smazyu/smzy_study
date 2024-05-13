//
// Created by 20212 on 14/05/2024.
//
/*
 *
 * 整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。

例如，对于 num = 1321 ，数组形式是 [1,3,2,1] 。
给定 num ，整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 。
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <malloc.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int Knum = k;
    int Ksize = 0;
    while(Knum / 10 || Knum > 0){
        Ksize ++;
        Knum /= 10;
    }
    int len = numSize > Ksize ? numSize + 1:Ksize + 1;
    int * RetArr = (int*)malloc(sizeof(int)*(len));
    int * karr = (int*)malloc(sizeof(int)*Ksize);
    int Ki = Ksize - 1;
    int klen = Ksize;
    while(klen --){
        int cur = k % 10;
        k = k /10;
        karr[Ki] = cur;
        Ki --;
    }
    int Ni = numSize - 1;
    Ki = Ksize - 1;
    int Ri = 0;
    int next = 0;
    while(Ni >= 0 || Ki >= 0){
        int num_ = (Ni >= 0 ? num[Ni] : 0) + (Ki>=0 ? karr[Ki] : 0) + next;
        if (num_ > 9){
            num_ -= 10;
            next = 1;
        }else{
            next = 0;
        }
        RetArr[Ri] = num_;
        Ni --;
        Ki --;
        Ri ++;
        //最后ri会多加1，多加1之后就是数组长度
    }
    if (next == 1){
        RetArr[Ri] = 1;
        Ri++;
    }
    *returnSize = Ri;
    int left = 0;
    int right = Ri -1;
    int temp = 0;
    while(left < right){
        temp = RetArr[left];
        RetArr[left] = RetArr[right];
        RetArr[right] = temp;
        left ++;
        right --;
    }
    return RetArr;
}