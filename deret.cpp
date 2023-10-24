#include <iostream>
using namespace std;
int main()
{
	int j=1,x;
	float s,p,y=1;
	cout<<"Jumlah Baris\t";cin>>x;
	cout<<"S\t:";
	s=0.0;
	while(j<=x)
	{
		int i;
		if(j%2==0)
		i=-1;
		else
		i=1;
		
		
		p=(1/y)*i;		
		if(p>0)
			cout<<"+";
			else
			cout<<"-";
			
		cout<<"1/"<<y;
		s=s+p;
		y++;
		      j++;
		
}
		cout<<"\nJumlah\t:"<<s;
}
