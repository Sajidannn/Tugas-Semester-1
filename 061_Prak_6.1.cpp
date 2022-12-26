#include<iostream>
using namespace std;

int GanjilGenap(int);
int main() {
	int test;
	cout << "Masukkan angka :";
	cin >> test;
	cout << GanjilGenap(test) << endl;
}
int GanjilGenap(int test) {
	int a;
	a = test % 2;
	if (a == 0) {
		cout << "Bilangan tersebut genap\n";
	}
	else {
		cout << "Bilangan tersebut ganjil\n";
	}
	return a;
}