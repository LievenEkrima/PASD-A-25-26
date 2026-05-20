#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100

class Biodataa {
public:
    char nama[20];
    int usia;
};

class QueueEkrima {
private:
    Biodataa queue_ekrima[MAX];
    int awal_ekrima, akhir_ekrima;

public:
    QueueEkrima() {
        init();
    }

    void init() {
        awal_ekrima = -1;
        akhir_ekrima = -1;
    }

    int full() {
        return (akhir_ekrima == MAX - 1);
    }

    int empty() {
        return (akhir_ekrima == -1);
    }

    Biodataa entridata() {
        Biodataa mhs_ekrima;
        cout << "\n=== INPUT DATA ===\n";
        cout << "Nama  : ";
        cin >> mhs_ekrima.nama;
        cout << "Usia  : ";
        cin >> mhs_ekrima.usia;
        return mhs_ekrima;
    }

    void enqueue(Biodataa mhs_ekrima) {
        if (empty()) {
            awal_ekrima = 0;
            akhir_ekrima = 0;
            queue_ekrima[awal_ekrima] = mhs_ekrima;
        } else if (!full()) {
            akhir_ekrima++;
            queue_ekrima[akhir_ekrima] = mhs_ekrima;
        } else {
            cout << "Queue sudah penuh!\n";
        }
    }

    Biodataa dequeue() {
        Biodataa mhs_ekrima;
        if (!empty()) {
            mhs_ekrima = queue_ekrima[awal_ekrima];

            for (int i = awal_ekrima; i < akhir_ekrima; i++) {
                queue_ekrima[i] = queue_ekrima[i + 1];
            }

            akhir_ekrima--;

            if (akhir_ekrima < 0) {
                init();
            }

        } else {
            cout << "Queue kosong!\n";
        }
        return mhs_ekrima;
    }

    void display(Biodataa mhs_ekrima) {
        cout << "Nama : " << mhs_ekrima.nama << endl;
        cout << "Usia : " << mhs_ekrima.usia << endl;
    }

    void baca() {
        cout << "\n=== ISI QUEUE ===\n";
        if (!empty()) {
            for (int i = awal_ekrima; i <= akhir_ekrima; i++) {
                cout << "\nData ke-" << (i + 1) << endl;
                display(queue_ekrima[i]);
            }
        } else {
            cout << "Data kosong!\n";
        }
    }
};

int main() {
    QueueEkrima q_ekrima;
    Biodataa mhs_ekrima;
    char pilih;

    cout << "====================================\n";
    cout << "   PROGRAM QUEUE MAHASISWA EKRIMA   \n";
    cout << "====================================\n";

    do {
        cout << "\n=========== MENU ===========\n";
        cout << "1. Input Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Lihat Data\n";
        cout << "4. Hapus Semua\n";
        cout << "5. Keluar\n";
        cout << "============================\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilih;

        switch(pilih) {
            case '1':
                mhs_ekrima = q_ekrima.entridata();
                q_ekrima.enqueue(mhs_ekrima);
                cout << "Data berhasil ditambahkan!\n";
                break;

            case '2':
                cout << "\n=== DATA DIHAPUS ===\n";
                mhs_ekrima = q_ekrima.dequeue();
                q_ekrima.display(mhs_ekrima);
                break;

            case '3':
                q_ekrima.baca();
                break;

            case '4':
                q_ekrima.init();
                cout << "Semua data berhasil dihapus!\n";
                break;

            case '5':
                cout << "\nTerima kasih, program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while(pilih != '5');

    return 0;
}