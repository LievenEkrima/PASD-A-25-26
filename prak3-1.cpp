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
typedef struct elm {
    NilaiMK Kontainer;
    struct elm *next;
} elemen;

//Deklarasi struktur stack
typedef struct {
    elemen* top;
} stack;

//Fungsi membuat stack kosong
void buatStackkosong(stack *S) {
    (*S).top = NULL;
}

//Fungsi push (menambah data)
void push(string npm, string nama_mhs, double nilai, stack *S) {
    elemen *info = new elemen;

    info->Kontainer.npm = npm;
    info->Kontainer.nama_mhs = nama_mhs;
    info->Kontainer.nilai = nilai;

    info->next = (*S).top;
    (*S).top = info;
}

//Fungsi pop (menghapus data)
void Pop(stack *S) {
    if ((*S).top != NULL) {
        elemen *hapus = (*S).top;
        (*S).top = (*S).top->next;
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

    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    cin.ignore(1000);

    string npm, nama;
    double nilai;

    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << endl;

        cout << "Nomor Pokok Mahasiswa: ";
        getline(cin, npm);

        cout << "Nama Mahasiswa       : ";
        getline(cin, nama);

        cout << "Nilai Mahasiswa      : ";
        cin >> nilai;
        cin.ignore(1000);

        push(npm, nama, nilai, &S);
    }

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