#include <iostream>

using namespace std;

struct mahasiswa
{
    string npm;
    string nama;
    string alamat;
    float ipk;
}mhs;

int main ()
{
    cout << "input"<<endl;
    cout << "Masukan NPM \t\t : ";
    cin >> mhs.npm;
    cout << "Masukkan Nama \t\t : ";
    cin >> mhs.nama;
    cout << "Masukkan alamat \t : ";
    cin >> mhs.alamat;
    cout << "Masukkan Nilai IPK \t : ";
    cin >> mhs.ipk;

    cout << endl <<"Output"<<endl;
    cout << "NPM mahasiswa \t\t : "<<mhs.npm<< endl;
    cout << "Nama mahasiswa \t\t : "<<mhs.nama<< endl;
    cout << "Alamat mahasiswa \t : "<<mhs.alamat<< endl;
    cout << "IPK Mahasiswa \t\t : "<<mhs.ipk<< endl;

    return 0;
}
