import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class Main {
    static File f = new File("C:\\Users\\Caner Çin\\OneDrive\\Masaüstü\\java\\circularLList\\src\\menuList.txt");
    static Scanner reader;

    static {
        try {
            reader = new Scanner(f);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    static Scanner scanner = new Scanner(System.in);
    static Operations operations = new Operations();
    static Foods firstFood = null;
    static Foods lastFood;
    public static void main(String[] args) {
        read();
        boolean bool = true;
        do {
            System.out.println("""
                    İşlem seçiniz
                    1 -> Ekleme
                    2 -> Silme
                    3 -> Listeleme
                    4 -> Yemek Seçimi
                    5 -> Çıkış""");
            int choose = scanner.nextInt();
            scanner.nextLine();
            switch (choose) {
                case 1 -> {
                    System.out.println("Eklemek istediğiniz ürünün ismini giriniz:");
                    String name = scanner.nextLine();
                    System.out.println("Eklemek istediğiniz ürünün gramajını giriniz:");
                    int weight = scanner.nextInt();
                    System.out.println("Eklemek istediğiniz ürünün fiyatını giriniz:");
                    double price = scanner.nextDouble();
                    firstFood = operations.seqAdd(firstFood, name, weight, price);
                }
                case 2 -> {
                    System.out.println("Silmek istediğiniz ürünün ismini giriniz");
                    String delName = scanner.nextLine();
                    firstFood = Operations.delete(firstFood, delName);
                }
                case 3 -> Operations.printList(firstFood);
                case 4 -> {
                    Operations.printList(firstFood);
                    double checkOut = 0;
                    boolean bool2 = true;
                    do {
                        System.out.println("Hangi yemeği seçmek istersiniz? ");
                        String find = scanner.nextLine();
                        checkOut = checkOut + Operations.find(find, firstFood);
                        System.out.println("Başka yemek seçmek ister misiniz? (e / h)");
                        String boolC = scanner.nextLine();
                        if (boolC.equalsIgnoreCase("h")) {
                            bool2 = false;
                        }
                    } while (bool2);
                    System.out.printf("Ödeme yapmanız gereken miktar %.2f.\n", checkOut);
                }
                case 5 -> {
                    System.out.println("Programdan çıkılıyor.");
                    bool = false;
                }
                default -> System.out.println("Geçerli işlem giriniz");
            }
            lastFood = Operations.findLast(firstFood);
        } while(bool);
    }

    public static void read(){
        while(reader.hasNextLine()){
            String[] line = reader.nextLine().split(" ");
            String name = line[0];
            int weight = Integer.parseInt(line[1]);
            double price = Double.parseDouble(line[2]);
            firstFood = operations.seqAdd(firstFood, name, weight, price);
        }
    }
}