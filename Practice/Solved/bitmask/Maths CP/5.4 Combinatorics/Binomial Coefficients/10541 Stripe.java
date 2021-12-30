import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;
import java.util.*;

/* 

TIME COMPLEXITY: 

APPORACH:
*/


class Main 
{ 
    public static void main(String[] args) throws IOException 
    { 

        Scanner sc = new Scanner(System.in);

        BigInteger[] fact = new BigInteger[210];
        fact[0] = BigInteger.valueOf(1);

        for(int i = 1; i <= 209; i++) {
            fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        }
             
        int t = sc.nextInt();
        while(t-- > 0) {

            int n = sc.nextInt();
            int b_grp = sc.nextInt();
            int ttl = 0; 
            for(int i = 0 ; i < b_grp; i++) ttl += sc.nextInt();
            int w_grp = n - ttl + 1;

            if(b_grp > w_grp) {
                System.out.println("0");
            }
            else {
                BigInteger rlt =  fact[w_grp].divide(fact[w_grp-b_grp]).divide(fact[b_grp]);
                System.out.println(rlt);
            }
        }




    } 
} 




