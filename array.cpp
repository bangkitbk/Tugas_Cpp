#include <iostream>
using namespace std;
int main()
{
	int baris,kolom,ordo;
	cout<<"Program Matriks identitas\n";
	cout<<"Ordo Matriks\t:";cin>>ordo;
	for (baris=0;baris<ordo;baris++)
	{
		for (kolom=0;kolom<ordo;kolom++)
		{
			if (baris==kolom)
			cout<<"1 ";
			else 
			cout<<"0 ";
		}
		cout<<endl;
	}
	getchar();
	getchar();
}
