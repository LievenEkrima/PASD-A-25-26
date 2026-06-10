#include <iostream>
#include <string>
using namespace std;

class BTreeNode {
    string *Kunci;
    int t, n;
    bool leaf;
    BTreeNode **C;

public:
    BTreeNode(int tt, bool _leaf);

    void SisipTdkPenuh(string k);
    void splitAnak(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(string k);

    friend class BTree;
};
class BTree {
    int t;
    BTreeNode *root;

public:
    BTree(int tt) {
        root = NULL;
        t = tt;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    BTreeNode* search(string k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    void Sisip(string k);
};
BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    Kunci = new string[2 * t - 1];
    C = new BTreeNode*[2 * t];

    n = 0;
}
void BTreeNode::traverse() {
    int i;

    for (i = 0; i < n; i++) {
        if (!leaf)
            C[i]->traverse();

        cout << Kunci[i] << " ";
    }

    if (!leaf)
        C[i]->traverse();
}
BTreeNode *BTreeNode::search(string k) {
    int i = 0;

    while (i < n && k > Kunci[i])
        i++;

    if (i < n && Kunci[i] == k)
        return this;

    if (leaf)
        return NULL;

    return C[i]->search(k);
}
void BTreeNode::splitAnak(int i, BTreeNode *y) {

    BTreeNode *z = new BTreeNode(y->t, y->leaf);

    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->Kunci[j] = y->Kunci[j + t];

    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        Kunci[j + 1] = Kunci[j];

    Kunci[i] = y->Kunci[t - 1];

    n++;
}
void BTreeNode::SisipTdkPenuh(string k) {

    int i = n - 1;

    if (leaf) {

        while (i >= 0 && Kunci[i] > k) {
            Kunci[i + 1] = Kunci[i];
            i--;
        }

        Kunci[i + 1] = k;
        n++;
    }
    else {

        while (i >= 0 && Kunci[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1) {

            splitAnak(i + 1, C[i + 1]);

            if (Kunci[i + 1] < k)
                i++;
        }

        C[i + 1]->SisipTdkPenuh(k);
    }
}
void BTree::Sisip(string k) {

    if (root == NULL) {

        root = new BTreeNode(t, true);

        root->Kunci[0] = k;
        root->n = 1;
    }
    else {

        if (root->n == 2 * t - 1) {

            BTreeNode *s = new BTreeNode(t, false);

            s->C[0] = root;

            s->splitAnak(0, root);

            int i = 0;

            if (s->Kunci[0] < k)
                i++;

            s->C[i]->SisipTdkPenuh(k);

            root = s;
        }
        else {
            root->SisipTdkPenuh(k);
        }
    }
}int main() {

    BTree t(3);

    int n;
    string kata;

    cout << "Masukkan Jumlah Kata = ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan Kata = ";
        cin >> kata;
        t.Sisip(kata);
    }

    cout << endl;
    cout << "        Pohon dengan menggunakan B-TREE     " << endl;
    cout << " -------------- Data Kata ------------------" << endl;
    cout << " -------------------------------------------" << endl;

    t.traverse();

    cout << endl;
    cout << endl;

    cout << "Masukkan kata yang dicari : ";
    cin >> kata;

    if (t.search(kata) != NULL)
        cout << "Kata yang dicari " << kata << " = Ditemukan";
    else
        cout << "Kata yang dicari " << kata << " = Tidak Ditemukan";

    cout << endl;

    cin.get();
}
