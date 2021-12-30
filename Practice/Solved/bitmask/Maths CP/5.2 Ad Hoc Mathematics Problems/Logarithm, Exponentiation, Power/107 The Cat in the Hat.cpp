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

double EPS = 1e-12;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

// #Approach : Here We are given Height of the first node = H and Last Level Worker = NW.

// Every Time Is diveded by N+1.

// So At a time when (H/(N+1)^K) == 1. ---- (1)

// But What is the Value of K?

// K is the level....

// For finding the K we use the not_work worker value.

// We know that for the last level == 1 we have total workers NW.

// So we can write tree property ... for the last level total nodes = N ^ level

// Here NW = N ^ K. --------- (2)

// We got this equation... 

// H = (N + 1) ^ (log(base=N,NW))...

// H = (N + 1) ^ (logN(NW))..

// after calculation we got..

// log(H) / log(NW) = log10(N+1)/log10(N) ------------ (3).




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int level,H,N,NW,not_work,total_height;
	vi heights, power_of_level;

	while(cin >> H >> NW)
	{
		if(NW == 0 && H == 0) break;

		heights.clear(); power_of_level.clear();
		double lgH_lgNW = log(H)/log(NW);

		int i = 1;
		while(log(i+1)/log(i) - lgH_lgNW >= EPS) i++;

		N = i; // Total Cat.
		level = 0;
		

		while(H)
		{
			heights.push_back(H);
			H /= (N + 1);
			level++;
		}

		for(int i = 0; i < level; i++)
		{
			power_of_level.push_back(floor(pow(N,i)));
		}


		not_work = 0;
		total_height = 0;

		for(double i = 0; i < heights.size() ; i++) {
			total_height += heights[i] * power_of_level[i];
			not_work += power_of_level[i];
		}

		not_work -= NW;

		cout << not_work <<  ' ' << total_height << endl;

	}


	return 0;
}

