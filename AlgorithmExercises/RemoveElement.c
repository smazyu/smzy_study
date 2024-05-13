/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/
//分为上下两个指针
int removeElement(int* nums, int numsSize, int val) {
    int fast = 0;
    int slow = 0;
    for (fast;fast < numsSize;fast++){
        if(nums[fast] != val){
            //当当前元素不为要删除的元素时，进行替换 当当前元素为val时，fast+1而slow为+1所以产生了错位，当下次当前元素不为val时，就会覆盖点错位的元素，即所要删除的元素
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}