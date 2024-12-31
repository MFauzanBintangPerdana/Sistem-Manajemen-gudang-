#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Barang {
    int id;
    string nama;
    int jumlah;
};

class Gudang {
private:
    vector<Barang> daftarBarang;
    int idCounter = 1;

public:
    void tambahBarang(const string& nama, int jumlah) {
        Barang barangBaru = {idCounter++, nama, jumlah};
        daftarBarang.push_back(barangBaru);
        cout << "Barang berhasil ditambahkan: " << nama << " (" << jumlah << ")\n";
    }

    void tampilkanBarang() const {
        if (daftarBarang.empty()) {
            cout << "Gudang kosong.\n";
            return;
        }

        cout << "Daftar Barang di Gudang:\n";
        for (const auto& barang : daftarBarang) {
            cout << "ID: " << barang.id << " | Nama: " << barang.nama << " | Jumlah: " << barang.jumlah << "\n";
        }
    }

    void hapusBarang(int id) {
        for (auto it = daftarBarang.begin(); it != daftarBarang.end(); ++it) {
            if (it->id == id) {
                cout << "Barang " << it->nama << " berhasil dihapus.\n";
                daftarBarang.erase(it);
                return;
            }
        }
        cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
    }

    void ubahJumlahBarang(int id, int jumlahBaru) {
        for (auto& barang : daftarBarang) {
            if (barang.id == id) {
                barang.jumlah = jumlahBaru;
                cout << "Jumlah barang " << barang.nama << " berhasil diubah menjadi " << jumlahBaru << ".\n";
                return;
            }
        }
        cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
    }
};

int main() {
    Gudang gudang;
    int pilihan;

    do {
        cout << "\nSistem Manajemen Gudang:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Ubah Jumlah Barang\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama;
                int jumlah;
                cout << "Masukkan nama barang: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan jumlah barang: ";
                cin >> jumlah;
                gudang.tambahBarang(nama, jumlah);
                break;
            }
            case 2:
                gudang.tampilkanBarang();
                break;
            case 3: {
                int id;
                cout << "Masukkan ID barang yang akan dihapus: ";
                cin >> id;
                gudang.hapusBarang(id);
                break;
            }
            case 4: {
                int id, jumlahBaru;
                cout << "Masukkan ID barang: ";
                cin >> id;
                cout << "Masukkan jumlah baru: ";
                cin >> jumlahBaru;
                gudang.ubahJumlahBarang(id, jumlahBaru);
                break;
            }
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
