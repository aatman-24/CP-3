#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <bitset>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


// #Approach : we have given initial pos of queen. we have to find all queen pos with minimum
// step to get no attack pos.we have given (n < 1000) test case.
// queen can move more than one moves at a time.Here we first find all the pos for 8 queen.
// than we find minimum step to take(it is means minimum number of raw has not same value when we
// 	check).


int N = 8;
vi cols;
vvi all_pos;


bool isvalid(int r,int c)
{
	for(int raw = 0; raw < r; raw++)
	{
		if((cols[raw] >= 0) && (cols[raw] == c || (abs(cols[raw] - c) == abs(raw - r)))) return false;
	}
	return true;
}


bitset<30> cw,rd,ld;


void backtracking(int r)
{
	if(r == N) {all_pos.push_back(cols); return;}

	for(int c = 0; c < N; c++)
	{
		if(cw[c] != true && rd[r+c] != true && ld[r-c+N-1] != true)
		{
			cw[c] = rd[r+c] = ld[r-c+N-1] = true;
			int c_t = cols[r];
			cols[r] = c + 1;
			backtracking(r+1);
			cw[c] = rd[r+c] = ld[r-c+N-1] = false;
			cols[r] = c_t;
		}
	} 
}

void find_distance_min(vi given_cols,vi cols,int &min_dist)
{

	int temp_dist = 0;
	for(int i = 0 ; i < N ; i++)
	{
		if(cols[i] != given_cols[i]) temp_dist++;
	}
	if(temp_dist < min_dist) 
	{	
		min_dist = temp_dist;
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



	cols.assign(N,-1);
	cols[0] = 0;
	backtracking(0);


	int a,min_dist;
	vi given_cols(N,0);
	int t = 1;
	while(cin >> a)
	{
		given_cols[0] = a;
		for(int i = 1; i < 8 ; i++) cin >> given_cols[i];


		min_dist = INT_MAX;
		for(double i = 0 ; i < all_pos.size() ; i++)
		{
			find_distance_min(given_cols, all_pos[i], min_dist);
		}

		cout << "Case " << t++ << ": " << min_dist << endl;
	}


	return 0;
}

