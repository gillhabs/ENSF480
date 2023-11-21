/*
* File Name: ThreeColumnTable_Observer.java
* Assignment: Lab 5 Exercise A
* Completed by: Gillian Habermehl 
* Submission Date: October 30, 2023
*/
import java.util.ArrayList;

public class ThreeColumnTable_Observer implements Observer {

    private ArrayList<Double> data;
    private Subject subj;

    public ThreeColumnTable_Observer(DoubleArrayListSubject subj) {
        this.subj = subj;
        subj.register(this);
    }

    @Override
    public void update(ArrayList<Double> arr) {
        this.data = arr;
        System.out.println("\nNotification to Three-Column Table Observer: Data Changed:");
        display();
    }

    public void display() {

        int n = data.size();
        int columns = 3;

        for (int i = 0; i < n; i++) {
            System.out.print(data.get(i) + " ");
            if ((i + 1) % columns == 0 || i == n - 1) {
                System.out.println();
            }
        }
    }
}
