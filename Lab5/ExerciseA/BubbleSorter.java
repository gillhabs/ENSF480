/*
* File Name: BubbleSorter.java
* Assignment: Lab 5 Exercise A
* Completed by: Gillian Habermehl
* Submission Date: October 30, 2023
*/

import java.util.ArrayList;

public class BubbleSorter<E extends Number & Comparable<E>> implements Sorter<E> {

    @Override
    public void sort(ArrayList<Item<E>> arr) {

        boolean isSwapped;

        for(int i = 0; i < arr.size(); i++) {
            isSwapped = false;
            
            for(int j = 0; j < arr.size() - i - 1; j++) {
                if(arr.get(j).getItem().compareTo(arr.get(j + 1).getItem()) > 0) {
                    Item<E> temp = arr.get(j);
                    arr.set(j, arr.get(j + 1));
                    arr.set(j + 1, temp);
                    isSwapped = true; 
                }
            }

            if(isSwapped != true) {
                break;
            }
        }
    }
}
