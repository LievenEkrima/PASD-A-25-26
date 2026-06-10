#include <iostream>
#include <cmath>
using namespace std;

// Konstanta gravitasi
const double g = 9.8; // m/s^2

int main() {
    int pilihan39;
    double v039, sudut39;
    double sudut_rad39;

    cout << "=====================================" << endl;
    cout << "  PROGRAM GERAK 2 DIMENSI (PARABOLA) " << endl;
    cout << "  NIM : 4525210039" << endl;
    cout << "=====================================" << endl;

    // Input utama
    cout << "Masukkan kecepatan awal v0 (m/s)    : ";
    cin >> v039;
    cout << "Masukkan sudut lempar (derajat)     : ";
    cin >> sudut39;

    // Konversi sudut ke radian
    sudut_rad39 = sudut39 * M_PI / 180.0;

    cout << endl;
    cout << "Pilih yang ingin dihitung:" << endl;
    cout << "1. Kecepatan awal arah X dan arah Y" << endl;
    cout << "2. Tinggi maksimum benda" << endl;
    cout << "3. Jarak maksimum benda" << endl;
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> pilihan39;
    cout << endl;

    if (pilihan39 == 1) {
        // Menghitung komponen kecepatan awal
        double v0x39, v0y39;

        v0x39 = v039 * cos(sudut_rad39);
        v0y39 = v039 * sin(sudut_rad39);

        cout << "=====================================" << endl;
        cout << "Hasil Perhitungan:" << endl;
        cout << "Kecepatan awal arah X (v0x) = " << v0x39 << " m/s" << endl;
        cout << "Kecepatan awal arah Y (v0y) = " << v0y39 << " m/s" << endl;
        cout << "=====================================" << endl;

    } else if (pilihan39 == 2) {
        // Menghitung tinggi maksimum
        double hmax39, v0y39;

        v0y39 = v039 * sin(sudut_rad39);

        // h_max = (v0y)^2 / (2 * g)
        hmax39 = (v0y39 * v0y39) / (2.0 * g);

        cout << "=====================================" << endl;
        cout << "Hasil Perhitungan:" << endl;
        cout << "Tinggi Maksimum (h_max) = " << hmax39 << " m" << endl;
        cout << "=====================================" << endl;

    } else if (pilihan39 == 3) {
        // Menghitung jarak maksimum (jangkauan)
        double Rmax39;

        // R = (v0^2 * sin(2*sudut)) / g
        Rmax39 = (v039 * v039 * sin(2.0 * sudut_rad39)) / g;

        cout << "=====================================" << endl;
        cout << "Hasil Perhitungan:" << endl;
        cout << "Jarak Maksimum (R) = " << Rmax39 << " m" << endl;
        cout << "=====================================" << endl;

    } else {
        cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}