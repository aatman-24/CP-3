import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;

/* 

TIME COMPLEXITY: 

APPORACH:
*/


class Main 
{ 
    public static void main(String[] args) throws IOException 
    { 

        // BufferedReader br = new BufferedReader( new FileReader("input.txt")); 
        // PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt"))); 
        Scanner sc = new Scanner(System.in);

        BigInteger[] fib = new BigInteger[200];
        BigInteger prev = BigInteger.ONE;
        BigInteger next = BigInteger.valueOf(2);
        BigInteger temp;
        for(int i = 0 ; i < 200;i++) {
            fib[i] = prev;
            temp = prev; prev = next; next = next.add(temp);
        }

        int n,m;
        String fr,sec;
        while(sc.hasNext()) {
            fr = sc.next(); sec = sc.next();
            n = fr.length();  m = sec.length();
            BigInteger ttl = BigInteger.ZERO;
            for(int i = 0 ; i < n ; i++) {
                if(fr.charAt(i) == '1') ttl = ttl.add(fib[n-i-1]);
            }

            for(int i = 0; i < m ; i++) {
                if(sec.charAt(i) == '1') ttl = ttl.add(fib[m-i-1]);
            }


            int k = 0;
            while(fib[k].compareTo(ttl) != 1) k++;
            String a = "";
            
            for(int i = k - 1; i > -1 ; i--) {
                if(ttl.subtract(fib[i]).compareTo(BigInteger.ZERO) != -1) {
                    ttl = ttl.subtract(fib[i]);
                    a += "1";
                }
                else {
                    a += "0";
                }
            }

            if(a.length() == 0) a = "0";
            

            // out.println(a);
            // if(sc.hasNext()) out.print("\n");
            System.out.println(a);
            if(sc.hasNext()) System.out.print("\n");
        }
        // out.flush();
    } 
} 




