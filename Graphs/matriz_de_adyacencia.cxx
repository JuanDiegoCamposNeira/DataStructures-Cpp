#include <bits/stdc++.h>
#define nodos 5

using namespace std; 

void imprimir_grafo( int grafo[nodos][nodos] );
void add_weight( int grafo[nodos][nodos], int source, int destiny, int peso );

int main( )
{
    /*               Ventajas
        Operaciones en O(1) -> eliminar un vertice
                            -> añadir un vertice                  
    */
    /*                Desventajas                                  
        Operaciones en O(n^2) -> anadir o eliminar un nodo
    
    */

   //Grafo de 5 nodos, no-dirigido
   int grafo[ nodos ][ nodos ];
   //Inicializo la matriz 
   for( int i = 0; i < nodos; i++ )
   {
       for( int j = 0; j < nodos; j++ )
       {
          grafo[ i ][ j ] = 0;  
       }
   }

   imprimir_grafo( grafo );
   add_weight( grafo, 1, 3, 2 );
   imprimir_grafo( grafo );

   return( 0 );
}


void imprimir_grafo( int grafo[nodos][nodos] )
{
     for( int i = 0; i < nodos; ++i )
     {
        for( int j = 0; j < nodos; ++j )
        {
            cout << grafo[ i ][ j ] << " ";
        }
        cout << endl; 
     }
    cout << "\n";
}

void add_weight( int grafo[nodos][nodos], int source, int destiny, int peso )
{
    grafo[ source - 1 ][ destiny - 1 ] = peso; 
}