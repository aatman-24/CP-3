#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
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


	int n,m,temp;
	while(cin >> n >> m, (n || m))
	{
		set<int> num;
		for(int i = 0 ; i < n ;i++)
		{
			cin >> temp;
			num.insert(temp);
		}
		for(int i = 0 ; i < m ;i++)
		{
			cin >> temp;
			num.insert(temp);
		}
		cout << (n+m) - num.size() << endl;
	}
	return 0;
}	



