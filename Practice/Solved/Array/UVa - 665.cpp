#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<int> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';
	}
	cout << endl;
}


const int token = -1039243;

void do_calculate(vector<int> &main,char op,vector<int> &left,vector <int> &right)
{
	int n =	left.size();
	for (double i = 0 ; i < n; i++)
	{
		if(op == '=')
		{
			if(main[left.at(i)] != token) main[left.at(i)] = token;
			if(main[right.at(i)] != token) main[right.at(i)] = token;
		}
		else if(op == '<')
		{
				if(main[left.at(i)] != token) main[left.at(i)]--;
				if(main[right.at(i)] != token) main[right.at(i)]++;
		}
		else
		{
				if(main[left.at(i)] != token) main[left.at(i)]++;
				if(main[right.at(i)] != token) main[right.at(i)]--;
		}
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

	int t; cin >> t;
	int m = t;
	while(t--)
	{
		
		int equal_sign = 0;
		int size_of_main,total_line;
		cin >> size_of_main >> total_line;
		std::vector<int> main(size_of_main+1,0);
		int target_value = total_line;
		while(total_line--)
		{
			int coin_in_panel;
			cin >> coin_in_panel;
			int temp = coin_in_panel;
			std::vector<int> left;
			std::vector<int> right;
			while(temp--)
			{
				int temp; cin >> temp;
				left.push_back(temp);
			}
			temp = coin_in_panel;
			while(temp--)
			{	
				int temp; cin >> temp;
				right.push_back(temp);
			}
			char op; cin >> op;
			if(op == '=') equal_sign++;
			do_calculate(main,op,left,right);
		}
		target_value -= equal_sign;
		int which,how_much = 0;
		for (int i = 1; i <= size_of_main; i++)
		{
			if((abs(main.at(i)) == target_value))
			{
				how_much++;
				which = i;
			}
		}
		if(t+1 != m) cout << "\n";
		if (how_much == 1)
			{	
				cout << which << "\n";
			}	
		else cout << "0\n";
	}
	
}	



