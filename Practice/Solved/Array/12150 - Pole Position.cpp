#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<pair<int,int>> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i).first << '\t' << temp.at(i).second << endl;
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

	int n;
	while(cin >> n)
		{
			if(!n) break;
			vector<int> C,P,result;
			bool set = false;
			for(int i = 0; i < n ; i++)
			{
				int c,p;
				cin >> c >> p;
				C.push_back(c); P.push_back(p);
			}
			vector<pair<int,int>> store;
			for(int i = 0; i < n ; i++)
			{
				if (abs(P[i]) >= n)
				{
					set = true;
				}
				store.push_back({i+P[i],C[i]});
			}
			sort(store.begin(),store.end());
			result.push_back(store[0].second);
			for(int i = 1 ; i < n ; i++)
			{
				if (store[i-1].first == store[i].first)
				{
					set = true;
					break;
				}
				else result.push_back(store[i].second);
			}
		if(set) cout << "-1";
		else
		{
			for (double i = 0;i < result.size();i++) 
				{
					if(i != result.size() - 1)
						cout << result.at(i) << ' ';
					else cout << result.at(i);
		
				}
		}
		cout << endl;

	}
}	



