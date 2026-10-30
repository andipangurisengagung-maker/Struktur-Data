#include <iostream>
#include <stdexcept>

using namespace std;

class StackArray {
private:
    static constexpr int CAP = 5; // Kapasitas maksimum 5 elemen
    int a[CAP];
    int t = -1;                   // Kosong: top = -1

public:
    // Memeriksa apakah stack kosong
    bool empty() const { 
        return t == -1; 
    }

    // Operasi Push: Menambahkan elemen ke TOP dengan input pengguna
    void push(int x) {
        if (t == CAP - 1) {
            throw overflow_error("❌ Error: Stack Overflow! Kapasitas penuh (maksimal 5 elemen), tidak bisa push.");
        }
        a[++t] = x;
        cout << "✅ Berhasil memasukkan angka " << x << " ke dalam stack. (Posisi TOP: index " << t << ")\n";
    }

    // Operasi Pop: Menghapus elemen di TOP
    void pop() {
        if (empty()) {
            throw underflow_error("❌ Error: Stack Underflow! Stack kosong, tidak ada data yang bisa di-pop.");
        }
        cout << "✅ Berhasil menghapus elemen teratas (" << a[t] << ").\n";
        --t;
    }

    // Operasi Top: Membaca elemen di TOP tanpa menghapusnya
    int top() const {
        if (empty()) {
            throw underflow_error("❌ Error: Stack Underflow! Stack kosong, tidak ada elemen di TOP.");
        }
        return a[t];
    }

    // Fungsi untuk menampilkan seluruh isi stack dari TOP ke bawah
    void display() const {
        if (empty()) {
            cout << "ℹ️ Stack saat ini dalam keadaan kosong.\n";
            return;
        }
        cout << "\n--- ISI STACK (Dari TOP ke Bawah) ---\n";
        for (int i = t; i >= 0; --i) {
            cout << "  Index [" << i << "] : " << a[i];
            if (i == t) cout << " <--- TOP";
            cout << "\n";
        }
        cout << "------------------------------------\n";
    }
};

int main() {
    StackArray s;
    int pilihan, nilai;

    do {
        cout << "\n=====================================\n";
        cout << "    MENU INTERAKTIF STACK (CAP: 5)\n";
        cout << "=====================================\n";
        cout << "1. Push (Tambah Angka)\n";
        cout << "2. Pop (Hapus Angka Teratas)\n";
        cout << "3. Top (Lihat Angka Teratas)\n";
        cout << "4. Tampilkan Seluruh Stack\n";
        cout << "5. Keluar Program\n";
        cout << "-------------------------------------\n";
        cout << "Silakan pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka yang ingin di-push: ";
                cin >> nilai;
                try {
                    s.push(nilai);
                } catch (const exception& e) {
                    cout << e.what() << "\n";
                }
                break;

            case 2:
                try {
                    s.pop();
                } catch (const exception& e) {
                    cout << e.what() << "\n";
                }
                break;

            case 3:
                try {
                    cout << "📌 Nilai di TOP saat ini adalah: " << s.top() << "\n";
                } catch (const exception& e) {
                    cout << e.what() << "\n";
                }
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Keluar dari program. Terima kasih!\n";
                break;

            default:
                cout << "⚠️ Pilihan tidak valid! Masukkan angka 1 sampai 5.\n";
        }
    } while (pilihan != 5);

    return 0;
}