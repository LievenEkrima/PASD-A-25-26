#include <iostream>
using namespace std;

// Node
struct node_ekrima {
    string data_ekrima;
    node_ekrima *next_ekrima;
};

// Queue
struct queue_ekrima {
    node_ekrima *first_ekrima;
    node_ekrima *last_ekrima;
};

// Buat kosong
void buatKosong_ekrima(queue_ekrima *Q_ekrima) {
    Q_ekrima->first_ekrima = NULL;
    Q_ekrima->last_ekrima = NULL;
}

// Tambah belakang
void addLast_ekrima(string data, queue_ekrima *Q) {
    node_ekrima *baru = new node_ekrima;
    baru->data_ekrima = data;
    baru->next_ekrima = NULL;

    if(Q->first_ekrima == NULL) {
        Q->first_ekrima = baru;
    } else {
        Q->last_ekrima->next_ekrima = baru;
    }
    Q->last_ekrima = baru;
}

// Insert setelah
void insertAfter_ekrima(string key, string dataBaru, queue_ekrima *Q) {
    node_ekrima *bantu_ekrima = Q->first_ekrima;

    while(bantu_ekrima != NULL) {
        if(bantu_ekrima->data_ekrima == key) {
            node_ekrima *baru = new node_ekrima;
            baru->data_ekrima = dataBaru;
            baru->next_ekrima = bantu_ekrima->next_ekrima;
            bantu_ekrima->next_ekrima = baru;

            if(bantu_ekrima == Q->last_ekrima) {
                Q->last_ekrima = baru;
            }
            return;
        }
        bantu_ekrima = bantu_ekrima->next_ekrima;
    }
}

// Hapus berdasarkan nilai
void deleteByValue_ekrima(string key, queue_ekrima *Q) {
    node_ekrima *curr = Q->first_ekrima;
    node_ekrima *prev = NULL;

    while(curr != NULL && curr->data_ekrima != key) {
        prev = curr;
        curr = curr->next_ekrima;
    }

    if(curr == NULL) return;

    if(prev == NULL) { // hapus depan
        Q->first_ekrima = curr->next_ekrima;
    } else {
        prev->next_ekrima = curr->next_ekrima;
    }

    if(curr == Q->last_ekrima) {
        Q->last_ekrima = prev;
    }

    delete curr;
}

// Cetak
void cetak_ekrima(queue_ekrima Q) {
    node_ekrima *bantu = Q.first_ekrima;
    while(bantu != NULL) {
        cout << bantu->data_ekrima << " -> ";
        bantu = bantu->next_ekrima;
    }
    cout << "NULL\n";
}

// MAIN
int main() {
    queue_ekrima Q;
    buatKosong_ekrima(&Q);

    // Data awal
    addLast_ekrima("Maemo", &Q);
    addLast_ekrima("Symbian", &Q);
    addLast_ekrima("Mac", &Q);
    addLast_ekrima("Windows", &Q);
    addLast_ekrima("Iphone", &Q);

    cout << "Awal:\n";
    cetak_ekrima(Q);

    // a
    addLast_ekrima("Maemo 4", &Q);
    deleteByValue_ekrima("Mac", &Q);

    // b
    insertAfter_ekrima("Windows", "Windows Mobile", &Q);
    deleteByValue_ekrima("Iphone", &Q);

    // c
    insertAfter_ekrima("Symbian", "Java Midlet", &Q);
    deleteByValue_ekrima("Maemo", &Q);

    // d
    insertAfter_ekrima("Mac", "Lion OS X", &Q); // (Mac sudah dihapus, jadi tidak akan masuk)
    deleteByValue_ekrima("Maemo", &Q); // sudah tidak ada

    // e
    insertAfter_ekrima("Iphone", "Android", &Q); // Iphone sudah dihapus
    deleteByValue_ekrima("Maemo", &Q);

    cout << "\nHasil akhir:\n";
    cetak_ekrima(Q);

    cin.get();
}