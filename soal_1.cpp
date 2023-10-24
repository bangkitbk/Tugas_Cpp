#include <iostream>
using namespace std;
#include <string.h>
typedef struct{
	int nilai;
	int jumlah;
	
	
}data;
int main(){
	char nilai[100];
	string tes="0123456789";
	int panjang;
	int panjang_nilai;
	cout<<"Input Angka\t:";
	cin>>nilai;
	panjang_nilai=strlen(nilai);
	panjang_nilai=panjang_nilai-1;
	cout<<"hasil:\n";
	for(int i=0;i<=9;i++){
		panjang=0;
			for(int j=0;j<=panjang_nilai;j++){			
		if(tes[i]==nilai[j])
		panjang=panjang+1;
		
		
	}
	data datax[panjang_nilai];
		datax[i].nilai=i;
		datax[i].jumlah=panjang;
		FILE *write;
		write=fopen("D:/Geany/nilai.txt","a");
		fwrite(&datax[i],sizeof(datax[i]),1,write);
		fclose(write);
	if(panjang>0)
	cout<<i<<"="<<panjang<<endl;
	
	
	}
	
	
	
}
