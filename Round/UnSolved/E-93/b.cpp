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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin >> t;
	while(t--)
	{
		int p,f;
		cin >> p >> f;
		int nS,nA;
		cin >> nS >> nA;
		int sw,aw;
		cin >> sw >> aw;

		std::vector<int> weight;
		std::vector<int> number;
		if(sw <= aw)
		{
			weight = {sw,aw};
			number = {nS,nA};
		}
		else
		{
			weight = {aw,sw};
			number = {nA,nS};
		}
		int bucket_of_me = 0;
		int bucket_of_f = 0;
		int n = 0;
		int i = 0;
		int turn1 = 0;
		int turn2 = 0;
		while((bucket_of_f <= f ) && (bucket_of_me <= p) && (i <= 1))
		{
			
			if ((p >= weight.at(i) + bucket_of_me) && (number.at(i)))
			{
				
				bucket_of_me += weight.at(i);
				n += 1;
				number.at(i) -= 1;
			}
			else
			{
				turn1 = 1;
			}
			if ((f >= weight.at(i) + bucket_of_f) && (number.at(i)))
			{
		
				bucket_of_f += weight.at(i);
				n += 1;
				number.at(i) -= 1;
				continue;
			}
			else
			{
				turn2 = 1;
			}
			if (turn1 && turn2)
			{
				i++;
				turn1 = 0;
				turn2 = 0;
			}
		}
		cout << n << endl;

	}

}


