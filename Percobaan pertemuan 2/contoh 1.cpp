#include <iostream>
using namespace std;

int main(){
    int matrixA[2][2];
    int matrixB[2][2];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
        cout << "Masukkan nilai dari matrix a = [" << i << "] [ " << j << " ] : ";
        cin >> matrixA [i] [j];
        }
    }
cout << " Matrix a : " << endl;
for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

 for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
        cout << "Masukkan nilai dari matrix b = [" << i << "] [ " << j << " ] : ";
        cin >> matrixB [i] [j];
        }
    }

cout << " Matrix b : " << endl;
for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    int matrixC[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
                matrixC [i][j] = matrixA [i][j] + matrixB [i][j];
                cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

}

