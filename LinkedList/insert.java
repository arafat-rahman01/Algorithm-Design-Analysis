
class Node{
    int data;
    Node next;

    Node(int data){
        this.data=data;
        this.next=null;
    }
}

class linkedList{
    Node head;
    void insertAtEnd(int value){
        Node newNode=new Node(value);
        if(head==null){
            head=newNode;
            return;
        }
        Node temp=head;
        while(temp.next!=null){
            temp=temp.next;
        }
        temp.next=newNode;
    }
    void insertAtBeg(int val){
        Node newNode=new Node(val);
        if(head==null){
            head=newNode;
            return;
        }
        newNode.next=head;
        head=newNode;
    }
    void insertAtAnyPosition(int val,int pos){
        Node newNode=new Node(val);
        if(pos==1){
            newNode.next=head;
            head=newNode;
            return;
        }
        Node temp=head;

       for(int i=0;temp!=null && i<pos-1;i++){
        temp=temp.next;
       }
       if(temp==null) return;
        newNode.next=temp.next;
        temp.next=newNode;
    }
    void display(){
        Node temp=head;
        while(temp!=null){
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.println("null");
    }
    public static void main(String[] args) {
        linkedList li=new linkedList();
        li.insertAtEnd(1);
        li.insertAtEnd(2);
        li.insertAtEnd(3);
        li.insertAtAnyPosition(11, 3);
        li.insertAtEnd(4);
        li.insertAtEnd(5);
        li.insertAtEnd(6);
        li.display();
    }
}