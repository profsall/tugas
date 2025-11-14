#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Array 2D: [5 tugas][3 kolom]
    // Kolom 0 = Nilai Teori, Kolom 1 = Nilai Praktek, Kolom 2 = Total (akan dihitung)
    int tugas[5][3] = {
        {50, 42, 0},
        {55, 45, 0},
        {40, 20, 0},
        {50, 49, 0},
        {60, 33, 0}
    };

    // Hitung total untuk setiap tugas
    for (int i = 0; i < 5; i++) {
        tugas[i][2] = tugas[i][0] + tugas[i][1];
    }

    // Tampilkan header tabel
    cout << "==================================================" << endl;
    cout << "No   Tugas     Nilai Teori   Nilai Praktek   Total" << endl;
    cout << "==================================================" << endl;

    // Tampilkan data
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << setw(4)
             << "Tugas " << setw(8) << (i + 1)
             << setw(13) << tugas[i][0]
             << setw(15) << tugas[i][1]
             << tugas[i][2] << endl;
    }

    return 0;
}
