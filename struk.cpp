#include <iostream>
#include <conio.h>
using namespace std;
int main()
{ 
	int i,j,x,z;
	int harga[100][100];
	char y[100][100];
	char nama[100][100][100];
	cout<<"jumlah Pembeli\t:";
	cin>>x;
	if (x>0)
	{
	for(i=1;i<=x;i++)
	{
		cout<<"Pembeli ke-"<<i<<endl;
		cout<<"Nama Pembeli\t:";cin>>y[i];
	    cout<<"Jumlah Barang\t:";cin>>z;
	    cout<<endl;
    for(j=1;j<=z;j++)
    {
		cout<<"Barang ke-";cout<<j;
		cout<<"\n\tNama Barang\t:";cin>>nama[i][j];
		cout<<"\tHarga Barang\t:";cin>>harga[i][j];
		cout<<endl;
}
}
}
{
	cout<<"====================OUTPUT=========================\n";
	for(i=1;i<=x;i++)
	{
		cout<<"Pembeli ke-"<<i<<endl;
		cout<<"Nama Pembeli\t:";cout<<y[i]<<endl;
    for(j=1;j<=z;j++)
    {
		cout<<"\nBarang ke-";cout<<j;
		cout<<"\n\tNama Barang\t:";cout<<nama[i][j]<<endl;
		cout<<"\tHarga Barang\t:";cout<<harga[i][j]<<endl;
}
        cout<<endl;
    }
}
}
