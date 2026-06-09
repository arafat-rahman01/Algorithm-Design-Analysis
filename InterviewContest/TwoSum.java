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
