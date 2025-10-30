//Lei Zhang
//CFA Pay
//09/18/2025

import java.util.Scanner;




public class CFApay {
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scanner=new Scanner(System.in);
		
		//~~~~~~~~~~~~~User input
		String firstName;
		String lastName;
		int pay=0;
		int remain=0;
		
		int tenThousand=0;
		int fiveThousand=0;
		int oneThousand=0;
		int fiveHundred=0;
		int oneHundred=0;
		int fifty=0;
		int twentyFive=0;
		int ten=0;
		int five=0;
	
		System.out.print("Enter your FirstName:");
		firstName=scanner.next();
		System.out.print("Enter your LastName: ");
		lastName=scanner.next();
		System.out.print("Enter your pay(Less than 100,000CFA):");
		pay=scanner.nextInt();
		
		//~~~~~~~~~~~~~~Calculation
		tenThousand=pay/10000;
		remain=pay%10000;
		
		fiveThousand=remain/5000;
		remain%=5000;
		
		oneThousand=remain/1000;
		remain%=1000;
		
		fiveHundred=remain/500;
		remain%=500;
		
		oneHundred=remain/100;
		remain%=100;
		
		fifty=remain/50;
		remain%=50;
		
		twentyFive=remain/25;
		remain%=25;
		
		ten=remain/10;
		remain%=10;
		
		five=remain/5;
		remain%=5;
		
		
		//~~~~~~~~~~~~~~~~~Output
		System.out.printf("%-15s %-5s %-3s %3s %3s %3s %3s %3s %3s %3s %3s%n",
		        "Name","Pay","10k","5k","1k","500","100","50","25","10","5");
		System.out.println("=============== ===== === === === === === === === === ===");

		String fullName = lastName + ", " + firstName;
		fullName = fullName.substring(0, Math.min(15, fullName.length()));

		System.out.printf("%-15s %-5d %3d %3d %3d %3d %3d %3d %3d %3d %3d%n",
		        fullName, pay, tenThousand, fiveThousand, oneThousand,
		        fiveHundred, oneHundred, fifty, twentyFive, ten, five);

		
		scanner.close();
		

	}
	
	


}
