import java.util.LinkedList;
import java.util.Queue;

public class BSTOperations {
    /**
     * @param head BST head node
     * @param data data to be inserted
     * @return head of BST
     * Creates BST
     */
    public BSTNode createBST(BSTNode head, int data) {
        if (head == null) {
            head = new BSTNode();
            head.data = data;
            head.left = null;
            head.right = null;
        } else if (data < head.data) {
            head.left = createBST(head.left, data);
        } else if (data > head.data) {
            head.right = createBST(head.right, data);
        }
        return head;
    }

    /**
     * @param head BST head node
     *             Prints BST in level order
     */
    public void levelOrderWithLevel(BSTNode head) {
        if (head == null) {
            return;
        }
        int i = 1;
        Queue<BSTNode> queue = new LinkedList<>();
        queue.add(head);
        do {
            int queueSize = queue.size();
            System.out.println();
            System.out.printf("Seviye %d: \t", i);
            for (int j = 0; j < queueSize; j++) {
                BSTNode temp = queue.poll();
                if (temp == null) {
                    System.out.print("boş,");
                    continue;
                } else {
                    System.out.printf("%d,", temp.data);
                }
                if (temp.left != null) {
                    queue.add(temp.left);
                } else {
                    queue.add(null);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                } else {
                    queue.add(null);
                }
            }
            i++;
        } while (!queue.isEmpty());
    }

    /**
     * @param head BST head node
     * @return head of BST
     * Creates mirror of BST
     *
     */
    public BSTNode createMirror(BSTNode head) {
        if (head == null) {
            return null;
        }
        BSTNode temp = head.left;
        head.left = head.right;
        head.right = temp;
        head.left = createMirror(head.left);
        head.right = createMirror(head.right);
        return head;
    }

    /**
     * @param head BST head node
     * @return head of BST
     */
    public BSTNode createMirror2(BSTNode head){
        BSTNode temp;
        if(head == null){
            return null;
        }
        temp = head.left;
        head.left = head.right;
        head.right = temp;

        return head;
    }
}
