import java.util.*;

public class StringClasses {
    public static void main(String[] args) {
        StringBuffer buffer = new StringBuffer("good");
        buffer.append(" morning");
        System.out.println("String Buffer: " + buffer);
        System.out.println("---------------------\n");
        StringBuilder builder = new StringBuilder("good");
        builder.append(" night");
        System.out.println("String Builder: " + builder);
        System.out.println("------------------------\n");
        String mydelim = ", ";
        String mystr = "Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday";
        StringTokenizer tokenizer = new StringTokenizer(mystr, mydelim);
        System.out.println("String Tokenizer: ");
        System.out.println("---------------\n");
        while (tokenizer.hasMoreTokens()) {
            System.out.println(tokenizer.nextToken());
        }
    }
}