// buatlah sebuah program dengan pendekatam OOP yang implmentasikan friend class, friend function dan pointer

#include <iostream>
#include <string>
using namespace std;

//// Deklarasi awal kelas-kelas yang diperlukan
class Dosen;
class Staff;
class Universitas;

// Class Mahasiswa menyimpan informasi seperti nama, NIM, dan nilai.
// Atribut nilai bersifat privat dan tidak boleh diubah langsung oleh objek lain, kecuali oleh dosen yang mengajar.
class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai; // Bersifat privat dan hanya bisa diubah oleh Dosen

public:
    Mahasiswa(string nama, string NIM, float nilai) 
        : nama(nama), NIM(NIM), nilai(nilai) {}

    void display() {
        cout << "Mahasiswa: " << nama << " (" << NIM << "), Nilai: " << nilai << endl;
    }
};