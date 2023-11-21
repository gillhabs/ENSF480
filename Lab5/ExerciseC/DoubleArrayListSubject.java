/*
* File Name: DoubleArrayListSubject.java
* Assignment: Lab 5 Exercise A
* Completed by: Gillian Habermehl 
* Submission Date: October 30, 2023
*/

import java.util.ArrayList;

public class DoubleArrayListSubject implements Subject{
    public ArrayList<Double> data;
    public ArrayList<Observer> observers;

    public DoubleArrayListSubject() {
        data = new ArrayList<Double>();
        observers = new ArrayList<Observer>();
    }

    public void populate(double[] arr) {
        for(int i = 0; i < arr.length; i++) {
            data.add(arr[i]);
        }
    }

    public void setData(double newData, int index) {
        data.set(index, newData);
        notifyObservers();
    }

    public void addData(double newData) {
        data.add(newData);
        notifyObservers();
    }

    public void display() {
        System.out.println("Empty List...");
    }

    @Override
    public void register(Observer o) {
        observers.add(o);
        o.update(data);
    }

    @Override
	public void remove(Observer o) {
        observers.remove(o);
    }

    @Override 
	public void notifyObservers() {
        for(int i = 0; i < observers.size(); i++) {
            Observer o = observers.get(i);
            o.update(data);
        }
    }
}
