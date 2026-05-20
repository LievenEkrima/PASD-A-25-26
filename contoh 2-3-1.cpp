//Deklarasi struktur data nilai MK_FP
typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
}   nilaiMK;

//Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
	nilaiMK komtainer;
	alamatelm nect;
}   elemen;

//Deklarasi struktur stack
typedef struct {
    elemen* top;
}   stack;

//Deklarasi fungsi membuat stack kosong 
void buatSTkosong(stack *s)  {
     (*s) .top = NULL;
}

//Deklarasi fungsi membuat stack kosong
int iskosong (stack s) {
    bool hasil = false;

    if(s.top == NULL)  {
      hasil  = true;
	}
    return hasil;
}

//Deklarasi fungsi menghitung jumlah elemen stack
int jmelemen(stack s) {
   int hasil =0;
   
   if(s.top !=NULL0 {
	   //kondisi stack tidak kosong 
	   elemen *bantu;
	   //inisialisai
	   bantu =bantu -> next;
   }
}
  return hasil;

//Deklarasi fungsi memasukkan elemen ke dalam stack 
void push(string npm, string nama_mhs, double nilai, stack *s) {
	elemen *info;
	info = new elemen;
	info -> kontainer.npm =npm;
	info -> kontainer.nama_mhs = nama_mhs;
	info -> kontainer.nilai = nilai;
	
	if ( (*s).top == NULL) {
		cout << "stack penuh" << endl;
		//jika stack kosong
		info -> next = NULL;
	}
	else {
		//jika stack tidak kosong
		info -> next = (*s) .top;
		(*s) .top = info;
		info=NULL;
	}
	
//Deklarasi fungsi mengeluarkan elemen keluar stack 
void pop(stack *s) {
	if( (*s) .top !+ NULL) {
		//jika list bukan stack kosong
		elemen *hapus = (*s) .top;
		
		if(jmelemen (*s) == 1) {
			
		