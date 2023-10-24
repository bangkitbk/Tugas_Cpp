#include <iostream>
#include <conio.h>
#define Phi 3.14
#define X "Bangkit"
using namespace std;
int main()
{
	float T,V,R;
	awal:
	cout<<X;
	cout<<"\nMenghitung Volume Tabung\n";
	cout<<"Masukkan Nilai Jari-jari=";cin>>R;
	cout<<"Masukkan Nilai Tinggi=";cin>>T;
	V=Phi*R*R*T;
	cout<<"Hasil Volume="<<V<<endl;
	goto awal;
}
