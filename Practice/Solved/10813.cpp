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

	int t ;
	cin >> t;
	while(t--){
		double p,q;
		cin >> p >> q;
		double a = (p + q)/2.0;
		double b = (p-q)/2.0;

		if ((a - int(a) != 0) || (b - int(b) != 0) || (a < 0) || (b < 0))
		{
			cout << "impossible" << endl;
		}
		else
		{
			cout <<  fixed  << int(a) << ' ' << int(b) << endl;
		}
	}
	
}	



