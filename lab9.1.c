#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int array[10000];

float timedifference_msec(struct timeval t0, struct timeval t1)
{
	return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void printArr(int a[], int n){  
	int i;  
	for (i = 0; i < n; i++){
		printf("%d ", a[i]);  
	}  
}

void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

int partition(int arr[], int start, int end)
{
	int pIndex = start;
	int pivot = arr[end];
	int i;
	for(i = start; i < end; i++){
		if(arr[i] < pivot){
			swap(&arr[i], &arr[pIndex]);
			pIndex++;
		}
	}
	swap(&arr[end], &arr[pIndex]);
	return pIndex;
}

void quicksort(int arr[], int start, int end)
{
	if(start < end){
		int pIndex = partition(arr, start, end);
		quicksort(arr, start, pIndex-1);
		quicksort(arr, pIndex+1, end);
	}
}

int main()
{
	printf("Quick Sort\n");
	struct timeval t0;
	struct timeval t1;
	float elapsed;
    
	long size;
	printf("Enter number of Elements:");
	scanf("%ld",&size);
	int array[size];
	
	int num=size;
	int i,j,x,y,temp;
	srand( (unsigned) time(NULL) * getpid());
	if(array != NULL){
		for(j = 0; j < num; j++){
			array[j] = rand()%100;
		}
	}
	printf("Array before sorting:\n");
	printArr(array,num);
	gettimeofday(&t0, NULL);
	quicksort(array,0,size-1);
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("\nArray after sorting:\n");
	printArr(array,num);
	printf("\n\nQuick Sort Code executed in %f milliseconds.\n", elapsed);
}
