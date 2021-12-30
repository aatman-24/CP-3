#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


// #Apporach : Finding The length of the Any Number We Used -> floor(log10(X)) + 1;

// But we can store any number maximum 64 Bit.


// floor(log10(X!)) + 1 ------ (1)



// log10(X!) = log10(X * (X-1) * (X-2) * (X-3) ...1)

// log10(X!) = log10(X) + log10(X-1) + log10(X-2) + log10(X-3) + .... log10(1)  <---------- BOOM -------------->

// Using this formula we can get the lenght of given number factorial.

// But Here We had asked for X <= 10^7 so we can calculate In... single phase...



// Note We Generally Used (1) formula... and It's right but In below we store the arr[1] = 1 which is already
// the lenght of the 1! so we don't need to add 1 here we just need to floor the value or take int part only.


// But if you want to use the regular concept at a time you have to store log10(1) = 0 not 1.
// so we can last apply floor(log10(X)) + 1;



double arr[10000001];

void make_list_of_fact_length()
{
    arr[1] = 1;  // for 1 -> floor(log10(1)) + 1; -> 1 so arr[1] = 1; (we store the answer here)
    // arr[1] = 0;  // for 1 -> log10(1); -> 0 so arr[1] = 0; (regular) (we store the log(x) here)
    for(int i = 2; i < 10000001; i++)
    {
        arr[i] = arr[i-1] + log10(i);   // check here we don't need to apply here the floor(log(X)) + 1;
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

    make_list_of_fact_length();
    int t,N; cin >> t;
    while(t--)
    {
        cin >> N;
        cout << fixed << (int)arr[N] << endl;
        // cout << fixed << (int)(floor(arr[N]) + 1) << endl; (regular)
    }


    return 0;
}

