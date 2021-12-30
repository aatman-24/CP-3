#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


int index_finder(string name,std::vector<string> v)
{
	for (double i = 0;i < v.size();i++)
	{
		if (name == v[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	while(cin)
	{
		int nFriend;
		cin >> nFriend;
		std::vector<string> nameFriend;
		std::vector<double> receive;
		receive.assign(nFriend,0);
		for (int i=0;i<nFriend;i++)
		{
			string st;
			cin >> st;
			nameFriend.push_back(st);
		
		}
		int n = nFriend;
		while (n--)
		{
			string sender;
			int total_money,gift_people;
			cin >> sender >> total_money >> gift_people;
			if(total_money)
			{
				int in_sender = index_finder(sender,nameFriend);
				receive[in_sender] -= total_money;
				if(gift_people)
				{
					int amount_given;
					amount_given = total_money / gift_people;
					receive[in_sender] += total_money - (amount_given)*(gift_people);
					while(gift_people--)
					{
						string receiver;
						cin >> receiver;
						int re_in = index_finder(receiver,nameFriend);
						receive[re_in] += amount_given;
					}
				}
			}

		}
		for (int i=0;i<nFriend;i++)
			{
				cout << nameFriend[i] << " " << receive[i] << endl;
			}
			cout << endl;
	}
	return 0;
}

