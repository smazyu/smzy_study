//
// Created by 20212 on 25/7/2024.
//

#include "sort.h"
void PrintArray(int*a,int n){
    for(int i = 0;i < n;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void TestInsertSort(){
    int a[] = {3,1,4,1,7,3,8,23,2,1111,0};
    PrintArray(a,sizeof(a)/sizeof(int));
    InsertSort(a,sizeof(a)/sizeof(int));
    PrintArray(a,sizeof(a)/sizeof(int));
}
int main(){
    TestInsertSort();
};