// Problem Link : https://csacademy.com/contest/round-9/task/3-divisible-pairs/
// Change class name to "Main" before submitting

import java.util.*;

public class _3_divisible_pairs {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        long[] cnt = {0, 0, 0};
        for(int i = 1; i <= N; i++)
            cnt[input.nextInt() % 3]++;
        input.close();
        long ans = cnt[1] * cnt[2] + (cnt[0] - 1) * cnt[0] / 2;
        System.out.println(ans);
    }
}
