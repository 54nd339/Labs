import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
public class Q4 extends Applet implements ActionListener {
    TextField in, out;
    public void init() {
        Label inp = new Label("Enter Number :", Label.RIGHT);
        Label opt = new Label("Result : ", Label.RIGHT);
        in = new TextField(5);
        out = new TextField(10);
        Button test = new Button("Test");
        Button reset = new Button("Reset");
        add(inp);
        add(in);
        add(opt);
        add(out);
        add(test);
        add(reset);
        
        out.setEditable(false);
        in.addActionListener(this);
        out.addActionListener(this);
        test.addActionListener(this);
        reset.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae) {
        String str = ae.getActionCommand();
        if (str.equals("Test")) {
            if (in.getText() != null && !in.getText().isEmpty()) {
                int n = Integer.parseInt(in.getText());
                if (n % 2 == 0)
                    out.setText("Even");
                else
                    out.setText("Odd");
            } else
                out.setText("Blank");
        }
        if (str.equals("Reset")) {
            in.setText("");
            out.setText("Blank");
        }
        repaint();
    }
}
// <applet code="Q4.class" height=60 width=350></applet>