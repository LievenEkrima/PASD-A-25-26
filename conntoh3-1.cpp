#include <iostream>
#include <string>
using namespace std;

//Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

//Deklarasi struktur elemen
typedef struct elm *alamatelem;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelem next;
} elemen;

//Deklarasi struktur stack
typedef struct {
    elemen* top;
} stack;

//Fungsi membuat stack kosong
void buatStackkosong(stack *S) {
    (*S).top = NULL;
}

//Fungsi mengecek stack kosong
int isKosong(stack S) {
    bool hasil = false;

    if (S.top == NULL) {
        hasil = true;
    }
    return hasil;
}

//Fungsi menghitung jumlah elemen stack
int jmlElemen(stack S) {
    int hasil = 0;

    if (S.top != NULL) {
        elemen *bantu;
        bantu = S.top;

        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

//Fungsi push (menambah data)
void push(string npm, string nama_mhs, double nilai, stack *S) {
    elemen *info;
    info = new elemen;

    info->Kontainer.npm = npm;
    info->Kontainer.nama_mhs = nama_mhs;
    info->Kontainer.nilai = nilai;

    if ((*S).top == NULL) {
        info->next = NULL;
    } else {
        info->next = (*S).top;
    }

    (*S).top = info;
    info = NULL;
}

//Fungsi pop (menghapus data)
void Pop(stack *S) {
    if ((*S).top != NULL) {
        elemen *hapus = (*S).top;

        if (jmlElemen(*S) == 1) {
            (*S).top = NULL;
        } else {
            (*S).top = (*S).top->next;
        }

        hapus->next = NULL;
        delete hapus;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

//Fungsi menampilkan isi stack
void CetakStack(stack S) {
    if (S.top != NULL) {
        cout << "MENAMPILKAN STACK" << endl;

        elemen *bantu = S.top;
        int i = 1;

        while (bantu != NULL) {
            cout << "====================================" << endl;
            cout << "Elemen ke            : " << i << endl;
            cout << "Nomor Pokok Mahasiswa: " << bantu->Kontainer.npm << endl;
            cout << "Nama Mahasiswa       : " << bantu->Kontainer.nama_mhs << endl;
            cout << "Nilai Mahasiswa      : " << bantu->Kontainer.nilai << endl;

            bantu = bantu->next;
            i++;
        }
        cout << "====================================" << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

//Program utama
int main() {
    stack S;

    buatStackkosong(&S);

    CetakStack(S);
    cout << endl << endl;

    cout << "==============================" << endl;

    push("4523210666", "Bidi", 88.75, &S);
    push("4523210777", "Susi", 78.85, &S);
    push("4523210888", "Nuri", 90.65, &S);
    push("4523210999", "Bimo", 68.55, &S);
    push("4523210555", "Arif", 70.85, &S);
    push("4523210444", "Rido", 98.65, &S);
    push("4523210222", "Ella", 60.55, &S);

    CetakStack(S);

    cout << "==============================" << endl;
    cout << endl << endl;

    Pop(&S);
    CetakStack(S);

    cout << endl << endl;

    Pop(&S);
    CetakStack(S);

    cout << "==============================" << endl;

    return 0;
}