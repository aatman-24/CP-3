#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;

#define M 10

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	// why bitmasking is needed ? -> In CP  * / %-[O(N^3)] this opreator is heavy for larger size of the number like (10^6) so using
	// bitwise oprator it can be done using O(N).


	unsigned char b = 9; 

	Bitwise Opreator : AND(&) OR(|) XOR(^) NOT(~) LEFT-SHIFT(<<) RIGHT-SHIFT(>>)

	



	Multiplication And Division 
// ----------------------------------------------------------------------------------------------------------
	- Mutliply the given number by some number k;   (b << k) == (b * 2^k)

	cout << (b << 1) << endl; 	//	(Mutliply by 2)
	cout << (b << 2) << endl; 	//	(Mutliply by 4)

	- Divide the given number by some number k;   (b >> k) == (b / 2^k)

	cout << (b >> 1) << endl; 	//	(Divide by 2)
	cout << (b >> 2) << endl; 	//	(Divide by 4)
// --------------------------------------------------------------------------------------------------------------



	To set/turn on the j-th item:
// --------------------------------------------------------------------------------------------------------------
	- use the bitwise OR operation S |= (1 << j)

	b = b | (1 << 2);          // j = 2
	cout << int(b) << endl;
// --------------------------------------------------------------------------------------------------------------


	To check if the j-th item of the set is on,
// --------------------------------------------------------------------------------------------------------------
	- use the bitwise AND operation T = S & (1 << j).

	int check = b & (1 << 1);           // b = 1101
	cout << bool(check) << endl;		// output = 0
// --------------------------------------------------------------------------------------------------------------


	To clear/turn off the j-th item of the set
// --------------------------------------------------------------------------------------------------------------
	- use the bitwise AND operation S &= ∼(1 << j)

	b = b & ~(1 << 2);          // b = 1101
	cout << int(b) << endl;		// 1101 -> 1001 -> 9
// --------------------------------------------------------------------------------------------------------------



	 To toggle (flip the status of) the j-th item of the set,
// --------------------------------------------------------------------------------------------------------------
	- use the bitwise XOR operation S ^= (1 << j).

	b = b ^ (1 << 2);          // b = 1001
	cout << int(b) << endl;	   // 1001 -> 1101 -> 13
// --------------------------------------------------------------------------------------------------------------



	To get the value of the least significant bit that is on (first from the right),
// --------------------------------------------------------------------------------------------------------------
	- use T = (S & (-S)).

	int LSB = (b & (-b));          // b = 1101  if b = 1100 then ans
	cout << LSB << endl;	   // 1101 -> 1			1100 -> 3
// --------------------------------------------------------------------------------------------------------------


  To turn on all bits in a set of size n,
// --------------------------------------------------------------------------------------------------------------
	- use S = (1 << n) - 1

	int p = (1 << 3) - 1;   // (1 << 3) -> 1000 - 1 -> 0111 -> p = 7
	cout << p << endl;	   // 7
// --------------------------------------------------------------------------------------------------------------
	


	Summary :

	Mutliplication  =  (S << k) -> S * (2^k)
	Division		=  (S >> k) -> S / (2*k)
	Set k bit 		=  S |= (1 << k)
	Unset k bit 	=  S &= ~(1 << k)
	check k is Set 	=  T = S & (1 << k)  (if T is 1 -> Set if T is 0 -> Unset)
	toggle k bit 	=  S ^= (1 << k)
	LSB(from right) =  LSB = (S & (-S))
	Set all bits
	for size n 		= S = (1 << n) - 1


	return 0;

}


void turn_on_last_zero()
{


	int  n = 41;


	int number_of_bits = floor(log2(n))+1; 


	int complment_1st =  n ^ ((1 << number_of_bits) - 1);


	int LSB = log2(complment_1st & (-complment_1st));





	// cout << LSB << endl;


	int new_ans = n ^ (1 << LSB);


	cout << new_ans << endl;

	
}





void last_1s_consecutive_bit()
{
	int n = 39;

	int number_of_bits = floor(log2(n)) + 1;

	int complment_1st =  n ^ ((1 << number_of_bits) - 1);

	int LSB = log2(complment_1st & (-complment_1st));	// we need to find which bit is going to filp after consecutive 1's.

	int new_n = n + 1;		// filping all the 1's last bits.

	int ans = new_n ^ (1 << LSB);	// filp the bit which is affected which we found as LSB.

	cout << ans << endl;

}