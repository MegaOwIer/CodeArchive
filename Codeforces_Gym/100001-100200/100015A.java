import java.util.Scanner;

public class MegaOwIer {
	static final char[] answer = {'P', 'S', 'R'};
	static Scanner input = new Scanner(System.in);
    public static void main(String[] argv) {
        while(true) {
            long N = input.nextLong() - 1;
            if(N == -1) break;
            int res = 0;
            while(N > 0) {
                res += N % 3;
                N /= 3;
            }
            System.out.println(answer[res % 3]);
        }
        input.close();
    }
}
