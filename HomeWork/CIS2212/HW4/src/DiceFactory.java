//Lei Zhang
//Dice Roller
//10/15/2025

import java.util.Random;


public class DiceFactory {

	// Declare instance variables to store the rolls, sides, and number of dice from
	// the last simulation.
	// We need some of this info for the getResults method and might need all of it
	// for future methods.
    private int myNumberOfRolls, myNumberOfDice, myNumberOfSides;
    
    //TODO: Declare an appropriate collection variable to store the totals.
    private int[] mySumRolls;// index is the sum of dice, value is the frequency
    

	/**
	 * The rollDice method simulates rolling numberOfDice with numberOfSides the numberOfRolls times.
	 * The method doesn't return anything.
	 * @param int numberOfRolls - the number of times the dice are to be rolled.
	 * @param int numberOfSides - the number of sides for each die.
	 * @param int numberOfDice - the number of dice to be rolled.
	 */

	//TODO: Write the rollDice method as described in the above comment. Save the results in the array declared above.
    //			Call getResults at the end and return the results.

    public void rollDice(int myNumberOfRolls, int myNumberOfDice, int myNumberOfSides) {
    	int sum;
    	int result;
    	
    	this.myNumberOfRolls = myNumberOfRolls;
    	this.myNumberOfDice = myNumberOfDice;
    	this.myNumberOfSides = myNumberOfSides;
    	
    	mySumRolls = new int[this.myNumberOfSides*this.myNumberOfDice-this.myNumberOfDice+1];
    	
    	Random random=new Random();
    	
    	for (int i=0;i<this.myNumberOfRolls;i++) {
    		sum = 0;
    		for (int j=0;j<this.myNumberOfDice;j++) {
    			// roll once
    			result = random.nextInt(1,this.myNumberOfSides+1);
    			
    			sum+=result;
    		}
    		//System.out.println("roll result:" + sum); for testing
    		mySumRolls[sum-this.myNumberOfDice]+=1;
    	}
    }
    
	/**
	 * The getResults method builds a String showing the results of the last simulation.
	 * @return - the String containing the results of the simulation.
	 */

	//TODO: Write the getResults method as described in the above comment.
	//      The method does not need parameters.
	//      If the array is null, which means getResults was called before rollDice, then return an error message.
    public String getResults(){

    	String res="";
    	for(int i=this.myNumberOfDice;i<this.myNumberOfSides*this.myNumberOfDice+1;i++) {
    		res += String.format("%6d)%7d%n", i, mySumRolls[i - this.myNumberOfDice]);
    	    
    	}
		return res;
		
    }

	
	/**
	 * Return an int array with the results of the last simulation.
	 * @return int array with the results of the last simulation.
	 */
	
	// TODO: If the results array is null, then return null.  Otherwise, return a clone of the results array.
    public int[] results() {
    	if(mySumRolls==null) {
    		return null;
    	}
    	else {
    		return mySumRolls.clone();//Resource: https://www.youtube.com/watch?v=6uemeqwFNeQ
    	}
   
    }

}

