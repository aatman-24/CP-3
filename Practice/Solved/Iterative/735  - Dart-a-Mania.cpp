#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <cstring>
#define ll long long

using namespace std;

int arr[21];

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;

bool valid[65][65][65];


// #I also refer from here : https://github.com/chatziiola/lowerBound/blob/master/UVa-00735-DartAMania.cpp


// #Explaination : 301 DARTS, Here we have score 301 and we have to make it 0 to win game before the other participant.

// Rules :-> 1) we have three dart. we have to throw it on the board.
// board has 0-20 number write down. where number is write down in this part also has three separete parts (1st -> 1*score),
// (2nd -> 2*score), (3nd -> 3*score). Here score is the range between(0-20).
// all three dart  sum is minus from the player current score.
// yes is it possible all the dart go to single subplace of any one number also. like for 17 (51,51,51) go to 3x place. 
// - and also one 50 point if we hit to middle bully.

 // #problem : we have to find all the COMBINATIONS and PERMUTATIONS for given score.
// we have to throw the darts for only once. if we can make it zero than okay otherwise not possible.


// #apporach : use three loop with all the value dart can have.(0-20, 2*(0)-2*(20), 3*(0)-3*(20) , 50(bully)).
// use three loops and count all the PERMUTATIONS.


// now for the COMBINATIONS see the below code here we use the memset.


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	
	set<int> si;
	si.insert(0);
	si.insert(50);

	for(int p = 1 ; p < 21 ; p++)
		{ si.insert(p); si.insert(p*2); si.insert(p*3);}


	set<int>::iterator i,j,k;

	int n,p,c;
	while(cin >> n)
	{
		if(n <= 0) 
			{
				cout << "END OF OUTPUT" << endl;
				break;
			}
		memset(valid,true,274625);
		p=0;
		c=0;
		for(i = si.begin();i != si.end();i++)
		{
			for(j = si.begin() ;j != si.end() ;j++)
			{
				k = si.find(n - *i- *j);
				if(k != si.end())
				{
					p++;
					if(valid[*i][*j][*k])
					{
						valid[*i][*j][*k] = false;
						valid[*i][*k][*j] = false;
						valid[*j][*i][*k] = false;
						valid[*j][*k][*i] = false;
						valid[*k][*i][*j] = false;
						valid[*k][*j][*i] = false;
						c++;
					}
				}
			}
		}


		if(p > 0)
		{
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << c << '.' << endl;
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p << '.' << endl;
		}
		else
		{
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
		}

		cout << "**********************************************************************" << endl;

	}

	return 0;

}