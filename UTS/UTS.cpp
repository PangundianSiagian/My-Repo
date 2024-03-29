#include <iostream>
using namespace std;

// Struct untuk data siswa
struct siswa { //Digunakan Untuk memasukkan Nama dan juga nilai siswa
    string nama;
    string nilai;
};

// Node untuk linked list
struct Node { // Digunakan Untuk  laporan data siswa yang telah di input
    siswa data;
    Node* next;
};

// Fungsi untuk menambahkan node baru ke linked list
void tambahNode(Node*& head, siswa newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* help = head;
        while (help->next != NULL) {
            help = help->next;
        }
        help->next = newNode;
    }
}

// Fungsi untuk menampilkan linked list
void menampilkanLinkedList(Node* head) {
    Node* help = head;
    while (help != NULL) {
        cout << "Nama: " << help->data.nama << ", Nilai: " << help->data.nilai << endl;
        help = help->next;
    }
}

//Tampilan Utama
int main() {
    int jumlahData;
    cout << "----Selamat Datang Di Program Perangkingan SD RIANG GEMBIRA----" << endl;
    cout << "----Program Ini Akan Membantu Anda Menentukan Peringkat--------\n" << endl;
    cout << "Silahkan Masukkan Berapa Jumlah Siswa/i : ";
    cin >> jumlahData;//Pengguna Diminta Memasukkan Jumlah Siswa
    cout << "===============================================================" <<endl;
    cout << "|                   HARAP PERHATIAN!!!!                       |" << endl;
    cout << "|Jika Nilai SISWA Adalah Desimal,Masukan Nilai Menggunakan(.) |" << endl;
    cout << "|                   Misalnya (95.5)                           |" << endl;
    cout << "===============================================================" << endl;
    siswa* siswaArray = new siswa[jumlahData];//Menyimpan data Siswa dalam Array
    Node* linkedListHead = NULL;

    // Input data
    for (int i = 0; i < jumlahData; ++i) {
        cout << "\nMasukkan Nama Siswa/i Ke-" << i+1 << ": ";
        cin.ignore();
        getline(cin, siswaArray[i].nama);//Memasukkan Nama siswa
        cout << "Masukkan Nilai Akhir Siswa/i Ke-" << i+1 << ": ";
        cin >> siswaArray[i].nilai;//Memasukkan Nilai Siswa

        // Setelah nama dan nilai di masukkan data akan ditambahkan ke linked list
        tambahNode(linkedListHead, siswaArray[i]);
    }
    //Perulangan Untuk Menentukkan dan membandingkan Perangkingan
     for (int i = 0; i < jumlahData - 1; ++i) {
        for (int j = 0; j < jumlahData - i - 1; ++j) {
            if (siswaArray[j].nilai < siswaArray[j+1].nilai) {
                // menukar posisi
                siswa temp = siswaArray[j];
                siswaArray[j] = siswaArray[j+1];
                siswaArray[j+1] = temp;
            }
        }
    }
    // menampilkan hasil pengurutan
    cout << "\nBerikut Perangkingan Yang Di Dapat Adalah :\n";
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Ranking ke-" << i+1 << ": Diperoleh Ananda : " << siswaArray[i].nama << ", Dengan Nilai: " << siswaArray[i].nilai << endl;
    }

    // Menampilkan Laporan Data siswa yang di masukkan menggunakan linked list
    cout << "\nLaporan Data Yang di Input Menggunakan linked list :\n";
    menampilkanLinkedList(linkedListHead);

    //Program Telah Usai
    cout << "\nSelamat Program Telah Selesai Silahkan Kembali Lagi Jika Program Di Butuhkan Yaa :V " <<endl;

    return 0;
}
