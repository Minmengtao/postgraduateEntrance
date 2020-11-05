import java.util.Scanner;

public class A{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        int [] num = new int[T];
        int i=0,N,j=0,sum;
        if(T>0&&T<50){
            while(i<T){
                N = scan.nextInt();
                sum=0;
                j=0;
                while(j<N){
                    sum=scan.nextInt();
                    num[i]+=sum;
                    j++;
                    
                }
                i++;
            }
        }
        for(int e:num)
            System.out.println(e);
    }
}