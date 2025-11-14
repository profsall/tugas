#include <iostream>
using namespace std;

bool cekTahunKabisat(int thn) {
    return (thn % 4 == 0 && thn % 100 != 0) || (thn % 400 == 0);
}

int hitungJumlahDigit(long long angka) {
    if (angka < 0) angka = -angka;
    if (angka == 0) return 1;
    int jumlah = 0;
    while (angka > 0) {
        jumlah++;
        angka /= 10;
    }
    return jumlah;
}

float rupiahKeUSD(float rp) {
    return rp / 15000.0f;
}

float usdKeRupiah(float usd) {
    return usd * 15000.0f;
}

bool cekKelipatan(int num1, int num2) {
    if (num2 == 0) return false;
    return num1 % num2 == 0;
}

float hitungBMI(float bb, float tb) {
    return bb / (tb * tb);
}

int main() {
    int pilihan;
    do {
        cout<<"Menu:\n1. Tahun Kabisat (NIM ganjil)\n2. Hitung Jumlah Digit (NIM genap)\n3. Konversi Mata Uang (NIM ganjil)\n4. Kelipatan dari Bilangan (NIM genap)\n5. Hitung BMI (SEMUA)\n6. Keluar\nPilih menu: ";
        cin>>pilihan;
        if (pilihan == 1) {
            int masukkanTahun;
            cout<<"Masukkan tahun: ";
            cin>>masukkanTahun;
            if (cekTahunKabisat(masukkanTahun))
                cout<<masukkanTahun<<" adalah tahun kabisat.\n";
            else
                cout<<masukkanTahun<<" bukan tahun kabisat.\n";
        } else if (pilihan == 2) {
            long long nomor;
            cout<<"Masukkan bilangan: ";
            cin>>nomor;
            cout<<"Jumlah digit: "<<hitungJumlahDigit(nomor)<<"\n";
        } else if (pilihan == 3) {
            int pilihJenis;
            cout<<"1. Rupiah ke USD\n2. USD ke Rupiah\nPilih: ";
            cin>>pilihJenis;
            if (pilihJenis == 1) {
                float uangRupiah;
                cout<<"Masukkan jumlah rupiah: ";
                cin>>uangRupiah;
                if (uangRupiah < 0) {
                    cout<<"Input tidak valid!\n";
                    continue;
                }
                cout<<"Hasil konversi ke USD: "<<rupiahKeUSD(uangRupiah)<<"\n";
            } else if (pilihJenis == 2) {
                float uangDolar;
                cout<<"Masukkan jumlah USD: ";
                cin>>uangDolar;
                if (uangDolar < 0) {
                    cout<<"Input tidak valid!\n";
                    continue;
                }
                cout<<"Hasil konversi ke Rupiah: "<<usdKeRupiah(uangDolar)<<"\n";
            } else {
                cout<<"Pilihan tidak valid!\n";
            }
        } else if (pilihan == 4) {
            int bilA, bilB;
            cout<<"Masukkan dua bilangan (A B): ";
            cin>>bilA>>bilB;
            if (bilB == 0)
                cout<<"Tidak bisa membagi dengan nol!\n";
            else if (cekKelipatan(bilA, bilB))
                cout<<bilA<<" adalah kelipatan dari "<<bilB<<".\n";
            else
                cout<<bilA<<" bukan kelipatan dari "<<bilB<<".\n";
        } else if (pilihan == 5) {
            float berat, tinggi;
            cout<<"Masukkan berat (kg): ";
            cin>>berat;
            cout<<"Masukkan tinggi (m): ";
            cin>>tinggi;
            if (berat <= 0 || tinggi <= 0) {
                cout<<"Input tidak valid!\n";
                continue;
            }
            float indeks = hitungBMI(berat, tinggi);
            cout<<"BMI Anda: "<<indeks;
            if (indeks < 18.5f)
                cout<<" (Kurus)\n";
            else if (indeks < 24.9f)
                cout<<" (Normal)\n";
            else if (indeks < 29.9f)
                cout<<" (Gemuk)\n";
            else
                cout<<" (Obesitas)\n";
        } else if (pilihan == 6) {
            cout<<"Terima kasih telah menggunakan program ini.\n";
        } else {
            cout<<"Menu tidak tersedia!\n";
        }
    } while (pilihan != 6);
    return 0;
}
