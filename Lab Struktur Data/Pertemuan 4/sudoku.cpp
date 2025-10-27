/*
Nama    : M. Ariel Afriza 
NIM     : 241401073
Lab     : Struktur Data 2
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // Bakal nyetak angka di posisi (i, j) plus ada spasinya
            cout << board[i][j] << " ";

            // Tiap 3 kolom, bakal ngasih spasi tambahan biar kotak 3x3 keliatan jelas
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl; // kasih enter abis 9 kolom dicetak 

        // Tiap 3 baris, bakal ngasih enter biar kotak 3x3 keliatan jelas kayak tadi juga
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa baris dan kolom, kalau sama gak boleh muncul lagi
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false; // bakal langsung batal kalau jumpa angka yg sama
        }
    }

    // Periksa sub-kotak 3x3
    int startRow = row - row % 3; // nyari baris awal blok 3x3 nya
    int startCol = col - col % 3; // nyari kolom awalnya
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false; // batal kalau ada angka yg sama di blok 3x3
            }
        }
    }

    return true; // bakal return semua angka yg valid di posisi tersebut
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS
bool solveSudoku(vector<vector<int>>& board) {

    // Cari sel kosong dulu
    int row = -1, col = -1; // buat sel kosong dulu
    bool foundEmpty = false; // penanda buat sel yg kosong

    // loop untuk ngelilingin seluruh papan 9x9 nya
    for(int i = 0; i < 9 && !foundEmpty;i++)
    {
        for(int j = 0; j < 9 && !foundEmpty;j++)
        {
            if(board[i][j] == 0)
            {
                // kalau udah nemu sel kosong, posisinya bakal disimpan
                row = i;
                col = j;
                foundEmpty = true; // penanda bakal dibuah true, biar loopnya berhenti
                break;
            }
        }
    }

    // Kalau gadak sel kosong, berarti solusinya udah jumpa
    if(!foundEmpty)
    {
        return true;
    }

    // Kalau jumpa sel kosong
        // Coba masukkan angka dari 1 - 9
        for(int num = 1; num <= 9; num++)
        {
            if(isValid(board, row, col, num))
            {
                // Masukin angkanya
                board[row][col] = num;

                // lakuin rekursi, kalau berhasil bakal balikin nilai true
                if(solveSudoku(board))
                {
                    return true;
                }

                // Kalau gagal, selnya bakal dikosongin lagi
                board[row][col] = 0;
            }
        }

        // kalau gadak angka yg valid, bakal backtrack (return false)
        return false;
}

int main() {

    // Buat papan sudoku ukuran 9x9, trus angka 0 untuk nandain sel yg harus diisi angka nanti
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    // Kondisi papan awalnya
    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    // Manggil fungsi untuk cari solusinya
    if (solveSudoku(board)) {
        // kalau berhasil, nampilin hasil akhirnya
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        // kalau gagal, nampilin pesan gak ada solusi
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}