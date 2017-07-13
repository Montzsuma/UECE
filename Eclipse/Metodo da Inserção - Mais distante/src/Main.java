import java.io.*;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(System.in);
		System.out.println("Digite o nome do Arquivo(com a extensão):");
		String arquivo = s.next();
		File f = new File("BD/"+arquivo);
		long tempoinicial = System.currentTimeMillis();
		insert ins = new insert(f);
		System.out.println("A matriz é:\n" + ins.getmatriz());
		System.out.println("Os critérios são:\n" + ins.getcriterio());
		System.out.println("O ciclo inicial é: " + ins.getciclo_final());
		ins.apresentar();
		System.out.println("\n\n");
		System.out.println("O Ciclo Final é: " + ins.getciclo_final());
		System.out.println("O custo total é: "+ ins.getcusto_total());
		long fim = (System.currentTimeMillis() - tempoinicial);
		System.out.println("O tempo de Execução foi: "+ fim + " Milisegundos");
		s.close();

	}

}
