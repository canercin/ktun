public class NodeOperations {
    public Node addNode(Node headNode, Node newNode){
        if (headNode == null){
            headNode = newNode;
        } else {
            Node currentNode = headNode;
            while (currentNode.nextNode != null){
                currentNode = currentNode.nextNode;
            }
            currentNode.nextNode = newNode;
        }
        return headNode;
    }
}
