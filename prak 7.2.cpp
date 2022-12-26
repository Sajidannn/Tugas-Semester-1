#include <fstream>
#include <iostream>
using namespace std;

int main() {

	string kota;
	int bnyk, jumlahKota = 0;

	ofstream outs("namakota.txt", ios::app);
	ifstream ins("namakota.txt");

	cout << "Jumlah kota yang di input : "; cin >> bnyk;
	cout << "Masukkan nama kota : \n";
	for (int i = 0; i < bnyk; i++) {
		cin >> kota;
		outs << "\n" << kota;
	}
	outs.close();

	cout << "\nNama kota di file sekarang :\n";
	while (!ins.eof()) {
		ins >> kota;
		cout << kota << endl;
		jumlahKota++;
	}
	cout << "jumlah kota di file sekarang : " << jumlahKota << endl;
	ins.close();
}