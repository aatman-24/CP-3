import java.math.BigInteger;
import java.util.Scanner;

/*
// 10430 Dear GOD




// Equation I got is:   T^N * X = (T^N-1+T^N-2+T^N-3+.........T^1+T^0) * K; It is true only when 
    // X = (T^N-1+T^N-2+T^N-3+.........T^1+T^0) and K = T^N.

How?
For the first time Let Suppose,

N = 4, X*T - K take it as P, so now P = X*T - K
N = 3, T(P) - K
N = 2, T(T(P)-K)-K
N = 1, T(T(T(P)-K)-K) - K 

MEANS THAT,
T(T(T(P)-K)-K) - K = 0
T^4 * X = (T^3+T^2+T^1+1(T^0)) * K

I FOUND THIS PATTERN LIKE THIS.


*/

class Main{
    

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        BigInteger K,T,X;
        int N,M;
        System.out.println("Dear GOD, Pardon Me");
        while(true)
        {
            T = sc.nextBigInteger();  N = sc.nextInt();
            M = N;
            X = BigInteger.ZERO;
            while(N-- > 0)
            {
                X = X.add(T.pow(N));
            }
            K = T.pow(M);
            if(sc.hasNext()) System.out.println("X = " + X + "\nK = " + K + "\n");
            else {System.out.println("X = " + X + "\nK = " + K); break;}
        }
    }
}