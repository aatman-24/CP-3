#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;


int main()
{

	ll int m,n,cost,temp,first,second;
	multiset<ll int> s;
	while(true)
	{
		
		cin >> m;
		if(m == 0) break;
		cost = 0;
		while(m--)
		{
			cin >> n;
			while(n--)
			{
				cin >> temp;
				s.insert(temp);
			}
			first = *s.begin();
			second = *s.rbegin();
			cost += (second - first);

			s.erase(s.find(first));
			s.erase(s.find(second));
		}

		cout << cost << endl;
		s.clear();	
	}
	return 0;
}	



