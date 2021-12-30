#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

#Approach : we have to find minimum move.
1) greedy Approach.
2) It's Ad-hoc type question. which is I given below.
minimum move(cost) it depends on initial location of both even or odd weights.

suppose we have 6 weights, {1,2,3,4,5,6} and now we want to assign even weight to the
// right side than it's  index sum is imp which is given by = (even * even-1)/2;
// suppose even = 3;.




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,x;
	int t; cin >> t;
	while(t--){

		cin >> n;

		ll even=0, odd=0, evensum = 0, oddsum = 0;


		for(int i = 0 ; i < n ; i++){
			cin >> x;
			if(x % 2){
				oddsum += i;
				odd++;
			}
			else
			{
				evensum += i;
				even++;
			}
		}


		ll for_even = evensum - (even*(even-1)/2);
		ll for_odd = oddsum - (odd*(odd-1)/2);

		cout << min(for_even,for_odd) << endl;
	}

	return 0;
}

