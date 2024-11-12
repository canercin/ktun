public class Example4 {
    public static void main(String[] args) {
        callAll(new X(), 123);
        callAll(new Y(), 123);
        callAll(new Z(), 123);
    }
    public static void callAll(IntA obj, int keyId){
        obj.collect(keyId);
        obj.run(keyId);
        obj.analysis(keyId);
        if (obj instanceof X) {
            ((X)obj).x1();
        }
        if (obj instanceof Y) {
            ((Y)obj).y1();
        }
        if (obj instanceof Z) {
            ((Z)obj).z1();
        }
    }
}
interface IntA{
    void collect(int keyId);
    void run(int KeyId);
    void analysis(int keyId);
}
class X implements IntA{
    @Override
    public void collect(int keyId) {
        System.out.println("collect a");
    }

    @Override
    public void run(int KeyId) {
        System.out.println("run a");
    }

    @Override
    public void analysis(int keyId) {
        System.out.println("analysis a");
    }

    public void x1(){
        System.out.println("x1");
    }
}
class Y implements IntA{

    @Override
    public void collect(int keyId) {
        System.out.println("collect b");
    }

    @Override
    public void run(int KeyId) {
        System.out.println("run b");
    }

    @Override
    public void analysis(int keyId) {
        System.out.println("analysis b");
    }
    public void y1(){
        System.out.println("y1");
    }
}
class Z implements IntA{

    @Override
    public void collect(int keyId) {
        System.out.println("collect c");
    }

    @Override
    public void run(int KeyId) {
        System.out.println("run c");
    }

    @Override
    public void analysis(int keyId) {
        System.out.println("analysis c");
    }
    public void z1(){
        System.out.println("z1");
    }
}

