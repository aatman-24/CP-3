import java.math.BigInteger;
import java.util.Scanner;


// 10551 Basic Remains


class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext())
        {
            int N = sc.nextInt();
            BigInteger BN = BigInteger.valueOf(N);
            String R = new StringBuffer(BN.toString()).reverse().toString();
            int RN = Integer.parseInt(R);
            BigInteger BRN = new BigInteger(R);
            System.out.printf("%d is ", N);
            if(!BN.isProbablePrime(10)) System.out.println("not prime.");
            else if(N != RN && BRN.isProbablePrime(10)) System.out.println("emirp.");
            else System.out.println("prime.");

        }
    }
}