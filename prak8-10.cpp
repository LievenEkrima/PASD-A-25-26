#include <iostream>
using namespace std;

struct DataHuruf_ekrima
{
    char huruf_ekrima[7];
};

int SequentialSearch_ekrima(char data_ekrima[], int jumlah_ekrima, char cari_ekrima)
{
    for(int i_ekrima = 0; i_ekrima < jumlah_ekrima; i_ekrima++)
    {
        if(data_ekrima[i_ekrima] == cari_ekrima)
        {
            return i_ekrima;
        }
    }

    return -1;
}

int main()
{
    DataHuruf_ekrima dataHuruf_ekrima =
    {{'A','B','C','D','E','F','G'}};

    int jumlah_ekrima = 7;
    char cari_ekrima = 'E';

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   SEQUENTIAL SEARCH HURUF EKRIMA" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "Isi data huruf :" << endl;

    for(int i_ekrima = 0; i_ekrima < jumlah_ekrima; i_ekrima++)
    {
        cout << "Data[" << i_ekrima << "] = "
             << dataHuruf_ekrima.huruf_ekrima[i_ekrima]
             << endl;
    }

    int hasil_ekrima =
    SequentialSearch_ekrima(
        dataHuruf_ekrima.huruf_ekrima,
        jumlah_ekrima,
        cari_ekrima
    );

    cout << "Huruf yang dicari : "
         << cari_ekrima << endl;

    if(hasil_ekrima != -1)
    {
        cout << "Huruf ditemukan pada indeks Data["
             << hasil_ekrima << "]" << endl;
    }
    else
    {
        cout << "Huruf tidak ditemukan" << endl;
    }

    cin.get();
}