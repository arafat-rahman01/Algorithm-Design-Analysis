package InterviewContest;

public class kadaneAlgo{

    public static int maxSub(int[] arr){
        int currSum=0;
        int maxSum=Integer.MIN_VALUE;

        for(int i=0;i<arr.length;i++){
            currSum+=arr[i];

            if(currSum>maxSum){
                maxSum=currSum;
            }
            if(currSum<0) currSum=0;
        }
        return maxSum;
    }

    public static void main(String[] args) {
        int[] arr={-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(maxSub(arr));
    }
}