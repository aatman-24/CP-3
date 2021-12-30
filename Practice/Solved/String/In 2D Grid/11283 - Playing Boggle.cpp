#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;

/*
==============================> Description <=============================================

Question : 	11283 - Playing Boggle
Topic : String , 2D Grid, Backtrcking
Problems :
*/

char arr[4][4];
int mark[4][4];
int scores[10];

int up[8] = {0,-1, -1, -1, 0, 1, 1, 1};
int down[8] = {1, 1, 0, -1, -1, -1, 0, 1};


bool findWord(string word, int cI, int cJ, int wordIndex) {


	if(wordIndex == word.size()) {
		return true;
	}

	for(int i = 0; i < 8; i++) {

		if(cI + up[i] >= 4 || cI + up[i] < 0 || cJ + down[i] >= 4 || cJ + down[i] < 0) continue;

		if(mark[cI + up[i]][cJ + down[i]] == 1) continue;

		if(arr[cI+up[i]][cJ+down[i]] == word[wordIndex]) {
	
			mark[cI+up[i]][cJ+down[i]] = 1;
			if(findWord(word, cI+up[i], cJ+down[i], wordIndex+1)) return true;
			mark[cI+up[i]][cJ+down[i]] = 0;
		}
	}

	return false;
}


int main() {

	memset(scores, 10, sizeof(scores));
	scores[3] = 1;
	scores[4] = 1;
	scores[5] = 2;
	scores[6] = 3;
	scores[7] = 5;
	scores[8] = 11;


	int t; cin >> t;
	REP(tc, t) {

		int score = 0;
		REP(i,4) REP(j,4) cin >> arr[i][j];
		

		string word;
		int m; cin >> m;
		while(m--) {
			cin >> word;
			memset(mark, 0, sizeof(mark));
			int flag = 0;
			REP(i,4) {
				REP(j,4) {
					if(arr[i][j] == word[0]) {
						mark[i][j] = 1;
						if(findWord(word, i, j, 1)) {
			 				flag = 1;
			 				break;
		 				}
					}
				}
				if(flag) break;
			}
			if(flag) {
				if(word.size() <= 2) score++;
				else if(word.size() >= 8) score += 11;
				else score += scores[word.size()]; 
			}
		}
		printf("Score for Boggle game #%d: %d\n",tc+1, score);
	}

	return 0;
}