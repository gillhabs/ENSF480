/*
* File Name: Decorator.java
* Assignment: Lab 6 Exercise A
* Completed by: Gillian Habermehl
* Submission Date: November 6, 2023
*/

import java.awt.Graphics;

public class Decorator implements Component {
    protected Component cmp;
    protected int x;
    protected int y;
    protected int width;
    protected int height;

    public Decorator() {
    }

    public Decorator(Component c, int a, int b, int w, int h) {
        cmp = c;
        x = a;
        y = b;
        width = w;
        height = h;
    }    

    @Override
    public void draw(Graphics g) {
    }

}
