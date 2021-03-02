#include <iostream>
using namespace std;
int main()
{
	int iValue1;
	cout << "첫번째 숫자 입력 : ";
	cin >> iValue1;
	if (iValue1 % 2 == 0) {
		printf("짝수");
	}
	else
	{
		printf("홀수");
	}
	return 0;
}