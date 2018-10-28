import java.util.*;
import java.lang.Math;

public class Main {
    static boolean connected(ArrayList<Integer> [] v) {
        int n = v.length;
        boolean [] b = new boolean[n];
        Queue<Integer> q = new ArrayDeque<Integer>();

        q.add(n - 2);
        b[n - 2] = true;

        while (q.size() > 0) {
            int i = q.remove();
            if (i == n - 1)
                return true;
            for (int j : v[i]) {
                if (!b[j]) {
                    b[j] = true;
                    q.add(j);
                }
            }
        }

        return false;
    }
    
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        double h = sc.nextDouble(), w = sc.nextDouble();
        int n = sc.nextInt();
        double [][] d = new double[n][3];
        for (int i = 0; i < n; ++i) {
            d[i][0] = sc.nextDouble();
            d[i][1] = sc.nextDouble();
            d[i][2] = sc.nextDouble();
        }
        ArrayList<Integer> [] v = new ArrayList[n+2];
        for (int i = 0; i < n + 2; ++i)
            v[i] = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                double dx = d[i][0] - d[j][0];
                double dy = d[i][1] - d[j][1];
                if (Math.sqrt(dx*dx + dy*dy) < d[i][2] + d[j][2]) {
                    v[i].add(j);
                    v[j].add(i);
                }
            }
        for (int i = 0; i < n; ++i)
            if (Math.abs(d[i][0]) < d[i][2])
                v[n].add(i);
        for (int i = 0; i < n; ++i)
            if (Math.abs(d[i][0] - w) < d[i][2])
                v[i].add(n+1);
        if (connected(v))
            System.out.println("NO NO NO");
        else
            System.out.println("YES YES YES");
    }
}
