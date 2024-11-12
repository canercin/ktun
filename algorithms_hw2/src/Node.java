import java.awt.*;

public class Node {
    int id;
    Node nextNode;
    Color color;

    public Node(int id) {
        this.id = id;
        color = Color.white;
    }
}
