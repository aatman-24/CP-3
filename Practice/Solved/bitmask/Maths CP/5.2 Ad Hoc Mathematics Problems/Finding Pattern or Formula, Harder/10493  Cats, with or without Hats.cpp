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

// Approach : if N == 1 and M == 1 means for cat = k(any number) k - 1 cat's hat have 1 cat but last one 
// does't not have any cat means M = 1 is alwasy true for any k. -> Multiple

// if N = 1 and M != 1 for that suppose cat = K, kth cat which is 1 doesn't have cat so it is not
// possilbe to have cat > 1 such type.


// otherwise you need to use this pattern p = p/n + m; while(p < p / n + m) if you try to draw 
// tree then you easily get.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int N, M;
	while(cin >> N >> M)
	{
		if(N == 0 && M == 0) break;
		if(N == 1)
		{
			if(M == 1) cout << N << ' ' << M << " Multiple" << endl;
			else cout << N << ' ' << M << " Impossible" << endl;
		}
		else
		{
			int p = M;
			int set = 0;
			while(p <= (p/N + M))
			{
				if((p == p/N + M) && ((p-1) % N == 0)) {set=1; break;}
				p++;
			}
			if(set) cout << N << ' ' << M << ' ' << p << endl;
			else cout << N << ' ' << M << " Impossible" << endl;
		}
	}



	return 0;
}

