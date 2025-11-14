#include <iostream>
#include <cstdlib> // Untuk system("cls") atau system("clear")

using namespace std;

// Deklarasi array 2D global untuk papan permainan
// Ini adalah "char board[3][3]" yang kita bahas!
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Variabel untuk melacak giliran pemain
char current_player = 'X';

// Deklarasi fungsi-fungsi
void display_board();
bool check_win();
void get_move();

// ==========================================================
// FUNGSI 1: MENAMPILKAN PAPAN
// ==========================================================
void display_board() {
    // Membersihkan layar konsol agar tampilan selalu rapi
    // Di Windows: system("cls"); | Di Linux/Mac: system("clear");
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    
    cout << "\n\t=== TIC-TAC-TOE (NOL-SILANG) C++ ===\n\n";
    cout << "Pemain 1 (X)  -  Pemain 2 (O)\n\n";

    // Loop untuk mencetak isi array 3x3
    for (int i = 0; i < 3; i++) {
        cout << "\t " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) {
            cout << "\t---|---|---" << endl;
        }
    }
    cout << "\n";
}

// ==========================================================
// FUNGSI 2: MEMERIKSA KEMENANGAN
// ==========================================================
// Analoginya: Seorang wasit yang memeriksa papan setiap kali langkah dibuat
bool check_win() {
    // 1. Cek Kemenangan BARIS (Horizontal)
    // Jika elemen pada satu baris (board[i][0], board[i][1], board[i][2]) SAMA
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    // 2. Cek Kemenangan KOLOM (Vertikal)
    // Jika elemen pada satu kolom (board[0][j], board[1][j], board[2][j]) SAMA
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }

    // 3. Cek Kemenangan Diagonal
    // Diagonal Kiri Atas ke Kanan Bawah: board[0][0], board[1][1], board[2][2]
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }

    // Diagonal Kanan Atas ke Kiri Bawah: board[0][2], board[1][1], board[2][0]
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false; // Jika tidak ada pola kemenangan yang ditemukan
}

// ==========================================================
// FUNGSI 3: MENGAMBIL INPUT DAN MEMPERBARUI PAPAN
// ==========================================================
void get_move() {
    int choice;
    cout << "Pemain " << current_player << ", masukkan nomor kotak (1-9): ";
    cin >> choice;

    // Menghitung posisi indeks [baris][kolom] dari input 1-9
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Logika Pintar: Cek validitas langkah
    if (choice >= 1 && choice <= 9) {
        // Cek apakah kotak tersebut masih berupa angka (belum terisi 'X' atau 'O')
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            
            // Kotak valid! Tuliskan simbol pemain saat ini ke papan
            board[row][col] = current_player; 

            // Ganti giliran pemain
            // Analoginya: Setelah melempar dadu, giliran diserahkan ke pemain berikutnya
            if (current_player == 'X') {
                current_player = 'O';
            } else {
                current_player = 'X';
            }
        } else {
            cout << "Pilihan tidak valid. Kotak sudah terisi! Coba lagi.\n";
            // Panggil fungsi lagi agar pemain yang sama mengulang langkah
            get_move(); 
        }
    } else {
        cout << "Pilihan tidak valid. Harap masukkan angka antara 1 dan 9.\n";
        // Panggil fungsi lagi agar pemain yang sama mengulang langkah
        get_move(); 
    }
}

// ==========================================================
// FUNGSI UTAMA: LOGIKA PERMAINAN
// ==========================================================
int main() {
    int turns = 0; // Menghitung jumlah langkah yang sudah dilakukan (maksimal 9)
    bool game_over = false;

    // Loop utama permainan
    while (!game_over) {
        display_board();
        get_move();
        turns++;

        // Cek apakah sudah ada pemenang
        if (check_win()) {
            display_board();
            // Karena giliran sudah diganti di get_move(), pemenang adalah pemain sebelumnya
            char winner = (current_player == 'X') ? 'O' : 'X'; 
            cout << "SELAMAT! Pemain " << winner << " MEMENANGKAN PERMAINAN!\n";
            game_over = true;
        } 
        // Cek apakah papan penuh (Seri/Draw)
        else if (turns == 9) {
            display_board();
            cout << "PERMAINAN BERAKHIR SERI (DRAW)!\n";
            game_over = true;
        }
    }

    // Mengembalikan nilai 0 menandakan program selesai dengan sukses
    return 0;
}