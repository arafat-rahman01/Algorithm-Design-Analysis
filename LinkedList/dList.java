class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
    }
}

public class dList {
    Node head;

    void insertEnd(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newNode;
        newNode.prev = temp;
    }

    void insertBegin(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        newNode.next = head;
        head.prev = newNode;
        head = newNode;
    }

    void displayForward() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    void displayBackward() {
        Node temp = head;
        if (temp == null) return;

        while (temp.next != null) {
            temp = temp.next;
        }
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.prev; 
        }
        System.out.println();
    }

    void deleteNode(int key) {
        if (head == null) return;

        Node temp = head;

        if (temp.data == key) {
            head = temp.next;
            if (head != null) head.prev = null;
            return;
        }

        while (temp != null && temp.data != key) {
            temp = temp.next;
        }

        if (temp == null) return; 

        if (temp.next != null)
            temp.next.prev = temp.prev;

        if (temp.prev != null)
            temp.prev.next = temp.next;
    }

    public static void main(String[] args) {
        dList dll = new dList();

        dll.insertEnd(10);
        dll.insertEnd(20);
        dll.insertBegin(5);
        dll.insertEnd(30);

        dll.displayForward();   
        dll.displayBackward();  

        dll.deleteNode(20);
        dll.displayForward(); 
    }
}
