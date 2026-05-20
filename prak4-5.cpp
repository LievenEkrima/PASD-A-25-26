#include <iostream>
#include <string>
using namespace std;

#define MAX 20

class QueueOS {
private:
    string data[MAX];
    int jumlah_ekrima;

public:
    QueueOS() {
        jumlah_ekrima = 0;
    }

    void tampil_ekrima() {
        cout << "Antrian OS: ";
        for (int ekrima_i = 0; ekrima_i < jumlah_ekrima; ekrima_i++) {
            cout << data[ekrima_i];
            if (ekrima_i != jumlah_ekrima - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    void tambahBelakang_ekrima(string x) {
        if (jumlah_ekrima < MAX) {
            data[jumlah_ekrima++] = x;
        } else {
            cout << "Queue penuh";
        }
    }

    // tambah sebelum target
    void tambahSebelum_ekrima(string target, string baru) {
        int pos_ekrima = -1;

        for (int ekrima_i = 0; ekrima_i < jumlah_ekrima; ekrima_i++) {
            if (data[ekrima_i] == target) {
                pos_ekrima = ekrima_i;
                break;
            }
        }

        if (pos_ekrima != -1 && jumlah_ekrima < MAX) {
            for (int ekrima_i = jumlah_ekrima; ekrima_i > pos_ekrima; ekrima_i--) {
                data[ekrima_i] = data[ekrima_i - 1];
            }
            data[pos_ekrima] = baru;
            jumlah_ekrima++;
        } else {
            cout << "Data tidak ditemukan / penuh";
        }
    }

    // tambah setelah target
    void tambahSetelah_ekrima(string target, string baru) {
        int pos_ekrima = -1;

        for (int ekrima_i = 0; ekrima_i < jumlah_ekrima; ekrima_i++) {
            if (data[ekrima_i] == target) {
                pos_ekrima = ekrima_i;
                break;
            }
        }

        if (pos_ekrima != -1 && jumlah_ekrima < MAX) {
            for (int ekrima_i = jumlah_ekrima; ekrima_i > pos_ekrima + 1; ekrima_i--) {
                data[ekrima_i] = data[ekrima_i - 1];
            }
            data[pos_ekrima + 1] = baru;
            jumlah_ekrima++;
        } else {
            cout << "Data tidak ditemukan / penuh";
        }
    }
};

int main() {
    QueueOS q;

    // ========================
    // Data Awal
    // ========================
    q.tambahBelakang_ekrima("Maemo");
    q.tambahBelakang_ekrima("Symbian");
    q.tambahBelakang_ekrima("Mac");
    q.tambahBelakang_ekrima("Windows");
    q.tambahBelakang_ekrima("Iphone");

    cout << "=== DATA AWAL ===" << endl;
    q.tampil_ekrima();

    // ========================
    // Proses Sesuai Soal
    // ========================

    // a. Iphone 5 sebelum Iphone
    q.tambahSebelum_ekrima("Iphone", "Iphone 5");

    // b. Windows Phone setelah Windows
    q.tambahSetelah_ekrima("Windows", "Windows Phone");

    // c. SnowLeopard setelah Mac
    q.tambahSetelah_ekrima("Mac", "SnowLeopard");

    // d. Symbian Belle setelah Symbian
    q.tambahSetelah_ekrima("Symbian", "Symbian Belle");

    // e. Maemo 4 paling bawah
    q.tambahBelakang_ekrima("Maemo 4");

    // ========================
    // Hasil Akhir
    // ========================
    cout << "\n=== SETELAH SEMUA OPERASI ===" << endl;
    q.tampil_ekrima();

    return 0;
}