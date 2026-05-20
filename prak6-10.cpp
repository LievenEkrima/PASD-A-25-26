#include <iostream>
#include <string>
using namespace std;

// Struct
struct Mahasiswa {
    string nama;
    int ekrima;
};

// Fungsi Quick Sort
void Q_Sort(Mahasiswa data[], int kiri, int kanan);

int main() {

    int jumlah;

    cout << "Masukkan jumlah data : ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];

    // Input
    for (int d = 0; d < jumlah; d++) {

        cout << "Data ke-" << d + 1 << endl;

        cout << "Nama    : ";
        cin >> mhs[d].nama;

        cout << "Nilai  : ";
        cin >> mhs[d].ekrima;
    }

    cout << "Data SEBELUM diurutkan" << endl;
    cout << "========================" << endl;

    for (int d = 0; d < jumlah; d++) {

        cout << mhs[d].nama
             << " - "
             << mhs[d].ekrima << endl;
    }

    // Quick Sort
    Q_Sort(mhs, 0, jumlah - 1);

    cout << "Data SETELAH diurutkan" << endl;
    cout << "========================" << endl;

    for (int d = 0; d < jumlah; d++) {

        cout << mhs[d].nama
             << " - "
             << mhs[d].ekrima << endl;
    }

    cin.get();
}

// Fungsi Quick Sort
void Q_Sort(Mahasiswa data[], int kiri, int kanan) {

    int pivot;
    int i_ekrima, j_ekrima;

    Mahasiswa temp;

    i_ekrima = kiri;
    j_ekrima = kanan;

    pivot = data[kiri].ekrima;

    while (i_ekrima < j_ekrima) {

        while ((data[j_ekrima].ekrima >= pivot) &&
               (i_ekrima < j_ekrima)) {

            j_ekrima--;
        }

        if (i_ekrima != j_ekrima) {

            temp = data[i_ekrima];
            data[i_ekrima] = data[j_ekrima];
            data[j_ekrima] = temp;

            i_ekrima++;
        }

        while ((data[i_ekrima].ekrima <= pivot) &&
               (i_ekrima < j_ekrima)) {

            i_ekrima++;
        }

        if (i_ekrima != j_ekrima) {

            temp = data[j_ekrima];
            data[j_ekrima] = data[i_ekrima];
            data[i_ekrima] = temp;

            j_ekrima--;
        }
    }

    if (kiri < i_ekrima - 1) {
        Q_Sort(data, kiri, i_ekrima - 1);
    }

    if (i_ekrima + 1 < kanan) {
        Q_Sort(data, i_ekrima + 1, kanan);
    }
}