#include <iostream>
#include <string>
using namespace std;

int main() {
    int pilihanRasa, pilihanTopping, pilihanUkuran, jumlahPesanan;
    char member;
    double hargaRasa, hargaTopping, hargaUkuran, totalBayar, totalBelanja;
    string namaRasa, namaTopping, namaUkuran;
    int diskon;
    
    cout<<"========================================"<<endl;
    cout<<"    SELAMAT DATANG DI ES KRIM KuCool"<<endl;
    cout<<"========================================"<<endl<<endl;

    cout<<"=== MENU ES KRIM ==="<<endl;
    cout<<"1. Vanilla        Rp 10000"<<endl; 
    cout<<"2. Cokelat        Rp 12000"<<endl;
    cout<<"3. Stroberi       Rp 15000"<<endl;
    cout<<"Pilih rasa (1-3): "; cin>>pilihanRasa;

    switch (pilihanRasa) {
        case 1:
            hargaRasa = 10000;
            namaRasa = "Vanilla";
            break;
        case 2:
            hargaRasa = 12000;
            namaRasa = "Cokelat";
            break;
        case 3:
            hargaRasa = 15000;
            namaRasa = "Stroberi";
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    cout<<"\n=== PILIH TOPPING ==="<<endl;
    cout<<"1. Cokelat Chips  Rp 3000"<<endl;
    cout<<"2. Kacang Almond  Rp 4000"<<endl;
    cout<<"3. Oreo Crumbs    Rp 3500"<<endl;
    cout<<"4. Tanpa topping  Rp 0"<<endl;
    cout<<"Pilih topping (1-4): "; cin>>pilihanTopping;

    switch (pilihanTopping) {
        case 1:
            hargaTopping = 3000;
            namaTopping = "Cokelat Chips";
            break;
        case 2:
            hargaTopping = 4000;
            namaTopping = "Kacang Almond";
            break;
        case 3:
            hargaTopping = 3500;
            namaTopping = "Oreo Crumbs";
            break;
        case 4:
            hargaTopping = 0;
            namaTopping = "Tanpa Topping";
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    cout << "\n=== PILIH UKURAN CUP ===" << endl;
    cout << "1. Small (harga normal)" << endl;
    cout << "2. Medium (+Rp 2.000)" << endl;
    cout << "3. Large (+Rp 5.000)" << endl;
    cout << "Pilih ukuran (1-3): "; cin >> pilihanUkuran;
  
			
    if (pilihanUkuran == 1) {
        hargaUkuran = 0;
        namaUkuran = "Small";
        } else if (pilihanUkuran == 2) {
            hargaUkuran = 2000;
            namaUkuran = "Medium";
            } else if (pilihanUkuran == 3) {
                hargaUkuran = 5000;
                namaUkuran = "Large";
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                    return 0;
                    } 
    
    cout << "\nJumlah pesanan: "; cin >> jumlahPesanan;
    if (jumlahPesanan <= 0) {
        cout << "Jumlah pesanan harus lebih dari 0." << endl;
        return 0;
        }

    cout<<"Apakah anda pelanggan member? (y/n): "; cin>>member;

    totalBelanja = (hargaRasa + hargaTopping + hargaUkuran) * jumlahPesanan;

    if (totalBelanja >= 100000) {
        diskon = 20;
       } else if (totalBelanja >= 50000) {
           diskon = 10;
           } else if (totalBelanja >= 30000) {
               diskon = 5;
               } else {
                   diskon = 0;
                   }

    if (member == 'y' || member == 'Y') {
        diskon += 5;
        }
    
    totalBayar = totalBelanja - (totalBelanja * diskon / 100.0);

    cout << "\n=====   STRUK PEMBELIAN KuCool   =====" << endl;
    cout << "Rasa Es Krim    : " << namaRasa << endl;
    cout << "Topping         : " << namaTopping << endl;
    cout << "Ukuran Cup      : " << namaUkuran << endl;
    cout << "Jumlah Pesanan  : " << jumlahPesanan << endl;
    cout << "Total Belanja   : Rp " << totalBelanja << endl;
    cout << "Diskon          : " << diskon << "%" << endl;
    cout << "Total Bayar     : Rp " << totalBayar << endl;
    cout << "Terima kasih sudah membeli es krim cuy!" << endl;
    return 0;
}
