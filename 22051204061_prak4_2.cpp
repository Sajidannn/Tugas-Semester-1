#include <iostream>
#define n 5 //jumlah praktikum
#define h 4 //jumlah mahasiswa
using namespace std;

int main()
{
	int rerata[h], nilaiPraktikum[n];
	int no, total, i, j;
	string nama[h], praktikum[n] = { "Praktikum 1 Pengenalan Program C++", "Praktikum 2 Kondisional", "Praktikum 3 Perulangan", "UTS", "Praktikum 4 Array" };

	cout << "========== DAFTAR NILAI Pemrograman Dasar TI B 2022 ============\n";
	for (j = 0; j < h; j++)
	{
		cout << "\nMasukkan nama mahasiswa ke " << j + 1 << ": ";
		cin >> nama[j];
		total = 0;
		cout << "Masukkan " << n << " nilai mahasiswa\n";
		for (i = 0; i < n; i++)
		{
			cout << praktikum[i] << " :";
			cin >> nilaiPraktikum[i];
			total = total + nilaiPraktikum[i];
		}
		rerata[j] = total / n;
		cout << "Nilai rata-rata " << nama[j] << " adalah : " << rerata[j] << endl;
		cout << "==============================================================\n";
	}
	cout << "\nMahasiswa yang lulus mata kuliah Pemrograman Dasar adalah  :\n"; no = 0;
	for (i = 0; i < n; i++)
	{
		if (rerata[i] >= 60) {
			no++;
			cout << no << ". " << nama[i] << " dengan nilai " << rerata[i] << endl;
		}
	}
	cout << "\nMahasiswa yang gagal mata kuliah Pemrograman Dasar adalah  :\n"; no = 0;
	for (i = 0; i < n; i++)
	{
		if (rerata[i] < 60) {
			no++;
			cout << no << ". " << nama[i] << " dengan nilai " << rerata[i] << endl;
		}
	}
	cout << "================== PROGRAM SELESAI ====================" << endl;
}
