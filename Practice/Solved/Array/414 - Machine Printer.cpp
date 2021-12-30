#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<int> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';
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

	int n;
	while(cin >> n)
	{
		if (n == 0) break;
		std::vector<int> X;
		int max_x = 0;
		string x;
		getline(cin,x);
		while(n--)
		{
			getline(cin,x);
			int count_x = 0;
			for(double i = 0;i < x.size();i++)
			{
				if(x[i] == 'X') count_x++;
			}
			max_x = max(max_x,count_x);
			X.push_back(count_x);
		}
		int min_B = 25 - max_x;
		int void_space = 0;
		for(double i = 0 ; i < X.size();i++)
		{
			void_space += (25 - X[i]- min_B);
		}
		cout << void_space << endl;

	}
	
}	



