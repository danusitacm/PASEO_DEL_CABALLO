#include <iostream>
using namespace std;
#define N 8
int nose=0;
int ktmove1[]={-2,-1,1,2,2,1,-1,-2},ktmove2[]={1,2,2,1,-1,-2,-2,-1};
int validarNumero(int numero,int max, int min){
	/*Funcion que verifica si un numero valido en dos rangos
	 *Parametros:
        numero -> Numero a verificar.
        max -> cota superior que se utiliza para verificar.
        min -> cota inferior que se utiliza para verificar.
	 *Retorno:
        Numero verificado.
	 */
	while(numero<min || numero>max){
		cout << "Error introduzca un valor valido.";
		cout << " El numero debe estar entre " << min << " y " << max << " : " ;
		cin >> numero;
	}
	return numero;
}
int **crearMatriz(int n){
	//Funcion que crea la matriz.
	int **puntero_matriz;
	puntero_matriz= new int*[n];
	for(int i{};i<n;i++){
		puntero_matriz[i]= new int[n];
	}
	return puntero_matriz;
}
int **inicializarMatriz(int **puntero_matriz,int n){
	//Funcion que inicializa la matriz con valores de cero.
	for(int i{}; i<n;i++){
		for(int j{};j<n;j++){
			puntero_matriz[i][j]=0;
		}
	}
	return puntero_matriz;
}
void imprimirMatriz(int **puntero_matriz,int n){
	//Funcion que imprime la matriz.
	for(int i{}; i<n;i++){
		for(int j{};j<n;j++){
			cout << " " << puntero_matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool verificarMovimiento(int  **puntero_matriz,int fila,int columna){
	if((fila>=0 && fila<=N-1) &&  (columna >=0 && columna<=N-1) &&  puntero_matriz[fila][columna]==0){
		return true;
	}
	return false;
}
void paseoDelCaballo(int **puntero_matriz,int fila,int columna,int salto){
	int auxfila,auxcolumna;
	for(int k{};k<N;k++){
		if(nose==1){
			break;
		}
		auxfila=fila;
		auxcolumna=columna;
		if(verificarMovimiento(puntero_matriz,fila+ktmove1[k],columna+ktmove2[k])){
			auxfila +=ktmove1[k];
			auxcolumna +=ktmove2[k];
			puntero_matriz[auxfila][auxcolumna]=salto;
			if(salto==N*N){
				nose=1;
				imprimirMatriz(puntero_matriz,N);
				cout << auxfila << auxcolumna << endl;
			}else{
				paseoDelCaballo(puntero_matriz,auxfila,auxcolumna,salto+1);
				puntero_matriz[auxfila][auxcolumna]=0;
			}
		}
	}
}
int main(){
	int i{},j{};
	int **puntero_matriz{NULL};
	puntero_matriz=crearMatriz(N);
	puntero_matriz=inicializarMatriz(puntero_matriz,N);
	cout << "Introduzca la posicion inicial de fila : " ;
	cin >> i;
	i=validarNumero(i,N-1,0);
	cout << "Introduzca la posicion inicial de columna : ";
	cin >> j;
	j=validarNumero(j,N-1,0);
	cout << "Posicion inicial al comenzar " << i << "x"<< j <<endl;
	puntero_matriz[i][j]=1;
	imprimirMatriz(puntero_matriz,N);
	paseoDelCaballo(puntero_matriz,i,j,2);
	//Se libera memoria
	for(int i{0};i<N;i++){
		delete puntero_matriz[i];
	}
	delete puntero_matriz;
	return 0;
}