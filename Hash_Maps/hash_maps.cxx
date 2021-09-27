#include <bits/stdc++.h>

using namespace std; 

int main( )
{

    /*MAPAS : 
      Son contenedores, de parejas que constan de una llave y un valor : [llave][valor]  
      La llave debe ser única, para cada valor, por ejemplo, cada está asociada a un valor, pero cada 
      valor está asociado a una llave única.
      
                mapas[llave][valor].
                - Insertar : Se realiza mediante la inserción de parejas
                        nombre_del_mapa.insert( pair< tipo, tipo >( llave, valor ) ) 
                - Acceder : Para acceder a alguna posición dentro del mapa, se debe acceder mediante la llave única,
                            y si se quiere o requuieren los indices, se necesita recorrer con iteradores
      */


    map<int,int> numeros; 
    vector<int> arreglo = { 4, 2, 6, 3, 6 }; 
    int objetivo = 12, complemento; 

    //Ciclo pone los numeros en el mapa
    for( int i = 0; i < arreglo.size(); ++i )
    {
        numeros.insert( pair<int,int>( arreglo[i], i ));
    }

    for( auto i : numeros ) cout << i.first << " " << i.second << endl;
    cout << endl; 

    //Como la llave está repetida, no se inserta
    numeros.insert(pair<int,int>(0,5));
    //Se inserta porque la llave no existe aún
    numeros.insert(pair<int,int>(5,5));
    
    cout << "Posición encontradad\n"; 
    cout << numeros.find(3)->second << endl; 

    for( auto e : numeros )
    {
        complemento = objetivo - e.second; 
        if( numeros.find( complemento ) )
        {

        }
    }

    return 0; 
}