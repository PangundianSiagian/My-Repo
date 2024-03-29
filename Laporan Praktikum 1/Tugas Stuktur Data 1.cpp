#include <iostream>
using namespace std;

char jh = '0';//variabel ini digunakan untuk menympan suatu abjad apabila muncul secara berurutan dan serupa
char ulang;//variabel ini digunakan untuk menyimpan banyak perulangan ketika sedang mengompresi abjad

void tampilkanHasil (char arr[], int sizeArr);//fungsi ini digunakan untuk menampilkan isi dari array
void pengompresanArray (char arr[], int sizeArr);//fungsi ini digunakan untuk mengompresi array

int main(){

    int sizeArray;//variabel ini digunakan untuk menyimpan ukuran array yang dimasukkan oleh pengguna
    cout << "SELAMAT DATANG DI PROGRAM PENGKOMPRESI NILAI ARRAY  " <<endl;

        //proses pengimputan oleh pengguna
    cout << "\nMasukkan Banyak Karakter Yang Ingin Ditampilkan : ";
    cin >> sizeArray;//memasukkan berapa banyak karakter yang ingin dimasukkan pengguna
    char huruf[sizeArray];//mendeklarasikan array yang sudah dimasukkan oleh pengguna

    for (int d = 0; d < sizeArray; d++){
        cout << "Masukkan Karakter Atau Abjad : ";
        cin >> huruf[d];//pengguna memasukkan abjad apa saja yang ingin di kompresi dan masuk ke dalam array
    }
        //proses pengimputan selesai

    cout << "\nKarakter Yang Anda Masukkan Adalah Sebagai Berikut: ";
    tampilkanHasil(huruf, sizeArray);//menampilkan array yang dimasukkan oleh pengguna

    cout << "\nHasil Dari Perkompresian Dari Karakter-Karakter Yang Di Inputkan Sebagai Berikut : ";
    pengompresanArray(huruf, sizeArray);//menampilkan hasil pengkompresian dari array yang sudah dimasukkan pengguna
    cout << "\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI DATANG LAGI LAIN KALI YAA :)" <<endl;

    return 0;
}
//fungsi ini digunakan untuk menampilkan isi dari array
void tampilkanHasil (char arr[], int sizeArr){
    cout << sizeArr << ", [" ;//menampilkan ukuran array
    for (int ind = 0; ind < sizeArr; ind++){//melakukan perulangan sebanyak ukuran array yang di masukkan oleh pengguna
        if (ind == sizeArr-1){
            cout << "\"" << arr[ind] << "\"";//tampilan abjad terakhir pada array
        }else{
            cout << "\"" << arr[ind] << "\", ";//tampilan yang abjadnya selain abjad terakhir di dalam array
        }
    }
    cout << "]" << endl;
}
//fungsi ini digunakan untuk mengompresi array
void pengompresanArray(char arr[], int sizeArr){

    for(int a = 0; a< sizeArr; a++){//proses penghitungan abjad jika berurut dan serupa

        for (int n = a; n < sizeArr; n++){//perulangan
            if (arr[a] == arr[n]){
                jh++;
            }
            if (arr[n+1] != arr[a]){
                break;
            }
        }

        //penggabungan abjad jika berurut dan serupa
        if (jh > '2'){
            ulang = jh;
            while (ulang > '2'){
                for (int s = a; s< sizeArr; s++){
                        arr[s+1];
                }
                ulang--;
                sizeArr--;
            }

        }

        if (jh > '1' && arr[a] == arr [a+1]){
            arr[a+1] = jh;
        //jika hasil pengelompokan atau penggabungan berurut dan serupa maka,
        //ubah abjad yang sama tersebut menjadi berapa jumlah abjad tersebut muncul tetapi apabila 1 maka tampilkan abjad saja
        }
        jh = '0';//reset jumlah abjad untuk abjad selanjutnya pada array
    }

    tampilkanHasil(arr, sizeArr);//menampilkan hasil pengompresian pada array
}
