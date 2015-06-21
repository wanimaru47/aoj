import java.util.Scanner;

class AOJ10004 {
	public static void main(String[] args) {
		int max = 0, middle = 0, min = 0, tmp;
		Scanner scan = new Scanner(System.in);
		max = scan.nextInt();
		middle = scan.nextInt();
		min = scan.nextInt();
		if (max < middle) {
			tmp = max;
			max = middle;
			middle = tmp;
		}
		if (max < min) {
			tmp = max;
			max = min;
			min = tmp;
		}
		if (middle < min) {
			tmp = middle;
			middle = min;
			min = tmp;
		}
		
		System.out.println(min + " " + middle + " " + max);
	}
}