
#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int v;
    Node* next;
};

class StackList {
    Node* head = nullptr;

public:
    bool empty() const {
        return !head;
    }

    // Menambahkan data
    void push(int x) {
        head = new Node{x, head};
        cout << "Data berhasil ditambahkan!\n";
    }

    // Menghapus data
    void pop() {
        if (empty()) {
            cout << "Stack masih kosong!\n";
            return;
        }

        Node* old = head;
        cout << "Data yang dihapus: " << head->v << endl;
        head = head->next;
        delete old;
    }

    // Melihat data paling atas
    void top() const {
        if (empty()) {
            cout << "Stack masih kosong!\n";
            return;
        }

        cout << "Data paling atas: " << head->v << endl;
    }

    // Menampilkan semua data
    void tampilkan() const {
        if (empty()) {
            cout << "Stack masih kosong!\n";
            return;
        }

        Node* bantu = head;

        cout << "Isi Stack (Top ke bawah): ";
        while (bantu != nullptr) {
            cout << bantu->v << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }

    // Membersihkan memori
    ~StackList() {
        while (!empty()) {
            Node* old = head;
            head = head->next;
            delete old;
        }
    }
};

int main() {
    StackList s;
    int pilihan, angka;

    do {
        cout << "\n===== PROGRAM STACK LINKED LIST =====\n";
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
                s.top();
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
