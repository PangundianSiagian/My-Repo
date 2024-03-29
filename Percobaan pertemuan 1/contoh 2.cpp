#include <iostream>

using namespace std;

int main() {

int x;
int *px;
int **ppx;

x = 170;
px = &x;
ppx = &px;
cout<<"Nilai x :"<<x<<endl;
cout<<"Nilai px :" <<*px<<endl;
cout<<"Nilai ppx :"<<**ppx<<endl;

return 0;
}

