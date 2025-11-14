#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
using namespace std;
int opsi;

bool login(int &nim);
int menugenap(int &opsigenap);
int menuganjil(int &opsiganjil);
bool teskabisat(int &thn);
int jmldigit(long &angka);
float rptousd(float &rp);
float usdtorp(float &usd);
bool cekkel(int &num1, int &num2);
float BMI(float &bb, float &tb);

int main() {
	bool tes = false;
	int nim = 0;
	char ulang,nimulang;
	
	do{
		do{
			cout<<"Masukan NIM : "; cin>>nim;
			if (cin.fail()) {
				login(nim);
				} else {
					tes = login(nim);
					}
			
			if(tes && nim > 0){
				cout<<"Berhasil login dengan NIM "<<nim<<".\n";
				cin.ignore(30,'\n');
				break;
				}
				
		} while(!tes || nim <= 0);
		
		cout<<"Apa nim nya mau diubah (y/n) : "; cin>>nimulang;
		cout<<endl;
		cin.ignore(30,'\n');
		
		while(nimulang != 'y' && nimulang != 'Y' && nimulang != 'n' && nimulang != 'N'){
			cout<<"Masukan pilihan (y/n) yang benar : "; cin>>nimulang;
			}
				
		}while(nimulang == 'Y' || nimulang == 'y');	
			
		do{
			if(nim % 2 == 0){
				menugenap(opsi);
				} else {
					menuganjil(opsi);
					}		

			switch(opsi){
				case 1: {
					int tahun;
					
					do{
						system("cls");
						cout<<"=== Cek Tahun Kabisat ===\n";
						cout<<"Masukkan tahun: "; cin>>tahun;
						
						if(cin.fail()){
							cout<<"Masukan yang benar dong!\n";
							cin.clear();
							cin.ignore(30,'\n');
							}
						
						if (teskabisat(tahun)){
							cout<<tahun<<" adalah tahun kabisat.\n";
							} else {
								cout<<tahun<<" bukan tahun kabisat.\n";
								}
							
							cout<<"Apakah anda ingin mengulang cek tahun kabisat (y/n) : "; cin>>ulang;
							cin.ignore(30,'\n');
							
							while(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N'){
								cout<<"Masukan pilihan (y/n) yang benar : "; cin>>ulang;
								cin.ignore(30,'\n');
								}
						
						}while(ulang == 'Y' || ulang == 'y');
					break;
				}
				
				case 2: {
					long nomor;
					
					do{
						system("cls");
						cout<<"=== Menu Jumlah Digit ===\n";
						cout<<"Masukkan bilangan : "; cin>>nomor;
						cout<<"Jumlah digit : "<<jmldigit(nomor)<<"\n";
						
						if(cin.fail()){
							cout<<"Masukan yang benar dong!\n";
							cin.clear();
							cin.ignore(30,'\n');
							}
						
						cout<<"Apakah anda ingin mengulang cek jumlah digit (y/n) : "; cin>>ulang;
						cin.ignore(30, '\n');
						}while(ulang == 'Y' || ulang == 'y');
					break;
				}
				
				case 3: {
					cout<<fixed<<setprecision(0);
					float Rp, USD;
					int pilih;
					 
					do{
						system("cls");
						cout<<"\n=== Menu Konversi Uang ===";
						cout<<"\n1. Konversi Rp to USD";
						cout<<"\n2. Konversi USD to Rp";
						cout<<"\nOpsi : "; cin>>pilih;
						
						if (cin.fail()) {
							cout<<"Input tidak valid! Masukkan hanya angka (1/2).\n";
							cin.clear();
							cin.ignore(30, '\n');
							}
						
						switch(pilih){
							case 1 :{
								cout<<"Masukkan jumlah uang (Rp) : "; cin>>Rp;
								if (Rp < 0) {
								cout<<"Input tidak valid! Masukan jumlah uang yang lebih besar dari 0!\n";
								}else {
									cout<<"Hasil konversi ke USD: "<<rptousd(Rp)<<"\n";
									}
									break;
								}
							case 2 :{							
								cout<<"Masukkan jumlah uang (USD) : "; cin>>USD;
								if (USD < 0){
									cout<<"Input tidak valid! Masukan jumlah uang yang lebih besar dari 0!\n";
									}else {
										cout<<"Hasil konversi ke USD: "<<usdtorp(USD)<<"\n";
										}
										break;
								}
							default :{
								cout<<"Opsi menu konversi tidak valid.\n";
								cin.ignore(30,'\n');
								break;
								}
							}
						
						cout<<"Apakah anda ingin mengulang konversi (y/n) : "; cin>>ulang;
						cin.ignore(30, '\n');
						}while(ulang == 'Y' || ulang == 'y');
					break;
				}
				
				case 4: {
					int bila, bilb;
					
					do{
						system("cls");
						cout<<"=== Menu Cek Kelipatan ===\n";
						cout<<"Masukkan dua bilangan (A & B): "; cin>>bila; cout<<"&"; cin>>bilb;
						if (bilb == 0){
							cout<<"Tidak bisa membagi dengan nol!\n";
							}else if (cekkel(bila, bilb)){
								cout<<bila<<" adalah kelipatan dari "<<bilb<<".\n";
								}else{
									cout<<bila<<" bukan kelipatan dari "<<bilb<<".\n";
									}
								
						cout<<"Apakah anda ingin mengulang cek kelipatan (y/n) : "; cin>>ulang;
						cin.ignore(30, '\n');
						}while(ulang == 'Y' || ulang == 'y');	
					break;
				}
				
				case 5: {
					float b, t;
					
					do{
						system("cls");
						cout<<"=== Menu BMI ===\n";
						cout<<"Masukkan berat (kg): "; cin>>b;
						cout<<"Masukkan tinggi (m): "; cin>>t;
						if ( b <= 0 || t <= 0) {
							cout<<"Input tidak valid! Berat dan tinggi harus lebih besar dari nol.\n";
							break;
							}
							
						float a = BMI(b, t);
						cout<<"BMI Anda: "<<a;
						if (a < 18.5){
							cout<<"Kurus\n";
							}else if (a >= 18.5 && a < 24.9){
								cout<<"Normal\n";
								}else if (a >= 25 && a < 29.9){
									cout<<"Gemuk\n";
									}else{
										cout<<"Obesitas\n";
										}

							cout<<"Apakah anda ingin mengulang cek BMI (y/n) : "; cin>>ulang;
							cin.ignore(30, '\n');
							}while(ulang == 'Y' || ulang == 'y');
					break;
				}
				
				case 6: {
					cout<<"Terima kasih telah menggunakan program ini!\n";
					return 0;
				}
				
				default: {
					cout<<"Opsi tidak ada, silakan coba lagi.\n";
					break;
				}
			}
			
				cout<<"Apakah anda ingin kembali ke menu utama (y/n) : "; cin>>ulang;
				system("cls");
				
				while(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N'){
					cout<<"Masukan pilihan (y/n) yang benar : "; cin>>ulang;
				}
				
			}while(ulang == 'Y' || ulang == 'y');
	
	cout<<"Terima kasih telah menggunakan program ini!\n";
	return 0;
}


bool login(int &nim){
	if(cin.fail()){
		cout<<"NIM yang kamu masukan tidak valid, mungkin berupa huruf atau simbol.\n";
		cout<<"Ulangi dan masukan nilai NIM yang benar!\n\n";
		cin.clear();
		cin.ignore(30, '\n');
		return false;
	}
	if (nim <= 0) {
		cout<<"NIM harus lebih besar dari 0.\n";
		return false;
	}
	return true;
}

int menugenap(int &opsigenap){
    bool v = false;
    
    while (!v) {
        cout<<"\n=== Menu NIM Genap ===";
        cout<<"\n2. Hitung Jumlah Digit";
        cout<<"\n4. Kelipatan dari Bilangan";
        cout<<"\n5. Hitung BMI";
        cout<<"\n6. Keluar";
        cout<<"\nOpsi (2/4/5/6) :"; cin>>opsigenap;

        if (cin.fail()) {
            cout<<"Input tidak valid! Masukkan hanya angka yang sesuai dengan menu.\n";
            cin.clear();
            cin.ignore(30, '\n');
        }
        
        if(opsigenap == 2 || opsigenap == 4 ||opsigenap == 5 || opsigenap == 6){
			v = true;
			}
        
        if (!v) {
            cout<<"Peringatan! Opsi "<<opsigenap<<" tidak tersedia untuk NIM Genap. Masukkan opsi yang benar (2, 4, 5, atau 6)!\n";
        }
    }

    return opsigenap;
}

int menuganjil(int &opsiganjil){
    bool v = false;
    
    while (!v) {
        cout<<"\n=== Menu NIM Ganjil ===";
        cout<<"\n1. Tahun Kabisat";
        cout<<"\n3. Konversi Mata Uang";
        cout<<"\n5. Hitung BMI";
        cout<<"\n6. Keluar";
        cout<<"\nOpsi (1/3/5/6) :"; cin>>opsiganjil;
        
        if (cin.fail()) {
            cout<<"Input tidak valid! Masukkan hanya angka yang sesuai dengan menu.\n";
            cin.clear();
            cin.ignore(30, '\n');
        }

        if( opsiganjil == 1 || opsiganjil == 3 ||opsiganjil == 5 || opsiganjil == 6){
			v = true;
			}
        
        if (!v) {
            cout<<"Peringatan! Opsi "<<opsiganjil<<" tidak tersedia untuk NIM Ganjil. Masukkan opsi yang benar (1, 3, 5, atau 6)!\n";
        }
    }
    
    return opsiganjil;
}

bool teskabisat(int &thn) {
	return (thn % 4 == 0 && thn % 100 != 0) || (thn % 400 == 0);
}

int jmldigit(long &n) {
	if (n < 0) n = -n;
	if (n == 0) return 1;
	int jml = 0;
	while (n > 0) {
		jml++;
		n /= 10;
	}
	return jml;
}

float rptousd(float &rp) {
	return rp / 15000.0;
}

float usdtorp(float &usd) {
	return usd * 15000.0;
}

bool cekkel(int &num1, int &num2) {
	if (num2 == 0) return false;
	return num1 % num2 == 0;
}

float BMI(float &bb, float &tb) {
	if (tb <= 0) return 0.0;
	return bb / (tb * tb);
}
