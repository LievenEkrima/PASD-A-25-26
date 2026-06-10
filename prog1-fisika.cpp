#include <iostream>
using namespace std;

int main() {
    int pilihan39;
    double v039, vt39, a39, t39;

    cout << "=====================================" << endl;
    cout << "   PROGRAM GERAK 1 DIMENSI " << endl;
    cout << "   NIM : 4525210039" << endl; //
    cout << "=====================================" << endl;

    cout << "Pilih perhitungan:" << endl;
    cout << "1. Menghitung waktu tempuh" << endl;
    cout << "2. Menghitung kecepatan awal" << endl;
    cout << "3. Menghitung percepatan" << endl;
    cout << "Masukkan pilihan (1/2/3) : ";
    cin >> pilihan39;

    cout << endl;

    if (pilihan39 == 1) {

        // Menghitung waktu tempuh
        cout << "Masukkan kecepatan awal (v0) : ";
        cin >> v039;

        cout << "Masukkan percepatan (a) : ";
        cin >> a39;

        cout << "Masukkan kecepatan akhir (vt) : ";
        cin >> vt39;

        // Rumus t = (vt - v0) / a
        t39 = (vt39 - v039) / a39;

        cout << endl;
        cout << "=====================================" << endl;
        cout << "Waktu tempuh (t) = " << t39 << " sekon" << endl;
        cout << "=====================================" << endl;

    } else if (pilihan39 == 2) {

        // Menghitung kecepatan awal
        cout << "Masukkan kecepatan akhir (vt) : ";
        cin >> vt39;

        cout << "Masukkan percepatan (a) : ";
        cin >> a39;

        cout << "Masukkan waktu tempuh (t) : ";
        cin >> t39;

        // Rumus v0 = vt - a*t
        v039 = vt39 - (a39 * t39);

        cout << endl;
        cout << "=====================================" << endl;
        cout << "Kecepatan awal (v0) = " << v039 << " m/s" << endl;
        cout << "=====================================" << endl;

    } else if (pilihan39 == 3) {

        // Menghitung percepatan
        cout << "Masukkan kecepatan awal (v0) : ";
        cin >> v039;

        cout << "Masukkan waktu tempuh (t) : ";
        cin >> t39;

        cout << "Masukkan kecepatan akhir (vt) : ";
        cin >> vt39;

        // Rumus a = (vt - v0) / t
        a39 = (vt39 - v039) / t39;

        cout << endl;
        cout << "=====================================" << endl;
        cout << "Percepatan (a) = " << a39 << " m/s^2" << endl;
        cout << "=====================================" << endl;

    } else {

        cout << "Pilihan tidak valid!" << endl;

    }

    return 0;
}