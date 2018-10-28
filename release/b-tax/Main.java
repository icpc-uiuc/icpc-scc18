import java.util.*;

public class Main {
    static int owed(int x) {
        int r = 0;
        if (x > 80000) {
            r += (x - 80000)*4/5;
            x = 80000;
        }
        if (x > 40000) {
            r += (x - 40000)*2/5;
            x = 40000;
        }
        if (x > 20000) {
            r += (x - 20000)/5;
            x = 20000;
        }
        if (x > 10000) {
            r += (x - 10000)/10;
            x = 10000;
        }
        return r;
    }

    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            int x = sc.nextInt();
            int r = owed(x);
            int h = x/2;
            if (r == h)
                System.out.printf("Clear\n");
            else if (r > h)
                System.out.printf("Owe %d\n", r - h);
            else
                System.out.printf("Refund %d\n", h - r);
        }
    }
}
