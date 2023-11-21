/*
* File Name: OneRow_Observer.java
* Assignment: Lab 5 Exercise A
* Completed by: Gillian Habermehl 
* Submission Date: October 30, 2023
*/

import java.util.ArrayList;

public class OneRow_Observer implements Observer{

    private ArrayList<Double> data;
    private Subject subj;

    public OneRow_Observer(DoubleArrayListSubject subj) {
        this.subj = subj;
        subj.register(this);
    }

    @Override
    public void update(ArrayList<Double> arr) {
        this.data = arr;
        display();
    }

    public void display() {
        int n = data.size();

        System.out.println("\nNotification to One-Row Observer: Data Changed:");
        for (int i = 0; i < n; i++) {
            System.out.print(data.get(i) + " ");
        }
        System.out.println();
    }
}
