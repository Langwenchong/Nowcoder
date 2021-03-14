import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int Alice = 0, Bob = 0;
        for (int i = 0; i < n; i++) {
            String s1 = sc.next();
            String s2 = sc.next();
            if (s1.equals("Jin") && s2.equals("Mu")) {
                Alice += 3;
            } else if (s1.equals("Mu") && s2.equals("Jin")) {
                Bob += 3;
            } else if (s1.equals("Mu") && s2.equals("Tu")) {
                Alice += 3;
            } else if (s1.equals("Tu") && s2.equals("Mu")) {
                Bob += 3;

            } else if (s1.equals("Tu") && s2.equals("Shui")) {
                Alice += 3;
            } else if (s1.equals("Shui") && s2.equals("Tu")) {
                Bob += 3;

            } else if (s1.equals("Shui") && s2.equals("Huo")) {
                Alice += 3;
            } else if (s1.equals("Huo") && s2.equals("Shui")) {
                Bob += 3;

            } else if (s1.equals("Huo") && s2.equals("Jin")) {
                Alice += 3;
            } else if (s1.equals("Jin") && s2.equals("Huo")) {
                Bob += 3;
            } else {
                Alice++;
                Bob++;
            }
        }
        if (Alice > Bob) {
            System.out.println("Alice");
        } else if (Alice < Bob) {
            System.out.println("Bob");
        } else {
            System.out.println("Draw");
        }
    }
}