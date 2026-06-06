package InterviewContest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class MaximumAndMinimum {
    public static ArrayList<Integer> findMinMax(int[] arr){
        ArrayList<Integer>sortedArr = new ArrayList<>();
        for(int num:arr){
            sortedArr.add(num);
        }
        Collections.sort(sortedArr);

        ArrayList<Integer> result = new ArrayList<>();
        result.add(sortedArr.get(0));
        result.add(sortedArr.get(sortedArr.size()-1));

        return result;
    }

    // public static void main(String[] args) {
    //     int[] arr = {3,5,4,1,9};
    //     ArrayList<Integer> result = findMinMax(arr);
    //     System.out.println(result.get(0)+" "+result.get(1));
    // }

    // 2 
    public static void main(String[] args) {
        int[] arr = {5,2,7,4,8,11};
        Arrays.sort(arr);
        System.out.print(arr[0]+" "+arr[arr.length-1]);
    }


}
