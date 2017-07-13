import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class insert {
	private int[][] matriz; // ArrayList de Array
	private int[] ciclo_final; 
	private List<Integer> vertices_faltando;
	private int custo_total = 0;
	private int[][] criterio; // O maior custo partindo de I até qualquer J.
	private int tam = 0; // qtd de vertices
	
	public insert(File f) throws IOException {
		BufferedReader fr = new BufferedReader(new FileReader(f));
		String [] ns = fr.readLine().split("\t");
		String [] ns2 = ns[0].split("=");
		String [] tp = ns[1].split("=");
		tam = Integer.parseInt(ns2[1]);
		int tipo = Integer.parseInt(tp[1]);
		System.out.println("tamanho: "+tam + "Tipo: "+tipo);
		int i = 0;
		inicializar_matriz(); // Inicializa todos as Arrays
		
		if(tipo == 2){
			Double [][] coordenadas = new Double [tam][2];
			while(fr.ready()){
				String linha = fr.readLine();
				String [] s = linha.split("\t");
				coordenadas[i][0] = Double.parseDouble(s[0]);
				coordenadas[i][1] = Double.parseDouble(s[1]);
				i++;
			}
			for(int z = 0; z<tam;z++){
				for(int x = 0; x<tam;x++){
					double xs = Math.pow(coordenadas[z][0] - coordenadas[x][0], 2);
					double ys = Math.pow(coordenadas[z][1] - coordenadas[x][1], 2);
					double custo = Math.sqrt(xs + ys);
					matriz[z][x] = (int) custo; // Se só for a parte inteira, se não fazer a declaração da matriz separada
				}
			}
		}else{
			while(fr.ready()){
				String linha = fr.readLine();
				String [] s = linha.split("\t");
				for(int k = 0;k<s.length;k++){
						matriz[i][k] = Integer.parseInt(s[k]);
				}
				i++;
			}
		}
		ciclo_inicial(); // Define o Ciclo inicial
		fr.close();
	}

	public void inicializar_matriz(){
		matriz = new int[tam][tam];
		vertices_faltando = new ArrayList<Integer>();
		criterio = new int[tam][3];
		ciclo_final = new int[tam];
		for(int i=0;i<tam;i++){
			vertices_faltando.add(i);
			ciclo_final[i]= -1;
			criterio[i][0]= i;
			criterio[i][1]= -1;
			criterio[i][2]= 0;
			for(int j=0;j<tam;j++){
				matriz[i][j] = -1; // Valor default pois não tem como existir!
			}
		}
	}

	public void ciclo_inicial(){
		/*
		Random r = new Random();
		for(int i = 0;i<3;i++){
			int valor = r.nextInt(vertices_faltando.size());
			ciclo_final[i] = vertices_faltando.get(valor);
			vertices_faltando.remove(valor);
		}
		*/
		ciclo_final[0] = 2;
		ciclo_final[1] = 9;
		ciclo_final[2] = 15;
		vertices_faltando.remove(2);
		vertices_faltando.remove(8);
		vertices_faltando.remove(13);
		criteriar(ciclo_final[0]);
		criteriar(ciclo_final[1]);
		criteriar(ciclo_final[2]);
		custo_total += matriz[ciclo_final[0]][ciclo_final[1]];
		custo_total += matriz[ciclo_final[1]][ciclo_final[2]];
		custo_total += matriz[ciclo_final[2]][ciclo_final[0]];
	}
	
	public void criteriar(int n){// n é o numero do vertice q vou criteriar
		criterio[n][1] = -1;
		for(int i = 0;i<vertices_faltando.size();i++){
			if(criterio[n][1] < matriz[n][vertices_faltando.get(i)]){
				criterio[n][1] = matriz[n][vertices_faltando.get(i)];
				criterio[n][2] = vertices_faltando.get(i);
			}
		}
	}

	public void inserir_no_ciclo(){
		int proximo = criterio[0][2]; // Vertice que vai entrar
		int auxf = 0; // Qual vertice parte
		int i = 0; // Anterior ao novo vertice
		int j = 0; // posterior ao novo vertice
		int cij= 0;
		int cik = 0;
		int ckj = 0;
		int ct = custo_total; // auxiliar de custo
		int cn = custo_total + matriz[proximo][ciclo_final[0]]; // Resultado do custo naquela posição
		for(int z = 0;z<tam;z++){ // Loop para definir quem é o próximo
			if(criterio[z][1] > criterio[auxf][1]){
				auxf = z;
				proximo = criterio[z][2];
			}
		}
		
		// Verificar se os calculos de i e j estão certos!
		
		
		for(int x=1;x<tam-1;x++){// Define a posição que o próximo vai entrar
			if(ciclo_final[x+1] != -1){
				cij = matriz[ciclo_final[x]][ciclo_final[x+1]];
				cik = matriz[ciclo_final[x]][proximo];
				ckj = matriz[proximo][ciclo_final[x+1]];
				ct = custo_total - cij + cik +ckj;
				if(ct < cn){
					cn = ct;
					i = x;
					j = x+1;
				}
			}else{
				cij = matriz[ciclo_final[x]][ciclo_final[0]];
				cik = matriz[ciclo_final[x]][proximo];
				ckj = matriz[proximo][ciclo_final[0]];
				ct = custo_total - cij + cik +ckj;
				if(ct < cn){
					cn = ct;
					i = x;
					j = x+1;
				}
				break;
			}
			
			/*			if(ciclo_final[x+1] == -1){ // Ultima posição do ciclo final, verifica se colocando no final do ciclo fica menor o custo
				int cij = matriz[ciclo_final[x]][ciclo_final[0]];
				int ckj = matriz[proximo][ciclo_final[0]];
				int cik = matriz[ciclo_final[x]][proximo];
				cn = custo_total - cij + ckj + cik;
				if(ct > cn){
					ct = cn;
					i = x;
					j = x+1;
				}
				break;
			}else{
				int cij = matriz[ciclo_final[x]][ciclo_final[x+1]];
				int ckj = matriz[proximo][ciclo_final[x+1]];
				int cik = matriz[ciclo_final[x]][proximo];
				cn = custo_total - cij + ckj + cik;
				if(ct > cn){
					ct = cn;
					i = x;
					j = x+1;
				}
			}
*/
		}
		System.out.print("Tamanho dos vertices:\n antes: "+ vertices_faltando.size());	
		custo_total = cn;
		for(int p = 0 ; p < vertices_faltando.size();p++){
			if(vertices_faltando.get(p) == proximo){
				vertices_faltando.remove(p);
				break;
			}
		}
		int[] aux = new int[tam];
		int m = 0;
		for(int y = 0; y< tam; y++){ // Realiza a troca de posição
			if(y != j){
					aux[y] = ciclo_final[m];
			}else{
				aux[y] = proximo;
				if(y+1 < tam){
					aux[y+1] = ciclo_final[m];
					y++;
				}
			}
			m++;
		}
		for(int l = 0; l<tam;l++){
			criteriar(l);
		}
		System.out.println("\t depois: "+ vertices_faltando.size());
		ciclo_final = aux;
	//	criteriar(proximo);
		System.out.println("O próximo é: " + proximo);
		System.out.println("O auxf é: "+ auxf);
		System.out.println("O I é: "+i+"\tO J é: "+j );
		System.out.println("O Novo ciclo é: "+getciclo_final());
		System.out.println("O Novo custo é: "+custo_total);
//		criteriar(auxf);
	}
	
	public void apresentar(){
		for(int i = 0; i<tam-3;i++){
			inserir_no_ciclo();
			System.out.println("Os critérios são:\n" + getcriterio());
		}
	}

	public String getciclo_final(){
		String r = "";
		for(int i=0;i<tam;i++){
			r += ciclo_final[i]+ " --> ";
		}
		
		return r;
	}
	
	public String getcriterio(){
		String r = "";
		for(int i= 0; i<tam;i++){
			r += criterio[i][0] + " --> " + criterio[i][2] + " = " + criterio[i][1]+ "\n";
		}
		return r;
	}

	public String getmatriz(){
		String r = "";
		for(int l=0;l<tam;l++){
			r+="\t{"+l+"}";
		}
		r+= "\n";
		for(int i = 0;i<tam;i++){
			r += "{"+i+"}\t";
			for(int j =0; j<tam; j++){
				r += matriz[i][j] + "\t";
			}
			r += "\n";
		}
		return r;
	}

	public int getcusto_total(){
		return custo_total;
	}
	
}
