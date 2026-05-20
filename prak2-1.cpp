#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	int ekky;
	char *namaKu,NM[4]= {'E','K','K','Y'};
	cout << " Nama Ku " << endl;
	cout << "~~~~~~~~~~~~~" << endl;
	for(ekky=0; ekky<4; ekky++)
	{
		namaKu = &NM [ekky];
		cout << "  " << *namaKu << endl;
	}
	cin.get();
}