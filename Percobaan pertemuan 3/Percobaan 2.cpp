#include <iostream>
using namespace std;

struct identitasDiri{
    string nama;
    int umur;
};

int main(){

    int jumlah;
    cout << "Masukkan jumlah data: ";
    cin >> jumlah;
    identitasDiri orang[jumlah];

    cout << "input data diri" << endl;
    for (int i = 0; i < jumlah; i++){
        cout << "Orang ke-" << i+1 << endl;
        cout << "Masukkan nama: ";
        cin >> orang[i].nama;
        cout << "Masukkan umur: ";
        cin >> orang[i].umur;
    }

    cout << endl;
    cout << "Output" << endl;
    for (int i = 0; i < jumlah; i++){
        cout << "Orang ke " << i+1 << endl;
        cout << "Nama: " << orang[i].nama << endl;
        cout << "Umur: " << orang[i].umur << endl;
    }


    return 0;
}
