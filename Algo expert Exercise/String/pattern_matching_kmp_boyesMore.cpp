#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;


// #Title : Pattern Matching Alogrithm.



// 1) Boyer-More Algo [worst-case = O(N^2) , Avg Case = O(N+M)]

void getLastOccurance(const string &s,vector<int> &last_occurance)
{
	int n = s.size();
	for(int i = 0 ; i < n ;i++)
	{
		last_occurance[s[i]] = i;
	}
}


int boyerMore(const string &s,const string &p)
{
	int i,k,n,m;
	vector<int> last_occurance(128,-1);
	getLastOccurance(p,last_occurance);

	n = s.size();
	m = p.size();

	i = m - 1;  // text pointer.
	k = m - 1;	// pattern pointer.
	if(i > n - 1) return -1;
	while (i <= n - 1)
	{
		if(s[i] == p[k])
		{
			if(k == 0) return i;
			else 
			{
				i--;k--;
			}
		}
		else
		{
			i = i + (m - min(k,1+last_occurance[s[i]])); // update text pointer
			k = m - 1; // pattern text pointer
		}
	}
	return -1;
}



// 2) KMP Algorihthm O(N+M)


vector<int> ComputeFailFunction(const string &pattern)
{
	int n = pattern.size();
	vector<int> result(n,0);
	int k = 0;
	int i = 1;
	while(i < n)
	{
		if(pattern[i] == pattern[k])
		{
			result[i] = k+1;
			k++; i++;
		}
		else if(k > 1)
		{
			k = result[k-1];
		}
		else
		{
			result[i] = 0;
			i++;
		}
	}
	return result;
}


int KMPmatch(const string &text, const string &pattern)
{
	int n = text.size();
	int m = pattern.size();
	vector<int> failure_fun = ComputeFailFunction(pattern);
	int i = 0 ; // text pointer
	int k = 0 ; // pattern pointer
	while(i < n)
	{
		if(text[i] == pattern[k])
		{
			if(k == m - 1)
				return i - m + 1;
			i++; k++;
		} 
		else if (k > 0) k = failure_fun[k-1]; // does not use abdul bhari concept if used then it is "failure_fun[k]".
		else i++;
	}
	return -1;

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	string s = "mynameisataman";
	string p = "atdaman";

	cout << KMPmatch(s,p);

}