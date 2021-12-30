#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mX;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;

/*
==============================> Description <=============================================
Question : 	422 - Word-Search Wonder
Topic : backtracking, 2D Grid Search, String
Problems :
*/

// Here given that you can not go upward direction.

// and only you can move unidirectional and stright. not wrap round(turn)

char s[101][101];
int mark[101][101];

int dx[7] = {0,-1, -1, 0, 1, 1, 1};
int dy[7] = {1, 1, -1, -1, -1, 0, 1};

int startX, startY, endX, endY, IndexSet;
bool setIndex;

bool findWord(string word, int X, int Y, int wI, int N) {
	

	if(wI == word.size()) {
		endX = X; endY = Y;
		return true;
	}

	// Here If Index is set then we move into this direction only.
	if(setIndex) {
		if(X + dx[IndexSet] >= N || X + dx[IndexSet] < 0 || Y + dy[IndexSet] >= N || Y + dy[IndexSet] < 0) return false;
		if(mark[X + dx[IndexSet]][Y + dy[IndexSet]] == 1) return false;
		if(s[X+dx[IndexSet]][Y+dy[IndexSet]] == word[wI]) {
			mark[X+dx[IndexSet]][Y+dy[IndexSet]] = 1;
			if(findWord(word, X+dx[IndexSet], Y+dy[IndexSet], wI+1, N)) return true;
			mark[X+dx[IndexSet]][Y+dy[IndexSet]] = 0;

		}
		return false;
	}

	// If setIndex is not set then we can choose any direction.
	for(int i = 0; i < 7 && !setIndex; i++) {

		if(X + dx[i] >= N || X + dx[i] < 0 || Y + dy[i] >= N || Y + dy[i] < 0) continue;

		if(mark[X + dx[i]][Y + dy[i]] == 1) continue;

		if(s[X+dx[i]][Y+dy[i]] == word[wI]) {

			IndexSet = i;
			setIndex = true;

			mark[X+dx[i]][Y+dy[i]] = 1;
			if(findWord(word, X+dx[i], Y+dy[i], wI+1, N)) return true;
			mark[X+dx[i]][Y+dy[i]] = 0;

			IndexSet = i;
			setIndex = false;
		}
	}

	return false;
}


int main() {

	int N;
	while(cin >> N) {
		if(!N) break;
		REP(i,N) REP(j,N) cin >> s[i][j];
		

		string word;
		while(cin >> word){

			if(word == "0") break;

			memset(mark, 0, sizeof(mark));

			bool found = false;
			for(int i = 0; i < N && !found ; i++) {
				for(int j = 0; j < N && !found; j++) {
					if(s[i][j] == word[0]){
						mark[i][j] = 1;
						setIndex = false;
						if(findWord(word, i, j, 1, N)) {
							startX = i; startY = j;
			 				found = true;
		 				}
		 				mark[i][j] = 0;
					}
				}
			}

			if(found) {
				printf("%d,%d %d,%d\n",startX+1,startY+1,endX+1,endY+1);
			}
			else printf("Not found\n");
		}
		
	}

	return 0;
}