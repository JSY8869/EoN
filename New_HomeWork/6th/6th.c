#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void pizza(int a[], int n) {
	for (int i = 0; i < n + 1; i++) {
		a[i] = i;
	}
	for (int j = 3; j < n + 1; j++) {
		a[j] = a[j - 1] + a[j - 2];
	}
	printf("%d", a[n]);
}

int main() {
	int* p;
	int num;
	printf("정수를 입력하세요: ");
	scanf("%d", &num);
	p = (int*)calloc(num+1, sizeof(int));
	pizza(p, num);
	free(p);
}
