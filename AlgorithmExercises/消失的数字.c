#if 0
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
#endif
#include <stdio.h>
int missingNumber(int* nums, int numsSize){
    int i = 0;
    int num = 0;
    for (i;i < numsSize;i++){
        num ^= nums[i];
        num ^= i;
    }
    num ^= numsSize;
    return num;
}
int main(){
    int arr[] = {1,3,0};
    int numsSize = sizeof(arr);
    int num = missingNumber(arr,numsSize);
    printf("%d\n",num);
    return 0;
}
    