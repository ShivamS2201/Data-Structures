
/*
 - This is a code for a menu driven atm service which has some inbuilt exctions, like:

-> InvalidInputException: An exception of this type is thrown whenever a conditional statement doesnot get the required type of 
Input.
-> InvalidPin: An exception of this type occurs when the user enters an invalid pin.

 - A hashmap has been used to pair pins and their related users (having a Name,Account id and an amount stored in an array)
*/
import java.util.*;
import java.util.Scanner;

class Users {
    int Amt;
    String Name, AccID;

    public Users(int Amt, String Name, String AccID) {
        this.AccID = AccID;
        this.Name = Name;
        this.Amt = Amt;
    }
}

class InvalidPin extends Exception {
    // Self-defined exception 1
    public InvalidPin(String str) {
        super(str);
    }
}

class InvalidInputException extends Exception {
    // Self-defined exception 2
    public InvalidInputException(String str) {
        super(str);
        // printStackTrace();
        getMessage();
        getCause();
    }
}

class first { // Main class
    static int a[] = { 1312, 2113, 4444 }; // An actual DB might have bigger list.
    static int count = 1;
    static int size_a = a.length;

    static void menu(int pin, HashMap map, Scanner s) {
        Users U = (Users) map.get(pin);
        System.out.print(" \nWelcome to " + U.Name + "!\n");
        System.out.print("---------\n");
        System.out.print("  MENU\n");
        System.out.print("---------\n");
        System.out.print("Choose Action[1|2|3]\n");
        System.out.print("----------------------\n");
        System.out.print("1. Transaction\n");
        System.out.print("2. See Details\n");
        System.out.print("3. Exit\n");
        System.out.println("Enter The Action");
        Scanner as = new Scanner(System.in);
        char in = as.nextLine().charAt(0);
        System.out.print("-----------------\n");
        try {
            if (in == '1') {
                System.out.print("Enter Amount\n");
                int amt = as.nextInt();
                try {
                    if (amt > U.Amt) {
                        throw new InvalidInputException("Transaction Cannot be excuted,Not enough Funds.");
                    } else {
                        if ((U.Amt - amt) <= 0) {
                            throw new ArithmeticException(
                                    "Account should have amount greater than Rs.1000, Cannot execute Transaction");
                        } else {
                            U.Amt = U.Amt - amt;
                            System.out.print("Amount remaining: "+ U.Amt +"\nCollect Payement\n");
                            System.out.print("\n ------------------------------\n");
                            System.out.print("\n  Remember to take your card\n");
                            System.out.print("\nTHANKYOU FOR USING SHATECH.AI ATM service \n");
                            System.exit(0);
                        }
                    }

                } catch (Exception e) {
                    System.out.println(e);
                }
            } else {
                if (in == '2') {
                    System.out.print("Details of " + U.Name);
                    System.out.print("\nName: " + U.Name);
                    System.out.print("\nAmonut: " + U.Amt);
                    System.out.print("\nAcc. ID: " + U.AccID);
                    menu(pin, map, s);

                    // Comes out done
                } else {
                    if (in == '3') {
                        System.exit(0);
                    } else {
                        throw new InvalidInputException("Enter A valid Input");
                    }

                }
            }
        } catch (Exception e) {
            System.out.print("Invalid Input \n" + e);
            clearScreen();
            menu(pin, map, s);

        }

    }

    static void CheckPin(int pin, HashMap map, Scanner s) {
        try {
            try{
                int ret_val = listSearch(pin);
                if (ret_val == 1) {
                    menu(pin, map, s);
                } else {
                    throw new InvalidPin("Pin passed is invalid");
    
                }
            }catch(Exception e)
            {throw new InvalidPin("Pin passed is invalid");

            }

        } catch (Exception e) {
            System.out.println(e);

        } finally {
            System.out.print("\n ------------------------------\n");
            System.out.print("\n  Remember to take your card\n");
            System.out.print("\nTHANKYOU FOR USING SHATECH.AI ATM service \n");
        }
    }

    static int listSearch(int ele) {
        for (int i = 0; i <= 4; i++) {
            if (a[i] == ele) {
                return 1;
            }
        }
        return 0;
    }

    static void clearScreen() {
        for (int i = 0; i < 20; i++) {
            System.out.print("\n");
        }
    }

    static void atmCaller(HashMap map, Scanner s) {
        System.out.println("\n Welcome to ShaTech.AI ATM \n");
        System.out.print("Press P to use ");
        try {
            char ss = s.nextLine().charAt(0); // To get a single character from the input from terminal.
            if (ss == 'P' || ss == 'p') {
                try {
                    System.out.println("\n Enter Card (Press C)");
                    ss = s.nextLine().charAt(0);
                    if (ss == 'C' || ss == 'c') {
                        System.out.println("Card Inserted");
                        System.out.println("Enter The Pin");
                        int pp = s.nextInt();
                        CheckPin(pp, map, s);
                    } else {
                        throw new InvalidInputException("Card Not Inserted Try again");

                    }
                } catch (Exception e) {
                    System.out.println(e);
                }

            } else {
                throw new InvalidInputException("Wrong Input, Press P");

            }
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        System.out.print("\tATM machine ");
        Scanner s = new Scanner(System.in);
        HashMap<Integer, Users> map = new HashMap<Integer, Users>();// Hashmap is used to relate users to pins.
        Users one = new Users(1000, "Ramesh", "3391923912");
        Users two = new Users(10000, "Raphael", "213123123");
        Users three = new Users(2300, "Shizi", "832491283");
        map.put(a[0], one);
        map.put(a[1], two);
        map.put(a[2], three);
        atmCaller(map, s);
        s.close();
    }
}
