import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

import javax.swing.event.MouseInputListener;


public class exp6_applets extends Applet {
    public static void main(String[] args) {
        Frame DrawingApplet = new Frame("Draw Rectangle using the drawRect () method. ");

        DrawingApplet.setSize(350, 250); // size of frame window
        Applet shapeRectangle = new exp6_applets();
        DrawingApplet.add(shapeRectangle);
        DrawingApplet.setVisible(true);
        DrawingApplet.addMouseListener(new MouseInputListener() {
            public void mouseDragged(java.awt.event.MouseEvent e) {
                DrawingApplet.setTitle("Mouse Exited");

            }

            public void mouseMoved(java.awt.event.MouseEvent e) {
                DrawingApplet.setTitle("Mouse Exited");

            }

            @Override
            public void mouseClicked(java.awt.event.MouseEvent e) {
                DrawingApplet.setTitle("MOUSE CLICKED");
                
            }

            @Override
            public void mousePressed(java.awt.event.MouseEvent e) {
                DrawingApplet.setTitle("Mouse Pressed");
                
            }

            @Override
            public void mouseReleased(java.awt.event.MouseEvent e) {
                DrawingApplet.setTitle("Mouse Released");
                
            }

            @Override
            public void mouseEntered(java.awt.event.MouseEvent e) {
                DrawingApplet.setTitle("Mouse Entered");
                
            }

            @Override
            public void mouseExited(java.awt.event.MouseEvent e) {
                DrawingApplet.setTitle("Mouse Exited");
                
            }
        });

        DrawingApplet.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0); // as soon as x is clicked it trigers an event that terminates the program.
            }

        });

    }

    public void paint(Graphics g)

    {
        // draws a Rectangle
        // Oval for face outline
        g.drawOval(80, 70, 150, 150);
        // Ovals for eyes
        // with black color filled
        g.setColor(Color.BLACK);
        g.fillOval(120, 120, 15, 15);
        g.fillOval(170, 120, 15, 15);
        // Arc for the smile
        g.drawArc(130, 180, 50, 20, 180, 180);
        g.drawString("by Shivam", 110, 100);

    }

}