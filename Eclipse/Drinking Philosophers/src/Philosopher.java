import java.util.ArrayList;
import java.util.Random;

public class Philosopher extends Thread 
{
	int ITERATION = 0;
	int ID;
	int STATUS;
	int TRANQUIL = 0;
	int THIRSTY = 1;
	int DRINKING = 2;
	int NEED = 1;
	int HAVE = 0;
	long Tsede = 0;
	long Ttranquilo = 0;
	long Tbebendo = 0;
	ArrayList<Bottle> BOTTLES = new ArrayList<Bottle>();
	Random Generator = new Random();
		
	Philosopher(int a)
	{
		ID = a;
		STATUS = TRANQUIL;
	}

	void Insert_Bottles(Bottle bottle) 
	{
		BOTTLES.add(bottle);
	}
	
	public synchronized void run()
	{
		System.out.println("F[" + ID + "] -> INIT.");
		for(ITERATION = 0; ITERATION < 5; ITERATION++)
		{
			System.out.println("F[" + ID + "] -> T");
			Tranquil_to_Thirsty();
			System.out.println("F[" + ID + "] -> S");
			Thirsty_to_Drinking();
			System.out.println("F[" + ID + "] -> B");
			Drinking_to_Tranquil();
		}
		System.out.println("###########################\n"
				         + "F[" + ID + "]\n"
				         + "Tranquilo por: " + Ttranquilo + "\n"
				         + "Com sede por: " + Tsede + "\n"
				         + "Bebendo por: " + Tbebendo + "\n"
				         + "###########################");
	}

	void NowWait()
	{
		try 
		{
			this.wait(1000);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}
	}
	
	private synchronized void Drinking_to_Tranquil()
	{
 		long aux = System.currentTimeMillis();
		NowWait();
		for(int i = 0; i < BOTTLES.size(); i++)
		{
			if(BOTTLES.get(i).Actual_Owner != null)
				if(this.ID == BOTTLES.get(i).Actual_Owner.ID)
					BOTTLES.get(i).ReleaseBottle();
		}
		HAVE = 0;
		STATUS = TRANQUIL;
		Tbebendo+=(System.currentTimeMillis()-aux);
	}

	private synchronized void Thirsty_to_Drinking() 
	{
		long aux = System.currentTimeMillis();
		for(int i = 0; i <= BOTTLES.size(); i++)
		{
			if(HAVE == NEED)
			{
				STATUS = DRINKING;
				break;
			}
			if(i == BOTTLES.size())
			{
				i = -1;
				NowWait();
			}
			else
				BOTTLES.get(i).CatchBottle(this);
		}
		Tsede = Tsede-aux+System.currentTimeMillis();
	}

	private synchronized void Tranquil_to_Thirsty() 
	{
 		long aux = System.currentTimeMillis();
		NowWait();
		STATUS = THIRSTY;
		NEED = Generator.nextInt(BOTTLES.size()) + 1;
		Ttranquilo = Ttranquilo-aux+System.currentTimeMillis();
	}
	
	synchronized void PrintPinga()
	{
		System.out.print("F[" + ID + "] -> G[");
		for(int i = 0; i < BOTTLES.size(); i++)
			System.out.print( BOTTLES.get(i).ID + " ");
		System.out.println("]");
	}
}
