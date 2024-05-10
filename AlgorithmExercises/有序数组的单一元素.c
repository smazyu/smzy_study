/*给定一个只包含整数的有序数组 nums ，
每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。
*/
int singleNonDuplicate(int* nums, int numsSize){
    int i = 0;
    int num = 0;
    for(i;i<numsSize;i++){
        num ^= nums[i];
    }
}