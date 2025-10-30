//Lei Zhang
//Game Character
//10/06/2025

import java.util.Random;

public class Weapon {
	String name;
	int lowestDamage;
	int highestDamage;
	
	Weapon(){
		this.name="sword";
		this.lowestDamage=12;
		this.highestDamage=26;
	}
	
	Weapon(String name){
		this.name=name;
		if (name.equals("sword")) {
			this.lowestDamage=12;
			this.highestDamage=26;
		}
		else if (name.equals("axe")) {
			this.lowestDamage=5;
			this.highestDamage=35;
		}
		else if (name.equals("bow")) {
			this.lowestDamage=0;
			this.highestDamage=50;
		}
		else {
			// error
		}
	}
	
	public int getDamage() {
		int damage=0;
		Random random=new Random();
		damage= random.nextInt(this.lowestDamage, this.highestDamage+1);
		return damage;
		
	}
	
	public String getName() {
			
		return this.name;
	}

}
