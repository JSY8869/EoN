#include <iostream>
using namespace std;
void pizza(int a[], int n) {
    for (int i = 0; i < n + 1; i++) {
        a[i] = i;
    }
    for (int j = 3; j < n + 1; j++) {
        a[j] = a[j - 1] + a[j - 2];
    }
    cout << a[n];
}

int main()
{
    int num;
    cout << "정수를 입력하세요: ";
    cin >> num;
    int* p;
    p = new int[num+1];
    pizza(p,num);
    delete[]p;

}