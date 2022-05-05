import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
public class Q6 extends Applet implements ActionListener {
    TextField input1, input2, output;
    Button Add, Sub;
    public void init() {
        Label inp1 = new Label("Enter Number 1 :", Label.RIGHT);
        Label inp2 = new Label("Enter Number 2 :", Label.RIGHT);
        Label opt = new Label("Result : ", Label.RIGHT);
        input1 = new TextField(5);
        input2 = new TextField(5);
        output = new TextField(10);
        Add = new Button("ADD");
        Sub = new Button("SUB");
        add(inp1);
        add(input1);
        add(inp2);
        add(input2);
        add(Add);
        add(Sub);
        add(opt);
        add(output);
        output.setText("0");
        output.setEditable(false);
        input1.addActionListener(this);
        input2.addActionListener(this);
        output.addActionListener(this);
        Add.addActionListener(this);
        Sub.addActionListener(this);
    }

    public void actionPerformed(ActionEvent ae) {
        String str = ae.getActionCommand();
        if (str.equals("ADD")) {
            if (input1.getText() != null && !input1.getText().isEmpty()
                && input2.getText() != null && !input2.getText().isEmpty()) {
                int n1 = Integer.parseInt(input1.getText());
                int n2 = Integer.parseInt(input2.getText());
                int sum = n1 + n2;
                output.setText(String.valueOf(sum));
            } 
            else
                output.setText("0");
        }
        if (str.equals("SUB")) {
            if (input1.getText() != null && !input1.getText().isEmpty()
                && input2.getText() != null && !input2.getText().isEmpty()) {
                int n1 = Integer.parseInt(input1.getText());
                int n2 = Integer.parseInt(input2.getText());
                int diff = n1 - n2;
                output.setText(String.valueOf(diff));
            } 
            else 
                output.setText("0");
        }
        repaint();
    }
}
// <applet code="Q6.class" height=60 width=370></applet>