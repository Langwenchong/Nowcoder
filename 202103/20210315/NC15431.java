import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int date[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2,
                1 };
        int n = sc.nextInt();
        if (n == 1) {
            // 一个情况的特判
            int a = sc.nextInt();
            // 如果刚好是0，那么下一天一定是1，直接输出UP
            if (a == 0)
                System.out.println("UP");
            // 如果是15，那么下一天一定是14，直接输出DOWN
            else if (a == 15)
                System.out.println("DOWN");
            else
                // 否则无法判断，返还-1
                System.out.println("-1");
        } else {
            int a[] = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = sc.nextInt();
            }
            int index = 0;
            // 寻找匹配的段，实际上两个天就可以找到起始天了
            case1: for (int i = 0; i < 30; i++) {
                for (int j = 1; j <= 2; j++) {
                    if (a[j] == date[i] && a[j + 1] == date[i + 1]) {
                        index = i;
                        break case1;
                    }
                }
            }
            // 然后加上n天取模30（因为可能会到下一个30天了）
            // 就得到了需要的下一天
            // 根据大小判断即可，此时不可能再有无法判断的情况了
            if (date[index + n % 30] > a[n])
                System.out.println("UP");
            else
                System.out.println("DOWN");
        }
    }
}