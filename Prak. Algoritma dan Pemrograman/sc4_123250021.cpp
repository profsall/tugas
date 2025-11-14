#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string nama, pw;
    int cobalogin,n,i,j,a,b,c,maxlogin,pilihan;
    char lanjut;

    cobalogin = 0;
    maxlogin = 3;
    nama = "admin";
    pw = "12345";

    do {
        cout << "Username : ";
        cin >> nama;
        cout << "Password : ";
        cin >> pw;

        if (nama == "admin" || pw == "12345") {
            cout << "Login berhasil" << endl;
            break;
        } else {
            cobalogin++;
            cout << "cobalagi" << endl;
            if(cobalogin == maxlogin){
				return 0;
				}
        }
    } while (cobalogin < maxlogin);
    
	system("cls");

        cout << "Menu" << endl;
        cout << "1. Angka 1" << endl;
        cout << "2. Bintang Garis" << endl;
        cout << "pilih menu (1/2) : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
				do{
                cout << "Masukkan Input angka : "; cin>>n;
                if (n <= 0) {
                    cout<<" \nInput n tidak valid. Kembali ke menu." << endl;
                    break;
                }

                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++) {
                        if (i == 1 || i == n) {
                            cout << j;
                        } else {
                            if (j == i - 1) {
                                cout << 1;
                            } else {
                                cout << j;
                            }
                        }
                    }
                    cout << endl;
                }
                
               cout<<"Apakah mau main lagi (y/n) : "; cin>>lanjut;
			}while(lanjut == 'y' || lanjut == 'Y');
                break;
            }

            case 2:{
				do{
					cout<<"masukan a : "; cin>>a;
					if (a <= 0) {
                    cout<<" \nInput n tidak valid. Kembali ke menu." << endl;
                    break;
                    }
                    
                    for(b=1;b<=a;b++){
						for(c=1;c<=a;c++){
							if(b % 2 != 0){
								if(c % 2 != 0){
									cout<<"*";
									}else{
										cout<<"-";
										}
								}else{
									if(c%2 != 0){
										cout<<"-";
										}else{
											cout<<"*";
											} 
									}
							}
							cout<<endl;
						}
						cout<<"Apakah ingin lanjut main (y/n) : "; cin>>lanjut;
					}while(lanjut == 'y' || lanjut == 'Y');
				}
                break;
            
            default: {
                cout << "Pilihan menu tidak valid." << endl;
                break;
            }
        }
   

    return 0;
}
