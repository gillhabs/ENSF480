/*
* File Name: Text.java
* Assignment: Lab 6 Exercise A
* Completed by: Gillian Habermehl
* Submission Date: November 6, 2023
*/

import java.awt.Graphics;
import java.awt.Graphics2D;


public class Text implements Component {
    protected int x;
    protected int y;
    protected String text;

    public Text(String s, int a, int b) {
        text = s;
        x = a;
        y = b;
    }

    @Override
    public void draw(Graphics g) {
      Graphics2D g2d = (Graphics2D) g;
      g2d.drawString(text, x, y);
    }
}
