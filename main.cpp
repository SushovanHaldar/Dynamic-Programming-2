#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	return (a>b)?a:b;
}

// length k from 0
bool isPalindrome(char *str, int start, int end) {
	if (end-start < 1)
		return true;
	int k = end - start + 1;

	int loop = 0;

	while(loop <= k/2) {
		if (str[end - loop] != str[start + loop])
			return false;
		loop++;
	}

	return true;
}

// cut(i) is the min cut until i
int minCut(char *str) {
	int n = strlen(str);

	int *cut = (int*)malloc(n * sizeof(int));
	
	for (int i = 0;i < n;i++) cut [i] = 0;

	for (int i = 1; i < n; i++) {
		if (isPalindrome(str,0,i)) {
			cut[i] = 0;
		}
		else {
			int interCut = INT_MAX;
			bool hasPalindrome = false;
			for (int j = 0; j < i; j++) {
				/*if (i ==11)  {
					printf("%d",i);
				}*/
				if (isPalindrome(str,j,i)) {
					if (cut[j-1] < interCut)
						interCut = cut[j-1];

					hasPalindrome = true;
					cut[i] = interCut  + 1;
				}
			}
			if (!hasPalindrome) cut[i] = cut[i-1] + 1;
		}

	}
	/*for (int i = 0; i < n; i ++)
		printf("%d: %d\n",i,cut[i]);
*/
	return cut[n-1];
}

void main() {
	bool checkPalindrome = isPalindrome("ababbbabba",0,9);
	//printf(checkPalindrome ? "true\n" : "false\n");
	
	//int cut = minCut("ababbbabbababa");
	int cut = minCut("aab");
	printf("%d\n", cut);
}