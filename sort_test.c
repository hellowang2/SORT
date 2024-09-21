#include <stdio.h>
#include <stdlib.h>
#include "sort_tool.h"
#include "sort.h"
#include "PSORT.h"

int main() {
    // 測試數據
    int intArr[] = {5, 2, 8, 1, 3};
    int intArr1[] = {5, 2, 8, 1, 3};
    int intArr2[] = {5, 2, 8, 1, 3};
    int intArr3[] = {5, 2, 8, 1, 3};
    int intArr4[] = {5, 2, 8, 1, 3};
    int intArr5[] = {5, 2, 8, 1, 3};
    int intArr6[] = {5, 2, 8, 1, 3};
    double doubleArr[] = {5.5, 2.2, 8.8, 1.1, 3.3};
    double doubleArr1[] = {5.5, 2.2, 8.8, 1.1, 3.3};
    double doubleArr2[] = {5.5, 2.2, 8.8, 1.1, 3.3};
    double doubleArr3[] = {5.5, 2.2, 8.8, 1.1, 3.3};
    double doubleArr4[] = {5.5, 2.2, 8.8, 1.1, 3.3};
    float floatArr[] = {5.5f, 2.2f, 8.8f, 1.1f, 3.3f};
    float floatArr1[] = {5.5f, 2.2f, 8.8f, 1.1f, 3.3f};
    float floatArr2[] = {5.5f, 2.2f, 8.8f, 1.1f, 3.3f};
    float floatArr3[] = {5.5f, 2.2f, 8.8f, 1.1f, 3.3f};
    float floatArr4[] = {5.5f, 2.2f, 8.8f, 1.1f, 3.3f};
    int size = sizeof(intArr) / sizeof(int);
    int i;

    
    printf("Using slow_sort_i:\n");
    slow_sort(intArr, 0, size - 1);
    printArray(intArr,size);
    printf("Using stooge_sort_i:\n");
	stooge_sort(intArr1,0,size-1);
	printArray(intArr1,size);
	printf("Using comb_sort_i:\n");
	comb_sort(intArr2,size);
	printArray(intArr2,size);
	printf("Using merge_sort:\n");
	merge_sort(intArr3,0,size-1);
	printArray(intArr3,size);
	printf("Using odd_even_sort:\n");
	odd_even_sort(intArr4,size);
	printArray(intArr4,size);
	printf("Using qsort:\n");
	quickSort(intArr5,0,size-1);
	printArray(intArr5,size);
	printf("Using select_sort:\n");
	select_sort(intArr6,0,size-1);//大到小
	printArray(intArr6,size);
	
	printf("Using slow_sort_d:\n");
    slow_sort(doubleArr, 0, size - 1);
    printArray(doubleArr,size);
    printf("Using stooge_sort_d:\n");
	stooge_sort(doubleArr1,0,size-1);
	printArray(doubleArr1,size);
	printf("Using merge_sort:\n");
	merge_sort(doubleArr2,0,size-1);
	printArray(doubleArr2,size);
	printf("Using qsort:\n");
	quickSort(doubleArr3,0,size-1);
	printArray(doubleArr3,size);
	printf("Using select_sort:\n");
	select_sort(doubleArr4,0,size-1);//大到小
	printArray(doubleArr4,size);
	
	printf("Using slow_sort_f:\n");
    slow_sort(floatArr, 0, size - 1);
    printArray(floatArr,size);
    printf("Using stooge_sort_f:\n");
	stooge_sort(floatArr1,0,size-1);
	printArray(floatArr1,size);
	printf("Using merge_sort:\n");
	merge_sort(floatArr2,0,size-1);
	printArray(floatArr2,size);
	printf("Using qsort:\n");
	quickSort(floatArr3,0,size-1);
	printArray(floatArr3,size);
	printf("Using select_sort:\n");
	select_sort(floatArr4,0,size-1);//大到小
	printArray(floatArr4,size);
    

    
    
    return 0;
}