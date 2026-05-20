#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct DataBuku {
    string kodeBuku;
    string judulBuku;
    string pengarang;
};

class StackBuku {
private:
    DataBuku stack[MAX];
    int top;

public:
    StackBuku() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(DataBuku buku) {
        if (isFull()) {
            cout << "Stack penuh! Tidak bisa menambah buku.\n";
        } else {
            stack[++top] = buku;
            cout << "Buku berhasil ditambahkan.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong! Tidak ada buku.\n";
        } else {
            cout << "Buku diambil:\n";
            cout << "Kode: " << stack[top].kodeBuku << endl;
            cout << "Judul: " << stack[top].judulBuku << endl;
            cout << "Pengarang: " << stack[top].pengarang << endl;
            top--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack kosong.\n";
        } else {
            cout << "\nDaftar Buku (Top ke Bottom):\n";
            for (int i = top; i >= 0; i--) {
                cout << "------------------------\n";
                cout << "Kode: " << stack[i].kodeBuku << endl;
                cout << "Judul: " << stack[i].judulBuku << endl;
                cout << "Pengarang: " << stack[i].pengarang << endl;
            }
            cout << "------------------------\n";
        }
    }
};

int main() {
    StackBuku sb;
    int pilihan;
    DataBuku buku;

    do {
        cout << "\n=== MENU STACK BUKU ===\n";
        cout << "1. Tambah Buku (Push)\n";
        cout << "2. Ambil Buku (Pop)\n";
        cout << "3. Tampilkan Buku\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan Kode Buku: ";
                getline(cin, buku.kodeBuku);
                cout << "Masukkan Judul Buku: ";
                getline(cin, buku.judulBuku);
                cout << "Masukkan Pengarang: ";
                getline(cin, buku.pengarang);
                sb.push(buku);
                break;

            case 2:
                sb.pop();
                break;

            case 3:
                sb.display();
                break;

            case 4:
                cout << "Keluar program.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    cin.get();
}