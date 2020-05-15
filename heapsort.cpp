//PROGRAM TO IMPLEMENT HEAPSORT
//by VIDUSHI RASTOGI (18/94011)
#include <iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j]) //comparison b/w left and right child
			j = j+1;
		if (temp > a[j]) //comparison between parent and larger child
			break;
		else if (temp <= a[j]) //swapping parent with larger child
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp; 
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Swapping first and the last element.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// max heap of remaining element.
		MaxHeapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	n++;
	int arr[n];
	for(i = 1; i < n; i++)
	{
		cout<<"Enter element "<<i<<": ";
		cin>>arr[i];
	}

	Build_MaxHeap(arr, n-1);
	HeapSort(arr, n-1);
 
	cout<<"\nSorted Data ";
 
	for (i = 1; i < n; i++)
		cout<<"->"<<arr[i];
 
	return 0;
}
