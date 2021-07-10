import java.util.*;
import javax.swing.*;

public class do_whilePassword
{

    public static void main ( String [] args )
    {
        String choice = "";

        do
        {
            choice = JOptionPane.showInputDialog("Please enter in a password");

        }while(! choice.equals("John") );

    }
}