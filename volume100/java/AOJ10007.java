import java.util.Scanner;

class AOJ10007 {
	public static void main(String[] args) {
		int num1, num2;
		Scanner scan = new Scanner(System.in);
		while (1 > 0) {
			num1 = scan.nextInt();
			num2 = scan.nextInt();
			if (num1 == 0 && num2 == 0) break;
			if (num1 > num2) {
				System.out.println(num2 + " " + num1);
			}else {
				System.out.println(num1 + " " + num2);
			}
		}
	}
}