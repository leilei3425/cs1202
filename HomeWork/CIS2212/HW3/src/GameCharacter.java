//Lei Zhang
//Game Character
//10/06/2025



public class GameCharacter {
	private String name;
	private int health; // character health
	private int characterDamage; // character health
	private int armor; // character health
	private double attackSpeed; // character health
	private Weapon currentWeapon; // character health
	
	GameCharacter(String name, int health, int damage, int armor, double attackSpeed, Weapon currentWeapon){
		this.name=name;
		this.health=health;
		this.characterDamage=damage;
		this.armor=armor;
		this.attackSpeed=attackSpeed;
		this.currentWeapon=currentWeapon;
		
	}
	
	//resource:https://www.youtube.com/watch?v=u3BGdOunOTI
	@Override
	public String toString() {
		
		return "Character info:\n "+
				"name: "+this.name+"\n"+
				"health: "+this.health+"\n"+
				"characterDamage: "+this.characterDamage+"\n"+
				"armor: "+this.armor+"\n"+
				"attackSpeed: "+this.attackSpeed+"\n"+
				"currentWeapon: "+this.currentWeapon.getName()+"\n";
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getHealth() {
		return health;
	}

	public void setHealth(int health) {
		this.health = health;
	}

	public int getDamage() {
		return characterDamage;
	}

	public void setDamage(int damage) {
		this.characterDamage = damage;
	}

	public int getArmor() {
		return armor;
	}

	public void setArmor(int armor) {
		this.armor = armor;
	}

	public double getAttackSpeed() {
		return attackSpeed;
	}

	public void setAttackSpeed(double attackSpeed) {
		this.attackSpeed = attackSpeed;
	}

	public Weapon getCurrentWeapon() {
		return currentWeapon;
	}

	public void setCurrentWeapon(Weapon currentWeapon) {
		this.currentWeapon = currentWeapon;
	}
	
	public int attack() {
		// check if the character is dead
		if (this.health==0) {
			return 0;
		}
		// check if the character is alive
		int weaponDamage = this.currentWeapon.getDamage();
		int totalDamage = weaponDamage + this.characterDamage;	
		double finalDamage = totalDamage*this.attackSpeed;
		return (int)finalDamage;
	}
	
	public void defend(int damage) {
		int takenDamage = damage - this.armor;
		// taken damage cannot be negative
		if (takenDamage<0) {
			takenDamage = 0;
		}
		this.health = this.health - takenDamage;
		// health cannot be negative
		if (this.health<0) {
			this.health = 0;
		}
	}

}
