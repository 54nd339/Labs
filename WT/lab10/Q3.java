import java.applet.Applet;
import java.awt.*;
public class Q3 extends Applet {
    public void init() {
        Label l = new Label("This is Label");
        add(l);
        TextField t = new TextField("This is a TextBox");
        add(t);
        TextArea area = new TextArea("This is a Text Area");
        add(area);
        Checkbox mycheckbox = new Checkbox("This is Checkbox");
        add(mycheckbox);
        CheckboxGroup cbg = new CheckboxGroup();
        Checkbox radiobutton = new Checkbox("This is Radio Button ", cbg, false);
        add(radiobutton);
        Button b = new Button("This is Button");
        add(b);
    }
}
// <applet code="Q3.class" height=300 width=500></applet>