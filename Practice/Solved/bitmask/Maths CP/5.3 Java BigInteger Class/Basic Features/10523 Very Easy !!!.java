import java.math.BigInteger;
import java.util.Scanner;
import java.math.*;


// 10551 Basic Remains

class Main{
    

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n,a;
        BigInteger N,A,sum,I;

        while(sc.hasNext()){
            n = sc.nextInt();
            a = sc.nextInt();
            
            A = BigInteger.valueOf(a);
            sum = BigInteger.ZERO;
            I = BigInteger.ONE;
            for(int i=1; i <= n ; i++){
                sum = sum.add(A.pow(i).multiply(I));
                I = I.add(BigInteger.ONE);
            }

            System.out.println(sum);
        }
    }
}