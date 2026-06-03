#include <iostream>
using namespace std;

class SequentialSearch
{
private:
    int data_ekrima[77];
    int jumlah_ekrima;

public:

    void inputData()
    {
        cout << "Masukkan jumlah elemen : ";
        cin >> jumlah_ekrima;

        cout << "\nMasukkan isi elemen array:\n";
        for(int i_ekrima = 0; i_ekrima < jumlah_ekrima; i_ekrima++)
        {
            cout << "Data[" << i_ekrima << "] : ";
            cin >> data_ekrima[i_ekrima];
        }
    }

    void tampilData()
    {
        cout << "\nIsi data array adalah:\n";
        for(int i_ekrima = 0; i_ekrima < jumlah_ekrima; i_ekrima++)
        {
            cout << "Data[" << i_ekrima << "] = "
                 << data_ekrima[i_ekrima] << endl;
        }
    }

    int cariData(int cari)
    {
        for(int i_ekrima = 0; i_ekrima < jumlah_ekrima; i_ekrima++)
        {
            if(data_ekrima[i_ekrima] == cari)
            {
                return i_ekrima;
            }
        }
        return -1;
    }
};

int main()
{
    SequentialSearch objek_ekrima;
    int cari_ekrima, hasil_ekrima;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "      PROGRAM SEQUENTIAL SEARCH";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    objek_ekrima.inputData();
    objek_ekrima.tampilData();

    cout << "Masukkan data yang dicari : ";
    cin >> cari_ekrima;

    hasil_ekrima = objek_ekrima.cariData(cari_ekrima);

    if(hasil_ekrima != -1)
    {
        cout << "Data ditemukan pada indeks Data["
             << hasil_ekrima << "]" << endl;
    }
    else
    {
        cout << "Data tidak ditemukan!" << endl;
    }

    cin.get();
}