import java.math.BigInteger;
import java.util.Scanner;
import java.math.*;


// 10551 Basic Remains

class Main{
    

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        BigInteger N,M;
        int n;
        String begin,end;

        while(sc.hasNext())
        {
        
            begin = sc.next();
            N = new BigInteger(begin);
            if(N.equals(BigInteger.ZERO)|| N.equals(BigInteger.ONE))
            {
                System.out.println("Not an Automorphic number.");
                continue;
            }
            
            int length = begin.length();
            M = N.multiply(N);


            end = M.toString();            
            if(end.indexOf(begin,end.length()-length) != -1){
                System.out.printf("Automorphic number of %d-digit.\n",length);
            }
            else{
                System.out.println("Not an Automorphic number.");
            }
            
        }
    }
}