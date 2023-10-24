#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string nama = "";
    int nim = 1, alas, tinggi;
    string judul = "PROGRAM";
	float luas_segitiga;
    cout<<"\t"<<judul<<endl;
    cout<<"\t"<<"Nama\t :"<<nama<<endl;
    cout<<"\t"<<"NIM\t :"<<nim<<endl;
    cout<<"\t"<<"Hitung Luas Segitiga"<<endl;
    cout<<"\t"<<"Masukkan Alas \t:"; cin>> alas;
    cout<<"\t"<<"Masukkan Tinggi\t :"; cin>> tinggi;
    luas_segitiga = (alas * tinggi) /2 ;
    cout<<"\t"<<"Luas Segitiga\t : "<< luas_segitiga;
}
