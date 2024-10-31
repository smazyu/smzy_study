//
// Created by 20212 on 24-11-1.
//
//下标为i的节点的父节点(i-1)/2
//左孩子 i*2 + 1;
//右孩子 i*2 + 2;
void swap(int*a,int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int lson = i * 2 + 1;
    int rson = i * 2 + 2;
    if (lson < n && arr[largest] < arr[lson])
        largest = lson;
    if (rson < n && arr[largest] < arr[rson])
        largest = rson;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr,n,largest);
    }
}
void 