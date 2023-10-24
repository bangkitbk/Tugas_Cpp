#include <iostream>
#include <string.h>
using namespace std;
typedef struct{
	int gaji[100],ktp[100];
}angka;
typedef struct{
	char nama[100][100];
	angka x;
}cari;
cari data[100];
int main()
{
	int i,q,jumlah,y,s;
	char z[100];
	awal:
	cout<<"MENU\n";
	cout<<"1.INPUT DATA\n";
	cout<<"2.CARI BERDASARKAN NAMA\n";
	cout<<"3.CARI BERDASARKAN GAJI\n";
	cout<<"4.CARI BERDASARKAN NO KTP\n";
	cout<<"Pilihan\t:";
	cin>>q;
	switch(q)
	{
		case 1:
		{cout<<"JUMLAH DATA\t:";
	    cin>>jumlah;
	    for(i=1;i<=jumlah;i++)
	{
		cout<<"Data "<<i<<endl;
		cout<<"Nama\t:";
		cin>>data[i].nama[i];
		cout<<"Gaji\t:";
		cin>>data[i].x.gaji[i];
		cout<<"No KTP\t:";
		cin>>data[i].x.ktp[i];
	}
	    cout<<"Tekan enter untuk melanjutkan";
	    getchar();
		getchar();
		system("cls");
		goto awal;
	}
		break;
		case 2:
		{
			i=1;
		    cout<<"Inputkan Nama\t:";
		    cin>>z;
		    while(i<=jumlah)
			{
				if(strstr(data[i].nama[i],z))
				{
		            cout<<"Nama\t:";
		            cout<<data[i].nama[i]<<endl;
	   	            cout<<"Gaji\t:";
		            cout<<data[i].x.gaji[i]<<endl;
		            cout<<"No KTP\t:";
		            cout<<data[i].x.ktp[i]<<endl<<endl;
		            i++;
			    }else
			    {
					i++;
				}
			    
		}
		    cout<<"Tekan enter untuk melanjutkan";
	        getchar();
		    getchar();
		    system("cls");
	      	goto awal;
		}
		break;
		case 3:
		{
			i=1;
			cout<<"Inputkan Gaji\t:";
			cin>>y;
			while(i<=jumlah)
			{
				if(y==data[i].x.gaji[i])
				{
		            cout<<"Nama\t:";
		            cout<<data[i].nama[i]<<endl;
	   	            cout<<"Gaji\t:";
		            cout<<data[i].x.gaji[i]<<endl;
		            cout<<"No KTP\t:";
		            cout<<data[i].x.ktp[i]<<endl<<endl;
		            i++;
			    }else if((i=jumlah)&&(y!=data[i].x.gaji[i]))
			    {
					cout<<"Data tidak ditemukan\n";
					i++;
				}
			    
			    else
			    {
					i++;
				}
			    
		}
		    cout<<"Tekan enter untuk melanjutkan";
	        getchar();
		    getchar();
		    system("cls");
		    goto awal;
	}
		break;
		case 4:
		{
			i=1;
			cout<<"Inputkan No KTP\t:";
			cin>>s;
			while(i<=jumlah)
			{
				if(s==data[i].x.ktp[i])
				{
		            cout<<"Nama\t:";
		            cout<<data[i].nama[i]<<endl;
	   	            cout<<"Gaji\t:";
		            cout<<data[i].x.gaji[i]<<endl;
		            cout<<"No KTP\t:";
		            cout<<data[i].x.ktp[i]<<endl<<endl;
		            i++;
			    }else if((i=jumlah)&&(s!=data[i].x.ktp[i]))
			    {
					cout<<"Data tidak ditemukan\n";
					i++;
				}
			    else
			    {
					i++;
				}
		}
		    cout<<"Tekan enter untuk melanjutkan";
	        getchar();
		    getchar();
		    system("cls");
		    goto awal;
	}
		break;

}
}
