#include <iostream>
using namespace std;

// Menambahkan class angka untuk menyimpan array dinamis dan menampilkan isinya
class angka {
private:
    int *arr;
    int panjang;
public:
    angka(int);    // Constructor: mengatur panjang dan alokasi array
    ~angka();      // Destructor: dealokasi array dan memberi pesan
    void cetakData();  // Fungsi untuk mencetak isi array
    void isiData();    // Fungsi untuk mengisi array dari input
};
// Definisi member function constructor
angka::angka(int i) { // Constructor
    panjang = i;
    arr = new int[i];     // Alokasi memori array
    isiData();            // Memanggil fungsi input data
}
