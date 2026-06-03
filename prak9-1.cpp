#include <iostream>
using namespace std;

typedef struct node *alamatnode;
typedef struct node {
    char INFO;
    alamatnode RIGHT;
    alamatnode LEFT;
} NODE;

typedef struct {
    NODE* root;
} TREE;

void BuatTree(char C, TREE *T) {
    NODE *Baru;
    Baru = new NODE;
    Baru->INFO  = C;
    Baru->RIGHT = NULL;
    Baru->LEFT  = NULL;
    (*T).root   = Baru;
}

void TambahKanan(char C, NODE *root) {
    if (root->RIGHT == NULL) {
        NODE *Baru;
        Baru = new NODE;
        Baru->INFO  = C;
        Baru->RIGHT = NULL;
        Baru->LEFT  = NULL;
        root->RIGHT = Baru;
    } else {
        cout << "Sub Tree Kanan telah diisi" << endl;
    }
}

void TambahKiri(char C, NODE *root) {
    if (root->LEFT == NULL) {
        NODE *Baru;
        Baru = new NODE;
        Baru->INFO  = C;
        Baru->RIGHT = NULL;
        Baru->LEFT  = NULL;
        root->LEFT  = Baru;
    } else {
        cout << "Sub Tree Kiri telah diisi" << endl;
    }
}

void CetakTreePreOrder(NODE *root) {
    if (root != NULL) {
        cout << root->INFO << endl;
        CetakTreePreOrder(root->LEFT);
        CetakTreePreOrder(root->RIGHT);
    }
}

void CetakTreeInOrder(NODE *root) {
    if (root != NULL) {
        CetakTreeInOrder(root->LEFT);
        cout << root->INFO << endl;
        CetakTreeInOrder(root->RIGHT);
    }
}

void CetakTreePostOrder(NODE *root) {
    if (root != NULL) {
        CetakTreePostOrder(root->LEFT);
        CetakTreePostOrder(root->RIGHT);
        cout << root->INFO << endl;
    }
}

int main() {
    TREE T;
    char root_val;
    char kiri1, kanan1;   
    char kiri2, kanan2;   
    char kiri3, kanan3;   

    cout << "===== INPUT BINARY TREE =====" << endl;
    cout << "Masukkan nilai ROOT         : "; cin >> root_val;
    cout << "Masukkan anak KIRI  root    : "; cin >> kiri1;
    cout << "Masukkan anak KANAN root    : "; cin >> kanan1;
    cout << "Masukkan anak KIRI  " << kiri1  << "       : "; cin >> kiri2;
    cout << "Masukkan anak KANAN " << kiri1  << "       : "; cin >> kanan2;
    cout << "Masukkan anak KIRI  " << kanan1 << "       : "; cin >> kiri3;
    cout << "Masukkan anak KANAN " << kanan1 << "       : "; cin >> kanan3;

    BuatTree(root_val, &T);
    TambahKiri (kiri1,  T.root);
    TambahKanan(kanan1, T.root);
    TambahKiri (kiri2,  T.root->LEFT);
    TambahKanan(kanan2, T.root->LEFT);
    TambahKiri (kiri3,  T.root->RIGHT);
    TambahKanan(kanan3, T.root->RIGHT);

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~  PREORDER  ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    CetakTreePreOrder(T.root);
    cout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~  INORDER   ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    CetakTreeInOrder(T.root);
    cout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~  POSTORDER ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    CetakTreePostOrder(T.root);
    cout << endl;

    cin.get();
}
