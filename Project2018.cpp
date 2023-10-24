#include <iostream>      
#include <queue>
#include <stack>
#include <stdlib.h>
using namespace std;
typedef struct{
	int kursi,uang;
	string makanan,kode;
	
}kasir;
typedef struct{
	string kodex;
}kodekursi;
int main()
{
	int total;
	kasir data1;
	kodekursi data2;
	queue<kasir>antrian;
	queue<kasir>antrian2;
	queue<kasir>antrian3;
	stack<kodekursi>A2;
	stack<kodekursi>A3;
	stack<kodekursi>A4;
	stack<kodekursi>B4;
	stack<kodekursi>C4;
	bool menu=true;
	do{
		int pilih;
		cout<<"Cafe Informatika";
		cout<<"\nMenu";
		cout<<"\n1.Tambah Antrian";
		cout<<"\n2.Panggil Antrian";
		cout<<"\n3.Lihat Antrian";
		cout<<"\n4.Lihat History";
		cout<<"\n5.Meja";
		cout<<"\nPilih menu\t:";
		cin>>pilih;
		switch(pilih){
			case 1:
			cout<<"Jumlah Kursi\t:";cin>>data1.kursi;
			if(data1.kursi==0)
			cout<<"tidak valid";
			else if(data1.kursi<=4)
			{
				if(data1.kursi<=2){
					if(A2.empty()){
						data2.kodex="A2";
						A2.push(data2);
						data1.kode="A2";
					}else if(A3.empty()){
						data2.kodex="A3";
						A3.push(data2);
						data1.kode="A3";
					}else if(A4.empty()){
						data2.kodex="A4";
						A4.push(data2);
						data1.kode="A4";
					}else if(B4.empty()){
						data2.kodex="B4";
						B4.push(data2);
						data1.kode="B4";
					}else if(C4.empty()){
						data2.kodex="C4";
						C4.push(data2);
						data1.kode="C4";
					}else if(!C4.empty()){
					cout<<"\nKursi penuh";
					break;}					
				}else if(data1.kursi<=3){
					if(A3.empty()){
						data2.kodex="A3";
						A3.push(data2);
						data1.kode="A3";
					}else if(A4.empty()){
						data2.kodex="A4";
						A4.push(data2);
						data1.kode="A4";
					}else if(B4.empty()){
						data2.kodex="B4";
						B4.push(data2);
						data1.kode="B4";
					}else if(C4.empty()){
						data2.kodex="C4";
						C4.push(data2);
						data1.kode="C4";
					}else if(!C4.empty())
					{cout<<"\nKursi penuh";
					break;}										
				}else if(data1.kursi<=4){
					if(A4.empty()){
						data2.kodex="A4";
						A4.push(data2);
						data1.kode="A4";
					}else if(B4.empty()){
						data2.kodex="B4";
						B4.push(data2);
						data1.kode="B4";
					}else if(C4.empty()){
						data2.kodex="C4";
						C4.push(data2);
						data1.kode="C4";
					}else if(!C4.empty())
					{cout<<"\nKursi penuh";
					break;}				
				}
				cout<<"Nama Makanan\t:";cin>>data1.makanan;
				cout<<"Jumlah Uang\t:";cin>>data1.uang;
				antrian.push(data1);		
			}else
			cout<<"\nKursi Tidak Tersedia";
			
			break;
			
			case 2:
			if(!antrian.empty()){
				cout<<"Meja\t:"<<antrian.front().kode;
				cout<<"\nJumlah Kursi\t:"<<antrian.front().kursi;
				cout<<"\nJumlah Uang\t:"<<antrian.front().uang;
				cout<<"\nNama Makanan\t:"<<antrian.front().makanan;
				cout<<"\nKeluar dari antrian";
				antrian3.push(antrian.front());
				if(antrian.front().kode=="A2"){
					antrian.pop();
					A2.pop();
				}else if(antrian.front().kode=="A3"){
					antrian.pop();
					A3.pop();
				}else if(antrian.front().kode=="A4"){
					antrian.pop();
					A4.pop();
				}else if(antrian.front().kode=="B4"){
					antrian.pop();
					B4.pop();
				}else if(antrian.front().kode=="C4"){
					antrian.pop();
					C4.pop();
				}
			}
			break;
			
			case 3:
			antrian2=antrian;
			if (!antrian2.empty()){
				while(!antrian2.empty()){
				cout<<"\nMeja\t:"<<antrian2.front().kode;
				cout<<"\nJumlah Kursi\t:"<<antrian2.front().kursi;
				cout<<"\nJumlah Uang\t:"<<antrian2.front().uang;
				cout<<"\nNama Makanan\t:"<<antrian2.front().makanan;
				antrian2.pop();
			}
			}else if(antrian2.empty()){
				cout<<"\ntidak ada antrian";
			}
			break;
			
			case 4:
			antrian2=antrian3;
			total=0;			
			while(!antrian2.empty()){
				cout<<"\nJumlah Kursi\t:"<<antrian2.front().kursi;
				cout<<"\nJumlah Uang\t:"<<antrian2.front().uang;
				cout<<"\nNama Makanan\t:"<<antrian2.front().makanan;
				total=total+antrian2.front().uang;
				antrian2.pop();
			}cout<<"\nTotal Pendatapatan\t:"<<total;
			break;
			
			case 5:
			antrian2=antrian;
			cout<<"\nMeja yang ada";
			cout<<"\n1.A2 '2 Kursi'";
			cout<<"\n2.A3 '3 Kursi'";
			cout<<"\n3.A4 '4 Kursi'";
			cout<<"\n4.B4 '4 Kursi'";
			cout<<"\n5.C4 '4 Kursi'";
			if (!antrian2.empty()){
			cout<<"\nMeja Yang Terisi";
			while(!antrian2.empty()){
			cout<<"\nMeja\t:"<<antrian2.front().kode;
			antrian2.pop();
			}
		}else if(antrian2.empty()){
			cout<<"\nSemua meja kosong";
		}
			break;
			default:
			cout<<"tidak valid";
		}
		cout<<"\ntekan enter untuk kembali";
		getchar();
		getchar();
		
		system("cls");
	}while(menu); 
}

