#include <iostream>
using namespace std;
void tampil (int a);
main(){
int a;
cout<<"Masukkan a; ";cin>>a;
if (a>=7) a=a-1;
if (a<=3) a=a+3;
tampil(a);	
	}
	
	void tampil(int a){
	if(a==1)
	cout<<endl<<'*';
	else{
		cout<<'*';
		tampil (a-1);
		cout<<'*';
		}	
		}
