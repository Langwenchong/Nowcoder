import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int f[] = new int[35];
        f[0] = 1;
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= 30; i++) {
            f[i] = f[i - 1] + 2 * f[i - 2];
        }
        for (int i = 1; i <= t; i++) {
            int n = sc.nextInt();
            System.out.println(f[n]);
        }
    }
}