/*--------------------------------------------------------------------------------------
--------------------------------------  HEAP SORT  -------------------------------------
---------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

//-----------------------------  Funciones  -----------------------------
void imprimir_arreglo(vector<int> &arreglo)
{
    for (int i : arreglo)
        cout << i << " ";
    cout << endl;
}
void heap_sort(vector<int> &arreglo, int limite_superior);
void build_max_heap(vector<int> &arreglo, int limite_superior);
void max_heapify(vector<int> &arreglo, int indice, int limite_superior);

int main()
{
    /*                                  HEAP SORT
     Comentarios: Es un método de ordenamiento bastante interesante, ya que introduce temas de 
                  arboles y ve al arreglo como un Arbol binario casi completo. 

     Heaps: Un heap es una estructura de datos que se divide en dos definiciones: 
            -Max-heap: Se dice que es un max-heap si la 'raiz' o el valor 'key' es estrictamente MAYOR a sus hijos.
            -Min-heap: Se dice que es un min-heap si la 'raiz' o el valor 'key' es estrictamente MENOR a sus hijos.
     
     Algoritmo: lo que hace el algoritmo es visualizar al arreglo que se va a ordenar como un 'NEARLY COMPLETED BINARY TREE'
                que en otras palabras, se pude ver como un heap (Todo arreglo se puede visualizar como un Heap), pero la gracia
                de verlo de esta manera es construir un max-heap para ordenarlo.

                -Arbol : i       ->  raiz del sub-arbol.
                         2i      ->  hijo derecho del sub-arbol 
                         2i + 1  ->  hijo izquierdo del sub-arbol

                -Ej: 
                [3, 2, 7, 4, 8, 5, 9, 1, 6, 10, 13, 15, 12, 11, 14]  =>                   3                        -> Raiz
                                                                                      /        \                   
                                                                                    2             7                -> Nivel 1
                                                                                 /    \        /    \ 
                                                                                4      8      5      9             -> Nivel 2
                                                                               / \    / \    / \    / \
                                                                              1   6  10 13  15 12  11 14           -> Nivel 3 
                                                                                                                      ...
                                                                                                                   -> Nivel n
                _____________________________________________________________________________________________________________________________
                | La idea entonces es ir buscando desde el nivel justamente anterior a las hojas e ir creando el arbol para que              |
                | se cumpla la condición de max-heap, (de abajo hacia arriba), sin embargo, cuando se llaegan a niveles superiores,          |
                | se tiene que volver a verificar que los sub-arboles cumplan dicha condición, solamente si se realizó algún intercambio,    |
                | de lo contrario, si no hubo un intercambio, se garantiza que los sub-arboles de niveles inferiores satisfcen la            |
                | condición.                                                                                                                 |
                |____________________________________________________________________________________________________________________________|
    */

    //Arreglo que se ordenará
    vector<int> arreglo = {3, 2, 7, 4, 8, 5, 9, 1, 6, 10, 13, 15, 12, 11, 14, 14, 3, 2, 7};

    //Imprimir el arreglo desordenado
    imprimir_arreglo(arreglo);

    //HEAP SORT
    int limite_superior = arreglo.size();
    heap_sort(arreglo, limite_superior);

    //Imprimir el arreglo ordenado con heap sort
    imprimir_arreglo(arreglo);

    //Fin del programa
    return (0);
}

void heap_sort(vector<int> &arreglo, int limite_superior)
{
    //Build the max-heap
    build_max_heap(arreglo, limite_superior); //Every sub-tree have the max-heap condition
    //Repeat the procedure untill 'upper_bound' is cero
    while (limite_superior > 0)
    {
        swap(arreglo[0], arreglo[--limite_superior]);
        //Como se intercambia el mayor con el menor, ahora se tiene que colocar al menor en el lugar
        max_heapify(arreglo, 0, limite_superior);
    }
}

//This function ensures to convert the array into a max-heap, but the sub-trees could violate the condition
void build_max_heap(vector<int> &arreglo, int limite_superior)
{
    int tamano = (limite_superior / 2) - 1;
    for (int i = tamano; i >= 0; --i)
    {
        max_heapify(arreglo, i, limite_superior);
    }
}

void max_heapify(vector<int> &arreglo, int indice, int limite_superior)
{
    int raiz = indice;
    int hijo_izquierdo = 2 * indice + 1;
    int hijo_derecho = 2 * indice + 2;
    //Si el hijo izquierdo es mayor, se cambia con la raiz
    if (arreglo[raiz] < arreglo[hijo_izquierdo] && hijo_izquierdo < limite_superior)
        raiz = hijo_izquierdo;
    //Si el hijo derecho es mayor, se cambia con la raiz
    if (arreglo[raiz] < arreglo[hijo_derecho] && hijo_derecho < limite_superior)
        raiz = hijo_derecho;
    //Si la raiz cambío, se busca recursivamente el lugar que le pertenece
    //Esta condición, lo que hace es buscar la posición hacia abajo, mientras que max_heapify busca la posición hacia arriba
    if (indice != raiz)
    {
        swap(arreglo[raiz], arreglo[indice]);
        max_heapify(arreglo, raiz, limite_superior);
    }
}