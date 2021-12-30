#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<string> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << endl;
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


	int t;
	while(cin >> t)
	{
		int n = t;
		std::vector<bool> visited(t,false);
		std::vector<int> data;
		while(t--)
		{
			int temp; cin >> temp;
			data.push_back(temp);
		}

		for(double i = 0; i < data.size() -1 ;i++)
		{
			int index = abs(data[i]-data[i+1]);
			if((index > n-1) || (index < 1))
			{
				break;
			}
			else
			{
				visited[index] = true;
			}
		}
		int j = 1;
		while(j < n)
		{
			if(!(visited[j]))
			{
				cout << "Not jolly\n";
				break;
			}
			j++;
		}
		if (j == n) cout << "Jolly\n";
	}
}	



