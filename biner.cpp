#include <iostream>
using namespace std;
void biner(int x)
{
	if (x!=1)
	biner(x/2);
	if (x%2==0)
	cout<<"0";
	else
	cout<<"1";
}
int main()
{
	int y;
	cout<<"Desimal\t:";
	cin>>y;
	biner(y);
}
