#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include<algorithm>
#define ll long long


using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	// int n,temp;
	int n,temp,first_boudary,r2,r3;
	vector<int> data;
	while(cin >> n)
	{
		for(int i = 0;i < n ;i++)
		{
			cin >> temp;
			data.push_back(temp);
		}


		sort(data.begin(),data.end());
		// int lowest_a1,r2,r3;

		first_boudary = data[(data.size() - 1)/2]; // First boundary is the minimum value.

		r2 = upper_bound(data.begin(),data.end(),first_boudary) - lower_bound(data.begin(),data.end(),first_boudary);

		if(data.size() % 2)   // when n is odd 
		{
			r3 = 1;
		}
		else
		{
			if(data[(data.size()-1)/2] ==  data[(data.size()/2)])
			{
				r3 = 1;
			}
			else
			{
				r3 = data[(data.size()/2)] -  data[(data.size()-1)/2] + 1;
			}
			if(r3 != 1)
			{
				int second_boud = data[data.size()/2];
				r2 += upper_bound(data.begin(),data.end(),second_boud) - lower_bound(data.begin(),data.end(),second_boud);

			}

		}
	

		cout << first_boudary << ' ' << r2 << ' ' << r3 << endl;
		data.clear();


	}



}	



