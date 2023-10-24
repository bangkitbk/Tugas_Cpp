#include<iostream>
#include<malloc.h>
using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode {
    typeinfo info;
    typeptr next;
};

typeptr awal,akhir;

void listbaru();
void sisipdepan(typeinfo infoBaru);
void sisipbelakang(typeinfo infoBaru);
void sisiptengah(typeinfo infoBaru, int);
void hapuslist(typeinfo info);
void bacamaju(int);
void bacamundur(int);
void print(int);
void printurut();

int jumlahNode();

int main() {
    int pilih, pilih1;
    char p, p1;
    int nilai, indeks;
    listbaru();

    do {
        cout << "---Menu---" << endl;
        cout << "\n1. Sisip Node";
        cout << "\n2. Hapus Node";
        cout << "\n3. Baca Maju";
        cout << "\n4. Baca Mundur";
        cout << "\n5. Urutkan Node\n";
        cout << "Pilih\t: ";
        cin >> pilih;

        switch(pilih) {
            case 1:
                do {
                    cout << "\n1. Depan\n2. Tengah\n3. Belakang\n";
                    cout << "Pilih\t: "; cin >> pilih1;
                    switch(pilih1) {
                        case 1:
                            cout << "Masukkan Nilai\t: "; cin >> nilai;
                            sisipdepan(nilai);
                            break;
                        case 2:
                            cout << "Masukkan Indeks\t: "; cin >> indeks;
                            cout << "Masukkan Nilai\t: "; cin >> nilai;
                            sisiptengah(nilai, indeks);
                            break;
                        case 3:
                            cout<< "Masukkan Nilai\t: "; cin >> nilai;
                            sisipbelakang(nilai);
                            break;
                        default:
                            cout << "Salah memilih menu!" << endl;
                            break;
                    }
                    cout << "Masukkan nilai lagi (y/n)\t: "; cin >> p1;
                    if(p1 == 'n' || p1 == 'N')
                    break;
                } while(true);
                break;
            case 2:
                cout << "Nilai yang ingin dihapus\t: "; cin >> nilai;
                hapuslist(nilai);
                cout << "\nBerhasil menghapus nilai!\n";
                break;
            case 3:
                cout << "Jumlah nilai yang ingin ditampilkan\t: "; cin >> indeks;
                cout << "Isi Node dari depan\n";
                bacamaju(indeks);
                break;
            case 4:
                cout << "Jumlah nilai yang ingin ditampilkan\\t: "; cin >> indeks;
                cout << "Isi Node dari belakang\n";
                bacamundur(indeks);
                break;
            case 5:
                cout << "Urutan Node setelah diurutkan\n";
                printurut();
                print(jumlahNode());
                break;
            default:
                cout << "Salah Memilih Menu!";
                break;
        }
         cout << "\n\nIngin kembali ke menu utama? (y/n)\t: "; cin >> p;
        if(p == 'n' || p == 'N')
        break;
		system("cls");
    } while(true);
    return 0;
}

void listbaru()
{
    awal = NULL;
    akhir = NULL;
}

void sisipdepan(typeinfo infoBaru)
{
    typeptr NewNode;
    NewNode = (typenode *) malloc(sizeof(typenode));
    NewNode->info = infoBaru;
    NewNode->next = NULL;
    if(awal == NULL) {
        awal = NewNode;
        akhir = NewNode;
    } else {
        NewNode->next = awal;
        awal = NewNode;
    }
}

void sisipbelakang(typeinfo infoBaru)
{
    typeptr NewNode;
    NewNode = (typenode *) malloc(sizeof(typenode));
    NewNode->info = infoBaru;

    if(awal == NULL) {
        awal = NewNode;
        akhir = NewNode;
    } else {
        akhir->next = NewNode;
        akhir = NewNode;
    }
    akhir->next = NULL;
}

void sisiptengah(typeinfo infoBaru, int indeks)
{
    typeptr NewNode, bantu;
    NewNode = (typenode *) malloc(sizeof(typenode));
    NewNode->info = infoBaru;
    NewNode->next = NULL;

    if(awal == NULL) {
        awal = NewNode;
        akhir = NewNode;
    } else {
        int i = 0;
        bantu = akhir;
        while((i<indeks-1) && (bantu->next != NULL)) {
            bantu =bantu->next;
            i++;
        }
        NewNode->next = bantu->next;
        bantu->next = NewNode;
    }
}

void hapuslist(typeinfo info)
{
    typeptr hapus, bantu;

    if(awal == NULL) {
        cout << "List masih kosong\n";
    } else {
        if(awal->info == info) {
            hapus = awal;
            awal = hapus->next;
            delete hapus;
        } else {
            bantu = awal;

            while((bantu->next->info != info) && (bantu->next != NULL)) {
                bantu = bantu->next;
            }
            hapus = bantu->next;

            if(hapus == NULL) {
                cout << "\nList tidak ditemukan\n";
            } else {
                if(hapus == akhir) {
                    akhir = bantu;
                    akhir->next = NULL;
                } else {
                    bantu->next = hapus->next;
                    delete hapus;
                }
            }
        }
    }
}

void print(int indeks)
{
    int i = 0;
    typeptr bantu;
    bantu = awal;
    while((bantu != NULL) && (i < indeks)) {
        cout << " " << bantu->info << " ";
        bantu = bantu->next;
        i++;
    }
}

void printurut()
{
    typeptr current, nextCurrent = NULL;
    if(awal == NULL) 
    {
        cout << "Data belum tersedia!";
    } else 
    {
        bool swapped;
        int i, j;
        do {
            swapped = 0;
            current = awal;

            while(current->next != nextCurrent) {
                if(current->info > current->next->info)
                {
                    swap(current->info, current->next->info);
                    swapped = 1;
                }
                current = current->next;
            }
            nextCurrent = current;
        } while(swapped);
    }
}

void bacamaju(int indeks)
{
    typeptr bantu;
    if(awal == NULL) {
        cout << "Data belum tersedia!";
    } else {
        print(indeks);
    }
}

void bacamundur(int indeks)
{
    typeptr atas,bantu;
    if(awal == NULL) {
          cout << "Data belum tersedia";
    } else {
        if(akhir !=awal) {
            atas= awal;
            awal = akhir;
            do {
                bantu=awal;
                while(bantu->next !=akhir) {
                    bantu = bantu->next;
                }
                akhir->next =bantu;
                akhir= bantu;
            } while(akhir!=atas);
            akhir->next = NULL;
            print(indeks);
        } else {
            print(indeks);
        }
    }
}


int jumlahNode() {
    int jumlahNode;
    typeptr bantu;
    if(awal == NULL) {
        return 0;
    } else {
        bantu = awal;
        while(bantu!=NULL) {
            jumlahNode++;
            bantu = bantu->next;
        }
        return jumlahNode;
    }
}

void swap(typeptr a, typeptr b) {
    typeinfo temp;
    temp = a->info;
    a->info = b->info;
    b->info = temp;
}
