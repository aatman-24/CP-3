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

// above A element all are go at intial position
vector<int> do_move(vector<pair<int,vector<int>>> &two_d_array,int i,int a,int where)
{
	vector<int> temp;
	while( a != two_d_array.at(where).second.at(i))
		{
			int element = two_d_array.at(where).second.at(i);
			two_d_array.at(element).second.push_back(element);
			two_d_array.at(element).first = element;
			two_d_array.at(where).second.pop_back();
			i--;
		}
	two_d_array.at(where).second.pop_back();
	temp.push_back(a);
	return temp;
}

// Reverse element from the a -> upper side into pile.
vector<int> do_pile(vector<pair<int,vector<int>>> &two_d_array,int i,int a,int where)
{
	vector<int> temp;
	while( a != two_d_array.at(where).second.at(i))
	{
		int element = two_d_array.at(where).second.at(i);
		temp.push_back(element);
		two_d_array.at(where).second.pop_back();
		i--;
	}
	two_d_array.at(where).second.pop_back();
	temp.push_back(a);
	return temp;

}

// Replace all the element above b
void do_onto(vector<pair<int,vector<int>>> &two_d_array,int j,int b,int where_2)
{
	while( b != two_d_array.at(where_2).second.at(j))
	{
		int element = two_d_array.at(where_2).second.at(j);
		two_d_array.at(element).second.push_back(element);
		two_d_array.at(element).first = element;
		two_d_array.at(where_2).second.pop_back();
		j--;
	}

}



void do_stacking(vector<pair<int,vector<int>>> &two_d_array,int &move,int &onto,int a,int b)
{
	int where = two_d_array.at(a).first;
	double i = two_d_array.at(where).second.size()-1;
	int where_2 = two_d_array.at(b).first;
	double j = two_d_array.at(where_2).second.size()-1;;
	std::vector<int> return_vector;
	if(move) return_vector = do_move(two_d_array,i,a,where);
	else return_vector = do_pile(two_d_array,i,a,where);
	if(onto) do_onto(two_d_array,j,b,where_2);
	int n = return_vector.size();
	while(n--)
	{
		int element = return_vector.at(n);
		two_d_array.at(where_2).second.push_back(element);
		two_d_array.at(element).first = where_2;
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


	std::vector<pair<int,vector<int>>> two_d_array;
	int n; cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		vector<int> v = {i};
		two_d_array.push_back({i,v});
	}

	// Command Start;

	while(1)
	{
		string move_pile,on_over;
		int a,b;
		cin >> move_pile;
		if(move_pile == "quit") break;
		cin >> a >> on_over >> b;
		int move = 0,onto= 0;
		if((a == b) || (two_d_array.at(a).first == two_d_array.at(b).first)) continue;
		if(move_pile == "move") move = 1;
		if(on_over == "onto") onto = 1;;
		do_stacking(two_d_array,move,onto,a,b);

	}

	// format the output
	for(double i = 0 ; i < two_d_array.size();i++)
	{
		cout << i << ":";
		vector<int> temp = two_d_array.at(i).second;
		for(double j = 0 ; j < temp.size(); j++)
		{
			cout << ' ' << temp.at(j);
		}
		cout << endl;
	}
	
}	


