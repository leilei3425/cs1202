//Lei Zhang
//Game Character
//10/06/2025


import java.util.Random;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Weapon axe = new Weapon("axe");
		Weapon sword = new Weapon("sword");
		Weapon bow = new Weapon("bow");
		Random random=new Random();
				
		GameCharacter boss1 = new GameCharacter("Hero", 300, 15, 5, 1, bow);
		GameCharacter boss2 = new GameCharacter("Bad guy", 270, 10, 7, 1.2, sword);
		
		boss1.setName("Boss1");
		boss2.setName("Boss2");
		
		boss1.setHealth((int) (boss1.getHealth()*0.9));
		boss1.setDamage((int) (boss1.getDamage()*0.8));
		boss1.setArmor((int) (boss1.getArmor()*1.2));
		boss1.setAttackSpeed((int) (boss1.getAttackSpeed()*1.1));
		boss1.setCurrentWeapon(axe);
		
		
		
		
		int fighting_round = 0;
		while(boss1.getHealth()>0 && boss2.getHealth()>0) {
			
			// randomly decide who attack first
			if (random.nextInt(0,100)%2==0) {
				boss2.defend(boss1.attack());
				boss1.defend(boss2.attack());
			}
			else {
				boss1.defend(boss2.attack());
				boss2.defend(boss1.attack());
			}
			
			
			fighting_round+=1;
		}
		

		
		if (boss2.getHealth()!=0) {
			System.out.println("After "+fighting_round+" rounds of fighting, the Winner is "+boss2.getName()+"!!!");
			System.out.println("He is using "+boss2.getCurrentWeapon().getName()+"!!!");
			System.out.println(boss2.toString());
			
		}
		
		if (boss1.getHealth()!=0) {
			System.out.println("After "+fighting_round+" rounds of fighting, the Winner is "+boss1.getName()+"!!!");
			System.out.println("He is using "+boss1.getCurrentWeapon().getName()+"!!!");
			System.out.println(boss1.toString());
			
		}
		
		
	}
}
