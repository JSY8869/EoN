#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int numarr[],int arr[], int count, int a, int b, int c,int d){    // �Ű������� ������ �迭�� ����� ������ ����
    
    for (int z = 0; z < d; z++){
        arr[z] = numarr[a-1];
        a++;
        //printf("%d", arr[z]);
    }
    int temp;

    for (int w = 0; w < count; w++)    // ����� ������ŭ �ݺ�
    {
        for (int r = 0; r < count - 1; r++)   // ����� ���� - 1��ŭ �ݺ�
        {
            if (arr[r] > arr[r + 1])          // ���� ����� ���� ���� ����� ���� ���Ͽ�
            {                                 // ū ����
                temp = arr[r];
                arr[r] = arr[r + 1];
                arr[r + 1] = temp;            // ���� ��ҷ� ����
            }
        }
    }//���� �Ϸ�
    printf("%d", arr[c-1]);
    printf("\n");
}
int comd(int numarr[]) {
    printf("i�� �Է��ϼ���: ");
    scanf("%d", &numarr[0]);
    return numarr[0];
}
int comd2(int numarr[]) {
    printf("j�� �Է��ϼ���: ");
    scanf("%d", &numarr[1]);
    return numarr[1];
}
int comd3(int numarr[]) {
    printf("k�� �Է��ϼ���: ");
    scanf("%d", &numarr[2]);
    return numarr[2];
}

int main() {
    int i, j, k,v;
    int* p;
	int array1[7] = { 1,5,2,6,3,7,4 };
	int commands[3];
    for (int m = 0; m < 1000; m++){
        i = comd(commands);
        j = comd2(commands);
        k = comd3(commands);
        v = j - i;
        p = (int*)calloc(v + 1, sizeof(int));
        bubble_sort(array1, p, v + 1, i, j, k, v + 1);
        free(p);
        if (m >= 2){
            break;
        }
    }

}