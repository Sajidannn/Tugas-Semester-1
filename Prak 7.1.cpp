#include <fstream>
#include <iostream>

using namespace std;

int main() {
	int sum = 0, num, input;
	float rerata, jml;

	ofstream outs("dataku.dat");
	ifstream ins("dataku.dat");

	cout << "jumlah input angka : ";
	cin >> jml;
	cout << "input angka\n";
	for (int i = 0; i < jml; i++) {
		cin >> input;
		outs << "\n" << input;
	}
	outs.close();

	while (!ins.eof()) {
		ins >> num;
		sum = sum + num;
	}
	cout << "Total : " << sum << endl;
	rerata = sum / jml;
	cout << "reratanya : " << rerata << endl;
	ins.close();

	return 0;
}
