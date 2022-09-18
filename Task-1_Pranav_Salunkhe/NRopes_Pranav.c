#include <stdio.h>

void swap(int* a, int* b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}

void minHeap(int arr[], int N, int i)
{
	int smallest = i;
	int left = 2*i+1;
	int right = 2*i+2;


	if (left < N && arr[left] < arr[smallest]) smallest = left;

	if (right < N && arr[right] < arr[smallest]) smallest = right;

	if (smallest != i)
	{
		swap(&arr[i], &arr[smallest]);
		minHeap(arr, N, smallest);
	}
}

void minHeapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--) minHeap(arr, N, i);
}


void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int findMinCost(int arr[], int N)
{
	minHeapSort(arr, N);
	int sum=0,k,j=0;
	while(N>1)
	{
		minHeap(arr, N, 0);		
		j = arr[0]+arr[1];
		sum += j;
		arr[1] = j;
		for(k=0; k<N-1; k++)
        {
            arr[k] = arr[k + 1];
        }
        N--;
	}
	return sum;
}

int main()
{
	int sum = 0;
	int arr[] = {5,4,2,8};
	int N = sizeof(arr) / sizeof(arr[0]);

	// or
	// int arr[10],N,sum = 0;
	// printf("Enter no. of ropes - ");
	// scanf("%d",&N);
	// for(int i=0;i<N;i++)
	// {
	// 	printf("Enter lenght of rope - ");
	// 	scanf("%d",&arr[i]);
	// }

	sum = findMinCost(arr, N);
	printf("Min cost = %d", sum);
		
}