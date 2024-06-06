//
// Created by 20212 on 6/6/2024.
//
void AdjustDown(int *a,int n,int root){
    int parent = root;
    int child = parent*2 +1;
    while(child < n){
        if(child + 1 < n && a[child +1] < a[child]){
            ++child;
        }
        if(a[child] < a[parent]){
            Swap(&a[child],&a[parent]);
            parent = child;
            child = parent *2 +1;
        }else{
            break;
        }
    }
}