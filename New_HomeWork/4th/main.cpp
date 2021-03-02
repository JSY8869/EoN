#include <iostream>

using namespace std;
int a[6] = { 6,5,4,3,2,1 };
void swap(int& a, int& b){

	int temp = a;
	a = b;
	b = temp;
}
void sort1(int b[]){

	for (int i = 0; i < 6; i++){

		for (int j = 0; j < 6 - i - 1; j++){

			if (b[j] > b[j + 1]){

				swap(b[j], b[j + 1]);
			}
		}
	}
}
int main(){
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	sort1(a);
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}