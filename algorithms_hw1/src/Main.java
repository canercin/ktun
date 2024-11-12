import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    //file dosyasının bulunmasında sıkıntı olabilir.
    static File file = new File("src/sources/text.txt");

    public static void main(String[] args) throws FileNotFoundException {
        NodeOperations operations = new NodeOperations();
        Scanner reader = new Scanner(file), scanner = new Scanner(System.in);
        int nodeCount = nodeCounter(), column = 0;
        boolean bool = true;
        Node[] nodeHeads = new Node[nodeCount];
        while (reader.hasNextLine()){
            String line = reader.nextLine();
            String[] list = line.split("->|/| ");
            for (int item = 0; item < list.length; item = item + 2){
                if(item == 0){
                    nodeHeads[column] = new Node(list[item], Integer.parseInt(list[item + 1]));
                }else {
                    nodeHeads[column] = NodeOperations.addNode(nodeHeads[column], new Node(list[item], Integer.parseInt(list[item + 1])));
                }
            }
            column++;
        }
        do {
            System.out.println("""
                    1 -> Komşuluk Listesini listeler,
                    2 -> Plakası girilen şehrin giriş ve çıkış düğümlerini hesaplar,
                    3 -> Graftaki toplam kenar sayısını listeler,
                    4 -> Plakası girilen şehirden hangi şehirlere gidilebileceğini listeler,
                    5 -> Plakası girilen şehre hangi şehirlerden gelinebileceğini listeler,
                    6 -> çıkış için seçiniz.                  \s
                    """);
            System.out.println("Seçiminizi Giriniz -> ");
            int choose = scanner.nextInt();
            scanner.nextLine();
            switch (choose){
                case 1 -> operations.adjacencyListPrinter(nodeHeads);
                case 2 -> {
                    System.out.print("Plaka giriniz -> ");
                    int cityPlate = scanner.nextInt();
                    scanner.nextLine();
                    operations.degreePrinter(nodeHeads, cityPlate);
                }
                case 3 -> System.out.printf("Graftaki kenar sayısı = %d \n\n", operations.edgeCounter(nodeHeads));
                case 4 -> {
                    System.out.print("Plaka giriniz -> ");
                    int cityPlate = scanner.nextInt();
                    scanner.nextLine();
                    operations.whereToGo(nodeHeads, cityPlate);
                }
                case 5 -> {
                    System.out.print("Plaka giriniz -> ");
                    int cityPlate = scanner.nextInt();
                    scanner.nextLine();
                    operations.cameCityFrom(nodeHeads, cityPlate);
                }
                case 6 -> bool = false;
                default -> System.out.println("Geçerli işlem giriniz");
            }
        }while(bool);
    }

    /**
     * @return Returns the number of nodes in the graph.
     */
    public static int nodeCounter() throws FileNotFoundException {
        Scanner reader = new Scanner(file);
        int nodeCounter = 0;
        while (reader.hasNextLine()){
            reader.nextLine();
            nodeCounter++;
        }
        return nodeCounter;
    }
}