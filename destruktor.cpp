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
angka::~angka() { // Destructor
    cout << endl;
    cetakData();               // Cetak isi array sebelum dihapus
    delete[] arr;              // Menghapus array
    cout << "Alamat Array Sudah Dilepaskan" << endl;
}

void angka::cetakData() {
    for (int i = 1; i <= panjang; i++) {   // Mengakses array dari indeks 1
        cout << i << " = " << arr[i] << endl;
    }
}

void angka::isiData() {
    for (int i = 1; i <= panjang; i++) {   // Mengisi array dari indeks 1
        cout << i << " = "; cin >> arr[i];
    }
    cout << endl;
}