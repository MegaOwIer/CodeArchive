// Problem Link : https://csacademy.com/contest/round-54/task/acronyms/
// Change class name to "Main" before submitting

import java.lang.*;
import java.util.*;

public class acronyms {
    static Scanner input = new Scanner(System.in);
    static int[] cnt = new int[26];

    public static void main(String[] args) {
        int N = input.nextInt();
        String[] S = new String[N];
        for(int i = 0; i < S.length; i++) {
            S[i] = input.next();
            cnt[S[i].charAt(0) - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < S.length; i++) {
            int[] cur = new int[26];
            System.arraycopy(cnt, 0, cur, 0, 26);
            cur[S[i].charAt(0) - 'a']--;
            for(int j = 0; j < S[i].length(); j++)
                cur[S[i].charAt(j) - 'a']--;
            boolean flag = true;
            for (int val : cur)
                flag &= (val >= 0);
            if(flag)
                ans++;
        }
        System.out.println(ans);
        input.close();
    }
}
