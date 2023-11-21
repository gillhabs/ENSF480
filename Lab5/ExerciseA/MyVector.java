/*
* File Name: MyVector.java
* Assignment: Lab 5 Exercise A
* Completed by: Gillian Habermehl
* Submission Date: October 30, 2023
*/

import java.util.ArrayList;

public class MyVector<E extends Number & Comparable<E>> {

    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;

    public MyVector(int n) {
        storageM = new ArrayList<Item<E>>(n);
    }

    public MyVector(ArrayList<Item<E>> arr) {
        for(int i = 0; i < arr.size(); i++) {
            storageM.add(arr.get(i));
        }
    }

    public void add(Item<E> value) {
        storageM.add(value);
    }

    public void setSortStrategy(Sorter<E> s) {
            sorter = s;
    }

    public void performSort() {
        sorter.sort(storageM);
    }

    public void display() {
        for(int j = 0; j < storageM.size(); j++) {
            System.out.print(storageM.get(j).getItem() + " ");
        }
        System.out.println();
    }
}
