#include <iostream>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#define true 1
#define false 0
using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;
typedef struct typenode{	typeinfo info;
							typeptr kiri, kanan;
					   };
typedef struct{		
				int noMhs, UTS, UAS, akhir;
				string nama;
			  }data;
data mhs[50];

typeptr akar, p, b;

void buat_ptb();
int ptb_kosong();
void sisipnode(typeinfo IB);
void cetak();
void preorder (typeptr akar);
void inorder (typeptr akar);
void postorder (typeptr akar);
void hapusnode(typeinfo IH);
void hapus();
void carinode(typeptr akar, int cari);

int jumlah, pilihan, cari, hhapus;
float hasil;
char jwb;

int main()
{
	buat_ptb();
	do
	{
	cout << "\n--------------------------------";
	cout << "\n------------- MENU -------------";
	cout << "\n--------------------------------";
	cout << "\n1. Input Data \n2. Cetak Data \n3. Cari Data \n4. Hapus Data";
	cout << "\nMasukan Pilihan : "; cin >> pilihan;
	if(pilihan==1)
	{
	cout << "Masukan banyak data : "; cin >> jumlah;
	for(int i=0; i<jumlah; i++){
			cout << "\n\nData ke-"<<i+1;
			cout << "\nNo Mhs : "; cin >> mhs[i].noMhs;
			cout << "Nama     : "; cin >> mhs[i].nama;
			cout << "UTS      : "; cin >> mhs[i].UTS;
			cout << "UAS      : "; cin >> mhs[i].UAS;
			hasil=0.4*mhs[i].UTS+0.6*mhs[i].UAS;
			sisipnode(mhs[i].noMhs);
			cout << "Akhir  : " << hasil;
		}
	}
	if(pilihan==2)
	{
		cetak();
	}
	if(pilihan==3)
	{
		cout << "Masukan No Mhs yang dicari : ";
		cin >> cari;
		carinode(akar,cari);
	}
	if(pilihan==4)
	{
		cout << "Masukan No Mhs yang ingin dihapus : ";
		cin >> hhapus;
		hapusnode(hhapus);
	}
		cout << "\nKembali ke menu? <y/n>"; cin >> jwb;
		cout << endl;
		system("cls");
	}
	
	while(jwb=='Y' || jwb=='y');
}


int ptb_kosong()
{
	if (akar==NULL)
		return(true);
	else
		return (false);
}


void buat_ptb()
{
	typeptr ptb;
	ptb=NULL;
	akar=ptb;
}

void sisipnode(typeinfo IB)
{
	typeptr NB;
	NB = (typenode * )malloc (sizeof(typenode));
	NB->info=IB;
	NB->kiri=NULL;
	NB->kanan=NULL;
	if(ptb_kosong())
	{
		akar=NB;
	}
	else
	{
		b=akar;
		p=akar;
		//mencari tempat untuk menyisipkan node
		while(p!=NULL && IB!=p->info)
		{
			b=p;
			if (IB<p->info)
				p=b->kiri;
			else
				p=b->kanan;
		}
		if(IB==b->info)
			cout<<"\n\nNode"<<IB<<"sudah ada!\n\n";
		else
		{
			if(IB<b->info)
				b->kiri=NB;
			else
				b->kanan=NB;
		}
	}
}

void cetak()
{
	cout<<"\nPre Order  : ";
	preorder(akar);
	cout<<"\nIn Order   : ";
	inorder(akar);
	cout<<"\nPost Order : ";
	postorder(akar);
	return;
	
}
void preorder(typeptr akar)
{
	if(akar!=NULL)
	{
		cout<<" "<<akar->info;
			preorder(akar->kiri);
			preorder(akar->kanan);
	}
}
void inorder(typeptr akar)
{
	if(akar!=NULL)
	{
		inorder(akar->kiri);
		cout<<" "<<akar->info;
		inorder (akar->kanan);
	}
}
void postorder(typeptr akar)
{
	if (akar!=NULL)
	{
		postorder(akar->kiri);
		postorder(akar->kanan);
		cout<<" "<<akar->info;
	}
}
void hapusnode (typeinfo IH)
{
	if(ptb_kosong())
	{
		cout<<"PTB masih kosong!!"<<endl;
	}
	else
	{
		b=akar;
		p=akar;
		//mencari tempat node yang dihapus
		while(p!=NULL && IH!=p->info)
		{
			b=p;
			if(IH<p->info)
			{
				p=b->kiri;
			}
			else
				p=b->kanan;
		}
		hapus();
	}
}

void hapus()
{
	typeptr temp;
	//bila ptb terdiri dari akar saja atau akar dengan 1 anak kiri/kanan
	if(p->kiri==NULL && p->kanan==NULL)
	{
		if(b==akar && p==akar)
			akar=NULL;
		else
		{
			if(p==b->kiri)
				b->kiri=NULL;
			else
				b->kanan=NULL;
		}
		free(p);
	}
	
	//bila ptb memiliki anak kiri dan anak kanan dengan banyak anak cabang 
	
	else if (p->kiri!=NULL && p->kanan!=NULL)
	{
		temp=p->kiri;
		b=p;
		while (temp->kanan!=NULL)
		{
			b=temp;
			temp=temp->kanan;
		}
		p->info=temp->info;
		if(b==p)
			b->kiri=temp->kiri;
		else
			b->kanan=temp->kiri;
			
		free (temp);
	}
	//bila ptb memiliki anak kiri saja dengan banyak anak cabang
	else if(p->kiri!=NULL && p->kanan==NULL)
	{
		if (b==p)
			akar=p->kiri;
		else
		{
			if(p==b->kiri)
				b->kiri=p->kiri;
			else
				b->kanan=p->kiri;
		}
		free(p);
	}
	//bila ptb memiliki anak kanan saja dengan banyak anak cabang
	else if (p->kiri==NULL && p->kanan!=NULL)
	{
		if(b==p)
			akar=p->kanan;
		else
		{
			if(p==b->kanan)
				b->kanan=p->kanan;
			else
				b->kiri=p->kanan;
		}
		free(p);
	}
}

//fungsi yang digunakan untuk melakukan pencarian data
void carinode(typeptr akar, int cari)
{
    if((akar) == NULL)
    {
        cout<<"Data tidak ditemukan!"<<endl;
    }
    //jika data yang dicari lebih kecil dari isi root
    else if(cari < akar->info)
        carinode(akar->kiri,cari);
    //jika data yang dicari lebih besar dari isi root
    else if(cari > akar->info)
        carinode(akar->kanan,cari);
    //jika data yang dicari sama dengan isi dari variabel root
    else if(cari == akar->info)
        cout<<"Data ditemukan!"<<endl;
}

