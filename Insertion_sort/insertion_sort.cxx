#include <bits/stdc++.h>

using namespace std; 

int main( )
{
    //Se define un arrglo que está en desorden, para realizar el ordenamiento
    int arreglo[ 6 ] = { 5, 2, 4, 6, 1, 3 };

    for( auto i : arreglo ) cout << i << " ";
    cout << endl; 

    /*                                       INSERTION SORT                                                    */
    int aux, it; 
    int pos_s, pos; 
    //Ciclo que recorre todas las posiciones del arreglo
    for( int pos = 1; pos < 6; pos++ ) //->El valor '6' hace referencia al tamaño del arreglo
    {
        /*Caso 1 : El número actual, es menor que el numero anterior.
                   -> En este caso, se realiza el 'swap' y se continúa 
                      hacinedolo, hasta que se encuentra la posición adecuada */
        if( arreglo[ pos ] < arreglo[ pos - 1 ] )
        {
            it = pos; 
            //Se realiza el cambio, hasta que el numero sea mayor que el número anterior
            while( it > 0 && arreglo[ it ] < arreglo[ it - 1 ] )
            {
                /*Pasos para hacer el intercambio entre la posición 
                  actual y la posición anterior*/
                aux = arreglo[ it ];
                arreglo[ it ] = arreglo[ it - 1 ];
                arreglo[ it - 1 ] = aux;
                it--;
            }
        }
        /*Caso 2 : El número actual es mayor que el anterior.
                   -> En este caso, no se hace nada porque el algoritmo
                      garantiza que tambien es mayor que todos los 
                      números anteriores.          */
        // ...
        /*Caso 3: El número actual es igual que el anterior.
                  -> En este caso, tampoco se hace nada, dado que el 
                     número tambien es mayor a todos sus antecesores.     */
        // ...
    }

    for( auto i : arreglo ) cout << i << " ";
    cout << endl; 

    return 0; 
}
