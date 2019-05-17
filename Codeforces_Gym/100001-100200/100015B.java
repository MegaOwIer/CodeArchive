import java.util.Scanner;

public class MegaOwIer {
    static Scanner input = new Scanner(System.in);
    static final int N = 1000, mod = 1000000007;
    public static void main(String[] args) {
        int[][] dp = new int[N + 1][N * 2 + 1];
        dp[1][1] = dp[1][2] = 2;
        for(int i = 2; i <= 1000; i++)
            for(int j = i; j <= i * 2; j++)
                dp[i][j] = (int)((dp[i][j - 1] * (long)(2 * i - j + 1) + dp[i - 1][j - 1] * 4L) % mod);
        while(true) {
            int n = input.nextInt();
            if(n == 0)
                break;
            System.out.println(dp[n][n * 2]);
        }
    }
}
