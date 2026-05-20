#include <iostream>
#include <iomanip>
using namespace std;

// ===== Struct ===== //
struct Mahasiswa
{
    char nama[50];
    char nim[20];
};

struct MataKuliah
{
    char nama_mk[50];
    int sks;
    char nilai_huruf;
    float nilai_angka;
};

int main()
{
    Mahasiswa mhs;
    MataKuliah mk[50];

    int jumlah_mk;
    int i_ekky;
    float total_sks = 0, total_nilai = 0;
    float ekky; // variabel tambahan (IPK)

    // ===== Input ===== //
    cout << "Jumlah Mata Kuliah : ";
    cin >> jumlah_mk;

    cout << "Nama Mahasiswa     : ";
    cin >> mhs.nama;

    cout << "NIM                : ";
    cin >> mhs.nim;

    cout << endl;

    // ===== Input Mata Kuliah ===== //
    for (i_ekky = 0; i_ekky < jumlah_mk; i_ekky++)
    {
        cout << "Mata Kuliah ke-" << i_ekky + 1 << endl;

        cout << "Nama MK     : ";
        cin >> mk[i_ekky].nama_mk;

        cout << "SKS         : ";
        cin >> mk[i_ekky].sks;

        cout << "Nilai Huruf : ";
        cin >> mk[i_ekky].nilai_huruf;

        // Konversi nilai huruf
        if (mk[i_ekky].nilai_huruf == 'A')
            mk[i_ekky].nilai_angka = 4;
        else if (mk[i_ekky].nilai_huruf == 'B')
            mk[i_ekky].nilai_angka = 3;
        else if (mk[i_ekky].nilai_huruf == 'C')
            mk[i_ekky].nilai_angka = 2;
        else if (mk[i_ekky].nilai_huruf == 'D')
            mk[i_ekky].nilai_angka = 1;
        else
            mk[i_ekky].nilai_angka = 0;

        total_sks += mk[i_ekky].sks;
        total_nilai += mk[i_ekky].nilai_angka * mk[i_ekky].sks;

        cout << endl;
    }

    // ===== Hitung IPK =====
    ekky = total_nilai / total_sks;

    // ===== Output ===== //
    cout << "===========================================" << endl;
    cout << "         KARTU HASIL STUDI (KHS)          " << endl;
    cout << "==========================================" << endl;

    cout << "Nama Mahasiswa : " << mhs.nama << endl;
    cout << "NIM            : " << mhs.nim << endl;

    cout << "------------------------------------------" << endl;
    cout << setw(5) << "No"
         << setw(15) << "MataKuliah"
         << setw(5) << "SKS"
         << setw(10) << "Huruf"
         << setw(10) << "Angka" << endl;

    for (i_ekky = 0; i_ekky < jumlah_mk; i_ekky++)
    {
        cout << setw(5) << i_ekky + 1
             << setw(15) << mk[i_ekky].nama_mk
             << setw(5) << mk[i_ekky].sks
             << setw(10) << mk[i_ekky].nilai_huruf
             << setw(10) << mk[i_ekky].nilai_angka << endl;
    }

    cout << "------------------------------------------" << endl;
    cout << "Jumlah Mata Kuliah : " << jumlah_mk << endl;
    cout << "Jumlah SKS         : " << total_sks << endl;
    cout << "IPK                : " << fixed << setprecision(2) << ekky << endl;
    cout << "==========================================" << endl;

    cin.get();
}