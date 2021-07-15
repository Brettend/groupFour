import java.util.*;
import javax.swing.*;

public class do_whilePassword{

     public static void main(String []args){
         
          
        String pass=JOptionPane.showInputDialog("Enter password");   //asking a  user to enter password.
        do
        {
                 for(int i=0;i<2;i++)                               //giving user only 3 attemps  to enter a correct password.
                 {
                     System.out.println("Incorrect password.Please enter password:")
                 }
                 System.out.println("password incorrect on three attempt.")
             new pass =JOptionPane.showInputDialog("The password was :"+ pass".Please enter a new user password:") // letting a user to enter his/her new password.
             System.out.println("password changed")
        }while(! pass.equals("John"))                                   //conditions.
        
     }
     /*
     Validating a password.
     limiting  the length of the password  between 1 character until 20 characters.
     */
     public  static boolean valPassword(String password)
     {
         
         
         if (password.length()<20)
         {
             if(checkPass(password))   // checking if it meet all the  conditions.
             {
                 
                 return true;
             }
             else
             {
                 return false;
             }
             
             
             
         }
     }
     /*
     At least 1 num.
     Has Underscore.
     At least 1 lower Case.
      At least 1 UpperCase.
     */
     public static boolean checkPass(String password)
     {
         
         boolean hasnum=false;boolean hasUnderScore=false;boolean hasLow=false;boolean hasCap=false;char c; //initilizing all the booleans to false first.
         for(int i=0;i<password.length();i++)
         {
                 c=password.charAt(i);
                 if(Character.isDigit(c))
                 {
                     hasnum=true;
                 }
                 else if(Character.isUnderScore(c))
                 {
                     
                     hasUnderScore=true;
                 }
                 else if(Character.isUpperCase(c))
                 {
                     hasCap=true;
                 }
                 else if(Character.isLowercase(c))
                 {
                   hasLow=true;             
        
                 }
               if (hasnum && hasUnderScore && hasCap && hasLow)          //checking if it has all 4 condition.
               {
                   return true;
               }
         }
         return false;
         
     }
}
