#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

int check_special_card(int c,int *a)
{
	int result ;
	if ((c % 13) == 0)
		{
			// ace
			result  = 4;
			

		}
	else if ((c % 13) == 10)
		{	
			// jack
			result = 1;

		}
	else if ((c % 13) == 11)
		{
			// queen
			result = 2;
		}
	else if ((c % 13) == 12)
		{
			// king
			result = 3;
		}
	else
		{
			result  = -1 ;
		}
	if ((result > 0) & (*a == 0))
			{
				*a = 1;
			}
		return result;	
}

void add_card_at_back(vector<int> &curr,vector<int> &adder)
{
	vector<int> temp;
	while(!(curr.empty()))
	{
		temp.push_back(curr.back());
		curr.pop_back();
	}
	while (!(adder.empty()))
	{
		curr.push_back(adder.back());
		adder.pop_back();
	}
	while(!(temp.empty()))
	{
		curr.push_back(temp.back());
		temp.pop_back();
	}	
}

int num_of_card(string s,vector<char> unique_card)
{
	int i;
	int j = 0;
	if (s[0] == 'S') i = 0;
	else if (s[0] == 'H') i = 13;
	else if (s[0] == 'D') i = 26;
	else i = 39;

	while (!(s[1] == unique_card.at(j)))
	{
		i++;
		j++;
	}
	return i++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	std::vector<char> suits;
	suits ={'S','H','D','C'};

	std::vector<char> unique_card;
	unique_card = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};


	int t;
	t = 1;
	while(t <= 20)
	{
		std::vector<string> all_card;
		int i = 52;
		while(i--)
		{
			string s;
			cin >> s;
			all_card.push_back(s);
		}
		// 33th card because abs(Y+(10-X)+1)*3 times.... >> (X+(10-X)+1)*3 >> 11*3 >> 33
		cout <<  "Case " << t << ": " << all_card.at(33) << endl;
		t++;
	}
		
}



