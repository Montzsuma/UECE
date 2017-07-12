import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main 
{
	public static void main(String[] args) 
	{		
		Scanner reader = new Scanner(System.in);
		int Philosophers = 0;
		Philosophers = reader.nextInt();
		int G[][] = new int [Philosophers][Philosophers];
		int Bottles = 0;
		for(int i = 0; i < Philosophers; i++)
			for(int j = 0; j < Philosophers; j++)
			{
				G[i][j] = reader.nextInt();
				if(G[i][j] != 0)
					Bottles++;
			}
		Bottles/=2;
		Philosopher[] Thinkers = new Philosopher[Philosophers];
		for(int i = 0; i < Thinkers.length; i++)
			Thinkers[i] = new Philosopher(i);
		List<Bottle> B = new ArrayList<Bottle>();
		for(int i = 0; i < Bottles; i++)
			B.add( new Bottle(null, i));
		Bottles = 0;
		for(int i = 0; i < Philosophers; i++)
			for(int j = i+1; j < Philosophers; j++)
				if(G[i][j] == 1)
				{
					Thinkers[i].Insert_Bottles(B.get(Bottles));
					Thinkers[j].Insert_Bottles(B.get(Bottles));
					Bottles++;
				}
		reader.close();
		for(int i = 0; i < Philosophers; i++)
			Thinkers[i].PrintPinga();
		for(int i = 0; i < Philosophers; i++)
			Thinkers[i].start();
	}
}
