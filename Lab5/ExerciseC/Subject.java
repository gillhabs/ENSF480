/*
* File Name: Subject.java
* Assignment: Lab 5 Exercise A
* Completed by: Gillian Habermehl 
* Submission Date: October 30, 2023
*/
public interface Subject {

    public void register(Observer o);
	public void remove(Observer o);
	public void notifyObservers();
}
