#include <iostream>
#include <string>
using namespace std;

// Struct
struct Mahasiswa {
    string nama;
    int ekrima;
};

// Fungsi Merge
void merge(Mahasiswa data[], int kiri, int mid, int kanan) {

    int n1 = mid - kiri + 1;
    int n2 = kanan - mid;

    Mahasiswa L[n1], R[n2];

    // Data kiri
    for (int i_ekrima = 0; i_ekrima < n1; i_ekrima++) {
        L[i_ekrima] = data[kiri + i_ekrima];
    }

    // Data kanan
    for (int j_ekrima = 0; j_ekrima < n2; j_ekrima++) {
        R[j_ekrima] = data[mid + 1 + j_ekrima];
    }

    int i_ekrima = 0;
    int j_ekrima = 0;
    int k = kiri;

    // Descending
    while (i_ekrima < n1 && j_ekrima < n2) {

        if (L[i_ekrima].ekrima >= R[j_ekrima].ekrima) {

            data[k] = L[i_ekrima];
            i_ekrima++;

        } else {

            data[k] = R[j_ekrima];
            j_ekrima++;
        }

        k++;
    }

    while (i_ekrima < n1) {

        data[k] = L[i_ekrima];
        i_ekrima++;
        k++;
    }

    while (j_ekrima < n2) {

        data[k] = R[j_ekrima];
        j_ekrima++;
        k++;
    }
}

// Fungsi Merge Sort
void mergeSort(Mahasiswa data[], int kiri, int kanan) {

    if (kiri < kanan) {

        int mid = kiri + (kanan - kiri) / 2;

        mergeSort(data, kiri, mid);
        mergeSort(data, mid + 1, kanan);

        merge(data, kiri, mid, kanan);
    }
}

// Cetak Data
void CetakData(Mahasiswa data[], int jumlah) {

    for (int i_ekrima = 0; i_ekrima < jumlah; i_ekrima++) {

        cout << data[i_ekrima].nama
             << " - "
             << data[i_ekrima].ekrima << endl;
    }
}

int main() {

    int jumlah;

    cout << "Masukkan jumlah data : ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];

    // Input
    for (int i_ekrima = 0; i_ekrima < jumlah; i_ekrima++) {

        cout << "Data ke-" << i_ekrima + 1 << endl;

        cout << "Nama    : ";
        cin >> mhs[i_ekrima].nama;

        cout << "Nilai  : ";
        cin >> mhs[i_ekrima].ekrima;
    }

    cout << "DATA SEBELUM diurutkan:" << endl;
    CetakData(mhs, jumlah);

    // Merge Sort Descending
    mergeSort(mhs, 0, jumlah - 1);

    cout << "DATA SETELAH diurutkan Descending:" << endl;
    CetakData(mhs, jumlah);

    return 0;
}