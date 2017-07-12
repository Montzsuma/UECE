import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Hello.hello();
        Scanner n = new Scanner(System.in);
        int a = n.nextInt();
        System.out.println(a*2);
        n.close();
    }
}
