#include <bits/stdc++.h> 
#include <iostream> 
using namespace std; 
void display(int a[], int n) 
{ 
	for (int i = 0; i < n; i++) { 
		cout << a[i] << " "; 
	} 
	cout << endl; 
} 
void findPermutations(int a[], int n) 
{
	sort(a, a + n);
	do {
		display(a, n);
	} while (next_permutation(a, a + n));
}
void findCombinationsUtil(int arr[], int index,int num, int reducedNum,int c) 
{ 
if (reducedNum < 0)
	return;
if (reducedNum == 0)
	{
	if(index<=c)
	{
	int ar[c];
	int i;
	for (i = 0; i < c-index; i++)
	ar[i]=0;
	for ( i = 0; i < index; i++) 
	ar[c-index+i]=arr[i];
	findPermutations(ar, c);
}
return; 
} 
int prev = (index == 0)? 1 : arr[index-1];
for (int k = prev; k <= num ; k++) 
	{ 
	arr[index]=k;
	findCombinationsUtil(arr, index + 1, num,reducedNum - k,c); 
	} 
} 
void findCombinations(int n,int c) 
{ 
	int arr[n]; 
	findCombinationsUtil(arr, 0, n, n,c); 
} 
int main() 
{ 
	int n,c;
	cout<<"Enter the sum "<<endl;
	cin>>n;
	cout<<"Enter the number of combinations you want"<<endl;
	cin>>c;
	findCombinations(n,c);
	return 0;
}
