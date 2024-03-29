# include <iostream>
using namespace std;

int main(){
    int angka [2][2];
    int *px;

    px= &angka [0][0];
    cout << "Value pada array angka : " << endl;
    for(int i = 0;  i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "Masukkan nilai dari array angka =  [" << i << "] [" << j <<"] : ";
            cin >> angka [i][j];
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "Alamat pada angka [" << i << "] [" << j <<"] :  " << px << endl;
            px++;
        }
    }
}
