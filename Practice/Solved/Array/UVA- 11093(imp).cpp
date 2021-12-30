#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<int> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ' ;
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


	int t; cin >> t;
	int j = 0;
	while(j++ < t)								
	{
		int size; cin >> size;
		int n = size;
		vector<int> fuel;
		vector<int> capacity;
		vector<int> right_side(size+2,0);
		vector<int> left_side(size+2,0);

		int temp;
		while(n--)
		{
			cin >> temp;
			fuel.push_back(temp);

		}
		n = size;
		while(n--)
		{
			cin >> temp;
			capacity.push_back(temp);
		}
		n = size;
		int mn,sum = 0;
		int i = 0;
		while(n--)
		{
			sum += fuel[i] - capacity[i];
			i++;
			mn = min(mn,sum);
		}
		i = 0;
		while(mn < 0 && i != size)
		{
			mn -= fuel[i]- capacity[i];
			i++;			
		}
		if(i == size || sum < 0) cout << "Case " << j << " :Not Possible\n";
		else cout << "Case " << j << ": Possilble from station " << i + 1 << endl;
	}

	
}	



