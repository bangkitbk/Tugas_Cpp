#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iomanip>
using namespace std;
typedef struct{
	int harga[100],kode[100];
	float jam[100];
}angka;
typedef struct{
	char tiket[100][100];
	int jumlah;
	angka x;
}cari;
cari data[100];
char namfile[100];
FILE *kereta;


void input();
void quick_sort(cari data[],int i,int u);
void oupud()
{
	int i=1;
	char namfile[100];
		cout<<"Nama file: ";
		cin>>namfile;
		kereta=fopen(namfile,"r");
	if ((kereta=fopen(namfile,"r"))==NULL)
			{cout<<"File TIDAK ADA!!!\n";}
    else{
		while (fread(&data[i],sizeof(data[i]),1,kereta)==1)
		{	
			cout<<endl<<"Tiket ke-"<<i+1<<endl;
			cout<<"Tiket Asal - Tujuan\t: "<<data[i].tiket[i]<<endl;
			cout<<"Jam Keberangkatan\t: "<<data[i].x.jam[i]<<endl;
			cout<<"Harga Tiket\t: "<<data[i].x.harga[i]<<endl;
			cout<<"Kode Tiket \t:"<<data[i].x.kode[i];
			i++;
		}
		}
		fclose(kereta);
}


int main()
{
	int i,q;
	char z[100];
	awal:
	cout<<"MENU\n";
	cout<<"1.Input Data\n";
	cout<<"2.Cari Tiket\n";
	cout<<"3.Pesan Tiket\n";
	cout<<"4.Tampilkan Tiket\n";
	cout<<"5.Exit\n";
	
	cout<<"Pilihan\t:";
	cin>>q;
	
	switch(q)
	{
	case 1:
		{
		input();
	    cout<<"Tekan enter untuk melanjutkan";
	    getchar();
		getchar();
		system("cls");
		goto awal;
		}
		break;
	case 2:
		{
		cout<<"File yang ingin ditampilkan : ";cin>>namfile;
		kereta=fopen(namfile,"r");
		
			i=1;
		    cout<<"Cari Tiket Asal atau Tujuan\t:";
		    cin>>z;
		    while((fread (&data[i], sizeof (data[i]),1,kereta))==1)
			{
			 
				if(strstr(data[i].tiket[i],z))
				{
		            cout<<"Tiket\t:";
		            cout<<data[i].tiket[i]<<endl;
	   	            cout<<"Jam\t:";
		            cout<<data[i].x.jam[i]<<endl;
		            cout<<"Harga\t:";
		            cout<<data[i].x.harga[i]<<endl;
		            cout<<"Kode\t:";
		            cout<<data[i].x.kode[i]<<endl<<endl;		            
		            i++;
			    }else
			    {
					cout<<" Tujuan atau Asal Kereta Tidak Ada/n";
					i++;
				}
			    
		}
		    cout<<"Tekan enter untuk melanjutkan";
	        getchar();
		    getchar();
		    fclose(kereta);
		    system("cls");
	      	goto awal;
		}
		break;
	case 3:
		{
			i=1;
			string nama;
			int s;

			cout<<"Nama\t:";
			cin>>nama;
			cout<<"Kode\t:";
			cin>>s;
			
			
			while(i<=data[0].jumlah)
			{
				if(s==data[i].x.kode[i])
				{
		            cout<<"Asal - Tujuan\t:";
		            cout<<data[i].tiket[i]<<endl;
	   	            cout<<"Jam\t:";
		            cout<<data[i].x.jam[i]<<endl;
		            cout<<"Harga\t:";
		            cout<<data[i].x.harga[i]<<endl;		            
		            fwrite(&data[i],sizeof(data[i]),1,kereta);
		            i++;
		           
			    }
			    else
			    {
					i++;
				}
			     
		}
		}
		    cout<<"Tekan enter untuk melanjutkan";
	        getchar();
		    getchar();
		    fclose(kereta);
		    system("cls");
		    goto awal;
		break;
	case 4:
		int f;
		cout<<"---Menu Tampilkan Tiket---\n";
		cout<<"1. Tampilkan tiket secara random \n";
		cout<<"2. Tampilkan tiket secara terurut menurut Kode tiket \n";
		cout<<" Pilihan Anda : ";cin>>f;
		switch(f){
		case 1 :
				oupud();
				break;
		case 2 :		
		cout<<"File yang ingin ditampilkan : ";cin>>namfile;
		kereta=fopen(namfile,"r");
		fread (&data[i], sizeof (data[i]),1,kereta); 
		if ((kereta=fopen(namfile,"r"))==NULL)
				{cout<<"File TIDAK ADA!!!\n";}
		else{

			fread (&data[i], sizeof (data[i]),1,kereta); 
			cout<<"Urutkan Berdasarkan Kode Tiket\n";
			quick_sort(data,0,data[0].jumlah);
			cout << "Data yang sudah diurutkan : "<< endl;
			
			cout<<setw(3)<<"No"<<setw(20)<<"Tiket Asal-Tujuan"<<setw(10)<<"Jam"<<setw(7)<<"Harga "<<setw(10)<<"kode";
			
			for(i=1;i<=data[0].jumlah;i++){
			cout<<"\n"<<setw(3)<<i<<setw(15)<<data[i].tiket[i]<<setw(10)<<data[i].x.jam[i]<<setw(10)<<data[i].x.harga[i]<<setw(15)<<data[i].x.kode[i];}}
			cout << endl;
			fclose(kereta);	
					break;
			}
			cout<<"\nTekan enter untuk melanjutkan";
	        getchar();
		    getchar();

		    system("cls");
		    goto awal;
		break;
		case 5:
		exit(0);
	}
}
void input()
{
		int i;
		cout<<" ~:::Masukkan Data untuk Disimpan dalam File:::~ "<<endl;
        cout<<"=============================================="<<endl<<endl;
        cout<<"Nama File yang akan dibuat (.txt)	= ";cin>>namfile;
        kereta=fopen(namfile,"w");
		cout<<"JUMLAH DATA\t:";
	    cin>>data[0].jumlah;
	    for(i=1;i<=data[0].jumlah;i++)
		{
			cout<<"Data "<<i<<endl;
			cout<<"Tiket Asal-Tujuan \t:";
			cin>>data[i].tiket[i];
			cout<<"jam\t:";
			cin>>data[i].x.jam[i];
			cout<<"Harga\t:";
			cin>>data[i].x.harga[i];
			cout<<"Kode\t:";
			cin>>data[i].x.kode[i];
			fwrite(&data[i],sizeof(data[i]),1,kereta);
		}
		fclose(kereta);
		cout<<endl;
}

void quick_sort(cari data[],int l,int u){
	int i=1;
	kereta=fopen(namfile,"r");
	fread (&data[i], sizeof (data[i]),1,kereta); 	
	int a,up,down;
	int temp;
	if(l>u)
	return;
	a=data[l].x.kode[l];
	up=u;
	down=l;
	while(down<up)
	{
	while (data[down].x.kode[down]<=a)
	down++;
	while(data[up].x.kode[up]>a)
	up--;
	if(down<up)
	{
		temp=data[down].x.kode[down];
		data[down].x.kode[down]=data[up].x.kode[up];
		data[up].x.kode[up]=temp;}}
		data[l].x.kode[l]=data[up].x.kode[up];
		data[up].x.kode[up]=a;
		quick_sort(data,l,up-1);
		quick_sort(data,up+1,u);
		fread(&data[i],sizeof(data[i]),1,kereta);
	fclose(kereta);
}
