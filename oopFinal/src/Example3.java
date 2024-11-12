public class Example3 extends B implements A {
    public static void main(String[] args) {
        Example3 obj = new Example3();
        obj.methodA();
    }

}
interface A {
    default void methodA(){
        System.out.println("interface");
    }
}
class B{
    public void methodA(){
        System.out.println("class");
    }
}
