/*
* File Name: ColouredGlassDecorator.java
* Assignment: Lab 6 Exercise B
* Completed by: Gillian Habermehl
* Submission Date: November 6, 2023
*/

import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ColouredGlassDecorator extends Decorator {

    public ColouredGlassDecorator(Component c, int a, int b, int w, int h, int e) {
        super(c, a, b, w, h);
    }

	public ColouredGlassDecorator(ColouredFrameDecorator d, int a, int b, int w, int h) {
		super(d, a, b, w, h);
	}

    @Override
    public void draw(Graphics g) {
		cmp.draw(g);
		Graphics2D g2d = (Graphics2D) g;

		g2d.setColor(Color.green);

		// Sets blending to "source over" (blends src and dest pixels)
		// Drawn rectangle will have 10% opacity (1 * 0.1f)
		g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1 * 0.1f));
		g2d.fillRect(x, y, width, height);
    }
}
