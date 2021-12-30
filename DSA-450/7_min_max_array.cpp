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



// Subject : 6) WAP to find minimum and maximum number from the array.

// Apporach - 1: 


void display(vi arr)
{
	for(double i = 0 ; i < arr.size() ; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int n ; cin >> n;

	vi arr(n,0);
	int temp;

	for(int i = 0 ; i < n ; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}


	// Apporach - 1 : Track the max and min value. O(n).

	int max = arr[0];
	int min = arr[0];

	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i] < min) min = arr[i];
		if(arr[i] > max) max = arr[i];
	}

	cout << "Max Value is " << max << "\nMin Value is " << min << endl;


	// Apporach - 2 : We can divide the array into two subpart and find the min and max
	// 				  for both part and decide the min and max but it is useful if we use
	// 				  another thread for another part. O(n).


	// Apporach - 3 : Here we are going to perform comparsion in pair.So we don't have to make
						// all comparsion. O(n).


	int max_num ;
	int min_num;
	int i = 0;
	if(n % 2 == 0)
	{
		if(arr[0] >  arr[1])
		{
			max_num = arr[0];
			min_num = arr[1];
		}
		else 
		{
			max_num = arr[1];
			min_num = arr[0];
		}
	}
	else 
	{
		min_num = arr[0];
		max_num = arr[0];
	}

	while(i < n - 1)
	{
		if(arr[i] < arr[i+1])
		{
			if(max_num < arr[i+1]) max_num = arr[i+1];
			if(min_num > arr[i]) min_num = arr[i];
		}
		else
		{
			if(max_num < arr[i]) max_num = arr[i];
			if(min_num > arr[i+1]) min_num = arr[i+1];
		}
		i++;
	}

	cout << max_num << '|' << min_num << endl;
	

	return 0;

}