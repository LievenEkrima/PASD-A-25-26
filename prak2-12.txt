#include <iostream>
using namespace std;

// ===== Struct KTP =====
struct KTP
{
    int NOKTP;
    string Nama;

    struct Alamat
    {
        string Jalan;
        string Kota;
        int KodePos;
    } alamat;

    struct Lahir
    {
        int Tanggal;
        int Bulan;
        int Tahun;
    } lahir;
};

int main()
{
    // Pointer ke struct
    KTP *ekky = new KTP;

    // ===== Input Data =====
    cout << "Masukkan No KTP  : ";
    cin >> ekky->NOKTP;

    cout << "Masukkan Nama    : ";
    cin >> ekky->Nama;

    cout << "Alamat" << endl;
    cout << "- Jalan   : ";
    cin >> ekky->alamat.Jalan;

    cout << "- Kota    : ";
    cin >> ekky->alamat.Kota;

    cout << "- KodePos : ";
    cin >> ekky->alamat.KodePos;

    cout << "Tanggal Lahir" << endl;
    cout << "- Tanggal : ";
    cin >> ekky->lahir.Tanggal;

    cout << "- Bulan   : ";
    cin >> ekky->lahir.Bulan;

    cout << "- Tahun   : ";
    cin >> ekky->lahir.Tahun;

    cout << endl;

    // ===== Output Data =====
    cout << "===== DATA KTP =====" << endl;
    cout << "No KTP        : " << ekky->NOKTP << endl;
    cout << "Nama          : " << ekky->Nama << endl;
    cout << "Alamat        : "
         << ekky->alamat.Jalan << ", "
         << ekky->alamat.Kota << ", "
         << ekky->alamat.KodePos << endl;

    cout << "Tanggal Lahir : "
         << ekky->lahir.Tanggal << "-"
         << ekky->lahir.Bulan << "-"
         << ekky->lahir.Tahun << endl;

    cin.get();
}