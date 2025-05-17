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

