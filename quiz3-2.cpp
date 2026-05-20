#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int data[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int nomor) {
        if (isFull()) {
            cout << "Antrian penuh!\n";
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear++;
            }
            data[rear] = nomor;
            cout << "Nomor antrian " << nomor << " masuk ke antrian.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong!\n";
        } else {
            cout << "Nomor antrian " << data[front] << " dipanggil.\n";
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
        } else {
            cout << "\nDaftar Antrian:\n";
            for (int i = front; i <= rear; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int pilihan, nomor = 1;

    do {
        cout << "\n=== MENU ANTRIAN ===\n";
        cout << "1. Ambil Nomor Antrian\n";
        cout << "2. Panggil Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                q.enqueue(nomor++);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Keluar program.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    cin.get();
}