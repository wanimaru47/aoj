import java.util.Scanner;

class AOJ10006 {
	public static void main(String[] args) {
		int tmp, i = 1;
		Scanner scan = new Scanner(System.in);
		while (i > 0) {
			tmp = scan.nextInt();
			if (tmp == 0) break;
			System.out.println("Case " + i + ": " + tmp);
			i++;
		}
	}
}