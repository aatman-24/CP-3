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

// Question : LongestPalindreom subsequence. O(N^2) -O(N)
// Apporach : 1) O(N^3) - O(N^2) to get subsequence * O(N) to check is palindrome or not.
			// 2) O(N^2) -  take the the all index as middle and explore it in both direction.



void getPalindrome(string &s,int mid,string &result)
{
	int n = s.size();
	int left,right;
	if(s[mid] == s[mid+1])
	{
		left = mid-1;
		right = mid +2;
	}
	else
	{
		left = mid-1;
		right = mid + 1;
	}
	while(left > -1 && right < n)
	{
		if(s[left] != s[right]) break;
		left--; right++;
	}

	if((right - left) > int(result.size()))
	{
		result = "";
		for(int i = left+1; i < right ;i++)
		{
			result += s[i];
		}
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


	string s;

	int t; cin >> t;

	while(t--)
	{
		cin >> s;
		string result = "";
		for(double i = 0 ; i < s.size() - 1; i++)
		{
			getPalindrome(s,i,result);
		}
		cout << result << endl;
	}







}