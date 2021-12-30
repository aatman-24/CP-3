// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
// #define ll long long


using namespace std;

// void display(std::vector<std::vector<int>> temp)
// {
// 	for (double i=0; i < temp.size() ; i++)
// 	{
// 		for(double j = 0 ; j < temp.at(i).size(); j++)
// 		{
// 			cout << temp.at(i).at(j) << ' ';
// 		}
// 		cout << endl;
// 	}
// }

// void display(std::vector<int> temp)
// {
// 	for (double i=0; i < temp.size() ; i++)
// 	{
// 		cout << temp.at(i) << ' ';
// 	}
// 	cout << endl;
// }


void rotate_me(std::vector<int> &temp)
{
	int last = temp.at(temp.size()-1);
	for (double i = temp.size()-1; i > 0 ; i--)
	{
		temp.at(i) = temp.at(i-1);
	}
	temp[0] = last;
}


int check_all_element_is_same_or_not(const vector<int> main,const vector<int> ch,vector<int> &temp)
{
	int n = main.size();
	int index = 0;
	while(index < n)
	{
		if(main.at(index) != ch.at(index) + temp.at(index)) return 0;
		index++;
	}
	return 1;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;
	while(cin >> n >> m,(n||m))
	{
		std::vector<int> ver_main(n,0);
		std::vector<int> hor_main(n,0);
		string s;
		for(int i = 0 ; i < n;i++)
		{
			cin >> s;
			for(int j = 0 ; j < n;j++)
			{
				if(s.at(j) == '*')
				{
					ver_main.at(i) += 1;
					hor_main.at(j) += 1;
				}
			}
		}
		std::vector<int> ver_temp(n,0);
		std::vector<int> hor_temp(n,0);
		for(int i = 0 ; i < m;i++)
		{
			cin >> s;
			for(int j = 0 ; j < m;j++)
			{
				if(s.at(j) == '*')
				{
					ver_temp.at(i) += 1;
					hor_temp.at(j) += 1;
				}
			}
		}
		int count = n;
		int set = 0;
		int t,p,x;
		while(count--)
		{	
			x = n;
			vector<int> rotate_vec_ver(ver_temp);
			while(x--)
			{
				if(check_all_element_is_same_or_not(ver_main,ver_temp,rotate_vec_ver))
				{	
					t = n;
					while(t--)
					{
						p = n;
						vector<int> rotate_vec_hoz(hor_temp);
						while(p--)
							{
							if(check_all_element_is_same_or_not(hor_main,hor_temp,rotate_vec_hoz))
								{
									set = 1;
								}
							rotate_me(rotate_vec_hoz);
							}
							if(set) break;
						rotate_me(hor_temp);
					}
					if(set) break;	
				}
				if(set) break;
				rotate_me(rotate_vec_ver);
			}
			if(set) break;	
			rotate_me(ver_temp);
		}
		cout << set << endl;
	}
}	



