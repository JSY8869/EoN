/*2번 문제 답지*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int num;
	printf("양의 정수를 입력하세요: ");
	scanf("%d",&num);
	if (num % 2 == 0){
		printf("짝수");
	}
	else
	{
		printf("홀수");
	}
}