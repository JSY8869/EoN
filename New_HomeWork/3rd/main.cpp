#include <iostream>
using namespace std;
void sumall(int a[]) {
    int sum = 0;
    cout << "입력한 정수의 합>> ";
    for (int i = 0; i < 6; i++)
    {
        sum += a[i];
    }
    cout << sum << endl;
}

int main()
{

    int* p;
    p = new int[6];     
                                  
    for (int i = 0; i < 6; i++)
    {
        cout << "정수 입력: ";
        cin >> p[i];
    }
    sumall(p);
    delete[]p;         
                             
}