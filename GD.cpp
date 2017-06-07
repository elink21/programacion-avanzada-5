#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;
const int NODOS = 6;
void printGraph(int [NODOS][NODOS]);
int isConected(int [NODOS][NODOS], int, int);
void newGraph(int [NODOS][NODOS]);


int main(int argc, char const *argv[]) {
  
  int G[NODOS][NODOS] = {
    {0,0,1,0,0,0},
    {1,0,0,1,0,1},
    {0,1,0,0,0,0},
    {0,0,0,0,0,0},
    {0,1,0,1,0,0},
    {0,0,0,0,0,0}};                   
  int option,o,d;

  while(option!=4)
  {
    cout<<"Programa para la prueba de GD, estas son las opciones:\n";
    cout<<"1.-Pedir nuevos valores (se pedira una nueva matriz)\n";
    cout<<"2.-Verificar adyacencia de nodos (se solicitara origen y destino)\n";
    cout<<"3.-Imprimir Grafo\n";
    cout<<"4.-Salir\n";
    cout<<"Inserte el numero de la opcion deseada: ";
    cin>>option;
    switch(option)
    {
      case 1:
        newGraph(G);
        break;
      case 2:
        cout<<"\nProporcione el origen (0-5) : ";
        cin>>o;
        cout<<"\nAhora proporciono el destino (0-5) :  ";
        cin>>d;
        if(isConected(G,o,d))
        {
          cout<<"\n\nEn efecto, hay conexion\n\n";
        }
        else cout<<"\n\nNo existe conexion entre los nodos\n\n";
        break;
      case 3:
        cout<<"\n\nEste es el grafo: \n\n";
        printGraph(G);
        break;
      default:
        if(option!=4)
        {
          cout<<"\n\nPor favor, inserte una opcion valida\n\n";
        }
    }

  }
  return 0;

}

void printGraph(int matrix[NODOS][NODOS]) {
  for (int i = 0; i < NODOS; i++) {
    for (int j = 0; j < NODOS; j++) {
      cout << matrix[i][j] <<"\t";
    }
    cout << "\n";
  }
}

int isConected(int matrix[NODOS][NODOS], int o, int d){
  if(o <= NODOS || o >= NODOS || d <= NODOS || d >= NODOS )
  return matrix[o][d];
}

void newGraph(int G[NODOS][NODOS])
{
  int conection;
  for(int i=0;i<NODOS;i++)
  {
    for (int j=0;j<NODOS;j++)
    {
      cout<<"\n\nHay conexion de "<<i+1<<" a "<<j+1<<"?(0,1): ";
      cin>>conection;
      G[i][j]=conection;
    }
  }
}
