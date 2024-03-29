#include <iostream>

using namespace std;

int main() {

int x [10] = {1,2,3,4,5,6,7,8,9,10};
int i;
int min = 1000; //asumsi paling minimum
int maks = -1000; //asumsi paling maksimum

for (i =0; i < 10; i++){
    if(x[i] > maks)
    {
        maks = x [i];
    }
    if(x[i] < min)
    {
        min = x [i];
    }
}
 cout<<"Nilai maksimum : "<<maks<<endl;
 cout<<"Nilai minimum : "<<min<<endl;

return 0;
}




