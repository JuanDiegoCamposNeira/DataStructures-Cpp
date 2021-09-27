#include <bits/stdc++.h>

using namespace std;

void merge(int arreglo[], int i_izq, int mitad, int i_der);
void merge_sort(int arreglo[], int i_izq, int i_der);
void imprimir(int arreglo[], int tam_arreglo);

int main()
{
    //Arreglo que se ordenará
    int arreglo[10] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
    int tam_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);
    /*Explicación del 'SIZEOF' : 
        Basicamente, el sizeof( ) devuelve la cantidad de bytes que ocupa el elemento en memoria
        - bool, char, unsigned char .......................... 1 byte
        - short, unsigned short .............................. 2 bytes
        - float, int, unsigned int, long, unsigned long ...... 4 bytes
        - double, long double, long long ..................... 8 bytes   

        Por lo tanto, un arreglo va a tener (tipo_de_dato * cantidad_de_elementos) de bytes en memoria
        es por eso que se divide por la cantidad de bytes que tiene un solo elemento en la memoria.
            (tipo_de_dato * cantidad_de_elementos) / tipo_de_dato = cantidad_de_elementos
        En la fórmula anterior, se cancela tipo_de_dato y queda solamente cantidad_de_elementos, que es lo que nos interesa
         */

    /*                                         MERGE SORT                                              */
    cout << "Arreglo : ";
    imprimir(arreglo, tam_arreglo);
    merge_sort(arreglo, 0, tam_arreglo - 1);
    imprimir(arreglo, tam_arreglo);

    return 0;
}

void merge_sort(int arreglo[], int i_izq, int i_der)
{
    /*Caso 1: Entrará a realizar las llamadas recursivas, siempre y cuando 
              el indice derecho, sea mayor al indice izquierdo                */
    if (i_izq < i_der)
    {
        //Se calcula el pivote para 'partir' el arreglo
        int mitad = i_izq + (i_der - i_izq) / 2;
        //Llamada recursiva para evaluar la primera mitad del arreglo
        merge_sort(arreglo, i_izq, mitad);
        //Llamada recursiva para evaluar la segund mitad del arreglo
        merge_sort(arreglo, mitad + 1, i_der);
        //Cuando terminan las dos llamadas anteriores, se procede a 'juntar' los dos arreglos
        merge(arreglo, i_izq, mitad, i_der);
    }
}

void merge(int arreglo[], int i_izq, int mitad, int i_der)
{
    //Primer paso : Se crean los arreglos temporales que guardarán la información
    //Antes, se calcula el tamaño que tendrá cada arreglo
    int tam_izq = (mitad - i_izq) + 1;
    int tam_der = i_der - mitad;
    int ar_izq[tam_izq], ar_der[tam_der];

    //Segundo paso : Se llenan los arreglos temporales con los datos del arreglo

    //Se crea un 'apuntador' que vaya iterando 'arreglo[]' en las posiciones que nos interesan
    for (int i = 0; i < tam_izq; ++i)
    {
        ar_izq[i] = arreglo[i_izq + i];
    }
    for (int j = 0; j < tam_der; ++j)
    {
        ar_der[j] = arreglo[mitad + 1 + j];
    }

    //Tercer paso : Se juntan los dos arreglos en 'arreglo[]'
    //Primero se crean los indices para cada arreglo auxiliar
    int indice_arreglo = i_izq; /*Este indice va a recorrer 'arreglo[]' y va a 
                                      empezar en el límite inferior que le llega a la función */
    int aux_izq = 0;            //Este indice, va a recorrer el arreglo auxiliar de la parte izquierda
    int aux_der = 0;            //Este indice, recorrerá el arreglo auxiliar de la parte derecha
    while (aux_izq < tam_izq && aux_der < tam_der)
    {
        if (ar_izq[aux_izq] <= ar_der[aux_der])
        {
            arreglo[indice_arreglo] = ar_izq[aux_izq];
            aux_izq++;
        }
        else
        {
            arreglo[indice_arreglo] = ar_der[aux_der];
            aux_der++;
        }
        indice_arreglo++;
    }

    /*Cuarto paso : SI HAY ELEMENTOS RESTANTES en alguno de los arreglos
                    auxiliares, se terminan de copiar en 'arreglo[]' */
    //Copia en 'arreglo[]' las posiciones restantes del arreglo auxiliar
    while (aux_izq < tam_izq)
    {
        arreglo[indice_arreglo] = ar_izq[aux_izq];
        aux_izq++;
        indice_arreglo++;
    }
    while (aux_der < tam_der)
    {
        arreglo[indice_arreglo] = ar_der[aux_der];
        aux_der++;
        indice_arreglo++;
    }
}

void imprimir(int arreglo[], int tam_arreglo)
{
    for (int i = 0; i < tam_arreglo; ++i)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}