#include <iostream>
using namespace std;

int main()
{
	int JamMasuk, JamKeluar, LamaKerja, ketwaktu;

	cout << "=========================================== PT. Mencari Cinta Sejati ============================================" << endl;
	cout << "Masukkan jam masuk kantor anda (angka 1-12): "; //jam buka kantor adalah jam 7 pagi
	cin >> JamMasuk;
	cout << "Pilih: \n 1. am\n 2. pm" << endl; //memasukkan keterangan waktu tersebut am(12 malam - 11 siang)/pm(12 siang - 11 malam)
	cin >> ketwaktu;

	if (ketwaktu == 1) { //1=am //jika jam masuk kurang dari 7am maka masih belum bisa masuk.
		if (JamMasuk < 7 || JamMasuk == 12) {
			cout << "Jam masuk terlalu awal. Tunggu beberapa jam lagi!!\n";
		}
		else {
			cout << "*****Anda masuk kantor pada jam " << JamMasuk << "am*****" << endl;
			cout << "Masukkan jam keluar kantor anda (angka 1-12): "; //jam tutup kntor adalah jam 8 malam
			cin >> JamKeluar;
			cout << "Pilih: \n 1. am\n 2. pm" << endl;
			cin >> ketwaktu;
			if (ketwaktu == 1) { //karena ket.waktu adalah am (12 malam - 11 siang) maka langsung dilakukan operasi berikut
				if (JamKeluar > JamMasuk) //agar hasil tidak negatf
				{
					LamaKerja = JamKeluar - JamMasuk;
					cout << "*****Anda keluar kantor pada jam " << JamKeluar << "am*****" << "\n*****Lama anda bekerja adalah " << LamaKerja << " jam*****" << endl;
				}
				else //jika jam keluar masih am dan jam keluar < jam masuk maka keluaran invalid
				{
					cout << "Jam keluar invalid.\n";
				}
			}
			else //jika masukan jam keluar !=1 maka menunjukkan pm dan dilakukan operasi berikut
			{
				if (JamKeluar == 12)
				{
					LamaKerja = 12 - JamMasuk;
					cout << "*****Anda keluar kantor pada jam " << JamKeluar << "pm*****" << "\n*****Lama anda bekerja adalah " << LamaKerja << " jam*****" << endl;
				}
				else if (JamKeluar >= 1 && JamKeluar <= 6)//mengubah jam 1-6 pm menjadi metode biasa dengan ditambah 12 
				{
					LamaKerja = JamKeluar + 12 - JamMasuk;
					cout << "*****Anda keluar kantor pada jam " << JamKeluar << "pm*****" << "\n*****Lama anda bekerja adalah " << LamaKerja << " jam*****" << endl;
				}
				else if (JamKeluar == 7)
				{
					LamaKerja = JamKeluar + 12 - JamMasuk;
					if (LamaKerja > 11)//jika sudah jam 7pm dan jam kerja sudah 12 jam masih bisa mencetak tetapi diberi peringatan
					{
						cout << "*****Anda keluar kantor pada jam " << JamKeluar << "pm" << " dan lama anda bekerja adalah " << LamaKerja << " jam.\nANDA BEKERJA TERLALU LAMA, KURANGI WAKTU KERJA ANDA ESOK HARI!!*****" << endl;
					}
					else
					{
						cout << "*****Anda keluar kantor pada jam " << JamKeluar << "pm" << " dan lama anda bekerja adalah " << LamaKerja << " jam." << endl;
					}
				}
				else
				{
					//jika jam kerja sudah 12 jam+ / lewat jam 8 malam maka tidak bisa mencetak lama kerja 
					cout << "ANDA SUDAH TERLALU LAMA MELEWATI BATAS WAKTU JAM KELUAR KANTOR. ANDA TIDAK BISA MELAKUKAN ABSEN KELUAR KANTOR HARI INI." << endl;
				}
			}
		}
	}
	else
	{	//apabila jam masuk lebih dari 11 siang atau sudah jam 12pm maka karyawan dianggap telat dan tidak bisa absen masuk
		cout << "WAKTU SUDAH PUKUL " << JamMasuk << "pm ANDA TELAT MASUK KANTOR!!\n";
	}
	cout << "=========================================== PT. Mencari Cinta Sejati ============================================\n\n";
}