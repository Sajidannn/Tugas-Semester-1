#include <iostream>
using namespace std;

int main() {
    int i, nilai, nilai1, banyak_nilai, max, min;
    double jumlah_nilai, mean;
	
	cout << "Ingin memasukkan berapa nilai(1-10):" << endl;
	cin >> banyak_nilai;
    cout << "masukkan nilai pertama" << endl;
    cin >> nilai;
    nilai1 = nilai;
    max = nilai;
    min = nilai;
    jumlah_nilai = 0;
    for (i = 1; i <banyak_nilai; i++) {
        cout << "masukkan nilai ke " << i+1 << endl;
        cin >> nilai;
        if (nilai > max) {
            max = nilai;
        }
        else if (nilai < min) {
                min = nilai;
        }
        jumlah_nilai = jumlah_nilai + nilai;
    }
    mean = (jumlah_nilai + nilai1) / i;
    cout << "Reratanya adalah: " << mean << endl;
    cout << "Nilai terendah adalah: " << min << endl;
    cout << "Nilai tertinggi adalah: "<< max << endl;
}
