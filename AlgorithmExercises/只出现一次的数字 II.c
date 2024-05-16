//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

// 你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
int singleNumber(int* nums, int numsSize) {
    int one = 0,two = 0;
    for(int i =0;i < numsSize;i ++){
        one = (one ^ nums[i]) & ~two;
        two = (two ^ nums[i]) &~ one;
    }
    return one;
    
}