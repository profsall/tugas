#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaLengkap;
    string nim;
    string plug;

    cout << "Masukkan Nama Lengkap : ";
    getline(cin, namaLengkap);

    cout << "Masukkan NIM : ";
    cin >> nim;

    cout << "Masukkan Plug : ";
    cin >> plug;
    cin.ignore();

    cout << "\n";
    cout << "Nama : " << namaLengkap << endl;
    cout << "NIM  : " << nim << endl;
    cout << "Plug : " << plug << endl;
    
    return 0;
}
	
