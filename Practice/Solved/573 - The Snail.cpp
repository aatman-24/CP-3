// #include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;

// Got WA

int count_day(int height,int up,int down,int factor)
	{
		int day = 1;
		double intial_height = 0;
		double fact_dist = ((up*factor)/100.00);
		double distance_climbed = up;
		double height_after_climbing = up;
		double height_after_sliding = (up-down);
			
		while(height_after_sliding >= 0)
		{
			intial_height = height_after_sliding;
			distance_climbed -= fact_dist;
			if (distance_climbed < 0)
				{
					distance_climbed = 0;
				}
			height_after_climbing =  intial_height + distance_climbed;
			height_after_sliding = height_after_climbing - down;
			day++;
			// cout << day << "|" << intial_height << "|" << distance_climbed << "|"<< height_after_climbing << "|"<< height_after_sliding << "\n";
			if (height_after_climbing >= height)
				{
					return day;
				}
			if (height_after_sliding < 0)
				{
					return 0-day;
				}
			
		}
		return 0-day;
	}


int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	while(cin)
	{
		
			while (cin){
				int h,u,d,f;
				cin >> h >> u >> d >> f;
				if((h==0) & (f==0))
				{
					break;
				}
			int day = count_day(h,u,d,f);
			if (day > 0)
			{
				cout << "success on day" << day << endl;
			}
			else
			{
				cout << "faliure on day" << 0-day << endl;
			}
		}

	}
	return 0;
}

