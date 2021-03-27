import java.util.Scanner;

public class h01 {
    public static int transform(int x){
        int tmp=x;
        int num=0;
        while(tmp!=0){
            num+=tmp%10;
            tmp/=10;
        }
        if(num==x%10){
            return num;
        }
        else{
            return transform(num);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int ans=transform(n);
        System.out.println(ans);
    }
}