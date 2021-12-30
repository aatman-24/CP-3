#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;


string change_into_lower(string s)
{
	int n = s.length()-1;
	string new_string = "";
		for(int i = 0;i<=n;i++)
		{
			if ((int(s[i]) >= 65) && (int(s[i]) <= 122))
			{
				if (s[i] < 91)
				{
					new_string += char(int(s[i])+32);
				}
				else
				{
					new_string += s[i];
				}	
			} 
		}
	return new_string;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	std::vector<bool> anagram;
	std::vector<string> og_string;
	std::vector<string> lower_string;
	std::vector<string> result;

	while(1)
	{

		cin >> s;
		if (s == "#")
		{
			break;
		}
		og_string.push_back(s);
		lower_string.push_back(change_into_lower(s));	
	}

	int n = og_string.size();
	for (double i=0; i < n ;i++)
	{
		sort(lower_string.at(i).begin(),lower_string.at(i).end());
	
	}
	
	anagram.assign(n,true);
	for (double i=0;i < n;i++)
	{
		if (anagram.at(i))
		{
			for (double j = 0; j < n ;j++)
			{
				if ((lower_string[i] == lower_string[j]) && (i != j))
				{
					anagram[i] = false;
					anagram[j] = false;
				}
			}
		}
	}
	for (double i = 0 ; i < n ;i++)
	{
			if (anagram.at(i))
			{
				result.push_back(og_string.at(i));
			}
	}
	sort(result.begin(),result.end());
	for (double i = 0;i< result.size() ;i++)
	{
		cout << result.at(i) << endl;
	}

}



