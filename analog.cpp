#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;


int maxSubarraySum(int size){
	int arr[size];
	int max_ending_here = 0;
	int max_so_far = 0; 
	for (int y = 0; y < size; y++){
	arr[y] = (rand()%100);
	if(y%2 !=0)
	arr[y] = arr[y]*-1;
	cout<<arr[y]<<" ";
	
}
	cout<<endl<<"Hasil : ";
	for (int i = 0; i < size; i++) { 
		if (arr[i] <= max_ending_here + arr[i]) { 
			max_ending_here += arr[i]; 
			}
			else { 
				max_ending_here = arr[i]; 
				} 
				if (max_ending_here > max_so_far) 
				max_so_far = max_ending_here; 
				} 
				return max_so_far;
		
}
int main(){
	//clock_t startTime = clock(); 
	int x;
	using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    do
{
	cout<<"Jumlah : ";
    cin>>x;
	auto t1 = high_resolution_clock::now();
    cout<<maxSubarraySum(x)<<endl;
    auto t2 = high_resolution_clock::now();
	duration<double, std::milli> ms_double = t2 - t1;
	std::cout <<"Waktu : "<< ms_double.count() << "ms"<<endl;
}while(x<1000);
	//time(&end);
	//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	//double dif = difftime(end,begin);
	//cout<< dif;
}
