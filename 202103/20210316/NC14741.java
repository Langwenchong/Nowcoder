import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int d = sc.nextInt();
            int num1 = a / d;
            int num2 = b / c;
            if (a % d != 0)
                num1++;
            if (b % c != 0)
                num2++;
            //当主人公可以支撑的回合数大于等于小怪时，主人公胜利
            //之所以等于是主人公胜利是因为他先手
            if (num2 >= num1)
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }
}