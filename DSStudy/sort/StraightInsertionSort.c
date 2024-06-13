//采用顺序查找查插入位置
#include <stdio.h>
void StraightInset(int * arr,int n){
 int j,i;
 for(i = 2;i < n;i++){
     if(arr[i -1]>arr[i])
         arr[0] = arr[i];
     for(j = i -1;arr[j] > arr[0];j--){
         arr[j + 1] = arr[j];
     }
//     if(arr[j] <= arr[0])
         arr[j + 1] = arr[0];
 }
}
int main(){
    int arr[10] = {10,3,20,11,76,13,46,99,1,31};
    StraightInset(arr,sizeof(arr)/sizeof(int));
    for(int i = 0;i < 10;i++){
        printf("%d ",arr[i]);
    }
}