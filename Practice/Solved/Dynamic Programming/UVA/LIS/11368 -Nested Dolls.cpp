#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define F first 
#define S second

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;
/*
==============================> Apporach <=============================================

Question : 	11368 -Nested Dolls
Topic : DP(LIS)

*/

// 1] Here I sort the height on decrease order. and try to find the LIS which result
// the differnt number of nested dolls. Here One change is that no equal height or 
// width can nested for that you have to handle this case. 
// Work on udebug but not on uva.

// bool sort_fun(ii &p1, ii &p2){
// 			if(p1.first > p2.first) return true;
// 			if(p1.first == p2.first && p1.second <= p2.second) return true;
// 			return false;
// }

// int LIS(vii arr) {
// 	vi lis;
// 	int n = (int)arr.size();

// 	lis.push_back(arr[0].second);
// 	for(int i = 1; i < n; i++) {
// 		int pos = lower_bound(lis.begin(), lis.end(), arr[i].second) - lis.begin();
// 		if(lis.back() <= arr[i].second) { // here when equal also add on lis.
// 			lis.push_back(arr[i].second);
// 		}
// 		else {
// 			if(lis[pos] == arr[i].second) { // not replace the equal value either spread to the right whichever place is best.
// 				int k = lis.size();
// 				while(pos < k) {
// 					if(lis[pos] == arr[i].second) pos++;
// 					else break;
// 				}
// 				if(pos == k) lis.push_back(arr[i].second);
// 				else lis[pos] = arr[i].second;
// 			}
// 			else {
// 				lis[pos] = arr[i].second;
// 			}
			
// 		}
// 	}
// 	return lis.size();
// }



// 2] This is differnt from above ones. sort by the increase order. first dolls can fit to
// the other dolls (latter dolls). so we replace it with this dolls. but if not fit(when the second dolls is small) then current
// we move to this first place.

// h : 10 20 
// w : 10 30

// -> 10 30 -> 10 -> 30(replaced 10) bcz (10 fit into 30).

// h : 10 20 30
// w : 10 20 15

// -> 10 20 15 -> 10 -> 20 (10 fit into the 20 replaced) -> 15 20 -> (20 not fit into the 15 so moved 15 first). 




bool sort_funIN(ii &a, ii &b){
	if(a.first==b.first) return a.second > b.second;
    return a.first < b.first;
}


int LIS(vii arr) {
	int n = (int)arr.size();

	deque<int> lis;
	for(int i = 0; i < n; i++) {
		int pos = lower_bound(lis.begin(), lis.end(), arr[i].second) - lis.begin();
		if(pos == 0) {
			lis.push_front(arr[i].second);
		}
		else {
			lis[pos-1] = arr[i].second;
		}
	}

	return lis.size();
}






int main()
{
	int t; cin >> t;
	vii arr;
	ii p1; 
	while(t--) {
		int n; cin >> n;
		int x = n;
		while(x--) {
			cin >> p1.first >> p1.second;
			arr.push_back(p1);
		}

		sort(arr.begin(), arr.end(), sort_funIN);
		cout << LIS(arr) << endl;
		arr.clear();
	}
}

