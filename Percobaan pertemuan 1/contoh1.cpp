#include <iostream>

using namespace std;

int main() {

int x=5;
int *y;
y = &x;

cout<<"Nilai Variabel x :"<<x<<endl;
cout<<"Alamat Variabel x :" <<&x<<endl;
cout<<"Nilai Yang Tersimpan Dalam Variabel y :"<<*y<<endl;

return 0;
}
