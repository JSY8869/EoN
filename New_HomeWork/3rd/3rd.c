/*3�� ���� ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sum(int a[],int b) {
	int total = 0;
	for (int i = 0; i < b; i++){
		printf("�迭�� �� ���� ������ �Է��ϼ���");
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < b; i++){
		total = total + a[i];
	}
	printf("%d",total);
}

int main() {
	int* p;
	int s = 6;
	p = (int*)calloc(s, sizeof(int));
	sum(p,s);
	free(p);
}