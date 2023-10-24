#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int y,i,j,z;
	int x[100][100];
	cout<<"Program Matriks Tranpose\n";
	cout<<"Baris\t:";cin>>y;
	cout<<"Kolom\t:";cin>>z;
	for (i=0;i<y;i++)
	{
		for (j=0;j<z;j++)
		{
			cout<<"["<<i<<"]"<<"["<<j<<"]";
			cin>>x[i][j];
		}
		cout<<endl;
	}
	for (i=0;i<y;i++)
	{
		for (j=0;j<z;j++)
		{
			cout<<" "<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	for (j=0;j<y;j++)
	{
		for (i=0;i<z;i++)
		{
			cout<<" "<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	getchar();
	getchar();
}
