#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;

#define M 10

int main()
{

	// MUST READ: bitset indexing start from the last index with 0.if you do any opreation it alwasy
	// consider from the last. bitset is not dynamic type.At a compile time it must have the size.


	// INITILIZATION OF BITSET
// ----------------------------------------------------------------------------------------------------	
	// with all bit zero
	bitset<M> bset1; 			// 0000000000
	
	// using number
	bitset<M> bset2(20);		// 0000010100
	
	// using string
	bitset<M> bset3("1100");	// 0000001100
// ----------------------------------------------------------------------------------------------------



	// count() | size() | how many bit set ? | how many bit unset ?
// -----------------------------------------------------------------------------------------------------
	bitset<8> bset4(20); // 0000010100


	// count() -> It returns total set bit(number of 1).

	cout << bset4.count() << endl;			// Output : 2

	// size()  -> It returns total bit.(number of 1 + number of 0)

	cout << bset4.size() << endl;   	// Output : 8 

	// Number of 0's bit = size() - count()

	cout << bset4.size() - bset4.count() << endl;   // Output : 6
// ----------------------------------------------------------------------------------------------------------


	// opreator [] : Start from the last with 0 indexing.
// ---------------------------------------------------------------------------------------------------------
	bitset<8> bset5(20); // 000010100

	cout << bset5[0] << endl;  		// Output : 0

	cout << bset5[2] << endl; 		// Output : 1

	// you can also set the bit.

	bset5[7] = 1; 
	cout << bset5 << endl;      // 000010100 -> 10010100
// -------------------------------------------------------------------------------------------------------------


	// any() | none() | test()
// ---------------------------------------------------------------------------------------------------------------
	bitset<8> bset6; // 000000000
	// bset5 -> 10010100

	// any() -> It return 1 if any of the bit is set(1's) else 0.

	cout << bset5.any() << endl;		// Output : 1
	cout << bset6.any() << endl;		// Output : 0

	// none() -> It return 1 if all the bit is (O's) else 0.

	cout << bset6.none() << endl;		// Output : 1
	cout << bset5.none() << endl;		// Output : 0

	// test(pos) -> It return 1 given pos is set else 0.

	cout << bset5.test(2) << endl;		// Output : 1
	cout << bset5.test(0) << endl;		// Output : 0
// --------------------------------------------------------------------------------------------------------------

	// set() | reset() | flip() 
// ---------------------------------------------------------------------------------------------------------------
	bitset<8> bset9(20); // 00010100

	// set() | set(pos) -> If pos given then set only this pos bit otherwise make all bit 1's.

	cout << bset9.set() << endl;   // 00010100 -> 11111111
	cout << bset9.set(0) << endl;   // 00010100 -> 00010101

	// reset()  | reset(pos) -> If pos given then only reset this pos otherwise make all the bits as 0's.

	cout << bset9.reset() << endl;   // 00010100 -> 00000000
	cout << bset9.reset(2) << endl;   // 00010100 -> 00010000


	// flip() | flip(pos) -> If pos given then only filp this bit otherwise all bit is filp.

	cout << bset9.flip() << endl;   // 00010100 -> 11101011
	cout << bset9.flip(1) << endl;   // 00010100 -> 00010010
// ---------------------------------------------------------------------------------------------------------------

	
	return 0;

}