#ifndef SORT_TOOL_H
#define SORT_TOOL_H
#include <stdio.h>
#include <stdbool.h>
#define swap(a,b)_Generic((a),int*:swap_i,\
							  double*:swap_d,\
							  float*:swap_f\
							  )(a,b)
							  
#define printArray(a,b)_Generic((a),int*:printArray_i,\
									double*:printArray_d,\
									float*:printArray_f\
									)(a,b)
									
#define get_max(a,b)_Generic((a),int*:get_max_i,\
								 double*:get_max_d,\
								 float*:get_max_f\
								 )(a,b)	
								 
#define get_min(a,b)_Generic((a),int*:get_min_i,\
								 double*:get_min_d,\
								 float*:get_min_f\
								 )(a,b)	
								 
#define have_negative_number(a,b)_Generic((a),int*:have_negative_number_i,\
								 double*:have_negative_number_d,\
								 float*:have_negative_number_f\
								 )(a,b)

#define have_postive_number(a,b)_Generic((a),int*:have_postive_number_i,\
								 double*:have_postive_number_d,\
								 float*:have_postive_number_f\
								 )(a,b)								 
								 								 															  
void swap_i(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void swap_d(double *a,double *b){
	double temp=*a;
	*a=*b;
	*b=temp;
}

void swap_f(float *a,float *b){
	float temp=*a;
	*a=*b;
	*b=temp;
}

void printArray_i(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printArray_d(double *arr,int size){
	for(int i=0;i<size;i++){
		printf("%lf ",arr[i]);
	}
	printf("\n");
}

void printArray_f(float *arr,int size){
	for(int i=0;i<size;i++){
		printf("%f ",arr[i]);
	}
	printf("\n");
}

int get_max_i(int *arr,int size){
	int max_value=arr[0];	
	for(int i=1;i<size;i++){
		if(arr[i]>max_value){
			max_value=arr[i];
		}
	}
	return max_value;
}

int get_max_d(double *arr,int size){
	double max_value=arr[0];	
	for(int i=1;i<size;i++){
		if(arr[i]>max_value){
			max_value=arr[i];
		}
	}
	return max_value;
}

int get_max_f(float *arr,int size){
	float max_value=arr[0];	
	for(int i=1;i<size;i++){
		if(arr[i]>max_value){
			max_value=arr[i];
		}
	}
	return max_value;
}

int get_min_i(int *arr,int size){
	int min_value=arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]<min_value){
			min_value=arr[i];
		}
	}
	return min_value;
}

int get_min_d(double *arr,int size){
	double min_value=arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]<min_value){
			min_value=arr[i];
		}
	}
	return min_value;
}

int get_min_f(float *arr,int size){
	float min_value=arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]<min_value){
			min_value=arr[i];
		}
	}
	return min_value;
}

bool have_negative_number_i(int *arr,int size){
	for(int i=0;i<size;i++){
		if(arr[i]<0){
			return true;
		}
	}
}

bool have_negative_number_d(double *arr,int size){
	for(int i=0;i<size;i++){
		if(arr[i]<0){
			return true;
		}
	}
}

bool have_negative_number_f(float *arr,int size){
	for(int i=0;i<size;i++){
		if(arr[i]<0){
			return true;
		}
	}
}

bool have_postive_number_i(int *arr,int size){
	for(int i=0;i<size;i++){
		if(arr[i]>0){
			return false;
		}
	}
}	

bool have_postive_number_d(double *arr,int size){
	for(int i=0;i<size;i++){
		if(arr[i]>0){
			return false;
		}
	}
}

bool have_postive_number_f(float *arr,int size){
	for(int i=0;i<size;i++){
		if(arr[i]>0){
			return false;
		}
	}
}

#endif