#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<bool> visited;


bool check_its_has_duplicate(int a){
	if(a < 9) return false;

	if(a >= 10 && a <= 99)
	{
		if((a % 10) == (a / 10)) return true;
		else return false;
	}

	visited.assign(10,0);

	while(a != 0)
	{
		if(visited[a%10]) return true;
		visited[a%10] = true;
		a /= 10;
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
	
	int L,U,cunt;

	while(cin >> L >> U)
	{
		cunt = 0 ;
		for(int i = L; i <= U; i++)
		{
			if(!check_its_has_duplicate(i)) cunt++;
		}
		cout << cunt << endl;
	}
	
	


	return 0;
}

