#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;


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


	int A,B,C,X,Y;
	while(scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y),(A||B||C||X||Y))
	{
		std::vector<int> princess;
		std::vector<int> prince;

		princess.push_back(A);
		princess.push_back(B);
		princess.push_back(C);
		prince.push_back(X);
		prince.push_back(Y);

		sort(princess.begin(),princess.end());
		sort(prince.begin(),prince.end());
		// int turn = 0;
		int max = 0;
		if (princess.at(1) > prince.at(1))
		{
			cout << "-1" << endl;
		}
		else{
			if (princess.at(0) < prince.at(0) )
			{
				for (int j=0; j < 2 ;j++)
					{
						if ((princess.at(j+1) - princess.at(j)) > 1)
						{
							max = princess.at(j);
						}
					}
			}
			else
			{	
				for (int j=0; j < 3 ;j++)
					{
						if ((princess.at(j) > max))
						{
							max = princess.at(j);
						}
					}
			}
			
			while(1)
			{
				if ((max == A) || (max == B) || (max == C) || (max == X) || (max == Y))
					{
						max++;
					}
				else
				{
					break;
				}
			}
			
			cout << max << endl;
			
		}
		

	}
		
}



