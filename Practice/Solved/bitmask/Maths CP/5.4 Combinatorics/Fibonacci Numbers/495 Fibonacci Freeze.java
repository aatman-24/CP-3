import java.math.BigInteger;
import java.util.Scanner;

class Main{
    
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        BigInteger a[] = new BigInteger[5001];

        BigInteger prev,tmp,nxt;

        prev = BigInteger.ZERO;
        nxt = BigInteger.ONE;

        for(int i = 0 ; i <= 5000; i++){
            a[i] = prev;
            tmp = prev;
            prev = nxt;
            nxt = prev.add(tmp);
        }

        int n;
        while(sc.hasNext())
        {
            n = sc.nextInt();
            System.out.printf("The Fibonacci number for %d is ",n);
            System.out.println(a[n]);
        }
        
        
    }
}