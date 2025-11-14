#include <iostream>
using namespace std;

int main() {
    int jumlahBuku = 2,hargaBuku = 50000;
    int jumlahPulpen = 3,hargaPulpen = 5000;

    int totalHargaBuku = jumlahBuku * hargaBuku;

    int totalHargaPulpen = jumlahPulpen * hargaPulpen;

    int totalBelanja = totalHargaBuku + totalHargaPulpen;
    
    cout << "Harga buku: Rp" << hargaBuku << endl;
    cout << "Jumlah buku: Rp" << jumlahBuku << endl << endl;
    cout << "Harga pulpen: Rp" << hargaPulpen << endl;
    cout << "Jumlah pulpen: Rp" << jumlahPulpen << endl << endl;
  
    cout << "Total harga buku: Rp" << totalHargaBuku << endl;
    cout << "Total harga pulpen: Rp" << totalHargaPulpen << endl;
    cout << "Total keseluruhan belanja: Rp" << totalBelanja << endl;

    return 0;
}
