//Lei Zhang
//Ninety-Nine Project


//TODO: Complete the Player class according to the specifications.
import java.util.ArrayList;

public class Player {
	private String name;
	private ArrayList<Card> hand;
	
	Player(String name) {
		this.name=name;
		this.hand=new ArrayList<>();
	}
	
	public String getName() {
		return this.name;
	}
	
	
	
	public Card getCard(int index) {
		return hand.get(index);
	}
	
	public Card playCard(int index) {
		return hand.remove(index-1);
	}
	
	public void addCard(Card card) {
		this.hand.add(card);
	}
	
}
