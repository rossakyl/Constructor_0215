#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    static int nim;     // Static member: disimpan bersama kelas, bukan objek
public:
    int id;
    string nama;

    void setID();       // Fungsi untuk mengatur ID dari nim
    void printAll();    // Menampilkan ID dan nama mahasiswa

    static void setNim(int pNim) { nim = pNim; } // Mengatur nilai nim awal (static)
    static int getNim() { return nim; }          // Mengambil nilai nim (static)

    mahasiswa(string pnama) : nama(pnama) { setID(); } // Constructor dengan parameter nama
};

int mahasiswa::nim = 0;

void mahasiswa::setID() { // Fungsi untuk memberikan nilai ID unik ke setiap objek mahasiswa
    id = ++nim; // ID akan selalu bertambah seiring objek baru dibuat
}

void mahasiswa::printAll() { // Fungsi untuk menampilkan informasi mahasiswa
    cout << "ID     = " << id << endl;
    cout << "Nama   = " << nama << endl;
    cout << endl;
}

int main() {
    mahasiswa mhs1("Sri Dadi");           // ID: 1
    mahasiswa mhs2("Budi Jatmiko");       // ID: 2
    mahasiswa::setNim(9); // Nim di-reset ke 9 (ID berikutnya jadi 10)
    mahasiswa mhs3("Andi Janu");          // ID: 10
    mahasiswa mhs4("Joko Wahono");        // ID: 11

    mhs1.printAll(); // Menampilkan semua data mahasiswa
    mhs2.printAll();
    mhs3.printAll();
    mhs4.printAll();

    cout << "akses dari luar object = " << mahasiswa::getNim() << endl; // Menampilkan nilai static nim terakhir dari luar objek

    return 0;
}