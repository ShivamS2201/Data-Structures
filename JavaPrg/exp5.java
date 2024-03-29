// Create a second thread by extending Thread
class NewThread extends Thread {
    NewThread() {
    // Create a new, second thread
    super("Demo Thread");
    System.out.println("Child thread: " + this);
    start(); // Start the thread
    }
    
    // This is the entry point for the second thread.
    public void run() {
    try {
    for(int i = 5; i > 0; i--) {
    System.out.println("Child Thread: " + i);
    // Let the thread sleep for a while.
    
    Thread.sleep(500);
    }
    } catch (InterruptedException e) {
    System.out.println("Child interrupted.");
    }
    System.out.println("Exiting child thread.");
    }
    }
    
    public class exp5 {
    public static void main(String args[]) {
    new NewThread(); // create a new thread
    try {
    for(int i = 5; i > 0; i--) {
    System.out.println("\nMain Thread: " + i);
    System.out.println("------------------");
    Thread.sleep(1000);
    }
    } catch (InterruptedException e) {
    System.out.println("Main thread interrupted.");
    }
    System.out.println("Main thread exiting.");
    }
    }