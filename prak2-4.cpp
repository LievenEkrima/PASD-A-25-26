#include <iostream>
using namespace std;

class Hari {
private:
    int ekrima_hari;

public:
    Hari() {
        cout << "Masukkan angka (0-6): ";
        cin >> ekrima_hari;
    }

    void tampil() {
        if (ekrima_hari == 0) {
            cout << "Minggu";
        } else if (ekrima_hari == 1) {
            cout << "Senin";
        } else if (ekrima_hari == 2) {
            cout << "Selasa";
        } else if (ekrima_hari == 3) {
            cout << "Rabu";
        } else if (ekrima_hari == 4) {
            cout << "Kamis";
        } else if (ekrima_hari == 5) {
            cout << "Jum'at";
        } else if (ekrima_hari == 6) {
            cout << "Sabtu";
        } else {
            cout << "Hari tidak valid";
        }
    }
};

int main() {
    Hari h;
    h.tampil();

    cin.get();
}