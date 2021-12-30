import java.math.BigInteger;
import java.util.Scanner;


// 713	Adding Reversed Numbers

class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        BigInteger N1,N2;
        String M1,M2,M3;
        BigInteger RN1,RN2,RN3;
        int N; N = sc.nextInt();
        while(N-- > 0){
            N1 = sc.nextBigInteger();
            N2 = sc.nextBigInteger();

            M1 = new StringBuffer(N1.toString()).reverse().toString();
            RN1 = new BigInteger(M1);

            M2 = new StringBuffer(N2.toString()).reverse().toString();
            RN2 = new BigInteger(M2);


            RN3 = RN1.add(RN2);

            M3 = new StringBuffer(RN3.toString()).reverse().toString();

            RN3 = new BigInteger(M3);

            System.out.println(RN3);


        }

    }
}