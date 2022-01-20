import java.awt.*;  
import java.awt.event.*;  
public class actionlistener {  
public static void main(String[] args) {  
    Frame f=new Frame("ActionListener Example");  
    f.setTitle("Give Input");
    final TextField tf=new TextField();  
    tf.setBounds(50,50, 200,20);  
    Button b=new Button("Click Here");  
    b.setBounds(50,100,60,30);  
  
    b.addActionListener(new ActionListener(){  
    public void actionPerformed(ActionEvent e){  
            tf.setText("Your Input has been recorded");  
    }  
    });
    f.addWindowListener(new WindowAdapter() {
        public void windowClosing(WindowEvent e) {
            System.exit(0); // as soon as x is clicked it trigers an event that terminates the program.
        }

    });  
    f.add(b);f.add(tf);  
    f.setSize(400,400);  
    f.setLayout(null);  
    f.setVisible(true);   
}  
}  