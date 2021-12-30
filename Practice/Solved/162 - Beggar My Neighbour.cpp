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


	int t = 1;
	while(t--)
	{
		std::vector<int> non_dealer;
		std::vector<string> all_card;
		std::vector<int> dealer;
		std::vector<int> stack;
		int j = 0;

		while(cin)
		{
			string s;
			cin >> s;
			if (s == "#")
			{
				break;
			} 
			else
			{	
				int i = num_of_card(s,unique_card);
				all_card.push_back(s);
				if (j % 2 == 0)
				{
					non_dealer.push_back(i);
				} 	
				else
				{
					dealer.push_back(i);
				}
				j++;
			}
		}

		int turn = 0, n = 1;
		int set = 0;
		int b;
		cout << "helos";
		while (!(non_dealer.empty()) | (dealer.empty()))
		{
			if (turn == 0)
			{
				
				while(n--)
				{
					int checker = non_dealer.back();
					non_dealer.pop_back();
					stack.push_back(checker);
					b = check_special_card(checker,&set);
					if (b > 0)
					{
						n = b;
						turn = 1;
						break;
					}	
				}
				if ((b == -1) & (set == 1))
					{
						add_card_at_back(dealer,stack);
						set = 0;
					}
				turn  = 1;
				if (n == 0)
				{
					n = 1;
				}
			}
			else
			{
				
				while(n--)
				{
					int checker = non_dealer.back();
					dealer.pop_back();
					stack.push_back(checker);
					b = check_special_card(checker,&set);
					if (b > 0)
					{
						n = b;
						turn = 1;
						break;
					}	
				}
				if ((b == -1) & (set == 1))
					{
						add_card_at_back(non_dealer,stack);
						set = 0;
					}
				turn  = 0;
				if (n == 0)
				{
					n = 1;
				}
			}
		}
		if (non_dealer.empty())
			{

				cout << "1" << dealer.size () << endl;
			}
		else
			{
				cout << "0" << non_dealer.size() << endl;
			}
	}
		
}



