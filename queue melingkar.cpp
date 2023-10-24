#include <iostream>
#include <malloc.h>
#define max 5
#define true 1
#define false 0
using namespace std;
typedef float typeinfo;
typedef struct typequeue
{
	int depan,belakang;
	typeinfo elemen[max];
};
struct data
{
	string nama;
}mhs[max];
struct typequeue queue;
void buatqueue();
void cetakqueue();
void enqueue(int IB);
void dequeue();
int queuepenuh();
int queuekosong();

int main()
{
	int nim,jumlah,hapus,i,j;
	string nama[10];
	buatqueue();
	cout<<"Masukkan jumlah mahasiswa = ";cin>>jumlah;
	for(i=1;i<=jumlah;i++)
	{
		cout<<"Data "<<i<<endl;
		cout<<"Nama \t: ";cin>>mhs[i].nama;
		cout<<"NIM \t: ";cin>>nim;
		enqueue(nim);
	}
	cetakqueue();
	cout<<"\nMasukkan jumlah data yang ingin dihapus \t: ";cin>>hapus;
	for(j=0;j<hapus;j++)
		dequeue();
	cout<<"Data setelah dihapus = ";
	
	cetakqueue();
}

void buatqueue()
{
	queue.depan=1;
	queue.belakang=1;
}

int queuekosong()
{
	if(queue.depan==queue.belakang)
	return true;
	else
	return false;
}

int queuepenuh()
{
	int next_belakang;
	if(queue.belakang==max)
	next_belakang=1;
	else
	next_belakang=queue.belakang+1;
	if(queue.depan==next_belakang)
	return true;
	else
	return false;
}

void enqueue(int IB)
{
	if(queuepenuh())
	cout<<"QUEUE OVERFLOW!";
	else
	{
		if(queue.belakang==max)
			queue.belakang=1;
		else
			queue.belakang++;
		queue.elemen[queue.belakang]=IB;
	}
}

void dequeue()
{
	typeinfo ID;
	if(queuekosong())
	cout<<"QUEUE UNDERFLOW!";
	else
	{
		ID=queue.elemen[queue.depan+1];
		if(queue.depan==max)
			queue.depan=1;
		else
			queue.depan++;
	}
	
}

void cetakqueue()
{
	int i;
	if(queue.depan==queue.belakang)
		cout<<"QUEUE KOSONG!";
	else
	{
		if(queue.depan<queue.belakang)
		{
			i=queue.depan+1;
			while(i<=queue.belakang)
			{
				cout<<"\nNama = "<<mhs[i-1].nama;
				cout<<"\nNIM = "<<queue.elemen[i];
				i++;
			}
		}
		else
		{
			for(i=queue.depan+1;i<=max;i++)
			{
				cout<<"\nNama = "<<mhs[i-1].nama;
				cout<<"\nNIM = "<<queue.elemen[i];
			}
			for(i=1;i<queue.belakang;i++)
			{
				cout<<"\nNama = "<<mhs[i-1].nama;
				cout<<"\nNIM = "<<queue.elemen[i];
			}
		}
	}
}

