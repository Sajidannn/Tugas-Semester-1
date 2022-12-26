#include <iostream>
using namespace std;

int main()
{
	int jumlah_uang, bulan, waktu;
	float bunga, bunga1;
	cout << "Masukkan jumlah uang yang akan disimpan: "<< endl;
	cin >> jumlah_uang;
	cout << "Setelah berapa bulan uang akan diambil: "<< endl;
	cin >> bulan;
	cout << "Berapa persen bunga setiap bulan : ";
	cin >> bunga;
	bunga1=bunga/100;
	for (waktu = 1; waktu <= bulan; waktu++)
	{
		jumlah_uang = jumlah_uang + jumlah_uang * bunga1;
	}
	cout << "jumlah uang di bulan " << bulan << " adalah " << jumlah_uang << endl;

}
