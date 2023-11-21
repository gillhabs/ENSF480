/*
* File Name: ColouredFrameDecorator.java
* Assignment: Lab 6 Exercise A
* Completed by: Gillian Habermehl
* Submission Date: November 6, 2023
*/

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;
import java.awt.BasicStroke;
import java.awt.Color;

public class ColouredFrameDecorator extends Decorator {

    private int thickness;

    public ColouredFrameDecorator(Component cmp, int a, int b, int w, int h, int t) {
        super(cmp, a, b, w, h);
		thickness = t;
    }

    @Override
    public void draw(Graphics g) {
		cmp.draw(g);
		Graphics2D g2d = (Graphics2D) g;
		Stroke oldStroke = g2d.getStroke();
		Color oldColor = g2d.getColor();

		g2d.setStroke(new BasicStroke(thickness));
		g2d.setColor(Color.red);
		g2d.drawRect(x, y, width, height);
		g2d.setStroke(oldStroke);
		g2d.setColor(oldColor);
    }
}
