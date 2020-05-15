//PROGRAM TO IMPLEMENT RADIX SORT
//by VIDUSHI RASTOGI (18/94011)
#include<iostream> 
using namespace std; 

//Function to get max value
int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 
	int output[n];  
	int i, count[10] = {0}; 

	//Loop for frequency
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 

	//Loop for cummulative frequncy
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// Build the output array 
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 

	//changing the array.
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 


void radixsort(int arr[], int n) 
{ 
	int m = getMax(arr, n); 

	//running countSort for each digit value
	//starting from once place
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 


void print(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

 
int main() 
{ 
	int limit;
	cout<<"Enter the number of elements you want to sort : ";
	cin>>limit;
	int* arr = new int[limit];
	cout<<"\n Enter elements : "<<endl;
	for(int i=0; i<limit; i++)
	{
		cin>>arr[i];
	} 
	radixsort(arr, limit);
	cout<<"\nSorted array : "<<endl; 
	print(arr, limit); 
	return 0; 
} 

