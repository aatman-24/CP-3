#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int lower = 97;
const int upper = 122;


void display(vector<int> &ele)
{
	int m = ele.size();
	for(double i = 0 ; i < m; i++)
	{
		cout << ele[i] << ' ';
	}
	cout << endl;
}	

// #AlgoExpert

// Question : Case Cipher. O(N) -O(1)
// soultion : Use mod(%) and some logic. both apporach is same.



void myapproach(string &s,int key)
{
	int index;
	string result;
	int n = s.size();
	char str[n];
	for(int i = 0 ; i < n ;i++)
	{
		str[i] = s[i];
	}

	for (int i = 0; i < n; i++)
	{
		if(str[i] >= lower && str[i] <= upper)
		{
			index = (int(str[i]) - lower + key) % 26;
			str[i] = alphabet[index];
		}
	}

	result = "";
	for(int i = 0 ; i < n ;i++)
	{
		result += str[i];
	}

	cout << result << endl;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	string s;
	int key;

	int t; cin >> t;

	while(t--)
	{
		cin >> key;
		getline(cin,s);
		getline(cin,s);
		myapproach(s,key);
		
	}



}