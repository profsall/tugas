#include <iostream>
#include <string>
using namespace std;

int main() {
    int pilihan, ayam, angka, i;
    char lanjut;
    string digit;

    do {
        cout << "Menu :";
        cout << "\n1. Anak ayam";
        cout << "\n2. Bilangan ganjil";
        cout << "\n3. Jumlah digit";
        cout << "\n4. Exit";
        cout << "\nPilih nomor berapa : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                do {
                    cout << "\nMasukkan jumlah anak ayam: "; cin >> ayam;

                    if (ayam <= 0) {
                        cout << "Jumlah ayam harus lebih dari 0." << endl;
                        }

                    cout << "Anak ayam ada " << ayam << endl;

                    for (i = ayam - 1; i > 0; --i) {
                        cout << "Mati satu tinggal " << i << endl;
                    }

                    cout << "Mati satu sisa induknya" << endl;
                    cout << "\nApakah anda ingin lanjut (y/n): "; cin >> lanjut;
                } while (lanjut == 'y' || lanjut == 'Y');
                break;

            case 2:
                do {
                    cout << "\nMasukkan angka akhir: "; cin >> angka;

                    if (angka <= 1) {
                        cout << "Angka akhir harus lebih besar dari 1." << endl;
                        }

                    for (i = 1; i <= angka; ++i) {
                        if (i % 2 != 0) {
                            cout << i << " ";
                        }
                    }
                    cout << endl;
                    cout << "\nApakah anda ingin lanjut (y/n): "; cin >> lanjut;
                } while (lanjut == 'y' || lanjut == 'Y');
                break;

            case 3:
               
                do {
                    cout << "\nMasukkan angka: "; cin >> digit;
                    cout << "\nAda " << digit.length() << " digit" << endl;
                    cout << "\nApakah anda ingin lanjut (y/n): "; cin >> lanjut;
                } while (lanjut == 'y' || lanjut == 'Y'); 
                break;

            case 4:
                cout << "\nTerima kasih! Program selesai." << endl;
                return 0;

            default:
                do {
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    cout << "\nApakah anda ingin lanjut (y/n): "; cin >> lanjut;
                } while (lanjut == 'y' || lanjut == 'Y');
                break;
        }
    } while (pilihan != 4);
}
