
public class Bottle 
{
	int ID;
	int TRANQUIL = 0;
	int  THIRSTY = 1;
	int DRINKING = 2;
	
	Philosopher Actual_Owner;
	Philosopher Nullifier = new Philosopher(-1);

	Bottle(Philosopher c, int i)
	{
		Actual_Owner = c;
		ID = i;
	}
	
	public synchronized void CatchBottle(Philosopher P)
	{
		if(Actual_Owner == Nullifier || Actual_Owner == null)
		{
			Actual_Owner = P;
			P.HAVE++;
			System.out.println("F[" + P.ID + "] <- G[" + ID + "]");
            System.out.println("F[" + P.ID + "] -> " + P.HAVE + "/" + P.NEED);
		}
		else
		{
			if(Actual_Owner.ID != P.ID && Actual_Owner.STATUS != DRINKING && (Actual_Owner.STATUS == TRANQUIL || Actual_Owner.ITERATION > P.ITERATION))
			{
				Actual_Owner.HAVE--;
				P.HAVE++;
				System.out.println("F[" + P.ID + "] <- G[" + ID + "] <- F[" + Actual_Owner.ID + "]");
				Actual_Owner = P;
				System.out.println("F[" + P.ID + "] -> " + P.HAVE + "/" + P.NEED);
			}
	 	}
	}

	public void ReleaseBottle() 
	{
		Actual_Owner = Nullifier;
	}
}
