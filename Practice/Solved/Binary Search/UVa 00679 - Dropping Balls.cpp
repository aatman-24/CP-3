#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


// #Approach : Divide the Problem into subproblem. Is it very clear if the given num is odd then It will
// be going to left bcz when odd number is visit the node it will be false and if is even it will be true.
// so if you just plot the 3 level tree than you identified how it will work. 


int MaxDepth;

int pow(int base, int n)
{
	if(n == 0) return 1;
	else return base * pow(base, n-1);
}


int getLastNode(int index, int I)
{
	int left = index * 2; int right = left + 1;
	if(left < MaxDepth && right < MaxDepth)
	{	
		if(I % 2 == 0) return getLastNode(right, I/2);
		else return getLastNode(left, I/2+1);
	}
	return index; 
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	



	int t; cin >> t;
	int nD,nI;
	while(t--)
	{
		cin >> nD >> nI;
		MaxDepth = pow(2, nD);
		cout << getLastNode(1, nI) << endl;
	}


	return 0;
}

