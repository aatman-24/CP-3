#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;


bool palindrome_or_not(string s)
{
	int n = s.length();
	if ((n % 2) == 0)
	{
		for (int i=0; i < (n/2);i++)
		{
	
			if (s[i] != s[n-1-i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int i=0; i < (n/2);i++) 	
		{
			if (s[i] != s[n-1-i])
			{
				return false;
			}
		}
		return true;
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

	

	string s;
	while(cin)
	{
	
		getline(cin,s);
		if (s == "DONE") break;
		int n = s.length();
		string new_string = "";
		for (int i = 0;i<=n;i++)
		{
			if ((int(s[i]) >= 65) && (int(s[i]) <= 122))
			{
				if (s[i] < 97)
				{
					new_string += char(int(s[i])+32);
				}
				else
				{
					new_string += s[i];
				}
				
			} 
		}
		if (palindrome_or_not(new_string))
		{
			cout << "You·won't·be·eaten!" << '\n';
		}
		else 
		{
			cout << "Uh oh.." << '\n';
		}

	}
}



