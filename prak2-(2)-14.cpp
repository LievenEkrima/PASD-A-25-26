#include <iostream>
#include <string>
using namespace std;

string stack[10];
int top = -1;
int ekrima;

void push(string data) {
    if (top == 9) {
        cout << "Stack penuh";
    } else {
        top++;
        stack[top] = data;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack kosong";
    } else {
        top--;
    }
}

void tampil() {
    cout << "Isi Stack:";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

int main() {

    // data awal
    push("Iphone");
    push("Windows");
    push("Mac");
    push("Symbian");
    push("Maemo");

    cout << "Data awal:";
    tampil();

    string ekrima1, ekrima2, ekrima3, ekrima4;

    ekrima1 = stack[top]; pop();
    ekrima2 = stack[top]; pop();
    ekrima3 = stack[top]; pop();
    ekrima4 = stack[top]; pop(); 

    pop();

    push("Iphone");
    push("Iphone 5");

    push(ekrima4);
    push(ekrima3);
    push(ekrima2);
    push(ekrima1);

    ekrima1 = stack[top]; pop();
    ekrima2 = stack[top]; pop(); 
    ekrima3 = stack[top]; pop(); 

    pop();

    push("Windows");
    push("Windows Phone");

    push(ekrima3);
    push(ekrima2);
    push(ekrima1);

    ekrima1 = stack[top]; pop();
    ekrima2 = stack[top]; pop();

    push("SnowLeopard");

    push(ekrima2);
    push(ekrima1);

    ekrima1 = stack[top]; pop();

    push("Symbian Belle");

    push(ekrima1);

    stack[0] = "Maemo 4";

    cout << "Setelah perubahan:";
    tampil();

    cin.get();
}