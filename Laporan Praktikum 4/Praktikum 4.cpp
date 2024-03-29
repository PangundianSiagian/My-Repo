#include <iostream>
using namespace std;

struct Angka{//Struct angka
    int data;
    Angka *sebelum, *next;
};
    Angka *head = NULL,//pointer
    *nextData = NULL,//pointer
    *temp,*printPtr;//pointer

void tampilanAngkaSebelum(){//Fungsi untuk menampilkan angka sebelum di ubah
    printPtr = head;//menjadikan head menjadi value dari printPtr
    while (printPtr != NULL){//Perulangan
        cout << printPtr->data << " ";//menampilkan data sebelum di ubah
        printPtr = printPtr->next;
    }
}

void tampilanDataSebelum(int angka){//Fungsi data
    Angka *temp = new Angka;
    temp->sebelum = NULL;
    temp->data = angka;
    temp->next = NULL;

    if (head == NULL){//perulangan jika
        head = nextData = temp;
    } else {//maka
        nextData->next = temp;//menukar variabel
        temp->sebelum = nextData;
        nextData = temp;
    }
}

void balikAngka(){//fungsi untuk membalikan angka
    while (head->next != NULL ){
        head = head->next;
    }
}

void tampilanAkhir(){//fungsi menampilkan tampilan akhir atau sesudah di ubah
    printPtr = head;
    while (printPtr != NULL){
        cout << printPtr->data << " ";//menampilkan angka setelah di ubah
        printPtr = printPtr->sebelum;
    }
}

int main(){
    //isi data sebelum di ubah
    tampilanDataSebelum(5);
    tampilanDataSebelum(4);
    tampilanDataSebelum(3);
    tampilanDataSebelum(2);
    tampilanDataSebelum(1);

    cout << "Original Linked List : ";
    tampilanAngkaSebelum();//menampilkan data sebelum di ubah
    cout << "\nReversed Linked List : ";
    balikAngka();//menampilkan data sesudah di ubah
    tampilanAkhir();
    cout<< endl;

    return 0;
}
