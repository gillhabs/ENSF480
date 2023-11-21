/*
* File Name: Sorter.java
* Assignment: Lab 5 Exercise A
* Completed by: Gillian Habermehl 
* Submission Date: October 30, 2023
*/

import java.util.ArrayList;

public interface Sorter<E extends Number & Comparable<E>> {
    public void sort(ArrayList<Item<E>> arr);
    
}
