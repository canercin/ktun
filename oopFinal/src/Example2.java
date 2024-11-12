public class Example2 {
    public static void binaryChech(int x) throws BinaryException{
        if (x == 0 || x == 1) {
            throw new BinaryException("Birler basamağı 0 yada 1");
        }
    }
    public static void main(String[] args) {
        try {
            binaryChech(55);
        } catch (BinaryException e) {
            System.out.println(e.getMessage());
        }
    }
}
class BinaryException extends Exception {
    public BinaryException(String str) {
        super(str);
    }
}