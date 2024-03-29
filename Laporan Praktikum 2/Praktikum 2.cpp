#include <iostream>

using namespace std;

int main(){
    int i, j, m, n;//Variabel yang akan digunakan dalam program
    int matriks[10][10];// dimisalkan sebagai penampung angka

    //Proses Pengimputan
    cout << "Selamat Datang Pada Program Mentranspose Matriks"<< endl;
    cout << "\nMasukkan Jumlah Baris Pada Matriks : ";
    cin >> m;//Pengunaan memasukkan berapa jumlah baris yang ingin dimasukkan pada matriks
    cout << "Masukkan Jumlah Kolom Pada Matriks : ";
    cin >> n;//Pengunaan memasukkan berapa jumlah kolom yang ingin dimasukkan pada matriks

    // Proses mentranspose
    cout << "\nMasukkan Elemen Matriks : \n";
    //Pengguna memasukkan elemen apa saja yang ingin di transpose pada matriks
    for( i = 0; i < m; i++){//Perulangan untuk memasukkan angka yang dimasukan pada matriks
        for ( j = 0; j < n; j++){
            cin >> matriks [i][j];//Nilai di simpan dalam array
        }
    }
    //Perulangan mentranspose matriks
    for( i = 0; i < m; i++){
        for ( j = i+1; j < n; j++){
                int temp = matriks[i][j];// variabel penyimpanan sementara untuk menyimpan matriks yang akan di tukar
                matriks[i][j] = matriks[j][i];
                matriks[j][i]= temp;
        }
    }

    // Menampilkan hasil Transpose
    cout << "\nHasil Transpose Matriks adalah :\n";
    for( i = 0; i < m; i++){//Perulangan untuk menampilkan hasil matriks yang telah di transpose
        for ( j = 0; j < m; j++){
        cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
    // program telah berakhir
    cout << "\nTerimakasih Telah Menggunakan Program Ini Jika Diperlukan Datang Kembali Yaa :v"<< endl;

    return 0;
}
