#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define debug cout << "Ok" << endl

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================



*/

ll gcd(ll a,ll b) {return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a, ll b) {return (a * (b / gcd(a,b)));}


vi primes;
ll _sieve_size;
bitset<100000007> bt;

void sieve(ll ub){
    _sieve_size = ub + 1;
    bt.set();
    bt[0] = bt[1] = 0;
    for(ll i = 2; i < _sieve_size; i++) {
        if(bt[i])
        {
            for(ll j = i * i ; j < _sieve_size; j+=i) bt[j] = 0;
            primes.push_back(i);
        }
    }
}


vii primesFactor(ll N) {
    vii factors;
    ll PF_index = 0, PF = primes[PF_index];
    while(PF * PF <= N) {
        if(PF % N) {
            // This If Clause for other logic..
            ll cnt = 0;
            while(N % PF == 0) {N /= PF; cnt++;}
            factors.push_back({PF,cnt});
        }
        PF = primes[++PF_index];
    } 
    if(N != 1) factors.push_back({N,1});
    return factors;
}


ll numPF(ll N) {                     // count all prime factors.(duplicate also)
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;

    while (PF * PF <= N) {
        while (N % PF == 0) { N /= PF; ans++; }
        PF = primes[++PF_idx];
    }

    if (N != 1) ans++;
    return ans;
}

ll numDiffPF(ll N) {                 // unique prime factor count here.
    ll PF_idx = 0, PF = primes[PF_idx], cnt = 0;
    while (PF * PF <= N) {
        if(N % PF  == 0) cnt++;
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }

    if (N != 1) cnt++;
    return cnt;
}




ll sumPF(ll N) {                 // Sum of all unique prime factor.
    ll PF_idx = 0, PF = primes[PF_idx], sum = 0;
    while (PF * PF <= N) {
        if(N % PF == 0) sum += PF;
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }

    if (N != 1) sum += N;
    return sum;
}

ll numDiv(ll N) {   //N = a^i × b^j × ... × c^k, then N has (i + 1) × (j + 1) × ... × (k + 1) divisors.

    ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
    while (PF * PF <= N) {
    ll power = 0; // count the power
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);             // according to the formula
    PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
    return ans;
}


/*  If a number N = a^i × b^j × ... × c^k, then
the sum of divisors of N is a^(i+1) − 1 / (a - 1) * b^(j+1) − 1 / (b - 1) .... c^(k+1) − 1 / (c - 1).
*/

ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
    while (PF * PF <= N) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
    PF = primes[++PF_idx];
    }
    if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
    return ans;
}


/*
Count the number of positive integers < N that are relatively prime
to N. Recall: Two integers a and b are said to be relatively prime (or coprime) if
gcd(a, b) = 1  Example -> (25,42)

->A na¨ıve algorithm to count the number of positive
integers < N that are relatively prime to N starts with counter = 0, iterates through
i ∈ [1..N-1]], and increases the counter if gcd(i, N) = 1.


A better algorithm is the Euler’s Phi (Totient) function ϕ(N) = N × multiplication(1 - 1/PF)
where PF is prime factor of N.

*/

ll EulerPhi(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = N; // start from ans = N
    while (PF * PF <= N) {
    if (N % PF == 0) ans -= ans / PF; // only count unique factor
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
    }
    if (N != 1) ans -= ans / N; // last factor
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    sieve(1000007);
    

    vii r = primesFactor(142391208960LL);
    for (vii::iterator i = r.begin(); i < r.end(); i++) {
        cout << (*i).first << '^' << (*i).second << ' ';
    }
    cout << endl;


    cout << numPF(142391208960LL) << endl; //142391208960LL
    cout << numDiffPF(142391208960LL) << endl;
    cout << sumPF(142391208960LL) << endl;
    cout << numDiv(142391208960LL) << endl;
    cout << sumDiv(142391208960LL) << endl;
    cout << EulerPhi(142391208960LL) << endl;

    return 0;
}

