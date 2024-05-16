//给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

// 你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int ret = 0;
    for(int i = 0;i < numsSize;++i){
        ret ^= nums[i];
        //异或之后剩下来的是 x1 和 x2 异或之后的值
    }
    //将这个整数数组分为两组
    //判断ret的第m位为1
    //为1 代表 原数这里不同 一个为1 另一个为0
    int m = 0;
    for (m = 0; m < 30;++m){
        if(ret & 1 << m){
            break;
        }
    //将nums中为1 和 为 0 的分为两组
    }
    //遍历一遍，进行分组
    int x1 = 0,x2 = 0;
    for( int i = 0;i < numsSize;++i){
        if(nums[i] & 1 << m){
            x1 ^= nums[i];
        }else{
            x2 ^= nums[i];
        }
    }
    *returnSize = 2;
    int* retArr = (int *)malloc(sizeof(int)*2);
    retArr[0] = x1;
    retArr[1] = x2;
    return retArr;
}