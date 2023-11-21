/*
* File Name: FiveRowsTable_Observer.java
* Assignment: Lab 5 Exercise A
* Completed by: Gillian Habermehl 
* Submission Date: October 30, 2023
*/

import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer{

    private ArrayList<Double> data;
    private Subject subj;

    public FiveRowsTable_Observer(DoubleArrayListSubject subj) {
        this.subj = subj;
        subj.register(this);
    }

    @Override
    public void update(ArrayList<Double> arr) {
        this.data = arr;
        System.out.println("\nNotification to Five-Rows Table Observer: Data Changed:");
        display();
    }

    public void display() {
        int n = data.size();
        int rows = 5;
        
        for (int i = 0; i < rows; i++) {
            for (int j = i; j < n; j += rows) {
                System.out.print(data.get(j) + " ");
            }
            System.out.println();
        }
    }
    

}
