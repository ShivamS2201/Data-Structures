import java.util.*;
public class MyClass {
 public static void main(String args[]) {

 // create a hashmap and store some random strings and some random integer.
 Map<String, Integer> map = new HashMap<String,Integer>();
 map.put("Humesh ", 12);
 map.put("Ram ", 30);
 map.put("Mayank ", 110);
 map.put("Kishn ", 120);
 map.put("Modar ", 52);
 // create a vector and store the names of the map.
 Vector<String> vec = new Vector<String>();
 // create an ArrayList of the same size as of map and store the int of the map.
 int[] arr;
 arr = new int[map.size()];

 int j = 0;
 // iterating over the map and store the names in the vector and values inside the array
 Iterator <String> it = map.keySet().iterator();
 while(it.hasNext()) {
 String key=(String)it.next();
 vec.add(key);
 arr[j++] = map.get(key);
 }
 System.out.println("The HashMap is: - " +map);
 System.out.println();
 System.out.println("The vector of names will be: - "+vec);
 System.out.println();
 System.out.print("The array of values will be: - ");

 for (int i = 0; i < arr.length; i++){
 System.out.print(arr[i]+ " ");
 }


 }
}