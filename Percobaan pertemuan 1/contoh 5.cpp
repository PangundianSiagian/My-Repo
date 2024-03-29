#include <iostream>

using namespace std;

int main()
{

    int x [10] = {1,2,3,4,5,6,7,8,9,10};
    int i,dicari;
    bool ketemu = false;

    cout<<"Bilangan yang ingin dicari : ";
    cin>>dicari;

    for (i =0; i < 10; i++)
    {
        if(x[i] == dicari)
        {
            ketemu = true;
            cout<<"Bilangan ditentukan di elemen : "<<i<<endl;
        }
    }
    if(ketemu)
    {
       cout<<"bilangan ditemukan!"<<endl;
    }else {
    cout<<"Bilangan tersebut tidak ditemukan!"<<endl;
    }

return 0;
}





