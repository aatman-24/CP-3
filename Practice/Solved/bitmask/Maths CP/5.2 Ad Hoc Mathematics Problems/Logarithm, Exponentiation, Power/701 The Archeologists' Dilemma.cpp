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


// If I said to you find the pow(2,N) such that some of the first digits is M.

// I apporach this Like

// for(int i = 1; i < 32; i++)   // power of 2
// {
//     num = pow(2,i) 
//     length_of_M = floor(log2(M)) + 1;
//     length_of_num = floor(log2(num)) + 1;

    //     and check if (length_of_M < length_of_num / 2)
    //     {
    //        Like suppose M = 12; N = 12345; ->  num/pow(10,5-2) -> 12345/1000.  Like this.
    //      if(M == num/pow(10,length_of_num - length_of_M)) cout << i << endl;    

    //     }

    
// }

// Am I right ? -> Yes. But probelm is it's worked for only 2^32 and if we used long long than 2^64.

// but Here Given length_of_M = 2147483648;

// So Now we are going to define another apporach Which is worked for any Num.

// How To apporach ?

// - See Our equation (M == num / pow(10,length_of_num - length_of_M)) ------------- (1)

// where num = pow(2,i);

// and we got the i = n such that It's true so -> num = pow(2,n).


// I am going to change this equation,

// Let P is Given Value (some of the first digit of Number)
// P == (floor)N / pow(10,T); --------------------------------(2).

// where T = length_of_num - length_of_M;
         // N = pow(2,n);


// Let's Try some Math...

// P = (floor)N / pow(10,T);


// P <= N/pow(10,T) < P+1;

// P * 10^T <= N < (P + 1) * 10^T

// Now put the N = 2^n;

// P * 10^T <= 2^n < (P + 1) * 10^T

// Take log2 both the side
// log2(P * 10^T) <= n < log2((P + 1) * 10^T)

// log2(P) + log2(10^T) <= n < log2(P+1) + log2(10^T)  you think cancel the log2(10^T) But do't do this

// T = length_of_num - length_of_M; -> T = length_of_M + i (i = 0 -> MAX_LIMIT) (WHICH IS SAME).

// T = length + i;

// log2(P) + log2(10^(length + i)) <= n < log2((P+1)) + log2(10^(length + i)) --------- (4).

// and finally.. we can write...



// log2(P) + (length + i) * log2(10) <= n < log2((P+1)) + (length + i)*log2(10) --------- (5).


// This means that we are going to find the n such that above condition is true and when this is true
// at a time our value is [ceil(log2(P) + log2(10^(length + i)))] OR [floor(log2((P+1)) * log2(10^(length + i)))].



// // Why you don't need to cancel this term ?

// // -> It contribute some of the value into the above term So you can't cancel it.


// log2(P) + (length + i) * log2(10) <= n < log2((P+1)) + (length + i)*log2(10) --------- (5).




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    unsigned int n;
    double a, b;
    unsigned int temp1, temp2;
    
    while (cin >> n) {

        int length = floor(log10(n)) + 1;
        unsigned long i = 0;

        while (++i) {

            a = log2(n) + (length+i)*log2(10);
            b = log2(n+1) + (length+i)*log2(10);
            	
            temp1 = (unsigned int)a;
            temp2 = (unsigned int)b;
            
            if (temp2 != b && temp2 - temp1 > 0) {
                cout << temp2 << endl;
                break;
            }
        }
    }
	return 0;
}

