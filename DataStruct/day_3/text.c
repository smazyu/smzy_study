//
// Created by 20212 on 11/05/2024.
//
/*
 * 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
 * 元素的 相对顺序 应该保持 一致 。
 * 然后返回 nums 中唯一元素的个数。
 */
int removeDuplicates(int* nums, int numsSize) {
    int fast = 0;
    int slow = 0;
    for(fast;fast < numsSize;fast++){
        if (nums[fast] != nums[slow]){
            slow++;
        }
        nums[slow] = nums[fast];
    }
    return slow+1;
}

