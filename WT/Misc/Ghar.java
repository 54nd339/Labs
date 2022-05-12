import java.applet.Applet;
import java.awt.*;
public class Ghar extends Applet {
    public void paint(Graphics g) {
        //roof
        g.setColor(Color.red);
        int x[] = {50, 150, 250, 50};
        int y[] = {100, 50, 100, 100};
        g.fillPolygon(x, y, 4);
        //house
        g.setColor(Color.green);
        g.fillRect(50, 100, 200, 100);
        //door
        g.setColor(Color.blue);
        g.fillRect(125, 150, 50, 50);
        //window
        g.setColor(Color.white);
        g.fillRect(75, 125, 25, 25);
        g.fillRect(200, 125, 25, 25);
    }
}
// <applet code="Q2.class" height=300 width=300></applet>