#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <iterator>
#include <math.h>
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


	std::multiset<int>::iterator iter ;
	multiset<int> elements;
	ll int x;
	int n = 0;
	while(cin >> x)
	{

		elements.insert(x);
		n++;
		iter = elements.begin();

		std::advance(iter,(n-1)/2);
		ll int first = *iter;
		if(n % 2)
		{
			cout << first << endl;
		}
		else
		{
			std::advance(iter,1);
			ll int second = *iter;

			cout << std::fixed << int(ceil((first+second)/2)) << endl;
		}
	}


}	



