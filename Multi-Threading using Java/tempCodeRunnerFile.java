// This is thread safe implementation using 'synchronized' keyword
// class Update implements Runnable {
//     int shared_resource=0;
//     public synchronized void increment() {
//         shared_resource++;
//     }
//     public void run() {
//         try{
//             for(int i=0;i<100;i++) increment();
//             Thread.sleep(1000);
//             System.out.println("Updated Value: "+shared_resource);
//         }
//         catch(InterruptedException e) {}
//     } // end of method
// } // end of class