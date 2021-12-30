// void primeFactorLCM(mii &a, mii b) {
// 	for(auto i : b) {
// 		if(a.find(i.first) == a.end()) a[i.first] = i.second;
// 		else a[i.first] += i.second;
// 	}
// }

// bool primeFactorGCD(mii a,  mii b) {
// 	for(auto i : b)
// 		if(a.find(i.first) == a.end() || a[i.first] < i.second) return false;
// 	return true;
// }


// bool factorialPrimeFactor(ll n, mii mFactors) {
// 	mii result,factors;
// 	while(n > 1) {
// 		factors = primeFactor(n);	
// 		primeFactorLCM(result,factors);
// 		if(primeFactorGCD(result, mFactors)) return true;
// 		n--;
// 	}
// 	return primeFactorGCD(result,mFactors);
// }


// void sieve(ll ub) {
// 	_sieve_size = ub + 1;
// 	arr.assign(_sieve_size,0);

// 	for(int i = 0; i < _sieve_size; i++) arr[i] = i;
// 	for(ll i = 2; i < _sieve_size; i++) {
// 		if(arr[i] == i){
// 			for(ll j = i*i; j < _sieve_size; j+=i) arr[j] = i;
// 			primes.push_back(i);
// 		}
			
// 	}
// }


// int sumDiv(ll N) {
// 	int cnt, res = 1;
// 	PI = 0; PN = primes[PI];
// 	while(N >= PN * PN) {
// 		cnt = 0;
// 		while(N % PN == 0) {N /= PN; cnt++;}
// 		if(cnt > 0){
// 			res = res * ((power(PN,cnt+1) - 1) / (PN-1));
// 		}
// 		PI++; PN = primes[PI];
// 	}
// 	if(N > 1) res = res * ((power(N,2) - 1 ) /(N-1));
// 	return res;
// }




// mii primeFactor(ll N) {
// 	mii result;

// 	if(N <= _sieve_size) {
// 		while(N != 1) {
// 		if(result.find(arr[N]) == result.end()) result[arr[N]] = 1;
// 		else result[arr[N]]++;
// 		N /= arr[N];
// 		}
// 	}
// 	else {
// 		PI = 0; PN = primes[PI];
// 		while(N >= PN * PN) {
// 			if(N % PN == 0) {
// 				result[PN] = 0;
// 				while(N % PN == 0) {N /= PN; result[PN]++;} 
// 			}
// 			PI++; PN = primes[PI];
// 		}
// 		if(N > 0) result[N] = 1;
// 	}
// 	return result;
// }

int numDiv(ll N) {
	int cnt,res = 1;
	PI = 0; PN = primes[PI];
	while(N >= PN * PN) {
		cnt = 0;
		while(N % PN == 0) {N/=PN; cnt++;}
		res *= (cnt + 1);
		PI++; PN = primes[PI];
	}
	if(N > 1) res *= 2;
	return res;
}

ll power(ll base, ll n) {
	ll res = 1;
	while(n) {
		if(n % 2) res *= base;
		base *= base;
		n/=2;
	}
	return res;
}

ll getEularPhiDepth(ll N) {
	ll ans = N;
	int cnt = 0;
	while(ans != 1) {
		if(EularPhiDepthArr[ans] != 0) {
			cnt += EularPhiDepthArr[ans];
			return cnt;
		}
		ans = EularPhi(ans);
		cnt++;
	}
	return cnt;
}

ll powerMod(ll base, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n % 2) res = ((res % mod) * (base % mod) % mod);
		base = ((base % mod) * (base % mod) % mod);
		n /= 2;
	}
	return res % mod;
}

ll EularPhi(ll N) {
	ll ans = N;
	PI = 0; PN = primes[PI];
	while(N >= PN * PN) {
		if(N % PN == 0) ans -= (ans / PN);
		while(N % PN == 0) N /= PN;
		PI++; PN = primes[PI];
	}
	if(N > 1) ans -= (ans / N);
	return ans;
}

void sieve(ll ub) {
	_sieve_size = ub + 1;
	bt.set();
	bt[0] = bt[1] = 0;
	for(ll i = 2; i < _sieve_size; i++) {
		if(bt[i]) {
			for(ll j = i * i; j < _sieve_size; j+=i) bt[j] = 0;
			primes.push_back(i);
		}
	}
}

ll _sieve_size, PI, PN;
bitset<1000007> bt;
vl primes;
int EularPhiARR[2000001];
vi EularPhiDepthArr(2000001, 0);