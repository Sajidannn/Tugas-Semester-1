#include <iostream>
#define m 2 //siswa
#define n 5 //mapel

using namespace std;

int main() {
	int nilai[m][n], total[n];
	char siswa[m][20], mapel[n][20] = { "Biologi", "Kimia", "Matematika", "Fisika", "PKN" };
	float rerata[n];

	for (int i = 0; i < m; i++)//menginput nilai mapel masing" siswa
	{
		cout << "Masukkan Nama Siswa ke" << i + 1 << ": ";
		cin >> siswa[i];
		cout << "Masukkan Nilai Pelajaran \n";
		for (int j = 0; j < n; j++)
		{
			cout << mapel[j] << ": ";
			cin >> nilai[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)//mencari total dan rata"
	{
		
		total[i] = 0;
		for (int j = 0; j < m; j++)
		{
			total[i] = total[i] + nilai[j][i];
		}
		rerata[i] = total[i] / m;
	}
	cout << "============ RAPOR =============\n";
	for (int i = 0; i < m; i++) {
		cout << "Rapor siswa : " << siswa[i] << endl;
		for (int j = 0; j < n; j++)
		{
			cout << mapel[j] << "\t\t: " << nilai[i][j] << "\t\tRata-rata kelas : " << rerata[j] << endl;
		}
		cout << endl;
	}
}
