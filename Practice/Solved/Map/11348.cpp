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


int const MAX_SIZE = 100001;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int n_friends,n_steps,temp,index;
	vector<int> result;
	int t,i; cin >> t;
	i = 0;
	while(i++ != t)
	{
		result.assign(100001,0);
		cin >> n_friends;
		index = 0;
		while(n_friends != index)
		{
			cin >> n_steps;
			while(n_steps--)
			{
				cin >> temp;
				if(result.at(temp) == 0) result.at(temp) = index + 1;
				else result.at(temp) = 0; 
			}
			index++;
		}


		map<double,double> mii;
		int count  = 0;
		for(int i = 0 ; i < MAX_SIZE ;i++)
		{
			if(result[i] != 0)
			{
				if(mii.find(result[i]) == mii.end())
				{
					mii[result[i]] = 1;
				}
				else mii[result[i]] += 1;
				count ++;
			}
		}

		cout << "Case " << i << ':';

		for(auto i:mii)
		{
			cout << ' ' << fixed << (i.second/count) * 100 << '%';
		}
		cout << endl;
		result.clear();
	}

	return 0;
	
}	



