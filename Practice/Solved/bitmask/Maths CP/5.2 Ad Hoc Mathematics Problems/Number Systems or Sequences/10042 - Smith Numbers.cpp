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

// #Apporach : What is Smith NUmber? -> If the number all digit sum is equal ==
// 				(prime factor of this number all digit sum).


// Appoach very simple brute force,

// but one thing you must care that if the number is divided by last by its sqrt(number).
// after remaining value of is prime number;



ll n_digit_sum,cur_sum,bfr_n,cur_sum_of_digit;
int flag;

ll SUM_OF_NUMBER(ll a)
{
	ll cur_sum = 0;
	while(a)
	{
		cur_sum += a % 10;
		a /= 10;
	}
	return cur_sum;
}



bool isItSmithNumber(ll n)
{
	n_digit_sum = SUM_OF_NUMBER(n);
	cur_sum_of_digit = 0;
	flag = 0;
	for(int i = 2; i <= (int)sqrt(n) ; i++)
	{
		while(n % i == 0) {
			n /= i;
			if(i < 10) cur_sum_of_digit += i;
			else cur_sum_of_digit += SUM_OF_NUMBER(i);
			flag = 1;
		}	
		if(n == 1) {break;}
	}
	if(flag && n != 1) {cur_sum_of_digit += SUM_OF_NUMBER(n);}  // sqrt(n) is last factor of n. after that remaining r is prime number.
	return (cur_sum_of_digit == n_digit_sum);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	ll N;
	int t; cin >> t;
	while(t--)
	{
		cin >> N;
		while(true){
			if(isItSmithNumber(++N)) break;
		}

		cout << N << endl;
	}

	return 0;
}

