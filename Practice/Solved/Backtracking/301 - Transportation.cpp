#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<iii> viii;

viii passangers;
vi temp;
vi last_to_drop;
int best_cost,CAPCITY,num_orders,M;


void display(viii arr)
{
	for(double i = 0 ; i < arr.size() ; i++) cout << i << ' ' << arr[i].first.first << '|' << arr[i].first.second << '|' << arr[i].second << endl;
}


void display(vi arr)
{
	for(double i = 0 ; i < arr.size() ; i++) cout << arr[i] << ' ';
	cout << endl;
}


bool isvalid(int i,int cur_cap)
{
	int pre_cost = 0;
	pre_cost = accumulate(last_to_drop.begin(),last_to_drop.begin() + passangers[i].first.first + 1,0);
	if(cur_cap + passangers[i].second - pre_cost > CAPCITY) return false;
	return true;

}


void backtracking(int nIndex,int cur_cost,int cur_cap)
{

	if(best_cost < cur_cost) best_cost = cur_cost;

	if(nIndex == num_orders)
	{
		return;
	}


	for(int i = nIndex; i < num_orders ; i++)
	{
		
		if(isvalid(i,cur_cap))
		{

			int start_p = passangers[i].first.first;
			int end_p = passangers[i].first.second;
			int nPassanger = passangers[i].second;
			int cost = (end_p - start_p) * nPassanger;

			//int start_p_index_cost = last_to_drop[start_p]; (If we don't add this three line that will be also okay)
			//last_to_drop[start_p] = 0;   						(bcz isvalid() sum the previous value.)
			last_to_drop[end_p] += nPassanger; 

			cur_cap = cur_cap - start_p_index_cost + nPassanger;
			cur_cost += cost;			
			
			backtracking(i+1, cur_cost, cur_cap);

			cur_cost -= cost;
			cur_cap = cur_cap + start_p_index_cost - nPassanger;

			last_to_drop[end_p] -= nPassanger;
			//last_to_drop[start_p] = start_p_index_cost;

			
		}
	}

}


bool sort_fun(iii p1, iii p2)
{
	if(p1.first.first < p2.first.first) return true;
	if(p1.first.first == p2.first.first && p1.first.second < p2.first.second) return true;
	if(p1.first.first == p2.first.first && p1.first.second == p2.first.second && p1.second < p2.second) return true;
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	


	int start,end,nPassanger_n;

	while(cin >> CAPCITY >> M >> num_orders)
	{
		if(!(CAPCITY || M || num_orders)) break;

		passangers.clear();
		last_to_drop.assign(M+1,0);
		temp.assign(num_orders,0);
		for(int i = 0; i < num_orders; i++)
		{
			cin >> start >> end >> nPassanger_n;
			passangers.push_back({{start,end}, nPassanger_n});
		}
		sort(passangers.begin(),passangers.end(),sort_fun);

		best_cost = INT_MIN;
		backtracking(0,0,0);
		cout << best_cost << endl;
	}





	

	return 0;
}

