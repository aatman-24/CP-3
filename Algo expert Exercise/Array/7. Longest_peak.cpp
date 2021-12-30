#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


// #Question 6: Maximum Peak Range. O(N) - O(N). N = Total Elements.


// # Apporach : Find Peak and find Length.


void display(vector<int> temp)
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


	vector<int> elements;
	int t; cin >> t;


	// (AlgoExpert) - Find Peak and find Length.
	int m,temp,last,max_peak=0,temp_l,peak,first;
	while(t--)
	{
		cin >> m;
		for(int i = 0 ; i < m ;i++)
		{
			cin >> temp;
			elements.push_back(temp);
		}

		// Find Peak
		int i = 1;
		while(i < m - 1)
		{
			if((elements[i] > elements[i-1]) && (elements[i] > elements[i+1]))
			{
				// Go Left - Find Length
				peak = 1;
				temp_l = i;
				while(temp_l >= 0 && elements[temp_l - 1] < elements[temp_l])
				{
					temp_l--;
					peak++;
				}

				// Go right - Find Length
				while(i < m -1 && elements[i] > elements[i+1])
				{
					i++;
					peak++;
				}
				if(max_peak < peak)
				{
					max_peak = peak;
					first = elements[temp_l];
					last = elements[i];
				}
			}
			else
			{
				i++;
			}
		}
		cout << max_peak << endl;
	}
	return 0;
}	



