#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    int nim;
    string nama;
public:
    mahasiswa();                             // Constructor default
    mahasiswa(int);                          // Constructor dengan parameter int
    mahasiswa(string);                       // Constructor dengan parameter string
    mahasiswa(int iNim, string iNama);       // Constructor dengan parameter int dan string
    void cetak();                            // Method untuk mencetak data
};

mahasiswa::mahasiswa() {
    nim = 0;
    nama = "";
}

mahasiswa::mahasiswa(int iNim) {
    nim = iNim;
}

mahasiswa::mahasiswa(string iNama) {
    nama = iNama;
}