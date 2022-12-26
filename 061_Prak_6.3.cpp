#include <iostream>
#include<string.h>
using namespace std;

int CariJumlahHuruf(char a[]);
int main() {
    char kalimat[100];

    cout << "Input kalimat: ";
    cin.getline(kalimat, 100);
    CariJumlahHuruf(kalimat);
}
//mencari banyak huruf dalam kalimat
int CariJumlahHuruf(char a[]) {
    int JumlahHuruf = 0;
    char CariHuruf;

    cout << "Masukkan huruf yang dicari: ";
    cin >> CariHuruf;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == CariHuruf) {
            JumlahHuruf++;
        }
    }
    if (JumlahHuruf > 0) {
        cout << "Jumlah huruf " << CariHuruf << " dalam kalimat adalah " << JumlahHuruf << endl;
    }
    else {
        cout << "Tidak ada huruf " << CariHuruf << " dalam kalimat " << endl;
    }
    return JumlahHuruf;
}