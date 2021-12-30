#include <bits/stdc++.h>
#include <iostream>
#define lls long long


using namespace std;




void display(std::vector<std::vector<int>> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		for(double j = 0 ; j < temp.at(i).size(); j++)
		{
			cout << temp.at(i).at(j) << ' ';
		}
		cout << endl;
	}
}

void display(std::vector<int> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';	
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


	string s,ll;
	deque<string> all_word;

	while(getline(cin,s))
	{
		int i = 0,set = 1;
		int n = s.size();

		
		ll="";
		
		while(i < n)
		{

			if(s[i] == '[')
			{

				if(set) all_word.push_front(ll);
				else all_word.push_back(ll);
				ll = "";
				set = 1;
			}
			else if ((s[i] == ']') )
			{
				if(set) all_word.push_front(ll);
				else all_word.push_back(ll);
				ll = "";
				set = 0;

			}
			else if ((s[i] != ']') && (s[i] != '['))
			{
				ll += s[i];
			}
			i++;
			if(i == n)
			{
				if(set) all_word.push_front(ll);
				else all_word.push_back(ll);
			}
			
		}

		double limit = all_word.size();
		string result = "";
		for(double k = 0 ; k < limit  ;k++)
		{
			result += all_word.at(k);
		}
		cout << result << endl;
		all_word.clear();
	}

	


}	



