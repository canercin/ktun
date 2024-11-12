import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        GraphOperations graphOperator = new GraphOperations();
        int numberOfNodes = getNumberOfNodes(new File("sources/graf.txt"));
        int[][] adjacencyMatrix = new int[numberOfNodes][numberOfNodes];
        graphOperator.fillMatrix(adjacencyMatrix, new File("sources/graf.txt"));
        Node[] nodeHeads = new Node[numberOfNodes];
        graphOperator.graphCreator(nodeHeads, adjacencyMatrix);
        graphOperator.printGraph(nodeHeads);
        Scanner scanner = new Scanner(System.in);
        System.out.print("Başlangıç düğümün numarasını giriniz: ");
        int nodeId = scanner.nextInt();
        graphOperator.deepFirstSearch(nodeId,nodeHeads);
    }
    public static int getNumberOfNodes(File graf) throws FileNotFoundException {
        Scanner reader = new Scanner(graf);
        int numberOfNodes = 0;
        while (reader.hasNextLine()){
            reader.nextLine();
            numberOfNodes++;
        }
        return numberOfNodes;
    }
}
