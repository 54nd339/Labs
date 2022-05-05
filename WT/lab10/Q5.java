import java.applet.Applet;
import java.awt.*;
public class Q5 extends Applet {
    public void paint(Graphics g) {
        g.drawRect(100, 10, 100, 30);
        g.setColor(Color.orange);
        g.fillRect(100, 50, 100, 50);
        g.setColor(Color.blue);
        g.fillRect(120, 60, 60, 30);
        g.setColor(Color.green);
        g.fillRect(140, 70, 20, 10);
        g.setColor(Color.yellow);
        g.drawRoundRect(100, 110, 100, 50, 15, 15);
        g.setColor(Color.red);
        g.fill3DRect(100, 170, 100, 50, true);
    }
}
// <applet code="Q5.class" height=230 width=300></applet>