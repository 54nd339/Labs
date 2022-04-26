import java.applet.Applet;
import java.awt.*;
public class Q2 extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.yellow);
        g.fillOval(50, 50, 200, 200);
        g.setColor(Color.white);
        g.fillOval(100, 100, 25, 25);
        g.fillOval(170, 100, 25, 25);
        g.setColor(Color.black);
        g.fillOval(106, 106, 13, 13);
        g.fillOval(176, 106, 13, 13);
        g.drawArc(100, 100, 100, 100, 210, 120);
    }
}
// <applet code="Q2.class" height=300 width=300></applet>