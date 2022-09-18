#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeap(int arr[], int N, int i)
{
    int left, right, small;
    small = i;
    left = 2*i + 1;
    right = 2*i + 2;

    if(left<N && arr[left]<arr[small])
    {
        small = left;
    }
    if(right<N && arr[right]<arr[small])
    {
        small = right;
    }

    if(small != i)
    {
        swap(&arr[small], &arr[i]);
        MinHeap(arr, N, small);
    }

}

void MinHeapsort(int arr[], int N)
{
    for(int i = N/2 - 1; i>=0; i--)
    {
        MinHeap(arr, N, i);
    }
}

void Display(int arr[], int N)
{
    for(int i=0; i<N; i++)
    {
        printf("%d ", arr[i]);
    }
}
int MinCost(int arr[], int N)
{
    int sum = 0;
    while(N>1)
    {
        MinHeap(arr, N, 0);
        int i = arr[0] + arr[1];
        sum+=i;
        arr[1] = i;
        for(int j=0; j<N-1; j++)
        {
            arr[j] = arr[j+1];
        }
        N--;
    }
    return sum;

}

void main()
{
    int arr[] = {2,4,1,8,9};
    int N = sizeof(arr)/sizeof(arr[0]);
    MinHeapsort(arr, N);
    int sum = MinCost(arr, N);
    printf("The Minimum Cost is: ");
    printf("%d", sum);
    //Display(arr, N);
}
