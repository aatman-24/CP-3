#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<string> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << endl;
	}
}


bool group_checker(int a,std::vector<bool> &group)
{
	return group[a];
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int test_cae;
	// cin >> test_cae;
	while(cin >> test_cae)
	{
		if (test_cae == 0) break;
		int number_of_edges;
		cin >> number_of_edges;
		std::vector<bool> red;
		std::vector<bool> black;
		red.assign(200,false);
		black.assign(200,false);


		std::vector<int> first_node_store;
		std::vector<int> second_node_store;
		int turn = 1;
		while(number_of_edges--)
		{
			int first_node,second_node;
			cin >> first_node >> second_node;
			first_node_store.push_back(first_node);
			second_node_store.push_back(second_node);
		}
		for (double i = 0 ; i < first_node_store.size() ; i++)
		{

			int first = first_node_store.at(i);
			int second = second_node_store.at(i);

			// cout << first << second << endl;

			if (red[first] == true)
			{	
			
				if ((red.at(second))) 
					{
						cout << "NOT BICOLORABLE.\n";
						turn = 0;
						break;
					}
				black[second] = true;
			}
			else if (black[first] == true)
				{
					if(black.at(second))
					{
						 cout << "NOT BICOLORABLE.\n";
						 turn = 0;
						 break;
					}
 					red[second] = true;
				}
			else
			{
				if ((red[first] && red[second]) || (black[first] && black[second]))
				{
					cout << "NOT BICOLORABLE.\n";
					turn = 0;
					break;
				}
				red[first] = true;
				black[second] = true;
			}
		}
		if(turn) cout << "BICOLORABLE." << std::endl;	
	}
}	



