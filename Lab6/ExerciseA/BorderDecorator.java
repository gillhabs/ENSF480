/*
* File Name: BorderDecorator.java
* Assignment: Lab 6 Exercise A
* Completed by: Gillian Habermehl
* Submission Date: November 6, 2023
*/

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;

public class BorderDecorator extends Decorator {

    public BorderDecorator(Component c, int a, int b, int w, int h) {
        super(c, a, b, w, h);
    }

    @Override
    public void draw(Graphics g) {
		cmp.draw(g);
		Graphics2D g2d = (Graphics2D) g;
		Stroke oldStroke = g2d.getStroke();
		Color oldColor = g2d.getColor();

		// width of the stroke is 4 pixels
		// end-cap style: ends apbruptly and end point
		// style of join: beveled(angled)
		// miter limit: 0
		// dash-pattern: length 9 before gap
		// offset: 0 (starts from beginning)
		g2d.setStroke(new BasicStroke(4, BasicStroke.CAP_BUTT, 
			BasicStroke.JOIN_BEVEL, 0, new float[] {9}, 0));
		g2d.setColor(Color.black);
		g2d.drawRect(x, y, width, height);
		g2d.setStroke(oldStroke);
		g2d.setColor(oldColor);
    }
}
