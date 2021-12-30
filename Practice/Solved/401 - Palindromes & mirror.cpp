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


bool mirror_or_not(string s,vector<int> mapper)
{
	int n = s.length();
	if ((n % 2) == 0)
	{
		for (int i=0; i < (n/2);i++)
		{
			if (mapper.at(int(s[i])) != int(s[n-1-i]))
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int i=0; i <=(n/2);i++) 	// Additional middle character also be mirror itself.
		{
			if (mapper.at(int(s[i])) != int(s[n-1-i]))
			{
				return false;
			}
		}
		return true;
	}
	return true;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	
	// prequisite for mirror mapping.

	std::vector<int> mapper;
	mapper.assign(100,0);
	mapper[char('A')] = char('A');
	mapper[char('E')] = char('3');
	mapper[char('H')] = char('H');
	mapper[char('I')] = char('I');
	mapper[char('J')] = char('L');
	mapper[char('L')] = char('J');
	mapper[char('M')] = char('M');
	mapper[char('O')] = char('O');
	mapper[char('S')] = char('2');
	mapper[char('T')] = char('T');
	mapper[char('U')] = char('U');
	mapper[char('V')] = char('V');
	mapper[char('W')] = char('W');
	mapper[char('X')] = char('X');
	mapper[char('H')] = char('H');
	mapper[char('U')] = char('U');
	mapper[char('V')] = char('V');
	mapper[char('W')] = char('W');
	mapper[char('X')] = char('X');
	mapper[char('Y')] = char('Y');
	mapper[char('1')] = char('1');
	mapper[char('2')] = char('S');
	mapper[char('3')] = char('E');
	mapper[char('5')] = char('Z');
	mapper[char('8')] = char('8');



	// int t = 2;
	while(cin)
	{
		string s;
		cin >> s;

		
		int a = palindrome_or_not(s);	
		int b =  mirror_or_not(s,mapper);

		if(!(a||b))
		{
			cout  << s << " -- is not a palindrome." << '\n';
		}
		else if ((a == 1) && (b == 0))
		{
			cout  << s << " -- is a regular palindrome." << '\n';
		}
		else if ((a == 0) && (b == 1))
		{
			cout  << s << " -- is a mirrored string." << '\n';
		}
		else
		{
			cout  << s << " -- is a mirrored palindrome." << '\n';
		}
		cout << endl;
	}	
}



