package java;
import java.io.*;
import java.util.*;

public class distinct {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine().trim());
        String[] input = br.readLine().trim().split(" ");

        HashSet<Integer> set = new HashSet<>();

        for (String num : input) {
            set.add(Integer.parseInt(num));
        }

        System.out.print(set.size());
    }
}
