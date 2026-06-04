package Patterns1;

public class invertedHalfPyramid {
    public static void main(String[] args) {
        for(int i=0;i<5;i++){
            int c=1;
            for(int j=5;j>=5-i;j--){
                System.out.print(c++ +" ");
            }

            for(int j=i+1;j<5;j++){
                System.out.print(" ");
            }

            System.out.println();
        }
    }
    
}
