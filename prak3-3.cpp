#include <iostream>
using namespace std;

struct data {
    string nama;
    int nilai;
};

struct elemen {
    data info;
    elemen* next;
};

struct stack {
    elemen* top;
};

void buatStackKosong(stack &S) {
    S.top = NULL;
}

void push(stack &S, string nama, int nilai) {
    elemen* baru = new elemen;
    baru->info.nama = nama;
    baru->info.nilai = nilai;

    baru->next = S.top;
    S.top = baru;
}

void cetak(stack S) {
    elemen* bantu = S.top;

    cout << "Nama : ";

    while (bantu != NULL) {
        cout << bantu->info.nama << " --" << bantu->info.nilai << "  ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    stack S;
    buatStackKosong(S);

    // Data langsung (tanpa input)
    push(S, "Candra", 22);
    push(S, "Cinthya", 66);
    push(S, "Ilham", 28);
    push(S, "Tiara", 63);
    push(S, "Fanny", 10);

    cetak(S);

    return 0;
}