#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort_tool.h"
#include "PSORT.h"
#define MAX 100
void slow_sort_i(int *arr,int left,int right){
	if(left>=right){
		return;
	}
	int m=(left+right)/2;
	slow_sort(arr,left,m);
	slow_sort(arr,m+1,right);
	
	if(arr[right]<arr[m]){
		swap(&arr[right],&arr[m]);
	}
	slow_sort(arr,left,right-1);
}

void slow_sort_d(double *arr,int left,int right){
	if(left>=right){
		return;
	}
	int m=(left+right)/2;
	slow_sort(arr,left,m);
	slow_sort(arr,m+1,right);
	
	if(arr[right]<arr[m]){
		swap(&arr[right],&arr[m]);
	}
	slow_sort(arr,left,right-1);
}

void slow_sort_f(float *arr,int left,int right){
	if(left>=right){
		return;
	}
	int m=(left+right)/2;
	slow_sort(arr,left,m);
	slow_sort(arr,m+1,right);
	
	if(arr[right]<arr[m]){
		swap(&arr[right],&arr[m]);
	}
	slow_sort(arr,left,right-1);
}

void stooge_sort_i(int *arr,int l,int r){
	if(arr[l]>arr[r]){
		swap(&arr[l],&arr[r]);
	}
	int t=(r-l+1)/3;//r-l+1>=3
	if(t>=1){
		stooge_sort(arr,l,r-t);
		stooge_sort(arr,l+t,r);
		stooge_sort(arr,l,r-t);
	}
	
}

void stooge_sort_d(double *arr,int l,int r){
	if(arr[l]>arr[r]){
		swap(&arr[l],&arr[r]);
	}
	int t=(r-l+1)/3;//r-l+1>=3
	if(t>=1){
		stooge_sort(arr,l,r-t);
		stooge_sort(arr,l+t,r);
		stooge_sort(arr,l,r-t);
	}
	
}

void stooge_sort_f(float *arr,int l,int r){
	if(arr[l]>arr[r]){
		swap(&arr[l],&arr[r]);
	}
	int t=(r-l+1)/3;//r-l+1>=3
	if(t>=1){
		stooge_sort(arr,l,r-t);
		stooge_sort(arr,l+t,r);
		stooge_sort(arr,l,r-t);
	}
	
}


void comb_sort(int *arr,int size){
	double shrink_factor=0.801711;
	int gap=size,swap_iped=2,i;
	while(gap>1||swap_iped){
		if(gap>1){
			gap*=shrink_factor;
		}
		swap_iped=0;
		for(i=0;gap+i<size;i++){
			if(arr[i]>arr[i+gap]){
				swap(&arr[i],&arr[i+gap]);
				swap_iped=1;
			}
		}
	}
}

void merge_A(int *arr,int left,int mid,int right){
    int i,j,k;
    int numL=mid-left+1;
    int numR=right-mid;
    int leftarr[numL];
    int rightarr[numR];
    for(i=0;i<numL;i++){//arr[left,mid] copy into leftarr
        leftarr[i]=arr[left+i];
    }
    for(i=0;i<numR;i++){
        rightarr[i]=arr[mid+1+i];
    }
    
    i=0;
    j=0;
    k=left;
    //compare element of leftarr and rightarr,put the smaller into the arr[left,right]
    while (i<numL && j<numR){
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    //put the remaining element into array
    while (i < numL) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    
    while (j < numR) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
    
    
}

void merge_sort_A(int *arr, int left, int right)
{
    if (arr == NULL || left >= right) {
        return;
    }
    
    int mid = (left + right) / 2;
    merge_sort_A(arr, left, mid);
    merge_sort_A(arr, mid + 1, right);
    merge_A(arr, left, mid, right);
}

void merge_B(int* arr, int p, int mid, int q) {
    int i, j, k;
    int leftarr[100], rightarr[100];
    int numL = mid - p + 1;
    int numR = q - mid;
    // Copy the elements from the [p,mid] region of arr array to the leftarr array
    for (i = 0; i < numL; i++) {
        leftarr[i] = arr[p - 1 + i];
    }
    // Copy the elements from the [mid+1,q] region of arr array to the rightarr array
    leftarr[i] = 2147483647;
    for (i = 0; i < numR; i++) {
        rightarr[i] = arr[mid + i];
    }
    rightarr[i] = 2147483647;
    i = 0;
    j = 0;
    // Compare the elements in leftarr and rightarr and copy the smaller element to the [p,q] region of arr array
    for (k = p; k <= q; k++) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k - 1] = leftarr[i];
            i++;
        }
        else {
            arr[k - 1] = rightarr[j];
            j++;
        }
    }
}

void merge_sort_B(int* arr, int p, int q) {
    int mid;
    if (arr == NULL || p > q || p == q) {
        return ;
    }
    mid = (p + q) / 2;
    // Split [p,q] into [p,mid] and [mid+1,q]
    merge_sort_B(arr, p, mid);
    merge_sort_B(arr, mid + 1, q);
    // Perform merging on the divided [p,mid] and [mid+1,q] regions
    merge_B(arr, p, mid, q);
}

void odd_even_sort(int *arr,int size){
	int odd_even,i;
	int temp;
	int sorted=0;
	while(!sorted){
		sorted=1;
		for(odd_even=0;odd_even<2;odd_even++){
			for(i=odd_even;i<size-1;i+=2){
				if(arr[i]>arr[i+1]){
					swap(&arr[i],&arr[i+1]);
					sorted=0;
				}
			}
		}
	}
}

void merge_d(double *arr,int left,int mid,int right){
    int i,j,k;
    int numL=mid-left+1;
    int numR=right-mid;
    double leftarr[numL];
    double rightarr[numR];
    for(i=0;i<numL;i++){//arr[left,mid] copy into leftarr
        leftarr[i]=arr[left+i];
    }
    for(i=0;i<numR;i++){
        rightarr[i]=arr[mid+1+i];
    }
    
    i=0;
    j=0;
    k=left;
    //compare element of leftarr and rightarr,put the smaller into the arr[left,right]
    while (i<numL && j<numR){
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    //put the remaining element into array
    while (i < numL) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    
    while (j < numR) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
    
    
}

void merge_sort_d(double* arr, int p, int q) {
    int mid;
    if (arr == NULL || p > q || p == q) {
        return ;
    }
    mid = (p + q) / 2;
    // Split [p,q] into [p,mid] and [mid+1,q]
    merge_sort(arr, p, mid);
    merge_sort(arr, mid + 1, q);
    // Perform merging on the divided [p,mid] and [mid+1,q] regions
    merge(arr, p, mid, q);
}

void merge_f(float *arr,int left,int mid,int right){
    int i,j,k;
    int numL=mid-left+1;
    int numR=right-mid;
    double leftarr[numL];
    double rightarr[numR];
    for(i=0;i<numL;i++){//arr[left,mid] copy into leftarr
        leftarr[i]=arr[left+i];
    }
    for(i=0;i<numR;i++){
        rightarr[i]=arr[mid+1+i];
    }
    
    i=0;
    j=0;
    k=left;
    //compare element of leftarr and rightarr,put the smaller into the arr[left,right]
    while (i<numL && j<numR){
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    //put the remaining element into array
    while (i < numL) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    
    while (j < numR) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
    
    
}

void merge_sort_f(float* arr, int p, int q) {
    int mid;
    if (arr == NULL || p > q || p == q) {
        return ;
    }
    mid = (p + q) / 2;
    // Split [p,q] into [p,mid] and [mid+1,q]
    merge_sort(arr, p, mid);
    merge_sort(arr, mid + 1, q);
    // Perform merging on the divided [p,mid] and [mid+1,q] regions
    merge(arr, p, mid, q);
}

int partition_i(int *array, int low, int high) {
    int pivot = array[low];
  
    while(low<high){
        while(low<high&&pivot<=array[high]){
            high--;
        }
        if(pivot>array[high]){
            swap(&array[low],&array[high]);
            low++;
        }
        while(low<high&&pivot>=array[low]){
            low++;
        }
        if(pivot<array[low]){
            swap(&array[low],&array[high]);
            high--;
        }
    }
    return high;
}

int partition_d(double *array, int low, int high) {
    double pivot = array[low];
  
    while(low<high){
        while(low<high&&pivot<=array[high]){
            high--;
        }
        if(pivot>array[high]){
            swap(&array[low],&array[high]);
            low++;
        }
        while(low<high&&pivot>=array[low]){
            low++;
        }
        if(pivot<array[low]){
            swap(&array[low],&array[high]);
            high--;
        }
    }
    return high;
}

int partition_f(float *array, int low, int high) {
    float pivot = array[low];
  
    while(low<high){
        while(low<high&&pivot<=array[high]){
            high--;
        }
        if(pivot>array[high]){
            swap(&array[low],&array[high]);
            low++;
        }
        while(low<high&&pivot>=array[low]){
            low++;
        }
        if(pivot<array[low]){
            swap(&array[low],&array[high]);
            high--;
        }
    }
    return high;
}

void quickSort_i(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void quickSort_d(double *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void quickSort_f(float *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void select_sort_i(int *arr, int low, int high) {
    if (high - low + 1 < 2) {
        return;
    }
    int max = arr[low];
    int max_index = low;
    for (int i = low + 1; i <= high; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    swap(&arr[low], &arr[max_index]);
    select_sort(arr, low + 1, high);
}

void select_sort_d(double *arr, int low, int high) {
    if (high - low + 1 < 2) {
        return;
    }
    double max = arr[low];
    int max_index = low;
    for (int i = low + 1; i <= high; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    swap(&arr[low], &arr[max_index]);
    select_sort(arr, low + 1, high);
}

void select_sort_f(float *arr, int low, int high) {
    if (high - low + 1 < 2) {
        return;
    }
    int max = arr[low];
    int max_index = low;
    for (int i = low + 1; i <= high; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    swap(&arr[low], &arr[max_index]);
    select_sort(arr, low + 1, high);
}

void countingSort(int *array,int place,int size){
	int i;
	int output[size];
	int *count=(int *)calloc(MAX + 1, sizeof(int));
	int max=(array[0]/place)%10;
	for(i=1;i<size;i++){
		if(((array[i]/place)%10)>max){
			max=array[i];
		}
	}
	
	for(i=0;i<size;i++){
		count[(array[i]/place)%10]++;
	}
	
	for(i=1;i<10;i++){
		count[i]+=count[i-1];
	}
	
	for(i=size-1;i>=0;i--){
		output[count[(array[i]/place)%10]-1]=array[i];
		count[(array[i]/place)%10]--;
	}
	
	for(i=0;i<size;i++){
		array[i]=output[i];
	}
}

void radix_sort(int *array,int size){
	int place,max;
	max=get_max(array,size);
	for(place=1;max/place>0;place*=10){
		countingSort(array,place,size);
	}
}
#endif
