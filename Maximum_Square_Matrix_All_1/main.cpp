#include <stdlib.h>
#include <stdio.h>

#define N 6
#define M 5

void printArray(int arr[N][M]) ;

void main() {
	int src_arr[N][M] = {
		{0,1,1,0,1},
		{1,1,0,1,0},
		{0,1,1,1,0},
		{1,1,1,1,0},
		{1,1,1,1,1},
		{0,0,0,0,0}
	};

	int max_arr[N][M];
	int max_row = 0;
	int max_column = 0;
	int max_value = 0;

	for (int i = 0; i < N;i++)
		max_arr[i][0] = 0;
		//max_arr[i][0] = src_arr[i][0];

	for (int j = 0; j < M;j++)
		max_arr[0][j] = 0;
		//max_arr[0][j] = src_arr[0][j];

	for (int i = 1; i < N; i++) {
		for (int j = 1 ; j < M; j ++) {
			if (src_arr[i-1][j] && src_arr[i-1][j-1] && src_arr[i][j-1] & src_arr[i][j]) {
				max_arr[i][j] = max_arr[i-1][j-1] + 1;
				if (max_arr[i][j] > max_value) {
					max_value = max_arr[i][j];
					max_row = i;
					max_column = j;
				}
			} else {
				max_arr[i][j] = 0;
			}
		}
	}
	printArray(max_arr);

	printf("Max square 1 matrix is %d, end at row: %d and column: %d \n",max_value, max_row,max_column);


}

void printArray(int arr[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0 ; j < M; j ++) {
			printf("%d  ", arr[i][j]); 
		}
		printf("\n");
	}
}
