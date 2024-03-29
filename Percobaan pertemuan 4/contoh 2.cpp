#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct dataKtp{
    char nama [50];
    char alamat [50];
    char golonganDarah[2];
    dataKtp *next, *prev;
};
dataKtp *awal=NULL, *akhir=NULL, *bantu, *baru;

void inputDatadepan() {
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama\t\t: ";
    cin >> baru->nama;
    cout << "Alamat\t\t: ";
    cin >> baru->alamat;
    cout << "Golongan darah: ";
    cin >> baru->golonganDarah;
    if (awal == NULL){
        awal = akhir = baru;
    }
    else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
    system ("cls");
}
void inputDatabelakang() {
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama\t\t: ";
    cin >> baru->nama;
    cout << "Alamat\t\t: ";
    cin >> baru->alamat;
    cout << "Golongan darah: ";
    cin >> baru->golonganDarah;
    if (awal == NULL){
        awal = akhir = baru;
    }
    else {
        akhir->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }
    system ("cls");
}
void outputData (){
    bantu=awal;
    while (bantu != NULL){
        cout << "Nama\t\t: "<<bantu->nama <<endl;
        cout << "Alamat\t\t: "<<bantu->alamat <<endl;
        cout << "Golongan Darah : "<<bantu->golonganDarah <<endl;
    }

}

int main()
{
    int pilihan;
    do {
        cout << "-------------DOUBLE LINKED LIST-------------\n";
        cout << "Pilih Menu : \n";
        cout << "1. Input data di depan\n";
        cout << "2. Input data di belakang\n";
        cout << "3. Output data\n";
        cout << "4. EXIT\n";
        cout << "Pilihan Menu : ";
        cin >> pilihan;
        switch(pilihan){
        case 1 :
            inputDatadepan();
            break;
        case 2 :
            inputDatabelakang();
            break;
        case 3 :
            if (baru == NULL){
                    cout << "Data Masih KOsong !\n";
            }else {
            outputData();
        }
        break;
        default:
            cout << "--------EXIT-----------";
            break;
        }
    }while (pilihan <= 3);
    getch();
}


