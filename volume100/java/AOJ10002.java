import java.util.Scanner;

class AOJ10002 {
	public static void main(String[] args) {
		int num1, num2, ans1, ans2;
		Scanner scan = new Scanner(System.in);
		num1 = scan.nextInt();
		num2 = scan.nextInt();
		ans1 = num1 * num2;
		ans2 = (num1 + num2) * 2;
		System.out.println(ans1 + " " + ans2);
	}
}