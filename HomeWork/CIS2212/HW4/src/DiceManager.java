//Lei Zhang
//Dice Roller
//10/15/2025

import java.util.Scanner;
import java.util.Arrays;

public class DiceManager {

        // Use these values for the quick roll option.
        final int ROLLS = 1000;
        final int DICE = 2;
        final int SIDES = 6;

        //TODO: Declare variables for a DiceFactory and console input.
		private int rolls;
		private int dice;
		private int sides;
		
		Scanner scanner;
		DiceFactory DF;
        /**
         * Construct a Scanner and a new DiceFactory object.
         */
		
        public DiceManager()
        {
        	//TODO: Instantiate the DiceFactory and Scanner objects.
        	
        	scanner = new Scanner(System.in);
        	DF = new  DiceFactory();
        }

        /**
         * Launch the Dice Roller program menu.
         */
        public void go(){
            System.out.println("\nWelcome to Dice Roller.\n");
            boolean isRuning= true;

        	//TODO: Display the menu and call inputInt to get the user's menu choice.
        	
        	//TODO: Write a switch statement to process the user's menu choice.
        	//      Choice 0 (Quit) - break out of the menu loop so that the program exits.
        	//      Choice 1 (Quick roll) - call the rollDice method and send the constants declared above.
        	//      Choice 2 (Custom roll) - use inputInt to get the number of rolls, dice, and sides.
            //		Choice 3 (results array) - get the array with the results of the last simulation.
        	
        	//TODO: Do all the above until the user chooses to quit.  Use the most appropriate loop statement.
            while(isRuning) {
            	displayMenu();
            	
            	
            	int choice=inputInt(scanner, "Enter your choice(0-3): ", 0, 3);

           	    switch(choice){
           	        case 0 -> isRuning=false;
           	        case 1 -> {
           	        	DF.rollDice(ROLLS,  DICE, SIDES);
           	        	System.out.println(DF.getResults());
           	        	
           	        }
           	        case 2 -> {
           	        	rolls = inputInt(scanner, "Enter how many times will you roll:  ", 0, Integer.MAX_VALUE);
           	        	dice = inputInt(scanner, "Enter the number of Dice:  ", 0, Integer.MAX_VALUE);
           	        	sides = inputInt(scanner, "Enter the number of Sides:  ", 4, Integer.MAX_VALUE);
           	        	
           	        	DF.rollDice(rolls, dice, sides);
           	        	System.out.println(DF.getResults());
           	        }
           	        case 3 -> {

           	        	System.out.println("Results array: "+Arrays.toString(DF.results()));
           	        }
           	        default -> System.out.println("Invalid choice!");
                }
           	    System.out.println("Thank you!");
            }
            	
            
        	
         }

        /**
         * Private helper method that displays the menu.
         */
        private void displayMenu()
        {
            System.out.println("\nHere's the menu of choices -");
            System.out.println("0) Quit");
            System.out.printf("1) Quick roll with the default values (rolls = %d, dice = %d, sides = %d)\n", ROLLS, DICE, SIDES);
            System.out.println("2) Custom dice rolling (You enter the number of rolls, dice and sides.)");
            System.out.println("3) Get the array showing the results of the last simulation.");
        }

        /**
         * (Mostly) Error-proof method to get an int in a specified range from the user.
         * This method would be best as a static method in some library so that it can be used
         * in any of our programs.  That's why the first parameter is a Scanner object.
         * @param input - the Scanner object previously created for input.
         * @param prompt - the message to be displayed for the input prompt.
         * @param min - the smallest number allowed.
         * @param max - the largest number allowed.
         * @return the int entered by the user.
         */
        private int inputInt(Scanner input, String prompt, int min, int max)
        {
            int number = -1;    // -1 Just to make the compiler happy.
            boolean wrong = true;
            do
            {
                try
                {
                    System.out.print(prompt);
                    number = Integer.parseInt(input.nextLine());

                    if (number > max || number < min)
                    {
                        System.out.printf("That number is out of range [%d to %d].  Try again.\n",
                                min, max);
                    }
                    else    // good input
                    {
                        wrong = false;
                    }
                }
                catch (NumberFormatException e)
                {
                    System.out.println("Make sure you enter an integer.  Try again.");
                }
            } while (wrong);

            return number;
            
        }
    }



