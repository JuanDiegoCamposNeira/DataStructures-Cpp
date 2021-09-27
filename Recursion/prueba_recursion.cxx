#include <bits/stdc++.h>
using namespace std; 

void funcion_recursiva( int iteracion ); 

int main()
{
	funcion_recursiva( 4 );
}

void funcion_recursiva( int iteracion )
{
	if( iteracion > 0 )
	{
		printf("Recursión, entra a la iteración %i\n", iteracion);
		funcion_recursiva( iteracion - 1 ); 
		cout << "salgo de la recursion \n"; 
	}	
	else
	{
		cout << "Entra en el else \n";
	}
	cout << "sale de la condición\n";	
}
