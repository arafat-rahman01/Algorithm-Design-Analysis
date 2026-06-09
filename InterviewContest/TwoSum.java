public class TwoSum {
    public static void main(String[] args) {
        int[] arr={1,3,3,4};
        int t=5,a=0,b=0;
        for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[i]+arr[j]==t){
                    a=i;
                    b=j;
                }
            }
        }
        System.out.println(a+" "+b);
    }
}

//https://workat.tech/problem-solving/practice/two-sum
// class Solution {
// 	int[] twoSum(int[] A, int target) {
// 	    // add your logic here
// 		int a=0,b=0;
//         for(int i=0;i<A.length;i++){
//             for(int j=i+1;j<A.length;j++){
//                 if(A[i]+A[j]==t){
//                     a=i;
//                     b=j;
//                 }
//             }
//         }
// 		return a,b;
// 	}
// }

//Optimised way
// HashMap<Integer,Integer> map = new HashMap<>();

// for(int i=0;i<A.length;i++){

//     int need = target - A[i];

//     if(map.containsKey(need)){
//         return new int[]{map.get(need), i};
//     }

//     map.put(A[i], i);
// }