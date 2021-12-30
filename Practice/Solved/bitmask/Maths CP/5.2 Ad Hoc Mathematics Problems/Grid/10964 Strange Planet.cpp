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

ll MAX_POINTS = 1000000000;
vi arr;
int x,y,val,i;



ii find_cordinates_of(int N)
{
	i = 0;
	while(arr[i] < N) i++;
	val = arr[i];
	// cout << i << "-------" << val << endl;
	if(arr[i] == N) return{-i,0};
	else
	{
		if(N < val && N >= val - i)
		{

			x = -i; y = 0;
			while(val != N)
			{
				x++; y--;
				val--;
			}
		}
		else if(N < val-i && N >= val - 2*i)
		{
			x = 0; y = -i;
			val = val - i;			
			while(val != N)
			{
				x++; y++;
				val--;
			}
		}
		else if(N < val-(2*i) && N >= val - (3*i))
		{
			val = val - (2*i);
			x = i; y = 0;
			while(val != N)
			{
				x--; y++;
				val--;
			}
		}
		else
		{
			val = val - (3*i);
			x = 0; y = i;
			while(val != N)
			{
				x--; y--;
				val--;
			}
		}
	}
	return {x,y};
}




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll prev = 0,i = 0;;
	while(prev <= MAX_POINTS)
	{
		prev += (4 * i);
		arr.push_back(prev);
		i++;
	}

	int N,M;
	double x_dist,y_dist,result;

	while(cin >> N >> M)
	{
		if(N < 0 || M < 0) break;

		if(N == M)
		{
			result = 0;
			printf("%.2f\n",result);

		}
		else
		{
			ii p1 = find_cordinates_of(N);
	  		ii p2 = find_cordinates_of(M);
	  		x_dist = p1.first - p2.first; y_dist = p1.second - p2.second;
			result = sqrt(x_dist*x_dist + y_dist*y_dist);
			// printf("[%d,%d] - [%d,%d]\n",p1.first,p1.second,p2.first,p2.second);
			printf("%.2f\n",result);
		}

	  // 
		// for(double i = 0 ; i < arr.size() ; i++) cout << arr[i] << ' ';
		// cout << endl;

	}


	return 0;
}

