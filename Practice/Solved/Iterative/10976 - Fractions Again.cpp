#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;

// // #Approach : Here we given 1/k = 1/x + 1/y. (0 < k < 10000).
// if we use two for loop for x and y and check for k than it give TLE.Bcz if k = 10000.
// The inner loop excute for (10 ^ 5 * 10^10).


// So another Approach is just use single loop and find the value of x for given y.
// So we first need to find boundary which is (n+1,2n) inclusive. Then we just get the value of
// x using this -> x = (n*y)/(n-y). when it gives perfect int than we consider this value.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	vii pairs;
	int c;

	double n;
	while(cin >> n)
	{
		c = 0;
		pairs.clear();
		double MIN_LIMIT = 2 * n;
		for(double i = n+1 ; i <= MIN_LIMIT ; i++)
		{
			if(((n*i)/(i - n) - int((n*i)/(i - n))) == 0)
			{
				int ans = (n*i)/(i - n);
				c++;
				pairs.push_back({ans,i});
					
			}
		}
		cout << c << endl;
		for(double i = 0 ; i < pairs.size() ; i++) cout << "1/" << n << " = " << "1/" << pairs[i].first << " + " << "1/" << pairs[i].second << endl;
	}
	return 0;

}