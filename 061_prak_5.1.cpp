#include <iostream>
#define n 5
using namespace std;

int main() {

	char kode[n][4] = { "SBN", "ODL", "SKT","SMP", "MYK" };
	string code;
	char barang[n][15] = { "Sabun Mandi","Odol", "Sikat Gigi", "Shampo", "Minyak Goreng" };
	int harga[n] = { 3500,2500,3000,2000,7000 };
	bool checked = false;

	cout << "Masukkan kode barang: ";
	cin >> code;
	for (int i = 0; i < n; i++)
	{
		if (code == kode[i])
		{
			checked = true;
			cout << barang[i] << " seharga " << "Rp" << harga[i] << endl;
		}
	}
	if (checked == false)
	{
		cout << "Kode tidak valdi!" << endl;
	}
}