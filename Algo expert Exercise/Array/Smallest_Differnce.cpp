#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


// #Question 3: Smallest Differnce Between Two array Elements. O(M*logM + N*logN) - O(1).



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


	int m,n,p1,p2,temp,min_val,dif;
	vector<int> first,second;
	cin >> m >> n;
	while(m--)
	{
		cin >> temp;
		first.push_back(temp);
	}
	while(n--)
	{
		cin >> temp;
		second.push_back(temp);
	}

	sort(first.begin(),first.end());
	sort(second.begin(),second.end());


	p1 = 0;
	p2 = 0;
	m = first.size();
	n = second.size();
	min_val = 3432323;
	pair<int,int> result;
	while(p1 != m && p2 != n)
	{
		dif = abs(first[p1] - second[p2]);
		if(min_val > dif)
		{
			result.first = first[p1];
			result.second = second[p2];
			min_val =dif;
		}
		if(first[p1] == second[p2])
		{
			break;
		}
		else if(first[p1] < second[p2])
		{

			p1++;
		}
		else
		{
			p2++;
		}
	}
	cout << "Smallest Differnce is " << result.first << '-' << result.second << '=' << min_val << endl;
	return 0;
	
}	



