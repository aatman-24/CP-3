#include <bits/stdc++.h>
#define ll long long
using namespace std;


void show(vector<int> &v)
{
	for (double i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	while (cin)
	{
	string text;
	getline(cin,text);
	int n = text.length();
	std::vector<char> v;
	for (int i=0;i<n;i++)
	{
		if ((text[i] == '"') && ((i == 0)|(text[i-1] == ' ')))
			{
				v.push_back('`');
				v.push_back('`');
				continue;
			}
		else if (text[i] == '"')
			{
				v.push_back('\'');
				v.push_back('\'');
				continue;
			}
		v.push_back(text[i]);
	}
	for(double i=0;i<v.size();i++)
	{
		cout << v.at(i);
	}

	}
	return 0;		
}



void minimum_beam(int n,int m)
{
		int ans1 = floor(m/3) * floor(n/3);
		cout << ans1 << endl;
}