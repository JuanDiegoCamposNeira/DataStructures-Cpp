#include <bits/stdc++.h>

using namespace std; 


void merge_both_arrays( int arreglo[], int low, int middle, int high );
void merge_sort( int arreglo[], int low, int high );
void print( int arreglo[], int size );


int main( )
{
    int arreglo[] = { 5, 2, 4, 6, 1, 3 };
    int size = sizeof(arreglo)/sizeof(arreglo[0]);

    cout << "Arreglo sin ordenar : " << endl; 
    print( arreglo, size ); 

    merge_sort( arreglo, 0, size - 1 );

    cout << "Arreglo ordenado : " << endl; 
    print( arreglo, size ); 

    return 0; 
}

void merge_sort( int arreglo[], int low, int high )
{
    if( low < high )
    {
        int middle = low + (high - low) / 2; 
        cout << "Parte izquierda\n"; 
        printf( "Lower bound[%i] Middle[%i] Upper bound[%i]\n", low, middle, high );
        //Parte izquierda
        merge_sort( arreglo, low, middle);
        //Parte derecha 
        cout << "Parte derecha\n";
        printf( "Lower bound[%i] Middle[%i] Upper bound[%i]\n", low, middle, high ); 
        merge_sort( arreglo, middle + 1, high );
        //Juntar los dos arreglos
        merge_both_arrays( arreglo, low, middle, high );
    }
}

void merge_both_arrays( int arreglo[], int low, int middle, int high )
{
    printf( "Junto los dos arreglos\n Lower bound[%i] Middle[%i] Upper bound[%i]\n", low, middle, high );
    int size_left = middle - low + 1; 
    int size_right = high - middle; 
    //Arreglos auxiliares
    int aux_left_array[ size_left ];
    int aux_right_array[ size_right ]; 

    //Llenar los arreglos auxiliares
    for( int i = 0; i < size_left; ++i )
    {
        aux_left_array[ i ] = arreglo[ low + i ];   
    }
    for( int j = 0; j < size_right; ++j )
    {
        aux_right_array[ j ] = arreglo[ middle + 1 + j ]; 
    }

    //Re ordenar el arreglo original
    int left_index, right_index, arreglo_original_index; 
    left_index = 0; 
    right_index = 0; 
    arreglo_original_index = low;  
    while( left_index < size_left && right_index < size_right )
    {
        //Compara si lo que esta en el arreglo auxiliar de la izquierda es menor a lo que está en el arreglo auxiliar de la derecha
        if( aux_left_array[ left_index ] < aux_right_array[ right_index ] )
        {
            arreglo[ arreglo_original_index ] = aux_left_array[ left_index ];
            left_index++;  
        }
        else 
        {
            arreglo[ arreglo_original_index ] = aux_right_array[ right_index ]; 
            right_index++; 
        }
        arreglo_original_index++; 
    }

    //Si sobran elementos de los arreglos auxiliares, se introducen en el arreglo
    while( left_index < size_left )
    {
        arreglo[ arreglo_original_index ] = aux_left_array[ left_index ];
        arreglo_original_index++;  
        left_index++; 
    }
    while( right_index < size_right )
    {
        arreglo[ arreglo_original_index ] = aux_right_array[ right_index ]; 
        arreglo_original_index++; 
        right_index++; 
    }

}

void print( int arreglo[], int size )
{
    for( int i = 0; i < size; ++i )
    {
        cout << arreglo[i] << " "; 
    }
    cout << endl; 
}