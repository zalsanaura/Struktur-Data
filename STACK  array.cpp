
#include <iostream>
using namespace std;

#define MAX 5

class StackArray {
    int data[MAX];
    int topIndex = -1;

public:

    // Memeriksa apakah Stack kosong
    bool empty() {
        return topIndex == -1;
    }

    // Memeriksa apakah Stack penuh
    bool full() {
        return topIndex == MAX - 1;
    }

    // Menambahkan data (Push)
    void push(int angka) {
        if (full()) {
            cout << "Stack penuh! Tidak bisa menambah data.\n";
        } else {
            data[++topIndex] = angka;
            cout << "Data berhasil ditambahkan!\n";
        }
    }

    // Menghapus data (Pop)
    void pop() {
        if (empty()) {
            cout << "Stack kosong! Tidak ada data yang dihapus.\n";
        } else {
            cout << "Data yang dihapus: " << data[topIndex] << endl;
            topIndex--;
        }
    }

    // Melihat data paling atas (Top)
    void lihatTop() {
        if (empty()) {
            cout << "Stack masih kosong!\n";
        } else {
            cout << "Data paling atas: " << data[topIndex] << endl;
        }
    }

    // Menampilkan semua data
    void tampilkan() {
        if (empty()) {
            cout << "Stack masih kosong!\n";
        } else {
            cout << "Isi Stack (Top ke bawah): ";
            for (int i = topIndex; i >= 0; i--) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    StackArray s;
    int pilihan, angka;

    do {
        cout << "\n===== PROGRAM STACK ARRAY =====\n";
        cout << "1. Push (Tambah Data)\n";
        cout << "2. Pop (Hapus Data)\n";
        cout << "3. Top (Lihat Data Teratas)\n";
        cout << "4. Tampilkan Semua Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> angka;
                s.push(angka);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.lihatTop();
                break;

            case 4:
                s.tampilkan();
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilihan != 5);

    return 0;
}
