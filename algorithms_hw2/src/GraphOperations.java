import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class GraphOperations {
    public void fillMatrix(int[][] adjacencyMatrix, File graf) throws FileNotFoundException {
        Scanner reader = new Scanner(graf);
        for(int i = 0; i < Main.getNumberOfNodes(graf); i++){
            String data = reader.nextLine();
            String[] splitData = data.split(" ");
            for(int j = 0; j < splitData.length; j++){
                adjacencyMatrix[i][j] = Integer.parseInt(splitData[j]);
            }
        }
    }
    public void graphCreator(Node[] nodeHeads, int[][] adjacencyMatrix) throws FileNotFoundException {
        NodeOperations nodeOperator = new NodeOperations();
        File graf = new File("sources/graf.txt");
        for(int i = 0; i < Main.getNumberOfNodes(graf); i++){
            nodeHeads[i] = new Node(i);
        }
        for(int i = 0; i < Main.getNumberOfNodes(graf); i++){
            for(int j = 0; j < Main.getNumberOfNodes(graf); j++){
                if(adjacencyMatrix[i][j] == 1){
                    nodeHeads[i] = nodeOperator.addNode(nodeHeads[i], new Node(j));
                }
            }
        }
    }
    public void printGraph(Node[] nodeHeads){
        for(Node node : nodeHeads){
            System.out.printf("%d: ", node.id);
            node = node.nextNode;
            while (node != null){
                if (node.nextNode != null){
                    System.out.printf("%d,", node.id);
                } else {
                    System.out.printf("%d", node.id);
                }
                node = node.nextNode;
            }
            System.out.println();
        }
    }

    public void deepFirstSearch(int id, Node[] nodeHeads){
        Node currentNode = nodeHeads[id];
        currentNode.color = Color.gray;
        System.out.printf("%d ", currentNode.id);
        while (currentNode.nextNode != null){
            currentNode = currentNode.nextNode;
            if(nodeHeads[currentNode.id].color == Color.white){
                deepFirstSearch(currentNode.id, nodeHeads);
            }
        }
        nodeHeads[id].color = Color.black;
    }

}
