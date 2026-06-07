//https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// Extra Space = O(n) (HashSet) Not Accept

import java.util.*;

public class repeatandmissingnumberarray {

    public static int[] repeatedNumber(int[] A) {

        HashSet<Integer> set = new HashSet<>();

        int duplicate = 0;
        int missing = 0;

        Arrays.sort(A);

        for (int i = 0; i < A.length - 1; i++) {

            if (A[i] == A[i + 1]) {
                duplicate = A[i];
            }

            if (A[i] + 1 != A[i + 1] && A[i] != A[i + 1]) {
                missing = A[i] + 1;
            }
        }

        // Edge Cases
        if (missing == 0) {
            if (A[0] != 1) {
                missing = 1;
            } else {
                missing = A.length;
            }
        }

        return new int[]{duplicate, missing};
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter array elements:");

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int[] ans = repeatedNumber(arr);

        System.out.println("Duplicate Number = " + ans[0]);
        System.out.println("Missing Number = " + ans[1]);

        sc.close();
    }
}