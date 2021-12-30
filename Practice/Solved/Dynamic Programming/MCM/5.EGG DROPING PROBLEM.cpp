#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;
/*
==============================> Apporach <=============================================

Question : EGG DROPING PROBLEM (MCM VARINATS)
Topic : DP.
*/

int minNumberOfAttmept(int e, int f) {

	if(f == 0 || f == 1) return f;

	if(e == 1) return f;

	int mn = INT_MAX;

	for(int k = 1; k <= f; k++) {
		int tmp_max =  1 + max(minNumberOfAttmept(e-1, k-1), minNumberOfAttmept(e, f-k));
		mn = min(tmp_max, mn);
	}

	return mn;

}

int main()
{

	int test,N;
	cin >> test;
	int E, F;
	while(test--) {
		// memset(t, -1, sizeof(t));
		cin >> E >> F;
		cout << minNumberOfAttmept(E, F) << endl;
		
	}


	return 0;

}


// Some hints if someone is having a hard time understanding this

// We are given with the number of eggs and the number of floors in the building

// We have to find the minimum number of attempts to find the critical floor with the given number of eggs (we can have leftover eggs)

// If we have only one egg then there is only strategy to keep dropping eggs starting from the bottom till we get to a floor where the egg breaks then we found the critical floor which will be the floor below it

// We do not have any facts on where from dropping from a particular floor wheather the egg breaks or not, for every floor the egg may or may not break

// We have to find the niminum number of attemps it would take to find the threshold floor in the worst case

// What would be best case? We select any floor and drop the egg from it and it does not break and we drop the egg from the floor above it and it does break, then our previous floor will be the critical floor. So in the best case it would take us two attempts and 1 egg to find the critical floor.

// Why just testing for in the middle and halving the floor is not necerrily a good solution? Becuase if you have only one egg left then you would have had to make as many attempts as there are floors to find the critical floor.

// What we are doing here? Our function returns the minimum number of attempts required to find the critical floor with E eggs and F floor (given in arguments), we dont what would the most optiomal floor to make the first attempt from so we are making attempt from every floor, we also dont know if by dropping from a floor wheather the egg would break or not so we test for both the cases, we recursively call the function for the left over floor and eggs, since we assume the worst possible case here and we do not know if from dropping from a floor wheather the egg will break or not, we check for which situation it would take greater number of attempts to find the critical floor and take that one.

// Also since we want the minimum number of attempts to find the critical floor in the worst possible case we take the minimum of the number of attempts required in the worst possible case when the first attempt is made from that fllor and return that as our answer.


// Under standing base cases,

// When there is only one egg then we would have to make as many attempts are there are floors in the worst case to find the critical floor.

// When there is only one floor then we would have to make only one attempt if the egg does not break then its the critical floor and if it does then ground floor is the critical floor, so the number of attempts in this case also would be as many as there are floors.


// When we have no eggs then its not possible to find the critical floor.

// Wehn there are no floors i.e. 0 floors then the group floor will be the critical floor so the answer would be equal to 0 i.e. number of floors.



// Will try to explain this, we have to find the minimum number of attempt to find the critical floor, 
// we don't know which floor would be the most optimal floor to make the first attempt hence we are trying 
// ut all the floors through the loop, also we do not know if dropping from a certain floor will cause the 
// gg to break or not so we are testing for both cases one in which we assume that the egg would break and
// in the other we assume that it won't, recursive calls with left over eggs and floors in both cases give 
// us the number of attempts required. But since the question asks us to assume the worst case we take the
//  possibility as a fact which requires greater number of attempts to find the critical floor. 

// In simpler terms, suppose if we are testing for the 3rd floor then we check the number of attempts to
//  find the critical floor for both cases if the egg would break from the 3rd floor and if the egg wont
//   break from the 3rd floor, if it requires greater number of attempts to find the critical floor if the
//    egg would break if dropped form the 3rd floor then we would assume that upon dropping from the 3rd 
//    floor the egg would actually break because we want the worst case here. Then we take the minimum of
//     number of attempts required for finding the critical floor in worst case of all of the floors in our 
//     range and that is the answer.