//Lei Zhang
//Ninety-Nine Project


import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Deck {
    // Constants for a normal deck of playing cards.
    private final int SUITS = 4;
    private final int RANKS = 13;
    private final int DECK_SIZE = SUITS * RANKS;
    private final int SHUFFLE_COUNT = 1000;

    //TODO: Declare instance variables to hold the cards and the number 
    //      of packs of cards in the deck.
    ArrayList<Card> deck;
    int numOfPacks;
   
    


    //TODO: Write a constructor that receives the number of packs of cards to put in the deck.
    //      The constructor should build the deck and then shuffle the cards.
    Deck(int numOfPacks){
    	this.deck=new ArrayList<>();
    	this.numOfPacks=numOfPacks;
    	buildDeck();
    	shuffleDeck();
    	
    }


    //TODO: Write the method that builds the deck of cards.
    //      Instantiate the ArrayList. Send the total number of cards to the constructor.
    //      Use nested loops.  The outer loop counts through the number of packs.
    //      The inner loop counts through the card numbers, from 0 to < DECK_SIZE.
    //      Add a new Card to the list using the inner loop control variable.
    private void buildDeck() {
    	for(int i=0;i<numOfPacks;i++) {
    		for(int j=0;j<DECK_SIZE;j++) {
    			Card card=new Card(j);
    			this.deck.add(card);
    		}
    		
    	} 

    }

    //TODO: Write the method that shuffles the deck
    private void shuffleDeck() {
    	Random random=new Random();
    	for(int i=deck.size()-1;i>0;i--) {
    		int j=random.nextInt(i+1);
    		Collections.swap(deck, i, j);
    	}
    		
    	
    	

    }

    //TODO: Write the methods that implement the behaviors of a deck of cards.
    public Card drawCard() {
    	if(deck.size()==0) {
    		return null;
    	}
    	else
    		return deck.remove(deck.size()-1);
    
    }
    
    
    public int remainNumOfCard() {
    	return deck.size();
    }


}
