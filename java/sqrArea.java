package java;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class sqrArea {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int t = scanner.nextInt(); // Read number of test cases

            while (t-- > 0) {
                Set<Integer> xCoords = new HashSet<>();
                Set<Integer> yCoords = new HashSet<>();

                // Read the four corners
                for (int i = 0; i < 4; i++) {
                    int x = scanner.nextInt();
                    int y = scanner.nextInt();
                    xCoords.add(x);
                    yCoords.add(y);
                }

                // Since it's a square with sides parallel to the axes, there should be exactly
                // 2 unique x and y coordinates
                var xArray = xCoords.toArray(new Integer[0]);
                var yArray = yCoords.toArray(new Integer[0]);

                // Calculate the side length of the square
                int sideLength = Math.abs(xArray[1] - xArray[0]); // or Math.abs(yArray[1] - yArray[0])

                // Calculate the area of the square
                int area = sideLength * sideLength;

                System.out.println(area);
            }
        }
    }
}
