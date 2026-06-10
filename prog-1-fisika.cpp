#include <iostream>
using namespace std;

int main() {
    int pilihan;
    const int NIM = 39;

    cout << "PROGRAM GERAK 1 DIMENSI\n";
    cout << "1. Menghitung Waktu Tempuh\n";
    cout << "2. Menghitung Kecepatan Awal\n";
    cout << "3. Menghitung Percepatan\n";
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: {
            double v0, a, vt, t;

            cout << "Masukkan kecepatan awal (v0): ";
            cin >> v0;
            cout << "Masukkan percepatan (a): ";
            cin >> a;
            cout << "Masukkan kecepatan akhir (vt): ";
            cin >> vt;

            // Tambah 39 pada setiap variabel
            v0 += NIM;
            a += NIM;
            vt += NIM;

            t = (vt - v0) / a;

            cout << "\nWaktu tempuh = " << t << " detik" << endl;
            break;
        }

        case 2: {
            double vt, a, t, v0;

            cout << "Masukkan kecepatan akhir (vt): ";
            cin >> vt;
            cout << "Masukkan percepatan (a): ";
            cin >> a;
            cout << "Masukkan waktu tempuh (t): ";
            cin >> t;

            // Tambah 39 pada setiap variabel
            vt += NIM;
            a += NIM;
            t += NIM;

            v0 = vt - (a * t);

            cout << "\nKecepatan awal = " << v0 << " m/s" << endl;
            break;
        }

        case 3: {
            double v0, t, vt, a;

            cout << "Masukkan kecepatan awal (v0): ";
            cin >> v0;
            cout << "Masukkan waktu tempuh (t): ";
            cin >> t;
            cout << "Masukkan kecepatan akhir (vt): ";
            cin >> vt;

            // Tambah 39 pada setiap variabel
            v0 += NIM;
            t += NIM;
            vt += NIM;

            a = (vt - v0) / t;

            cout << "\nPercepatan = " << a << " m/s^2" << endl;
            break;
        }

        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}