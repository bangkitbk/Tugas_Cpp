#include <iostream>
using namespace std;
typedef struct{
	int nim;
	string nama;
	string jurusan;
	float ipk;
}mhs;

int main(){
	int x;
	cout<<"input jumlah mahasiswa\t:";
	cin>>x;
	mhs data[x];
	for(int i=0;i<x;i++){
	cout<<"Nim\t:";
	cin>>data[i].nim;
	cout<<"nama\t:";
	getline(cin,data[i].nama);
	cin.ignore();
	cout<<"jurusan\t:";
	getline(cin,data[i].jurusan);
	cin.ignore();
	cout<<"ipk\t:";
	cin>>data[i].ipk;
	if(data[i].ipk>4||data[i].ipk<0){
		cout<<"nilai tidak valid\n";
		cout<<"ipk\t:";
	cin>>data[i].ipk;
	}
}
	cout<<"\n\nOUTPUT\n";
	for(int i=0;i<x;i++){
	cout<<"Nim\t:";
	cout<<data[i].nim<<endl;
	cout<<"nama\t:";
	cout<<data[i].nama<<endl;
	cout<<"jurusan\t:";
	cout<<data[i].jurusan<<endl;
	cout<<"ipk\t:";
	cout<<data[i].ipk<<endl;
}
}

