#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
	
    const string USERNAME_BENAR = "isal";
    const string PASSWORD_BENAR = "021";
    const int MAX_LOGIN = 3;
    const int KAPASITAS_MAKSIMUM = 10; 
    int percobaan_login = 0;
    string input_username;
    string input_password;
    bool login_sukses = false;
    int pilihan_menu;
    bool kembali_ke_menu = true;
    int total_kendaraan_saat_ini = 0;
    
    do {
        cout << "=== LOGIN SISTEM PARKIR ===" << endl;         cout << "Username: ";
        cin >> input_username;
        cout << "Password: ";
        cin >> input_password;

        if (input_username == USERNAME_BENAR && input_password == PASSWORD_BENAR) {
            cout << "Login berhasil!" << endl;
            login_sukses = true;
        } else {
            percobaan_login++;
            if (percobaan_login < MAX_LOGIN) {
                cout << "Username atau Password salah. Tersisa " << MAX_LOGIN - percobaan_login << " kali percobaan." << endl;
            }
        }
    } while (!login_sukses && percobaan_login < MAX_LOGIN);

    if (!login_sukses) {
        cout << "Login Gagal, program Berhenti" << endl;
        return 0;
    }

    do {
        cout << "\n==== SISTEM PARKIRAN ====" << endl;
        cout << "1. Hitung Biaya Parkir" << endl;
        cout << "2. Cek Kapasitas Parkir" << endl;
        cout << "3. Daftar Nomor Parkir Ganjil-Genap" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";

        if (!(cin >> pilihan_menu)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan_menu = -1;
        }

        switch (pilihan_menu) {
            case 1: {
                int lama_parkir;
                long total_biaya = 0;
                int jam_saat_ini = 1;

                cout << "Masukkan lama parkir (jam): ";
                if (!(cin >> lama_parkir) || lama_parkir <= 0) {
                    cout << "Input jam tidak valid." << endl;
                    break;
                }

                while (jam_saat_ini <= lama_parkir) {
                    if (jam_saat_ini == 1) {
                        total_biaya += 5000; 
                    } else {
                        total_biaya += 2000;
                    }
                    jam_saat_ini++;
                }

                cout << "Total biaya parkir: Rp " << total_biaya << endl;
                break;
            }

            case 2: {
                int kendaraan_masuk;

                do {
                    cout << "Masukkan jumlah kendaraan yang masuk (0 untuk selesai): ";
                    if (!(cin >> kendaraan_masuk)) {
                         cout << "Input tidak valid." << endl;
                         cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(), '\n');
                         continue;
                    }

                    if (kendaraan_masuk > 0) {
                        if (total_kendaraan_saat_ini + kendaraan_masuk > KAPASITAS_MAKSIMUM) {
                            cout << "Parkiran penuh! Tidak bisa menambah kendaraan lagi." << endl;
                            total_kendaraan_saat_ini = KAPASITAS_MAKSIMUM;
                            kendaraan_masuk = 0;
                        } else {
                            total_kendaraan_saat_ini += kendaraan_masuk;
                        }
                        cout << "Total kendaraan saat ini: " << total_kendaraan_saat_ini << endl;
                    }
                } while (kendaraan_masuk != 0);

                cout << "Total akhir kendaraan di parkiran: " << total_kendaraan_saat_ini << endl;
                break;
            }

            case 3: {
                int jumlah_kendaraan;
                string ganjil = "";
                string genap = "";

                cout << "Masukkan jumlah kendaraan di parkiran: ";
                if (!(cin >> jumlah_kendaraan) || jumlah_kendaraan < 0) {
                    cout << "Input jumlah kendaraan tidak valid." << endl;
                    for (int i = 1; i <= jumlah_kendaraan; ++i) {
                    if (i % 2 != 0) {
                        ganjil += to_string(i) + " "; 
                    } else {
                        genap += to_string(i) + " "; 
                    }
                }

                cout << "Nomor parkir ganjil: " << ganjil << endl;
                cout << "Nomor parkir genap: " << genap << endl;
                break;
            }

            case 4: {
                kembali_ke_menu = false;
                cout << "Terima kasih telah menggunakan Sistem Parkir LoopingLand Mall." << endl;
                break;
            }

            default:
                cout << "Pilihan menu tidak valid. Silakan coba lagi." << endl;
                break;
        }
        
        if (kembali_ke_menu && pilihan_menu >= 1 && pilihan_menu <= 3) {
            char ulangi;
            cout << "Kembali ke menu utama? (y/n): "; [cite: 32]
            cin >> ulangi;
            if (ulangi == 'n' || ulangi == 'N') {
                kembali_ke_menu = false;
                cout << "Terima kasih telah menggunakan Sistem Parkir LoopingLand Mall." << endl;
            }
        } else if (pilihan_menu == 4) {
            kembali_ke_menu = false;
        }
    } while (kembali_ke_menu);

   
  }
 return 0;
}





					if (pilih == 1){
						cout<<"Masukkan jumlah uang (Rp) : "; cin>>Rp;
						if (Rp < 0) {
							cout<<"Input tidak valid! Masukan jumlah uang yang lebih besar dari 0!\n";
							}else {
								cout<<"Hasil konversi ke USD: "<<rptousd(Rp)<<"\n";
								}
						}else if (pilih == 2){
							cout<<"Masukkan jumlah uang (USD) : "; cin>>USD;
							if (USD < 0){
								cout<<"Input tidak valid! Masukan jumlah uang yang lebih besar dari 0!\n";
								} else {
									cout<<"Hasil konversi ke USD: "<<usdtorp(USD)<<"\n";
									}
							}else {
								cout<<"Opsi menu konversi tidak valid.\n";
								}
