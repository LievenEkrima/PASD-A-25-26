#include <iostream>
using namespace std;

// Struktur node
struct node_ekrima {
    string data_ekrima;
    node_ekrima *next_ekrima;
};

// Struktur queue
struct queue_ekrima {
    node_ekrima *first_ekrima;
    node_ekrima *last_ekrima;
};

// Inisialisasi queue
void buatKosong_ekrima(queue_ekrima *Q_ekrima) {
    Q_ekrima->first_ekrima = NULL;
    Q_ekrima->last_ekrima = NULL;
}

// Tambah di belakang
void addLast_ekrima(string data_ekrima, queue_ekrima *Q_ekrima) {
    node_ekrima *baru_ekrima = new node_ekrima;
    baru_ekrima->data_ekrima = data_ekrima;
    baru_ekrima->next_ekrima = NULL;

    if(Q_ekrima->first_ekrima == NULL) {
        Q_ekrima->first_ekrima = baru_ekrima;
    } else {
        Q_ekrima->last_ekrima->next_ekrima = baru_ekrima;
    }
    Q_ekrima->last_ekrima = baru_ekrima;
}

// Insert setelah node tertentu
void insertAfter_ekrima(string key_ekrima, string dataBaru_ekrima, queue_ekrima *Q_ekrima) {
    node_ekrima *bantu_ekrima = Q_ekrima->first_ekrima;

    while(bantu_ekrima != NULL) {
        if(bantu_ekrima->data_ekrima == key_ekrima) {
            node_ekrima *baru_ekrima = new node_ekrima;
            baru_ekrima->data_ekrima = dataBaru_ekrima;
            baru_ekrima->next_ekrima = bantu_ekrima->next_ekrima;
            bantu_ekrima->next_ekrima = baru_ekrima;

            if(bantu_ekrima == Q_ekrima->last_ekrima) {
                Q_ekrima->last_ekrima = baru_ekrima;
            }
            return;
        }
        bantu_ekrima = bantu_ekrima->next_ekrima;
    }
}

// Insert sebelum node tertentu
void insertBefore_ekrima(string key_ekrima, string dataBaru_ekrima, queue_ekrima *Q_ekrima) {
    node_ekrima *baru_ekrima = new node_ekrima;
    baru_ekrima->data_ekrima = dataBaru_ekrima;

    // Jika di depan
    if(Q_ekrima->first_ekrima != NULL && Q_ekrima->first_ekrima->data_ekrima == key_ekrima) {
        baru_ekrima->next_ekrima = Q_ekrima->first_ekrima;
        Q_ekrima->first_ekrima = baru_ekrima;
        return;
    }

    node_ekrima *prev_ekrima = NULL;
    node_ekrima *curr_ekrima = Q_ekrima->first_ekrima;

    while(curr_ekrima != NULL && curr_ekrima->data_ekrima != key_ekrima) {
        prev_ekrima = curr_ekrima;
        curr_ekrima = curr_ekrima->next_ekrima;
    }

    if(curr_ekrima != NULL) {
        prev_ekrima->next_ekrima = baru_ekrima;
        baru_ekrima->next_ekrima = curr_ekrima;
    }
}

// Cetak queue
void cetak_ekrima(queue_ekrima Q_ekrima) {
    node_ekrima *bantu_ekrima = Q_ekrima.first_ekrima;
    cout << "Isi Queue: ";
    while(bantu_ekrima != NULL) {
        cout << bantu_ekrima->data_ekrima << " -> ";
        bantu_ekrima = bantu_ekrima->next_ekrima;
    }
    cout << "NULL\n";
}

// MAIN
int main() {
    queue_ekrima Q_ekrima;
    buatKosong_ekrima(&Q_ekrima);

    // Data awal
    addLast_ekrima("Maemo", &Q_ekrima);
    addLast_ekrima("Symbian", &Q_ekrima);
    addLast_ekrima("Mac", &Q_ekrima);
    addLast_ekrima("Windows", &Q_ekrima);
    addLast_ekrima("Iphone", &Q_ekrima);

    cout << "Awal:\n";
    cetak_ekrima(Q_ekrima);

    // a
    insertBefore_ekrima("Iphone", "Iphone 5", &Q_ekrima);

    // b
    insertBefore_ekrima("Windows", "Windows Phone", &Q_ekrima);

    // c
    insertAfter_ekrima("Mac", "SnowLeopard", &Q_ekrima);

    // d
    insertAfter_ekrima("Symbian", "Symbian Belle", &Q_ekrima);

    // e
    addLast_ekrima("Maemo 4", &Q_ekrima);

    cout << "\nHasil akhir:\n";
    cetak_ekrima(Q_ekrima);

    cin.get();
}