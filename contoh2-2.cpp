#include <iostream>
using namespace std;

struct mahasiswa{
	        char NPM[9];
			char nama[30];
			float ipk;
};
int main(){
	mahasiswa mhs;
	cout<< "nomor pokok mahasiswa  = "; cin>> mhs.NPM;
	cout<< "nama mahasiswa         = "; cin>> mhs.nama;
	cout<< "indek prestasi komulatif = "; cin>> mhs.ipk;
	cout<<endl;
	cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<< "              data anda" << endl;
	cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<< "nomor pokok mahasiswa  = " << mhs.NPM << endl;
	cout<< "nama mahasiswa         = " << mhs.nama << endl;
	cout<< "indek prestasi mahasiswa = " << mhs.ipk << endl;
	cin.get();
}