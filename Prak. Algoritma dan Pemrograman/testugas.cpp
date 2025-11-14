#include <iostream>
#include <limits>
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
	char ulang;
	bool tes = false;
	int nim;
	
	do{
		cout<<"masukan nim : "; cin>>nim;
		tes = login(nim);
		
		if(tes == true){
			cout<<"berhasil";
			break;
			}
		}while(!tes);
		
		do{
		if(nim%2 == 0){
			menugenap(opsi);
			}else{
				menuganjil(opsi);
				}

			switch(opsi){
				case 1:{
					
					int tahun;
					cout<<"Masukkan tahun: "; cin>>tahun;
					
					if (teskabisat(tahun)){
						cout<<tahun<<" adalah tahun kabisat.\n";
						}else{
							cout<<tahun<<" bukan tahun kabisat.\n";
							}
					break;
					}
				case 2:{					
				    long nomor;
					cout<<"Masukkan bilangan: "; cin>>nomor;
					cout<<"Jumlah digit: "<<jmldigit(nomor)<<"\n";
					break;
					}
				case 3:{
					float Rp,USD;
					int pilih;
					do{
				    cout<<"\n=== Menu Konversi Uang ===";
					cout<<"\n1. Konversi Rp to USD";
					cout<<"\n2. Konversi USD to Rp";
					cout<<"opsi : "; cin>>pilih;
					
					if (pilih == 1){
						cout<<"Masukkan jumlah uang (Rp) : "; cin>>Rp;
						if (Rp < 0) {
							cout<<"Input tidak valid! Masukan jumlah uang yang lebih besar dari 0!\n";
							}else{
								cout<<"Hasil konversi ke USD: "<<rptousd(Rp)<<"\n";
								}
							

						
						
						}else if (pilih == 2){
							cout<<"Masukkan jumlah uang (USD) : "; cin>>USD;
							if (USD < 0){
							cout<<"Input tidak valid! Masukan jumlah uang yang lebih besar dari 0!\n";
							}else{
								cout<<"Hasil konversi ke USD: "<<usdtorp(USD)<<"\n";
								}
							}
												cout<<"Apakah anda ingin mengulang ingin mengkonversi Rp ke USD lagi (y/n ):"; cin>>ulang;
					
					if((ulang == !'y' || ulang == !'Y') && (ulang == !'n' || ulang == !'N')){
						cout<<"Masukan pilihan (y/n)!\n";
						}
						}while(ulang == 'Y' || ulang == 'y');	
					break;
					}
				case 4:{
					            int bilA, bilB;
            cout<<"Masukkan dua bilangan (A B): ";
            cin>>bilA>>bilB;
            if (bilB == 0)
                cout<<"Tidak bisa membagi dengan nol!\n";
            else if (cekkel(bilA, bilB))
                cout<<bilA<<" adalah kelipatan dari "<<bilB<<".\n";
            else
                cout<<bilA<<" bukan kelipatan dari "<<bilB<<".\n";
					break;
					}
				case 5:{
					            float berat, tinggi;
            cout<<"Masukkan berat (kg): ";
            cin>>berat;
            cout<<"Masukkan tinggi (m): ";
            cin>>tinggi;
            if (berat <= 0 || tinggi <= 0) {
                cout<<"Input tidak valid!\n";
            }
            float indeks = BMI(berat, tinggi);
            cout<<"BMI Anda: "<<indeks;
            if (indeks < 18.5f)
                cout<<" (Kurus)\n";
            else if (indeks < 24.9f)
                cout<<" (Normal)\n";
            else if (indeks < 29.9f)
                cout<<" (Gemuk)\n";
            else
                cout<<" (Obesitas)\n";
					break;
					}
				case 6:{
					            cout<<"Terima kasih telah menggunakan program ini.\n";
					break;
					}
				default :{
					cout<<"Menu tidak tersedia!\n";
					break;
					}
					
			
				}
			cout<<"Apakah anda ingin mengulang ingin mengkonversi Rp ke USD lagi (y/n ):"; cin>>ulang;
					
					if((ulang == !'y' || ulang == !'Y') && (ulang == !'n' || ulang == !'N')){
						cout<<"Masukan pilihan (y/n)!\n";
						}
						}while(ulang == 'Y' || ulang == 'y');
			
							
			return 0;
}


bool login(int &nim){
	if(cin.fail()){
		cout<<"Nim yang kamu masukan tidak valid mungkin berupa huruf atau simbol"<<endl;
		cout<<"ulangi dan masukan nilai yang benar!"<<endl<<endl;
		cin.clear();
		cin.ignore(25,'\n');
		return false;
		}
return true;
}

int menugenap(int &opsigenap){
	
const int valid_opsi[] = {2, 4, 5, 6};
    const int num_valid_opsi = 4; // Jumlah opsi yang valid
    bool opsi_valid = false;
    
    while (!opsi_valid) { // Loop akan berlanjut sampai opsi valid dimasukkan
        cout << "\n=== Menu NIM Genap ===";
        cout << "\n2. Hitung Jumlah Digit";
        cout << "\n4. Kelipatan dari Bilangan";
        cout << "\n5. Hitung BMI";
        cout << "\n6. Keluar";
        cout << "\nOpsiuw :"; 

        if (!(cin >> opsigenap)) {
            cout << "Input tidak valid! Masukkan hanya angka yang sesuai dengan menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        // Cek apakah opsi yang dimasukkan ada dalam array valid_opsi
        for (int i = 0; i < num_valid_opsi; ++i) {
            if (opsigenap == valid_opsi[i]) {
                opsi_valid = true;
                break;
            }
        }
        
        if (!opsi_valid) {
            cout << "Peringatan! Opsi " << opsigenap << " tidak tersedia untuk NIM Genap. Masukkan opsi yang benar (2, 4, 5, atau 6)!\n";
        }
    }

    return opsigenap;    
}

int menuganjil(int &opsiganjil){
    bool v = false;
    
    while (!v) {
        cout << "\n=== Menu NIM Ganjil ===";
        cout << "\n1. Tahun Kabisat";
        cout << "\n3. Konversi Mata Uang";
        cout << "\n5. Hitung BMI";
        cout << "\n6. Keluar";
        cout << "\nOpsiaw :"; 
        
        if (cin.fail()) {
            cout << "Input tidak valid! Masukkan hanya angka yang sesuai dengan menu.\n";
            cin.clear();
            cin.ignore(25,'\n');
            continue;
            }
        
        if (opsiganjil == 1 || opsiganjil == 3 || opsiganjil == 5 || opsiganjil == 6) {
			v = true;
			}
        
        if (!v) {
            cout << "Peringatan! Opsi " << opsiganjil << " tidak tersedia untuk NIM Ganjil. Masukkan opsi yang benar (1, 3, 5, atau 6)!\n";
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
    return rp / 15000.0f;
}

float usdtorp(float &usd) {
    return usd * 15000.0f;
}

bool cekkel(int &num1, int &num2) {
    if (num2 == 0) return false;
    return num1 % num2 == 0;
}

float BMI(float &bb, float &tb) {
    return bb / (tb * tb);
}
