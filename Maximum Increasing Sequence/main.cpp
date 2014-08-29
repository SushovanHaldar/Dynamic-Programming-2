#include <stdio.h>
#include <stdlib.h>

/*
*
* Longest Sum Increasing Sequence: Recursive 
* n: number of int start from 0
* limit: only + when arr[i] < limit
*/

#define N 7

int max(int a, int b) {
	return (a>b)?a:b;
}

// https://e2718281828459045.wordpress.com/category/dynamic-programming/

// n elements but index of nth is (n-1)

int recurisveLISHelper(int arr[], int n, int limit) {
	if (n == 0) return 0;

	if (n == 1) 
		if (arr[n-1] < limit) return arr[n-1];
		else return 0;

		if (arr[n-1] < limit) return arr[n-1] + recurisveLISHelper(arr,n-1,limit);
		else return recurisveLISHelper(arr,n-1,limit);
}

// n elements but index of nth is (n-1)

int recursiveLIS(int arr[], int n) { 
	// no elements
	if (n == 0) return 0; 

	if (n == 1) return arr[n-1];


	int maxLIS = INT_MIN;
	int currentMax = INT_MIN;
	
	for (int i = n-1; i >= 0; i--) {
		currentMax = arr[i] + recurisveLISHelper(arr,i,arr[i]); 
		if (maxLIS < currentMax) maxLIS = currentMax;
	}
	
	return maxLIS;

}


void main () {
	//int arr[] = {1,101,2,3,100,4,5};

	int arr[] = {10,5,4};

	int result = recursiveLIS(arr,N);

	printf("%d\n",result);
}