package Patterns1;

public class howllowRec {
    public static void main(String[] args) {
        for(int i=0;i<4;i++){
            if(i>0 && i!=3){
                System.out.print("*       *");
            }else {
                for(int k=0;k<5;k++){
                    System.out.print("* ");
                }
            }
            
            System.out.println();
        }
    }
}
