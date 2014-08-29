/*
Let say minJump[i] = minimum number of Jumps from i to n-1

Array:  1	3	5	8	9	2	6	7	6	8	9
Jump:	3	2	2	1	1	2	1	1	1	1	0

return 3
*/
#include <stdlib.h>
#include <stdio.h>

#define N	11

int findMinJump(int arr[N]) {
	int *jump = (int*) malloc(sizeof(int) * N);

	jump[N-1] = 0;

	
	for (int i = N-2; i >= 0; i--) {
		jump[i] = INT_MAX;
		for (int j = N-1; j >= i;j --) {
			if (arr[i] + i >= j) {
				int tmpJump = jump[j] + 1;
				if (tmpJump < jump[i]) {
					jump[i] = tmpJump;
					break; // break loop j
				}
			}
		}
	}
	return jump[0];
}

void main() {
	int arr[N] = {1,3,5,8,9,2,6,7,6,8,9};

	int minJump = findMinJump(arr);

	printf ("%d\n", minJump);
}