public class Main {
    public static void main(String[] args) {
        BSTOperations bstOperations = new BSTOperations();
        BSTNode head = null;
        int[] arr = {10, 5, 15, 3, 7, 12, 18, 2, 4, 6, 8, 11, 13, 17, 19, 1, 9, 14, 16, 20};
        for (int i :
                arr) {
            head = bstOperations.createBST(head, i);
        }
        bstOperations.levelOrderWithLevel(head);
        System.out.println();
        System.out.println();

        head = bstOperations.createMirror2(head);
        bstOperations.levelOrderWithLevel(head);
    }
}