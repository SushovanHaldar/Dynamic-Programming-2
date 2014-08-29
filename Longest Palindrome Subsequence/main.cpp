#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen

#define N 6

int max(int a, int b) {
	return (a > b) ? a : b;
}

// dynamic programming 
int dpLongestPalindrome(char *str, int start, int end) {
	int len = strlen(str);
	//int **tbl = (int**) malloc(len * sizeof(int)); // tbl[i][j] means start at i and end at j
	
	//int tbl[len][len]; // not a valid deleration


	for (int i = 0; i < len; i++) {
		
	}
	return 0;
}


/*
* start 
*
*/
int longestPalindrome(char *str, int start, int end) {
	
	if (start == end)
		return 1;

	if (start > end)
		return 0;

	if (str[start] == str[end]) {
		return 2 + longestPalindrome(str, start + 1, end -1 );
	}
	else {
		return max ( longestPalindrome(str,start, end-1), 
					 longestPalindrome(str,start+1, end) );
	}
}

void main() {
	char* str = "BBABCBCAB";
	int longest = longestPalindrome(str,0,strlen(str)-1);
	printf("%d\n", longest);


}