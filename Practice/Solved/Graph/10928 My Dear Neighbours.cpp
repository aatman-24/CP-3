#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;


void display(vector<ii> &vii)
{
	int n = vii.size();
	for (int i = 0; i < n; i++)
	{
		cout << vii[i].first << ' ' << vii[i].second << endl;
	}
}


// #Explaination : Here we need to find the place for the portegues man where the neighbours is fewest if more than one place found
// we have to return all the place. (very simple) here we used the getline() string method and count total neighbours.

int deilimiter_string_by_space(string &s)
{
	int count = 0;
	for(double i = 0 ; i < s.size() ;i++)
	{
		if (s[i] == ' ') count++;  //(Here we count space bcz ele is space+1) [11 2 3 4] space = 3, ele = space + 1 = 4
	}
	return count+1;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	vector<ii> vii;

	int t; cin >> t;
	string s;
	while(t--)
	{
		int p; cin >> p;
		vii.clear();
		getline(cin,s);
		for (int i = 0; i < p; i++)
		{
			getline(cin,s);
			int count_ele = deilimiter_string_by_space(s);
			vii.push_back({count_ele,i+1});

		}
		sort(vii.begin(),vii.end());
		int min_val = vii[0].first;
		cout << vii[0].second;
		for (double i = 1; i < vii.size(); i++)
		{
			if(vii[i].first == min_val) cout << ' ' << vii[i].second;
			else break;
		}
		cout << endl;
	}

	return 0;

}