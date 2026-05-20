#include <iostream>
using namespace std;

class BubbleSort_ekrima
{
private:
    int data_ekrima[100];
    int n_ekrima;

public:
    void inputData_ekrima()
    {
        cout << "Masukkan jumlah data : ";
        cin >> n_ekrima;

        cout << endl;

        for(int i_ekrima = 0; i_ekrima < n_ekrima; i_ekrima++)
        {
            cout << "Masukkan data ke-" << i_ekrima + 1 << " : ";
            cin >> data_ekrima[i_ekrima];
        }
    }

    void tampilData_ekrima()
    {
        for(int i_ekrima = 0; i_ekrima < n_ekrima; i_ekrima++)
        {
            cout << data_ekrima[i_ekrima] << " ";
        }

        cout << endl;
    }

    void bubbleSortAscending_ekrima()
    {
        int k_ekrima = 0;
        int flag_ekrima = 1;
        int i_ekrima;
        int x_ekrima;

        while(k_ekrima <= n_ekrima - 2 && flag_ekrima == 1)
        {
            i_ekrima = 0;
            flag_ekrima = 0;

            while(i_ekrima <= n_ekrima - 2 - k_ekrima)
            {
                // Ascending
                if(data_ekrima[i_ekrima] > data_ekrima[i_ekrima + 1])
                {
                    flag_ekrima = 1;

                    x_ekrima = data_ekrima[i_ekrima];
                    data_ekrima[i_ekrima] = data_ekrima[i_ekrima + 1];
                    data_ekrima[i_ekrima + 1] = x_ekrima;
                }

                i_ekrima++;
            }

            cout << "Tahap " << k_ekrima + 1 << " : ";
            tampilData_ekrima();

            k_ekrima++;
        }
    }
};

int main()
{
    BubbleSort_ekrima bs_ekrima;

    cout << "====================================" << endl;
    cout << "     PROGRAM BUBBLE SORT            " << endl;
    cout << "         ASCENDING ORDER            " << endl;
    cout << "====================================" << endl;

    bs_ekrima.inputData_ekrima();

    cout << endl;
    cout << "Data Sebelum Diurutkan : ";
    bs_ekrima.tampilData_ekrima();

    cout << endl;
    cout << "Proses Bubble Sort..." << endl;

    bs_ekrima.bubbleSortAscending_ekrima();

    cout << endl;
    cout << "Data Setelah Diurutkan : ";
    bs_ekrima.tampilData_ekrima();

    cout << "====================================" << endl;

    cin.get();
}