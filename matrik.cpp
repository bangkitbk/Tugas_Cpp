#include <iostream>
using namespace std;
int main(){
	int x,y;
	cout<<"matriks:";
	cin>>x;cout<<" ";cin>>y;
	int array[x][y],array2[x][y],array3[x][y];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout<<"array["<<i<<"]["<<j<<"]";
			cin>>array[i][j];
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout<<"array["<<i<<"]["<<j<<"]";
			cin>>array2[i][j];
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			array3[i][j]=0;
			for(int k=0;k<y;k++){
			array3[i][j]+=array[i][k]*array2[k][j];
		}
		cout<<array3[i][j]<<" ";
		
		}
		cout<<endl;
	}
}


