package java;
import java.io.*;
import java.util.*;

public class bookShop {

    public static void main(String[] args) throws IOException {
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] h = new int[n];
        int[] s = new int[n];
        for(int i = 0; i < n; i++){
            h[i] = sc.nextInt();
        }
        for(int i = 0; i < n; i++){
            s[i] = sc.nextInt();
        }

        int[] total = new int[x + 1];
        for(int i = 0; i < n; i++){
            for(int j = x; j >= h[i]; j--){
                total[j] = Math.max(total[j], total[j-h[i]] + s[i]);
            }
        }

        System.out.println(total[x]);

        sc.close();
    }
}