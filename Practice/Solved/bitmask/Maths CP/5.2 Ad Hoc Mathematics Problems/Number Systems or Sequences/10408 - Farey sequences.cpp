#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


// a/b c/d p/q three terms

// p = floor((b+n)/ d) * (c - a)
// q = floor((b+n)/ d) * (d - b)

// next time,
// a = c,  b = d, c = p, d = q and again we have to find p and q which is next term.

// How ? check on wikipedia.



int gcd(int A,int B){
    if (B == 0)
        return A;
    if (A == 0)
        return B;
    return gcd(B, A%B);	
}



void farey(int n,int k) // O(N).
{
	if(k == 1) printf("1/%d\n",n);
	else
	{
		double x,y=0;
		double x1=0, y1=1, x2=1, y2=n;

		k--; 								// we have to find k-1 term.
		while(k--)
		{
			x = floor((y1+n)/y2) * x2 - x1;
			y = floor((y1+n)/y2) * y2 - y1;
			x1 = x2; y1 = y2; x2 = x; y2 = y;
		}
		printf("%.0f/%.0f\n",x,y);
	}

}

void brute_force()  // O(N^2 * logN)
{
	vector<pair<double,pair<int,int>>> arr;
	int n,k;

	set<pair<double,pair<int,int>>> st;

	int prev_n = 1;
	while(cin >> n >> k)
	{
		st.clear();

		if(prev_n != n)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j < i; j++)
				{
					if(gcd(i,j) == 1)
					{
						st.insert({(double)j/i,{j,i}});
					}
				}
			}
			prev_n = n;
		}
	
		arr.assign(st.begin(),st.end());
		cout << arr[k-1].second.first << '/' << arr[k-1].second.second << endl;
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

	int n,k;
	while(cin >> n >> k)
	{
		farey(n,k);
	}


	return 0;
}
