#include <iostream>
#include <conio.h>
using namespace std;

int main(){

int i,j,matrik[10][10];
float hasilbagi,det,a,b,c,d;


for(i=0;i<=1;i++)
{
        for(j=0;j<=1;j++)
      {
        cout<<"matrik ["<<i<<"]["<<j<<"]"<<" = "; cin>>matrik[i][j];
      cout<<endl;
        }
}

for(i=0;i<=1;i++)
{
        for(j=0;j<=1;j++)
      {

        cout<<matrik[i][j]<<" ";
        }
        cout<<endl;
        }

det=(matrik[0][0] * matrik[1][1]) - (matrik[1][0] * matrik[0][1]);

cout<<"Maka  determinannya adalah = ";
cout<<det<<endl;

hasilbagi = 1/det;

a = hasilbagi * matrik[1][1];
b= hasilbagi * -matrik[0][1];
c = hasilbagi * -matrik[1][0];
d = hasilbagi * matrik[0][0];

cout<<"\n Jadi matrik inversnya adalah = \n";
cout<<"["<<a<<" "<<b<<"]"<<endl;
cout<<"["<<c<<" "<<d<<"]";
getch();
} 
