//Lei Zhang
//Ninety-Nine Project


//TODO: Complete the Card class according to the specifications.
public class Card{
	private final int SUITS = 4;
    private final int RANKS = 13;
	private final String[] SUITSName= {"Diamonds", "Clubs", "Hearts" ,"Spades"};
	private final String[] RANKSName= {"Ace", "Two", "Three" ,"Four", "Five", "Six", "Seven" ,"Eight", "Nine", "Ten", "Jack" ,"Queen", "King"};
	int cardNum;
	String cardName;
	
	
	Card(int cardNum) {
		this.cardNum=cardNum;
		this.cardName=toString();
	
	}
		
	
	public String getSUITSName() {
		if(cardNum<=13) {
			return SUITSName[0];
		}
		else
			return SUITSName[cardNum/RANKS];
	}
	
	public String getRANKSName() {
		if(cardNum==0) {
			return "Ace";
		}
		else
			return RANKSName[cardNum%RANKS];
	}
	
	public String toString() {
		return getRANKSName()+" of "+getSUITSName();
	}
	
}