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

mahasiswa::mahasiswa(int iNim, string iNama) {
    nim = iNim;
    nama = iNama;
}
void mahasiswa::cetak() {  // Method cetak() digunakan untuk menampilkan data nim dan nama dari objek mahasiswa
    cout << endl << "Nim = " << nim << endl;
    cout << "Nama = " << nama << endl;
}

int main() {
    mahasiswa mhs1;                  // Menggunakan constructor default
    mahasiswa mhs2(20);              // Menggunakan constructor dengan int
    mahasiswa mhs3("Indra");         // Menggunakan constructor dengan string
    mahasiswa mhs4(30, "Fauzan");    // Menggunakan constructor dengan int dan string

    mhs1.cetak();
    mhs2.cetak();
    mhs3.cetak();
    mhs4.cetak();

    return 0;
}