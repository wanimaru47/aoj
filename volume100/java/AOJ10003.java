import java.util.Scanner;

class AOJ10003 {
	public static void main(String[] args) {
		int num1, num2;
		Scanner scan = new Scanner(System.in);
		num1 = scan.nextInt();
		num2 = scan.nextInt();
		if (num1 > num2) {
			System.out.println("a > b");
		}else if (num1 == num2) {
			System.out.println("a == b");
		}else {
			System.out.println("a < b");
		}
	}
}