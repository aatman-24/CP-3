#include <bits/stdc++.h>
#include <iostream>
#define ll long long


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


	
	// int circle_counter;
	long x,y;
	
	long inner_circle_max_pos;
	vector<int> where_to_check;
	vector<pair<long,long>> corner_checker;
	long k;
	double sz,p;
	while(cin >> sz >> p, (sz || p))
	{

		if (p == 1)
		{
			cout << "Line = "  << ceil(sz/2) << ", column = " << ceil(sz/2)  << '.' << endl;
			continue;
		}

		// find ring max value.
		long temp = sz;
		
		while(p <= (temp*temp))
		{
			inner_circle_max_pos = temp;
			temp = temp - 2;
		}
		long temp_square = (inner_circle_max_pos * inner_circle_max_pos);
		long n = inner_circle_max_pos;
		long temp_temp_square = temp_square;
		corner_checker = {{n,n},{1,n},{1,1},{n,1}};
		k = 4;
		while(k--)
		{
			where_to_check.push_back(temp_temp_square);
			temp_temp_square -= (n-1);
		}
		long i = 0;
		long index = i ;
		while((i <= 3) && (p <= where_to_check.at(i)))
		{
			index = i;
			i++;
		}
		x = corner_checker.at(index).first;
		y = corner_checker.at(index).second;
		temp_square = where_to_check.at(index);
		i = 0;
		while(p != temp_square)
		{
			if(index == 0)
			{
				x--;
			}
			else if(index == 1)
			{
				y--;
			}
			else if(index == 2)
			{
				x++;
			}
			else
			{
				y++;
			}
			temp_square--;
		}
		long inc = (sz - inner_circle_max_pos)/2;
		cout << "Line = "  << x+inc << ", column = " << y+inc << '.' << endl;
		where_to_check.clear();
		corner_checker.clear();
	}
}	



