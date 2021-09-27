#include <bits/stdc++.h>

using namespace std; 

int busqueda_binaria_recursiva( vector<int> num, int parte_izquierda, int parte_derecha, int numero );

int main( )
{
    vector<int> numeros = { 1, 2, 3, 4, 5, 6, 9 };
    //Imprimo los numeros del vector
    for( int i : numeros ) cout << i << " "; 
    cout << endl ; 

    int posicion;  
    //En el siguiente ejemplo, quiero intentar buscar el número 5
    posicion = busqueda_binaria_recursiva( numeros, 5, 0, numeros.size() - 1 );
    if( posicion != -1 ) printf( "Número encontrado en la posicion [%i]\n", posicion ); 
    else printf( "Número, no encontrado\n" );

    //En el siguiente ejemplo, quiero intentar buscar el número 13
    posicion = busqueda_binaria_recursiva( numeros, 13, 0, numeros.size() - 1 );
    if( posicion != -1 ) printf( "Número encontrado en la posicion [%i]\n", posicion ); 
    else printf( "Número, no encontrado\n" );

    return( 0 );
}

/*
Parametros: 
    - numero : El numero que se pretende buscar
    - i_izq : El 'lower bound'
    - i_der : El 'upper bound'
    - arreglo : Se refiere al arreglo que está ordenado

NOTA : En este caso, el pivote es la mitad del arreglo             */
int busqueda_binaria_recursiva( vector<int> arreglo, int numero, int i_izq, int i_der )
{
    /*Caso 0: Si el número no se encuentra.
              -> Esto se puede saber si el indice izquierdo, sobre pasa al indice derecho
                 o si el indice derecho sobre pasa el indice izquierdo.
              -> Si los indices NO FUNCIONAN (Se sobrepasan unos de los otros) no se debería
                 dejar calcula la mitad, dado que se estarian restando en lugar de sumar y 
                 el indice puede dar negativo o se puede estar dividiendo a cero, lo cual
                 no se pude.                                                                    */
    if( i_der < i_izq || i_izq > i_der ) return -1; 
    //Si los indices no se solapan, se calcula la mitad con la formula
    int mitad = i_izq - (i_der - i_izq) / 2;
    /*Caso base: Si el número que debo encontrar, se encuentra en la mitad del arreglo,
                 retorno la posición, en este caso, sería la mitad */
    if( arreglo[ mitad ] == numero ) return mitad; 
    /*Caso 1: Si el número a encontrar es mayor que el contenido de la mitad del arreglo.
              -> En este caso, se pretende buscar desde la mitad + 1, hasta el 'upper bound',
                 el cual, en este caso, sería el indice derecho. */
    else if( numero > arreglo[ mitad ] ) return busqueda_binaria_recursiva( arreglo, numero, mitad + 1, i_der );
    /*Caso 2: Si el número a encontrar es menor que el contenido de la mitad del arreglo.
              -> En este caso, se pretende buscar desde el 'lower bound', el cual en este 
                 caso, sería el indice izquierdo, hasta la mitad - 1.  */
    else if( numero < arreglo[ mitad ] ) return busqueda_binaria_recursiva( arreglo, numero, i_izq, mitad - 1 );
} 
