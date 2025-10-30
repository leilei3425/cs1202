//Lei Zhang
//Calorie Burn
//09/09/2025

import java.util.Scanner;

public class main {
	
	private static final double age_weights = 3.14;

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		


Scanner scanner= new Scanner(System.in);

		
		
		System.out.println("Enter your name: ");
		String name= scanner.nextLine();
		
		System.out.println("Enter your age: ");
		int age= scanner.nextInt();
		
		System.out.println("Enter your weight: ");
		double weight=scanner.nextDouble();
		
		System.out.println("Enter your heartrate: ");
		int heartrate=scanner.nextInt();
		
		System.out.println("Enter your time(minutes): ");
		int time=scanner.nextInt();
		
		double calories=(age*0.2757+weight*0.03295+heartrate*1.0781-75.4991)*time/8.368;
		
		
		System.out.println(name+" has burnt "+calories+" calories!");
		
scanner.close();
		
	}

}
