#include <iostream>
using namespace std;

int data_ekrima[10] = {45, 12, 9, 30, 21, 55, 1, 17};
int n_ekrima = 8;

void tukar_ekrima(int a_ekrima, int b_ekrima)
{
    int t_ekrima;

    t_ekrima = data_ekrima[b_ekrima];
    data_ekrima[b_ekrima] = data_ekrima[a_ekrima];
    data_ekrima[a_ekrima] = t_ekrima;
}

void tampil_ekrima()
{
    for(int i_ekrima = 0; i_ekrima < n_ekrima; i_ekrima++)
    {
        cout << data_ekrima[i_ekrima] << " ";
    }

    cout << endl;
}

void bubble_sort_ekrima()
{
    for(int i_ekrima = 1; i_ekrima < n_ekrima; i_ekrima++)
    {
        for(int j_ekrima = n_ekrima - 1; j_ekrima >= i_ekrima; j_ekrima--)
        {
            if(data_ekrima[j_ekrima] < data_ekrima[j_ekrima - 1])
            {
                tukar_ekrima(j_ekrima, j_ekrima - 1);
            }
        }

        tampil_ekrima();
    }

    cout << endl;
}

int main()
{
    cout << "*--------------------------------*" << endl;
    cout << "*     Program Bubble Sort        *" << endl;
    cout << "*        Ascending Order         *" << endl;
    cout << "*--------------------------------*" << endl;

    cout << "Data Sebelum Diurutkan : ";
    tampil_ekrima();

    cout << endl;
    cout << "Proses Bubble Sort......." << endl;
    cout << "--------------------------------" << endl;

    bubble_sort_ekrima();

    cout << "Data Setelah Diurutkan : ";
    tampil_ekrima();

    cout << "--------------------------------" << endl;
    cout << " TERIMA KASIH " << endl;
    cout << "--------------------------------" << endl;

    cin.get();
}