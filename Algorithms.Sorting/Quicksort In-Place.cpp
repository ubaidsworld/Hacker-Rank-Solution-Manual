#include <iostream>

int size;

//Swap 2 elements of an array
void swap(int* a, int* b)
{
    int t = *a;*a = *b;*b = t;
}
// print out int array
void dump(int* a, int N)
{
    int i = 0;
    for(;i<N;i++) printf("%d ",a[i]);
    printf("\n");
}
/*
A partition method
return false if no swap
*/
int partition(int* a, int lt, int rt)
{
    int pivot = rt; // choose right as pivot
    int pval = a[pivot];
    int new_pivot = lt;
    int i;
     
    for(i=lt;i<rt;i++)
    {
        if(a[i]<pval)
        {
            swap(a + i, a + new_pivot++);
        }
    }
    swap(a + rt, a + new_pivot);
    
    dump(a,size);
    return new_pivot;
}
/*
A normal quicksort
http://en.wikipedia.org/wiki/Quicksort#Algorithm
*/
void quicksort(int* a, int lt, int rt)
{
    int pivot = -1;
    if(lt>=rt) return;
    pivot = partition(a, lt, rt);
    quicksort(a, lt, pivot-1);
    quicksort(a, pivot+1, rt);
}

int main() {
    int i,t;
    
    std::cin >> size;
    
    int* arr = (int*)malloc(sizeof(int)*size);
    
    for(i=0;i<size;i++){
        std::cin>>t;
        arr[i] = t;
    }
    
    quicksort(arr,0,size-1);
    
    free(arr);
    return 0;
}