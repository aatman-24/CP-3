#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;
typedef map<char,int> mci;

int map_of_string(string &s,mci &mapper)
{
	int unique = 0;
	for(double i = 0 ; i < s.length() ; i++)
	{
		if(mapper.find(s[i]) == mapper.end())
		{
			mapper[s[i]] = 1;
			unique++;
		}
		else
		{
			mapper[s[i]] += 1;
		}
	}
	return unique;
}

int first_traversal_to_find_L_R(string &s,mci &match,mci &cur,int &i,int count)
{
	int unique = 0;
	while(i < int(s.length()))
	{
		if(match.find(s[i]) != match.end())
		{
			if(cur.find(s[i]) == cur.end()) 
			{
				cur[s[i]] = 1;
			}
			else
			{
				if(cur[s[i]] != match[s[i]])
					{
						cur[s[i]] += 1;
					}
				
			}
			if(cur[s[i]] == match[s[i]]) unique++;
			if(unique == count) return unique;
		}
		i++;
	}
	return -1;
}

void increase_L_repair_super_map(char ch,mci &super,mci &sub,int &count)
{
	if(sub.find(ch) != sub.end())
	{
		if(super[ch] == sub[ch]) count--;
		super[ch] -= 1;
	}
}

void increase_R_repair_super_map(char ch,mci &super, mci &sub,int &count)
{
	if(super.find(ch) == super.end())
	{
		super[ch] = 1;
	}
	else super[ch] += 1;
	if(super[ch] == sub[ch]) count++;
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	string super,sub;
	mci super_map,sub_map;


	int t; cin >> t;
	while(t--)
	{
		super_map.clear(),sub_map.clear();	
		cin >> super >> sub;
		int sub_unique_char = map_of_string(sub,sub_map);
		int n = int(super.size());
		int result = n;
		int L = 0 ,R = 0;
		int super_unique_char = first_traversal_to_find_L_R(super,sub_map,super_map,R,sub_unique_char);
		if(super_unique_char == -1)
		{
			cout << "Not contain all the characters of substrings\n";
		}
		else
		{
			while(R < n)
			{
				if(sub_unique_char == super_unique_char)
				{
					increase_L_repair_super_map(super[L],super_map,sub_map,super_unique_char);
					L++;
				}
				else
				{
					R++;
					if(sub_map.find(super[R]) != sub_map.end())
					{
						increase_R_repair_super_map(super[R],super_map,sub_map,super_unique_char);
					}
				}
				if(sub_unique_char == super_unique_char && (R - L) < result)
				{
					result = R - L;				}
			}
			cout << "Length is \t" << ':' << min(result+1,n)  << endl;
		}

	}
	return 0;

}