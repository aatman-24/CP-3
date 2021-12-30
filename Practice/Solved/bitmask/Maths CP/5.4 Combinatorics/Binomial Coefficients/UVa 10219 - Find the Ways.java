import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;
import java.util.*;
import java.math.*;

/* 

TIME COMPLEXITY: 

APPORACH:
*/


class Main 
{ 

    
    public static void main(String[] args) throws IOException 
    { 

        // BufferedReader br = new BufferedReader( new FileReader("input.txt")); 
        // PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output1.txt"))); 
        Scanner sc = new Scanner(System.in);


       
        int n,k;
        while(sc.hasNextInt()) {
            n = sc.nextInt(); k = sc.nextInt();
            BigInteger result = BigInteger.ONE;
            int r = Math.min(n,k);
            for(int i = 1; i <= r ; i++) {
                result = result.multiply(BigInteger.valueOf(n-k+i));
                result = result.divide(BigInteger.valueOf(i));
            }
            System.out.println(result.toString().length());
            
        }
    } 
} 




