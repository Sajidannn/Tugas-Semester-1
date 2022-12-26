//detik 1-10=3m/s  //10*3=30m
//detik 11-20=4m/s //10*4=40m+30m=70m
//detik 21-30=5m/s //10*5=50m+70m=120m
#include<iostream>
using namespace std;

int main() {
	int t = 0, v, v1, s, s1, interval = 1;
	cout << "Masukkan jarak yang harus dicapai(m): " << endl;
	cin >> s;
	cout << "Masukkan kecepatan awal(m/s): " << endl;
	cin >> v;
	v1=v;
	s1 = s;
	while (s > 0) {
		if (t % 10 == 0 && t != 0) {
			v++;
			++interval;
		}
		s -= v;
		t++;
	}
	cout << "Waktu yang diperlukan untuk mencapai jarak " << s1 << "m dengan kecepatan awal " << v1 << "m/s adalah :\n" << t << " detik\n";
	cout << "Dengan kecepatan maksimal " << v << "m/s\n";
	cout << "Dengan kenaikan kecepatan sebanyak " << interval << " kali" << endl;
}
