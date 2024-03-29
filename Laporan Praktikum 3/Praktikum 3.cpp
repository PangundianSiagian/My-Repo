#include <iostream>
using namespace std;

struct Nilai {//Struct Penilaian
    float absen;
    float tugas;
    float UTS;
    float UAS;
    float akhir;
    char predikat;
};
struct Mahasiswa{//Struct biodata mahasiswa
    string npm;
    string nama;
    Nilai nilaiMhs;
} mhs[20];

int jmlh = 0;//Variabel untuk menyatakan bahwa variabel jmlh = 0

void masukkanData(int *jmlh);//Fungsi yang akan digunakan untuk memasukan data baru
void tampilkanData(int *ind);//Fungsi untuk menampilkan data mahasiswa
void editData(string *cariNpm);//Fungsi untuk memperbaharui/edit data Mahasiswa
void hapusData(string *cariNpm);//Fungsi untuk menghapus data mahasiswa
void tampilkanMenu();//Fungsi Yang digunakan Pada opsi Menu
void predikatNilai(int *ind, float nilaiAkhir);//Fungsi yang digunakan untuk Penilaian Predikat
float masukkanNilai(float nilai);//Fungsi Yang digunakan untuk penilaian

int main(){

    int opsi;//Variabel untuk memilih Opsi
    string cariNpm;//digunalkan untuk mencari Npm ketika opsi Penghapusan data atau mengedit

    while (opsi != 5){//Perulangan jika angka dari opsi tidak ada pada opsi
        tampilkanMenu();
        cin >> opsi;

        //Switch case untuk Pemilihan Opsi
        switch (opsi){
        case 1:

            masukkanData(&jmlh);//digunakan untuk memasukan data mahasiswa
            jmlh++;
            break;
        case 2:
            for (int j = 0; j < jmlh; j++){//Perulangan apabila data tidak ada maka akan kembali ke opsi awal
                tampilkanData(&j);
            }
            break;
        case 3:
            cout << "\nMasukkan NPM Mahasiswa Untuk Mengedit Data\n= ";
            cin >> cariNpm;
            editData(&cariNpm);//digunkan ketika ingin mengubah data dan yang digunakan untuk mencari data adalah NPM (pointer pada NPM)
            break;
        case 4:
            cout << "\nMasukkan NPM Mahasiswa Untuk Menghapus Data\n= ";
            cin >> cariNpm;
            hapusData(&cariNpm);//digunkan ketika ingin menghapus data dan yang digunakan untuk mencari data adalah NPM (pointer pada NPM)
            jmlh--;//Maka data berkurang 1
            break;
        case 5:
            cout << "\nTerima Kasih Dan Datang Kembali Jika Perlu YAA :V\n";//Opsi 5 yaitu Keluar
            break;

        default:
            cout << "\nPilihan Anda Tidak Di Temukan\n";//ditampilkan jika angka tidak ada pada opsi
            break;
        }
    }
    return 0;
}

//Fungsi Yang digunakan Pada opsi Menu
void tampilkanMenu(){
    cout << "\nSELAMAT DATANG PADA PROGRAM PERHITUNGAN NILAI IP MAHASISWA\n";
    cout << "\nMenu Yang Disajikan\n\n";
    cout << "1. Masukkan Data Mahasiswa\n";
    cout << "2. Tampilkan Data Mahasiswa\n";
    cout << "3. Edit Data Mahasiswa\n";
    cout << "4. Hapus Data Mahasiswa\n";
    cout << "5. Keluar";
    cout << "\n\nMasukkan Angka Untuk Opsi Yang Akan Dipilih = ";
}
//Fungsi Yang digunakan untuk penilaian
float masukkanNilai(float nilai){
    //Perulangan jika nilai yang dimasukkan kurang dari 0 maka akan di ulang sampai lebih dari 0
    do {
        cin >> nilai;
        if (nilai > 100 || nilai < 0){
            cout << "Besar Nilai yang Anda Masukkan Salah.\nSilahkan masukkan ulang: ";
        }
    } while (nilai > 100 || nilai < 0);
    return nilai;
}
//Fungsi yang digunakan untuk Penilaian Predikat
void predikatNilai(int *ind, float nilaiAkhir){
    if (nilaiAkhir > 80){//jika nilai mahasiswa lebih dari 80 maka Predikat A
        mhs[*ind].nilaiMhs.predikat = 'A';
    } else if (nilaiAkhir > 70){//jika nilai mahasiswa lebih dari 70 maka Predikat B
        mhs[*ind].nilaiMhs.predikat = 'B';
    } else if (nilaiAkhir > 60){//jika nilai mahasiswa lebih dari 60 maka Predikat c
        mhs[*ind].nilaiMhs.predikat = 'C';
    } else {//jika kurang dari 60 Maka Predikat E
        mhs[*ind].nilaiMhs.predikat = 'E';
    }
}
//Fungsi yang akan digunakan untuk memasukan data baru
void masukkanData(int *jmlh){
    cout << "\nMasukkan Data Mahasiswa\n\n";
    cout << "Masukkan NPM: ";
    cin >> mhs[*jmlh].npm;//data pada struct untuk menampilkan data  lalu pointer pada variabel jmlh untuk berapa data yang ada pada array
    cout << "Masukkan Nama: ";
    cin.ignore();//ignore digunakan untuk nama yang mempunyai lebih dari 2 kata(Spasi)
    getline(cin, mhs[*jmlh].nama);
    cout << "Masukkan Nilai Absen: ";
    mhs[*jmlh].nilaiMhs.absen = masukkanNilai(mhs[*jmlh].nilaiMhs.absen);//struct mahasiswa,lalu pointer pada jmlh,nilai mahasiswa,absen pada sturct nilai
    cout << "Masukkan Nilai Tugas: ";
    mhs[*jmlh].nilaiMhs.tugas = masukkanNilai(mhs[*jmlh].nilaiMhs.tugas);
    cout << "Masukkan Nilai UTS: ";
    mhs[*jmlh].nilaiMhs.UTS = masukkanNilai(mhs[*jmlh].nilaiMhs.UTS);
    cout << "Masukkan Nilai UAS: ";
    mhs[*jmlh].nilaiMhs.UAS = masukkanNilai(mhs[*jmlh].nilaiMhs.UAS);

    //Perhitungan untuk menentukan nilai Akhir
    mhs[*jmlh].nilaiMhs.akhir = 0.1*mhs[*jmlh].nilaiMhs.absen + 0.2*mhs[*jmlh].nilaiMhs.tugas + 0.3*mhs[*jmlh].nilaiMhs.UTS + 0.4*mhs[*jmlh].nilaiMhs.UAS;
    //Perhitungan untuk menentukan nilai Akhir
    predikatNilai(jmlh, mhs[*jmlh].nilaiMhs.akhir);
}
//Fungsi untuk menampilkan data mahasiswa
void tampilkanData(int *ind){
        cout << "\nData Mahasiswa ke-" << *ind+1 << endl;//data mahasiswa di tampilkan dan + 1 untuk setiap data lainnya
        cout << "Nama: " << mhs[*ind].nama << endl;//struct mahasiswa dan pointer berguna untuk memanggil data mahasiswa 1 misalkan dan seterusnya untuk menampilkan nama
        cout << "NPM: " << mhs[*ind].npm << endl;
        cout << "Nilai Mahasiswa ke-" << *ind+1 << endl;//struct penilaian ditampilkan dan + untuk setiap data lainnya
        cout << "Nilai Absen: " << mhs[*ind].nilaiMhs.absen << endl;//struct penilaian dan pointer berguna untuk memanggil data mahasiswa 1 misalkan dan seterusnya untuk menampilkan nilai absen
        cout << "Nilai Tugas: " << mhs[*ind].nilaiMhs.tugas << endl;
        cout << "Nilai UTS: " << mhs[*ind].nilaiMhs.UTS << endl;
        cout << "Nilai UAS: " << mhs[*ind].nilaiMhs.UAS << endl;
        //lalu variabel nilai akhir di panggil untuk menampilkan nilai akhir dan memberikan predikat menggunakan pointer
        cout << "Nilai Akhir Adalah = " << mhs[*ind].nilaiMhs.akhir << " Mahasiswa Mendapatkan Predikat " << mhs[*ind].nilaiMhs.predikat << endl;
}
//Fungsi untuk memperbaharui/edit data Mahasiswa
void editData(string *cariNpm){
    int pilihEdit;//variabel untuk opsi memperbarui data
    for (int j = 0; j < jmlh; j++){//perulangan
        if (mhs[j].npm == *cariNpm){
            tampilkanData(&j);

            cout << "\nEdit Data Mahasiswa\n";
            cout << "1. Nama\n";
            cout << "2. NPM\n";
            cout << "3. Nilai Absen\n";
            cout << "4. Nilai Tugas\n";
            cout << "5. Nilai UTS\n";
            cout << "6. Nilai UAS\n";
            cout << "Masukkan Angka Untuk Mengubah Data = ";
            cin >> pilihEdit;

            //swich case untuk opsi mengubah data
            switch (pilihEdit){
            case 1:
                //mengubah nama
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, mhs[j].nama);
                break;
            case 2:
                //mengubah NPM
                cout << "Masukkan NPM: ";
                cin >> mhs[j].npm;
                break;
            case 3:
                //mengubah nilai absen
                cout << "Masukkan Nilai Absen: ";
                mhs[j].nilaiMhs.absen = masukkanNilai(mhs[j].nilaiMhs.absen);

                mhs[j].nilaiMhs.akhir = 0.1*mhs[j].nilaiMhs.absen + 0.2*mhs[j].nilaiMhs.tugas + 0.3*mhs[j].nilaiMhs.UTS + 0.4*mhs[j].nilaiMhs.UAS;

                predikatNilai(&j, mhs[j].nilaiMhs.akhir);
                break;
            case 4:
                //mengubah nilai tugas
                cout << "Masukkan Nilai Tugas: ";
                mhs[j].nilaiMhs.tugas = masukkanNilai(mhs[j].nilaiMhs.tugas);

                mhs[j].nilaiMhs.akhir = 0.1*mhs[j].nilaiMhs.absen + 0.2*mhs[j].nilaiMhs.tugas + 0.3*mhs[j].nilaiMhs.UTS + 0.4*mhs[j].nilaiMhs.UAS;

                predikatNilai(&j, mhs[j].nilaiMhs.akhir);

                break;
            case 5:
                //mengubah nilai UTS
                cout << "Masukkan Nilai UTS: ";
                mhs[j].nilaiMhs.UTS = masukkanNilai(mhs[j].nilaiMhs.UTS);

                mhs[j].nilaiMhs.akhir = 0.1*mhs[j].nilaiMhs.absen + 0.2*mhs[j].nilaiMhs.tugas + 0.3*mhs[j].nilaiMhs.UTS + 0.4*mhs[j].nilaiMhs.UAS;

                predikatNilai(&j, mhs[j].nilaiMhs.akhir);

                break;
            case 6:
                //mengubah nilai UAS
                cout << "Masukkan Nilai UAS: ";
                mhs[j].nilaiMhs.UAS = masukkanNilai(mhs[j].nilaiMhs.UAS);

                mhs[j].nilaiMhs.akhir = 0.1*mhs[j].nilaiMhs.absen + 0.2*mhs[j].nilaiMhs.tugas + 0.3*mhs[j].nilaiMhs.UTS + 0.4*mhs[j].nilaiMhs.UAS;

                predikatNilai(&j, mhs[j].nilaiMhs.akhir);
                break;
            default:
                //Jika angka tidak ada pada opsi
                cout << "Pilihan Anda Salah.";
                break;
            }
            break;
                //Jika Npm tidak Ada pada Data
        } else if (mhs[j].npm != *cariNpm && j+1 == jmlh){
            cout << "Data Tidak Ada\n\n";
        }
    }
}
//Fungsi untuk menghapus data mahasiswa
void hapusData(string *cariNpm){
    for (int j = 0; j < jmlh; j++){//perulangan
        if (mhs[j].npm == *cariNpm){//jika struct data mahasiswa dan npm ditemukan data akan dihapus
            for (int k = j; k < jmlh; k++){
                mhs[k] = mhs[k+1];
            }
            break;
        } else if (mhs[j].npm != *cariNpm && j+1 == jmlh){
            cout << "Data Tidak ada\n\n";
        }
    }
}
