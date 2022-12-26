#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool LoginFunction(string, string, bool&, int&);
int getOption(string nama) {
    int input;
    system("cls");
    cout << "================= Program Karyawam PT. Maju Mundur =================" << endl;
    cout << "Selamat datang " << nama << endl;
    cout << "Pilih tindakan selanjutnya" << endl;
    cout << "1. Absen harian" << endl;
    cout << "2. Cek gaji bulanan" << endl;
    cout << "3. Cek data diri" << endl;
    cout << "4. Keluar dari program" << endl;
    cout << "====================================================================" << endl;
    cout << "Masukkan 1 - 4 : ";
    cin >> input;
    return input;
}
void absen(string, int&);
void cekgaji(string, int&);
void DataDiri(string);
void hitungGaji(string, string, int, int);
void cetakSlip(string, int, int, int, int, int);

int main()
{
    bool success = false;
    int fail = 5, option, absenToday = 0;
    char is_continue;
    string username, userpass, namafile, nama;

    while (!success && fail >= 0)
    {
        cout << "Masukkan username anda : ";
        cin >> username;
        cout << "Masukkan password anda: ";
        cin >> userpass;
        LoginFunction(username, userpass, success, fail);
    }
    if (success) {

        string Bulan[] = { "januari", "februari", "maret", "april", "mei", "juni", "juli", "agustus", "september", "oktober", "november", "desember" };
        int i;
        cout << "LOGIN BERHASIL!" << endl;
        insertBulan:
        cout << "1. Januari\n2. Februari\n3. Maret\n4. April\n5. Mei\n6. Juni\n7. Juli\n8. Agustus\n9. September\n10. Oktober\n11. November\n12. Desember" << endl;
        cout << "Pilih bulan yang akan dioperasikan(1-12) : ";
        cin >> i;
        if (i > 0 && i <= 12)
        {
            namafile = username + Bulan[i - 1] + ".txt";
            ifstream Signed(namafile);
            if (Signed.is_open())
            {
                getline(Signed, nama);
            }
            else
            {
                system("cls");
                cout << "Data bulan yang dipilih belum ada, pilih bulan lain" << endl;
                goto insertBulan;
            }
            Signed.close();
        }
        else
        {
            system("cls");
            goto insertBulan;
        }

        option = getOption(nama);

        while (option != 4)
        {
            switch (option)
            {
            case 1:
                cout << "=========================== Absen harian ===========================" << endl;
                absen(namafile, absenToday);
                break;
            case 2:
                cout << "========================= Cek gaji bulanan =========================" << endl;
                cekgaji(namafile, absenToday);
                break;
            case 3:
                cout << "======================= Cek data diri pegawai =======================" << endl;
                DataDiri(namafile);
                break;
            default:
                cout << "Pilihan tidak ditemukan" << endl;
                break;
            }
        label_continue:

            cout << "Lanjutkan?(y/n) : ";
            cin >> is_continue;
            if (is_continue == 'y' || is_continue == 'Y') {
                option = getOption(nama);
            }
            else if (is_continue == 'n' || is_continue == 'N') {
                break;
            }
            else {
                goto label_continue;
            }
        }

        cout << "Program selesai" << endl;
    }
    else {
        cout << "LOGIN DITOLAK!" << endl;
    }

    return 0;
}

bool LoginFunction(string username, string userpass, bool& success, int& fail) {
    string adminname, adminpass, line;
    ifstream readfile("login.txt");

    while (getline(readfile, line)) {
        stringstream iss(line);
        iss >> adminname >> adminpass;

        if (username == adminname && userpass == adminpass) {

            success = true;
        }
    }
    if (!success) {
        system("cls");
        cout << "Username / Password salah, masukkan kembali.\n";
        cout << fail << " kesempatan tersisa.\n";
        fail--;
    }
    return success;
}

void absen(string namafile, int& absenToday) {
    int banyak = 0, JamMasuk, JamKeluar, JamPokok = 0, JamLembur = 0, LamaKerja, ketwaktu;
    string buffer, isdata;

    ifstream absen(namafile);
    while (getline(absen, isdata))
    {
        if (isdata == "A" || isdata == "B" || isdata == "C")
        {
            break;
        }
    }
    while (!absen.eof()) 
    {
        banyak++;
        getline(absen, buffer);
    }
    absen.close();
    if (banyak < 23 && absenToday == 0)
    {
        cout << "Masukkan jam masuk kantor anda (angka 1-12): ";
        cin >> JamMasuk;
        cout << "Pilih: \n 1. am\n 2. pm" << endl;
        cin >> ketwaktu;
        if (ketwaktu == 1) {
            if (JamMasuk < 8 || JamMasuk == 12) {
                cout << "Jam masuk terlalu awal. Tunggu beberapa jam lagi!!\n";
            }
            else {
                cout << "Masukkan jam keluar kantor anda (angka 1-12): ";
                cin >> JamKeluar;
                cout << "Pilih: \n 1. am\n 2. pm" << endl;
                cin >> ketwaktu;
                if (ketwaktu == 1) {
                    if (JamKeluar > JamMasuk)
                    {
                        JamPokok = JamKeluar - JamMasuk;
                        cout << "Lama anda bekerja adalah " << JamPokok << " jam" << endl;
                    }
                    else
                    {
                        cout << "Jam keluar invalid.\n";
                    }
                }
                else {
                    if (JamKeluar == 12)
                    {
                        JamPokok = 12 - JamMasuk;
                        cout << "Lama anda bekerja adalah " << JamPokok << " jam" << endl;
                    }
                    else if (JamKeluar >= 1 && JamKeluar <= 8)
                    {
                        LamaKerja = JamKeluar + 12 - JamMasuk;
                        if (LamaKerja > 8)
                        {
                            JamPokok = 8;
                            cout << "Lama anda bekerja adalah " << JamPokok << " jam" << endl;
                            JamLembur = LamaKerja - 8;
                            cout << "Lama anda lembur adalah " << JamLembur << " jam" << endl;
                        }
                        else
                        {
                            JamPokok = LamaKerja;
                            cout << "Lama anda bekerja adalah " << JamPokok << " jam" << endl;
                        }
                    }
                    else
                    {
                        cout << "BATAS WAKTU ABSEN HARI INI TERLAMPAUI. ANDA TIDAK BISA ABSEN HARI INI";
                        absenToday++;
                    }
                }
            }
        }
        else
        {
            absenToday++;
            cout << "WAKTU SUDAH PUKUL " << JamMasuk << "pm ANDA TELAT MASUK KANTOR!!\n";
            ofstream jam(namafile, ios::app);
            jam << "\n" << JamPokok;
            jam << " " << JamLembur;
            jam.close();
        }
        if (JamPokok != 0)
        {
            absenToday++;
            ofstream jam(namafile, ios::app);
            jam << "\n" << JamPokok;
            jam << " " << JamLembur;
            jam.close();
            cout << "Anda sudah melakukan absen sebanyak " << ++banyak << " kali bulan ini." << endl;
        }
    }
    else if (absenToday != 0)
    {
        cout << "Hari ini anda sudah absen, lakukan absen lagi esok hari." << endl;
    }
    else
    {
        cout << "Tidak bisa melakukan absen lagi, jumlah absen anda bulan ini sudah penuh." << endl;
        cout << "Anda sudah melakukan absen sebanyak " << banyak << " kali bulan ini." << endl;
    }
    cout << "=====================================================================" << endl;
}

void cekgaji(string namafile, int& absenToday) {
    string buffer, golongan;
    int pokok, lembur, numPokok = 0, numLembur = 0, jam = 0, banyak = 0;

    ifstream cekgaji(namafile);
    while (getline(cekgaji, golongan)) {
        if (golongan == "A" || golongan == "B" || golongan == "C")
        {
            break;
        }
    }
    while (getline(cekgaji, buffer)) {
        stringstream iss(buffer);
        iss >> pokok >> lembur;
        numPokok += pokok;
        numLembur += lembur;
        banyak++;
    }
    cekgaji.close();

    if (banyak < 21)
    {
        char cond;
        cout << "Jumlah kehadiranmu masih dibawah 21 hari dan belum bisa melakukan cek gaji" << endl;
        cout << "Ingin melakukan absensi untuk hari ini? (y/n) : ";
        cin >> cond;
        if (cond == 'y' || cond == 'Y')
        {
            cout << "=========================== Absen harian ===========================" << endl;
            absen(namafile, absenToday);
        }
    }
    else
    {
        hitungGaji(golongan, namafile, numPokok, numLembur);
    }
}

void DataDiri(string namafile) {
    string nama, jabatan, NIK, email, telp, golongan;

    ifstream ins(namafile);
    getline(ins, nama);
    getline(ins, jabatan);
    getline(ins, NIK);
    getline(ins, email);
    getline(ins, telp);
    getline(ins, golongan);
    ins.close();

    cout << "Pegawai atas nama " << nama << endl;
    cout << "Dengan jabatan sebagai " << jabatan << endl;
    cout << "Golongan       : " << golongan << endl;
    cout << "No. Induk      : " << NIK << endl;
    cout << "Alamat e-mail  : " << email << endl;
    cout << "No. Telepon    : " << telp << endl;
    cout << "=====================================================================" << endl;

}

void hitungGaji(string golongan, string namafile, int pokok, int lembur) {
    int gaji[2][3] = { 28800, 30000, 32000, 39000, 40000, 41500 }, gajipokok, gajilembur, total;
    string Golongan[3] = { "C", "B", "A" };

    for (int i = 0; i < 3; i++)
    {
        if (golongan == Golongan[i])
        {
            gajipokok = pokok * gaji[0][i];
            gajilembur = lembur * gaji[1][i];
            total = gajipokok + gajilembur;
            cout << "Gaji anda bulan ini adalah Rp." << total << " dengan rincian : " << endl;
            cout << "Rp." << gajipokok << " gaji pokok" << endl;
            cout << "Rp." << gajilembur << " gaji lembur" << endl;
        }
    }
    char cond;
    cout << "Ingin mencetak slip gaji?(y/n) : ";
    cin >> cond;
    cout << "=====================================================================" << endl;
    if (cond == 'y' || cond == 'Y')
    {
        cetakSlip(namafile, pokok, lembur, gajipokok, gajilembur, total);
    }
}

void cetakSlip(string namafile, int pokok, int lembur, int gajipokok, int gajilembur, int total) {
    string nama, golongan, NIK, filename, jabatan, email, telp;

    ifstream ins(namafile);
    getline(ins, nama);
    getline(ins, jabatan);
    getline(ins, NIK);
    getline(ins, email);
    getline(ins, telp);
    getline(ins, golongan);
    ins.close();
    filename = "slip" + nama + ".txt";

    ofstream outs(filename);
    outs << "============== Slip Gaji PT. Maju Mundur ==============" << endl;
    outs << "Nama       : " << nama << "\n";
    outs << "Golongan   : " << golongan << "\n";
    outs << "Jabatan    : " << jabatan << "\n";
    outs << "No. Induk  : " << NIK << "\n";
    outs << "E-mail     : " << email << "\n";
    outs << "No. Telpon : " << telp << "\n";
    outs << "======================= Rincian =======================" << endl;
    outs << "Total jam kerja    : " << pokok << " jam\n";
    outs << "Total jam lembur   : " << lembur << " jam\n";
    outs << "Gaji pokok         : Rp." << gajipokok << endl;
    outs << "Gaji lembur        : Rp." << gajilembur << endl;
    outs << "Gaji total         : Rp." << total << endl;
    outs << "=======================================================";
    outs.close();
    cout << "Slip gaji sudah dicetak" << endl;
    cout << "=====================================================================" << endl;
}