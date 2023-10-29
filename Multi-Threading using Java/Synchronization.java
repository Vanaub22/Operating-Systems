public class Synchronization {
    public static void main(String args[]) throws Exception {
        Runnable obj=new Update();
        Thread t1=new Thread(obj,"First Thread");
        Thread t2=new Thread(obj,"First Thread");
        t1.start();
        t2.start();
        t1.join();
        t2.join();
    } // end of main
} // end of class

// // This is not thread safe implementation
// class Update implements Runnable {
//     int shared_resource=0;
//     public void run() {
//         for(int i=0;i<100;i++) increment();
//         System.out.println("Updated Value: "+shared_resource);
//     } // end of method
//     public void increment() {
//         shared_resource++;
//     }
// } // end of class

// This is thread safe implementation using 'synchronized' keyword
class Update implements Runnable {
    int shared_resource=0;
    public synchronized void increment() {
        shared_resource++;
    }
    public void run() {
        for(int i=0;i<100;i++) increment();
        System.out.println("Updated Value: "+shared_resource);
    } // end of method
} // end of class
