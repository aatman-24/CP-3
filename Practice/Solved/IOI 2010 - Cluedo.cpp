#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int visited[25][2];
	char faceup[50];

	for (int i=0;i<50;i++)
	{
		cin >> faceup[i];
	}

	// Unvisited all the cards.
	for (int i=0;i<25;i++)
	{
		for (int j=0;j<2;j++)
		{
			visited[i][j] = 0;
		}
	}

	int k;
	char r;
	int column_no;

	// First round memorize all the cards.
	for (int i=0; i < 50 ; i++)
	{
		r = faceup(i);          // Return 'K' like char....
		k = int(r) - int('A');		// get the number of char like .... B = 2 ,C = 3.
		column_no = (visited[k][0]) ? 1 : 0;	// visited the char (memoraize)
		indext[k][column_no] = i;	// (set the card number)

	}

 	// All the cards now remember we just have to open card using it number.

 	for (int i=0;i<25;i++)
 	{
 		faceup(visited[i][0]);
 		faceup(visited[i][1]);
 	}


 	// Total faceup call is 50 + 2 * (25) == 100
	return 0;
}

