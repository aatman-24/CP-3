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

// Question : Longest subsequence withoout duplication. O(N) -O(min(N,A)) A = unique character in map.
// Apporach : 1) MyApporach (clean the map & don't make the string on every increment)
			// 2) AlgoExpert - make string on every increment and also update mapper.


map<char,int> mapper;

int start;

string myApporach(string &s)
{
	mapper.clear();
	int n = s.size();
	int i = 0;
	int first = 0;
	string result = "";
	while(i < n)
	{
		if(mapper.find(s[i]) == mapper.end())
		{
			mapper[s[i]] = i;
			i++;
		}
		else
		{
			if(int(result.size()) < (i - first))
			{
				result = "";
				for(int j = first ; j < i ; j++)
				{
					result += s[j];
				}
			}
			i = max(first,mapper[s[i]] + 1);
			first = i;
			mapper.clear();
			
		}
	}
		if(int(result.size()) < (i - first))
			{
				result = "";
				for(int j = first ; j < i ; j++)
				{
					result += s[j];
				}
			}
	return result;
}



string getLongestString(string &s)
{
	mapper.clear();
	int n = s.size();
	start = 0;
	int i = 0;
	string result = "";
	string temp = "";
	while(i < n)
	{
		if(mapper.find(s[i]) == mapper.end())
		{
			temp += s[i];
			mapper[s[i]] = i;
			i++;
		}
		else
		{
			if(result.size() < temp.size())
			{
				result = temp;
			}
			start = max(start,mapper[s[i]] + 1);
			mapper[s[i]] = i;
			temp = "";
			for(int j = start;j <= i ;j++)
			{
				temp += s[j];
			}
			i++;
		}
	}
	if(result.size() < temp.size())
	{
		result = temp;
	}
	return result;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	string s,result;

	int t; cin >> t;

	while(t--)
	{
		cin >> s;
		result = getLongestString(s);
		cout << result << endl;
		result = myApporach(s);
		cout << result << endl;
	}


}