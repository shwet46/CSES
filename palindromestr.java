import java.util.Scanner;

public class palindromestr {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // number of test cases
        scanner.nextLine(); // consume the newline after reading the integer

        for (int i = 0; i < t; i++) {
            String str = scanner.nextLine().trim(); // read the string and trim any surrounding whitespace
            if (isPalindrome(str)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        scanner.close();
    }

    public static boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
