#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;



// Subject : 6) Write a program to reverse an array or string. O(N).

// Apporach - 1: We Used Two Pointer Start and end. (start++ and end-- both index value swap.)


void display(vi arr)
{
	for(double i = 0 ; i < arr.size() ; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}


void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void reverse_array(vi &arr, int start,int end)
{
	if(start > end) return;
	else 
	{
		swap(arr[start],arr[end]);
		reverse_array(arr,++start,--end);

	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	vi arr;
	int temp;
	int n; cin >> n;
	arr.assign(n,0);

	for(int i = 0 ; i < n ; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}

	int start = 0;
	int end = n - 1;
	while(start <= end)
	{
		swap(arr[start],arr[end]);
		start++;
		end--;
	}
	display(arr);


	// Apporach - 2 : Recursive.
	reverse_array(arr,0,n-1);
	display(arr);

	return 0;

}