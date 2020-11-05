//https://www.cnblogs.com/8023spz/p/10394814.html
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static Scanner sc = new Scanner(System.in);
    private static long Mo = 999101;
    private static BigInteger Mod = new BigInteger("999101");
    private static long [] f = new long[999101];
    private static long [][] dp = new long[1001][1001];
    private static long Lucas(BigInteger n,BigInteger m) {
        long ans = 1;
        while(!n.equals(BigInteger.ZERO) && !m.equals(BigInteger.ZERO)) {
            ans = ans * C(n.mod(Mod).intValue(),m.mod(Mod).intValue()) % Mo;
            n = n.divide(Mod);
            m = m.divide(Mod);
        }
        return ans;
    }
    private static long C(int n,int m) {
        if(n < m) return 1;//第四个测试数据
        long ans = f[n] % Mo;
        ans = ans * pow(f[m],BigInteger.valueOf(Mo - 2)) % Mo;
        ans = ans * pow(f[n - m],BigInteger.valueOf(Mo - 2)) % Mo;
        return ans;
    }
    private static long pow(long a,BigInteger b) {
        long d = 1;
        BigInteger two = new BigInteger("2");
        while(!b.equals(BigInteger.ZERO)) {
            if(b.mod(two).equals(BigInteger.ONE)) d = d * a % Mo;
            a = a * a % Mo;
            b = b.divide(two);
        }
        return d;
    }
    private static void init(long n,int k) {
        f[0] = 1;
        for(int i = 1;i < Mo;i ++) {
            f[i] = f[i - 1] * i % Mo;
        }
        dp[0][0] = 1;
        for(int i = 0;i < k;i ++) {
            for(int j = 0;j <= i;j ++) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * j) % Mo;
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (n - j) * dp[i][j]) % Mo;
            }
        }
    }
    public static void main(String[] args) {
        BigInteger n = sc.nextBigInteger();
        BigInteger m = sc.nextBigInteger();
        int k = sc.nextInt();
        init(n.mod(Mod).intValue() + Mo,k);
        long ans = 0;
        long p = pow(2,n);
        for(int i = 0;i <= k;i ++) {
            ans = (ans + dp[k][i] * p) % Mo;
            p = (Mo + 1) / 2 * p % Mo;
        }
        ans = ans * Lucas(n,m) % Mo;
        System.out.println(ans);
    }
}