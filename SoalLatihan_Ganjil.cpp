// buatlah sebuah program dengan pendekatam OOP yang implmentasikan friend class, friend function dan pointer

#include <iostream>        //untuk input/output (fungsi cin, cout).
#include <string>         // Agar bisa menggunakan tipe data string.
using namespace std;     //Menghindari penulisan std:: secara berulang

// class yamg akan dideklarasikan
class Dosen;
class Staff;
class Universitas;

// Class Mahasiswa menyimpan informasi seperti nama, NIM, dan nilai. 
// Atribut nilai bersifat privat dan tidak boleh diubah langsung oleh objek lain, kecuali oleh dosen yang mengajar.

class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai;  

    //SET DATA untuk mengisi atau mengatur nilai dari atribut-atribut privat 
public:  
    void setData(string pNama, string pNIM, float pNilai = 0) {
        nama = pNama;
        NIM = pNIM;
        nilai = pNilai;
    }

    //pNama → parameter

    //nama → atribut class

    //nama (atribut class) = pNama (parameter fungsi)


    void display() {
        cout << "Mahasiswa: " << nama << " (" << NIM << "), Nilai: " << nilai << endl;
    }

   // Oleh karena itu, class Dosen harus dideklarasikan sebagai friend class dari Mahasiswa,
   // sehingga dosen dapat mengakses dan memberikan nilai menggunakan method seperti beriNilai(Mahasiswa* m, float nilai).

    friend class Dosen;  
};

// Class Dosen menyimpan atribut pribadi seperti nama, NIDN, pangkat, dan gaji, dengan pangkat dan gaji bersifat privat.
class Dosen {
private:
    string nama;       
    string NIDN;
    string pangkat;    
    float gaji;

public:
    void setData(string pNama, string pNIDN, string pPangkat, float pGaji) {
        nama = pNama;
        NIDN = pNIDN;
        pangkat = pPangkat;
        gaji = pGaji;
    }
    
    void display() {
        cout << "Dosen: " << nama << " (" << NIDN << "), Pangkat: " << pangkat << endl;
    }

    void beriNilai(Mahasiswa* m, float nilai) {                // metode beriNilai dengan pointer Mahasiswa
        m->nilai = nilai;                                     // dapat mengubah nilai karena friend class Mahasiswa
        cout << nama << " memberi nilai " << nilai << " kepada " << m->nama << endl;
    }

    // Pangkat dosen hanya dapat diubah oleh Staff, sehingga class Staff harus dijadikan friend class oleh Dosen.
    // Namun, berbeda dari akses gaji, pihak Universitas tidak dijadikan friend class secara langsung,
    // melainkan hanya dapat mengakses informasi gaji dosen melalui sebuah fungsi friend yang dideklarasikan secara eksplisit di dalam class Dosen.
    // Fungsi tersebut akan menerima objek Dosen* sebagai argumen dan dideklarasikan sebagai friend dari class Dosen,
    // tetapi didefinisikan di luar sebagai bagian dari class Universitas.

    friend class Staff;  
    friend float lihatGajiDosen(Dosen* d);  
    friend string lihatNamaDosen(Dosen* d);  
};

    // Class Staff menyimpan informasi seperti nama, ID staff, dan gaji, dengan gaji bersifat privat.
class Staff {
private:
    string nama;     
    string IDstaff;
    float gaji;      
public:
    void setData(string pNama, string pID, float pGaji) {
        nama = pNama;
        IDstaff = pID;
        gaji = pGaji;
    }
    
    void display() {
        cout << "Staff: " << nama << " (" << IDstaff << ")" << endl;
    }

    // Staff memiliki kemampuan untuk mengubah pangkat dosen melalui pointer menggunakan method ubahPangkat(Dosen* d, string pangkatBaru).
    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;  
        cout << nama << " mengubah pangkat " << d->nama << " menjadi " << pangkatBaru << endl;
    }

    // Sama seperti dosen, data gaji staff tidak bisa diakses langsung oleh class Universitas,
    // tetapi disediakan melalui sebuah fungsi friend bernama lihatGajiStaff(Staff* s) yang dideklarasikan sebagai friend dalam class Staff, dan diimplementasikan dalam class Universitas.
    friend float lihatGajiStaff(Staff* s);  
};

// Implementasi fungsi friend akses gaji dosen (bukan member class Universitas)
float lihatGajiDosen(Dosen* d) {
    return d->gaji;
}

// Implementasi fungsi friend akses gaji staff (bukan member class Universitas)
float lihatGajiStaff(Staff* s) {
    return s->gaji;
}

class Universitas {
public:
    // Universitas TIDAK dijadikan friend class langsung,
    // hanya mengakses gaji dosen melalui fungsi friend yang sudah dideklarasikan
    void infoGajiDosen(Dosen* d) {
        cout << "Gaji " << lihatGajiDosen(d) << ": Rp" << lihatGajiDosen(d) << endl;
    }
    
    // Sama halnya, akses gaji staff melalui fungsi friend lihatGajiStaff
    void infoGajiStaff(Staff* s) {
        cout << "Gaji " << lihatGajiStaff(s) << ": Rp" << lihatGajiStaff(s) << endl;
    }
};

int main()
{
    Mahasiswa mhs;
    mhs.setData("Rossa Kayla", "M12345");
    
    Dosen dosen;
    dosen.setData("Ibu Rachel", "D67890", "Lektor", 10000000);
    
    Staff staff;
    staff.setData("Anggun", "S54321", 5000000);
    
    Universitas univ;
    
    // Dosen memberi nilai mahasiswa
    dosen.beriNilai(&mhs, 95.5);
    
    // Staff mengubah pangkat dosen
    staff.ubahPangkat(&dosen, "Lektor Kepala");
    
    // Menampilkan informasi
    mhs.display();
    dosen.display();
    staff.display();
    
    // Menampilkan informasi gaji
    univ.infoGajiDosen(&dosen);
    univ.infoGajiStaff(&staff);
    
    return 0;
}
