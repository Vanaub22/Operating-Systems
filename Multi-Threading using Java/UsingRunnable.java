// Using threads by implementing the Runnable interface
class Hi implements Runnable{
    public void run() {
        for(int i=0;i<5;i++) {
            System.out.println("Hi");
            try { Thread.sleep(1000); } catch(Exception e) {}
        } // end of for loop
    } // end of over-ridden method run
} // end of class
class Hello implements Runnable {
    public void run() {
        for(int i=0;i<5;i++) {
            System.out.println("Hello");
            try { Thread.sleep(1000); } catch(Exception e) {}
        } // end of for loop
    } // end of over-ridden method run
} // end of class
public class UsingRunnable {
    public static void main(String args[]) {
        Runnable ob1=new Hi(),ob2=new Hello(); // creating objects using Interface reference
        Thread th1=new Thread(ob1),th2=new Thread(ob2);
        th1.start();
        try { Thread.sleep(10); } catch(Exception e) {}
        th2.start();
    } // end of main
} // end of class