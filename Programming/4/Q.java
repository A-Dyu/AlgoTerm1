import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

import static java.lang.Math.min;

public class Main {
    static BufferedWriter writer;
    static Scanner sc;
    static int mod;
    static int matrix[][];

    static int check(int x, int y, int m) {
        for (int i = 0; i < m - 1; i++) {
            int a0 = min(1, x & (1 << i));
            int a1 = min(1, x & (1 << (i + 1)));
            int b0 = min(1, y & (1 << i));
            int b1 = min(1, y & (1 << (i + 1)));
            if (a0 == b0 && a0 == a1 && a1 == b1) {
                return 0;
            }
        }
        return 1;
    }

    static int[][] mul(int[][] a, int [][] b) {
        int[][] c = new int[a.length][b[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                c[i][j] = 0;
                for (int r = 0; r < b.length; r++) {
                    c[i][j] = (c[i][j] + a[i][r] * b[r][j]) % mod;
                }
            }
        }
        return c;
    }

    static int[][] pow(BigInteger n) {
        if (n.equals(BigInteger.valueOf(1))) {
            return matrix;
        }
        int[][] a = pow(n.divide(BigInteger.valueOf(2)));
        a = mul(a, a);
        if (n.mod(BigInteger.valueOf(2)).equals(BigInteger.valueOf(1))) {
            a = mul(a, matrix);
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        writer =  new BufferedWriter(
                new OutputStreamWriter(new FileOutputStream("nice3.out")));
        sc = new Scanner(new InputStreamReader(new FileInputStream("nice3.in")));
        BigInteger n = new BigInteger(sc.next());
        int m = sc.nextInt();
        mod = sc.nextInt();
        matrix = new int[(1 << m)][(1 << m)];
        for (int i = 0; i < (1 << m); i++) {
            for (int j = 0; j < (1 << m); j++) {
                matrix[i][j] = check(i, j, m);
            }
        }
        if (n.equals(BigInteger.valueOf(1))) {
            writer.write(Integer.toString((1 << m) % mod));
        } else {
            n = n.add(BigInteger.valueOf(-1));
            int[][] a = pow(n);
            int[][] b = new int[(1 << m)][1];
            for (int i = 0; i < (1 << m); i++)
                b[i][0] = 1;
            a = mul(a, b);
            int ans = 0;
            for (int i = 0; i < (1 << m); i++) {
                ans = (ans + a[i][0]) % mod;
            }
            writer.write(Integer.toString(ans));
        }
        writer.close();
    }
}