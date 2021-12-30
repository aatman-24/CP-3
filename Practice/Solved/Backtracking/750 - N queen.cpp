#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;



int N = 8;
vi raws;
int r_initial,c_initial,count_n;


void display(vi arr)
{
	if(count_n <= 9) cout << ' ' << count_n << "      ";
	else cout << count_n << "      ";
	
	// cout << " #\t   1 2 3 4 5 6 7 8\n" << endl;
	for(double i = 0 ; i < arr.size() ; i++) 
	{
		if(i != N - 1)  cout << arr[i]+1 << ' ';
		else cout << arr[i]+1 << endl;
	}
	// cout << endl;
}

bool isvalid(int r,int c)
{
	for(int col = 0 ; col < c ; col++)
	{
		if((raws[col] >= 0 ) && (raws[col] == r || abs(raws[col] - r) == abs(col - c))) return false;
	}
	return true;
}

void backtracking(int col)
{
	if(col == N)
	{
		if(raws[c_initial] == r_initial) {display(raws); count_n++;}
		return;
	}

	for(int raw = 0 ; raw < N; raw++)
	{
		if(isvalid(raw,col))
		{
			int raw_temp = raws[col];
			raws[col] = raw;
			backtracking(col+1);
			raws[col] = raw_temp;
		}
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
	



	int t; cin >> t;
	while(t--)
	{
		cin >> r_initial >> c_initial; r_initial--; c_initial--;

		raws.assign(N,-1);
		raws[0] = 0;
		count_n = 1;
		// SOLN       COLUMN


		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8\n" << endl;
		// cout << r_initial << c_initial << endl;


		backtracking(0);
		// cout << count_n << endl;
		if(t) cout << endl;

	}



	return 0;
}

