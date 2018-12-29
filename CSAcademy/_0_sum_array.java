// Problem Link : https://csacademy.com/contest/round-25/task/0-sum-array/
// Change class name to "Main" before submitting

import java.util.*;

public class _0_sum_array {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt(), sum = 0;
        int[] arr = new int[N];
        for(int i = 0; i < N; i++)
            sum += (arr[i] = input.nextInt());
        input.close();
        sum /= 2;
        for(int i = 0; i < N; i++)
            if(arr[i] == sum) {
                System.out.println(i + 1);
                return;
            }
        System.out.println(-1);
    }
}
