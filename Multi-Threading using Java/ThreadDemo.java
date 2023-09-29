// Using threads by inheriting from the Thread class using 'extends'
class Hi extends Thread {
    public void run() {
        for(int i=0;i<5;i++) {
            System.out.println("Hi");
            try { Thread.sleep(1000); } catch(Exception e) {}
        } // end of for loop
    } // end of over-ridden method run
} // end of class
class Hello extends Thread {
    public void run() {
        for(int i=0;i<5;i++) {
            System.out.println("Hello");
            try { Thread.sleep(1000); } catch(Exception e) {}
        } // end of for loop
    } // end of over-ridden method run
} // end of class
class ThreadDemo {
    public static void main(String args[]) {
        Hi ob1=new Hi();
        Hello ob2=new Hello();
        ob1.start();
        // to ensure uniform output we insert a small delay
        try { Thread.sleep(10); } catch(Exception e) {}
        ob2.start();
    } // end of main
} // end of class