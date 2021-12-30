#include <bits/stdc++.h>
#include <iostream>
#include<vector>
#include <algorithm>
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


	int n,temp,i,j;
	vector<int> red,blue;
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		if(n == 0)
		{
			cout << '0' << endl;
			continue;
		}
		for(int i = 0 ; i < n ;i++)
		{
			cin >> temp;
			if(temp < 0) red.push_back(abs(temp));
			else blue.push_back(temp);
		}
		i = red.size();
		j = blue.size();
		if(i == 0 || j == 0)
		{
			cout << '1' << endl;
			red.clear(); blue.clear();
			continue;
		}
		else if (i == 1 && j== 1) 
		{
			cout << '2' << endl;
			red.clear();blue.clear();
			continue;
		}
		sort(red.begin(),red.end());
		sort(blue.begin(),blue.end());
		i--; j--;
		int set,top,count=0;
		if(red[i] > blue[j])
		{
			top = red[i]; i--; count++;
			set = 0;
		} 
		else
		{
			top = blue[j]; j--; count++;
			set = 1;
		}
		while(i >= 0 &&  j >= 0)
		{
			if(set == 1)
			{
				if(top > red[i])
				{
					top = red[i];
					set  = 0;
					count++;
				}
				i--;
					if((i == -1) && (set == 0))
					{
						while(j >= 0)
						{
							if(top > blue[j])
							{
								count++;
								break;
							}
							j--; 
						}
						
					}
			}
			else 
			{
				if(top > blue[j])
				{
					top = blue[j];
					set = 1;
					count++;
				}
				j--;
					if((j == -1) && (set == 1))
					{
						while(i >= 0)
						{
							if(top > red[i])
							{
								count++;
								break;
							}
							i--;
						}
					}
			}
		}


		cout << count << endl;




		red.clear(); blue.clear();
	}


}	



