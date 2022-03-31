#include <string.h>
#include <stdio.h>
#include<stdlib.h>


int main() {

	char a[20];
	char b[20];

	scanf_s("%s %s", a, b);
	int anum = strtol(a, NULL, 16);
	int bnum = strtol(b, NULL, 2);

	int res1 = -(anum & bnum) << 4;
	int res2 = (anum ^ 0xCD) & (bnum >> 3);
	printf("%d %d\n", res1, res2);
	return 0;
}
