#include <stdio.h>
#include <iostream>
#include <stdlib.h> // untuk malloc
#include <string.h>

using namespace std;

// Deklarasi fungsi
void BUAT_SIMPUL(int X);
void AWAL();
void CETAK();
void INSERTKANAN();

// Deklarasi struktur node
struct Node {
    int INFO;
    struct Node *LINK;
};

typedef struct Node Simpul;

// Deklarasi pointer
Simpul *P, *FIRST, *LAST, *Q;
int X;

int main() {
    int A[7] = {22, 28, 7, 11, 66, 63, 10}; // Data
    int i;

    FIRST = NULL; // Inisialisasi Linked List

    // Membuat simpul pertama
    X = A[0];
    BUAT_SIMPUL(X);
    AWAL();

    // Membentuk linked list
    for (i = 1; i <= 6; i++) {
        X = A[i];
        BUAT_SIMPUL(X);
        INSERTKANAN();
    }

    cout << "Nilai Sebelum Dilakukan Insert Kanan : ";
    CETAK();

    // Insert data baru
    X = 100;
    BUAT_SIMPUL(X);
    INSERTKANAN();

    cout << endl;
    cout << "Nilai Setelah Dilakukan Insert Kanan : ";
    CETAK();

    cout << endl;
    cin.get();
}

// Fungsi membuat simpul baru
void BUAT_SIMPUL(int X) {
    P = (Simpul*) malloc(sizeof(Simpul));
    if (P != NULL) {
        P->INFO = X;
    } else {
        cout << "Pembuatan Simpul Tidak Berhasil" << endl;
        cin.get();
        exit(1);
    }
}

// Fungsi membuat simpul awal
void AWAL() {
    FIRST = P;
    LAST = P;
    P->LINK = NULL;
}

// Fungsi insert ke kanan (akhir)
void INSERTKANAN() {
    LAST->LINK = P;
    LAST = P;
    P->LINK = NULL;
}

// Fungsi mencetak isi linked list
void CETAK() {
    int X;
    Q = FIRST;

    while (Q != NULL) {
        X = Q->INFO;
        cout << " " << X;
        Q = Q->LINK;
    }
}