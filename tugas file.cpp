#include <iostream>
#include <string.h>
using namespace std;
typedef struct{
	int nim;
	char nama[20],alamat[20];
	char golongan[1];
}dataMhs;
int i;
dataMhs data[100];
void input(){
	i=0;
	cout<<"Input data\n";
	cout<<"Nim\t:";cin>>data[i].nim;
	cout<<"Nama\t:";cin>>data[i].nama;
	cout<<"Alamat\t:";cin>>data[i].alamat;
	cout<<"Golongan\t:";cin>>data[i].golongan;
	FILE *write;
	write=fopen("D:/Geany/dataMahasiswa.txt","a");
	fwrite(&data[i],sizeof(data[i]),1,write);
	fclose(write);
}
void output(){
	i=0;
	cout<<"Output data\n";
	FILE *read;
	read=fopen("D:/Geany/dataMahasiswa.txt","r");
	
	while((fread(&data[i],sizeof(data[i]),1,read)==1)){
		cout<<"Nim\t:"<<data[i].nim<<endl;
		cout<<"Nama\t:"<<data[i].nama<<endl;
		cout<<"Alamat\t:"<<data[i].alamat<<endl;
		cout<<"Golongan\t:"<<data[i].golongan<<endl;
		i++;
	};
	fclose(read);
};
void search(){
	i=0;
	int x;
	cout<<"Cari data\t:";cin>>x;
	FILE *cari;
	cari=fopen("D:/Geany/dataMahasiswa.txt","r");
	while((fread(&data[i],sizeof(data[i]),1,cari)==1)){
	if(data[i].nim==x){
		cout<<"Nim\t:"<<data[i].nim<<endl;
		cout<<"Nama\t:"<<data[i].nama<<endl;
		cout<<"Alamat\t:"<<data[i].alamat<<endl;
		cout<<"Golongan\t:"<<data[i].golongan<<endl;
		break;
		}
		i++;
	}
}
int main(){
	int z;
	do{
		int y;
		cout<<"Menu\n";
		cout<<"1.Input\n";
		cout<<"2.Output\n";
		cout<<"3.Search\n";
		cout<<"Pilih\t:";cin>>y;
		system("cls");
		switch(y){
		case 1:
		input();
		break;
		
		case 2:
		output();
		break;
		
		case 3:
		search();
		break;
	}
		cout<<"Input 1 untuk kembali\t:";
		cin>>z;
		system("cls");
	}while(z==1);

}
