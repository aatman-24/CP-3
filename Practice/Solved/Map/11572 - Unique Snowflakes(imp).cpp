#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;


void display(vector<string> temp)
{
	for(double i = 0 ; i < temp.size() ; i++)
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


	map<int,int> m;
	std::vector<int> elements;
	int t,n,temp,index; cin >> t;
	int count,max_size;
	while(t--)
	{
		cin >> n;
		while(n--)
		{
			cin >> temp;
			elements.push_back(temp);

		}
		double i = 0;
		count = 0;
		max_size = 0;
		while(i < elements.size())
		{
			if(m.find(elements[i]) == m.end())
			{
				m[elements[i]] = i;
				count++;
				i++;
			}
			else
			{
				if(max_size < count) max_size = count;
				index = m[elements[i]];
				i = index + 1;
				m.clear();
				count = 0;
			}
		}
		if(max_size < count) max_size = count;
		cout << max_size << endl;
		elements.clear();
		m.clear();
	}
	return 0;
	
}	



