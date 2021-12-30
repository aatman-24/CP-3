import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;
import java.util.*;

/* 

Question : 787 - Maximum Sub-sequence Product
APPORACH: Max1DRangeSum
*/


class Main 
{ 
    public static void main(String[] args) throws IOException 
    { 

        
        BufferedReader br = new BufferedReader( new FileReader("input.txt")); 
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output1.txt"))); 
        Scanner sc = new Scanner(br);
        // Scanner sc = new Scanner(System.in);

        BigInteger endNum = BigInteger.valueOf(-999999);
    
        ArrayList<BigInteger>arr = new ArrayList<BigInteger>();
        while(sc.hasNext()) {
            
            BigInteger tmp = sc.nextBigInteger();
            if(endNum.compareTo(tmp) != 0) {
                arr.add(tmp);
            }
            else {
         
                BigInteger max = arr.get(0);
                int n = arr.size();

                // for(int i = 0 ; i < n ; i++) System.out.print(arr.get(i));

                for(int i = 0; i < n-1; i++) {
                    BigInteger prod = BigInteger.valueOf(1);
                    for(int j = i; j < n; j++) {
                        prod = prod.multiply(arr.get(j));
                        if(prod.compareTo(max) == 1) max = prod;
                    }
                }
                System.out.println(max.toString());
                arr.clear();
                continue;
            }
        }

    } 
} 




