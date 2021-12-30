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

vii pairs;
vi result,visited;
int size,set_;
int N,a,b;

void display(vii &arr)
{
	for(double i = 0 ; i < arr.size(); i++) cout << arr[i].first << '|' << arr[i].second << endl;
		cout << endl;
}

void display(vi &arr)
{
	cout << "1" << ' ';
	for(double i = 0 ; i < arr.size(); i++)
	{
		if(i != arr.size() - 1) cout << arr[i] << ' ';
		else cout << arr[i] << endl;
	}
	 
}



bool isValid(int index,int preValue, int j)
{
	// display(result);
	// display(visited);
	// cout << pairs[index].first << '|' << preValue << '|' << pairs[index].second << endl;
	if(j < N - 1 && (pairs[index].first != preValue || visited[pairs[index].second])) return false;
	if(j == N - 1 && (pairs[index].first != preValue || pairs[index].second != 1 )) return false;
	// cout << "Its true" << endl;
	return true;
}



bool backtracking(int nIndex,int preValue)
{
	if(nIndex == N) {display(result); return true;}



	for(int i = 0; i < size; i++)
	{
		if(isValid(i, preValue, nIndex))
		{
			
			int temp = result[nIndex];
			result[nIndex] = pairs[i].second;
			visited[pairs[i].second] = 1;
			

			if(backtracking(nIndex+1, pairs[i].second)) return true;
		
			visited[pairs[i].second] = 0;
			result[nIndex] = temp;

		}
	}
	return false;

}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	char l;
	while(scanf("%d\n",&N) != EOF)
	{
		pairs.clear();
		while(scanf("%d %d\n",&a,&b))
		{
			pairs.push_back({a,b});
			pairs.push_back({b,a});
		}


		size = (int)pairs.size();
		result.assign(N,0);
		visited.assign(N+1,0);
		visited[1] = 1;

		if(!backtracking(0,1)) cout << 'N' << endl;
		scanf("%c",&l);
	}
	return 0;
}

