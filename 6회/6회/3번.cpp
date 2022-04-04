#include<stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int cnt = 0;
	while (N) {
		if (N & 1)cnt++;
		N >>= 1;
	}

	printf("%d", cnt);
	return 0;
}