/*
Damian Dalto, CI: 5.024.782-2, damianema21@gmail.com
Sebastian Gallo, CI: 5.141.778-7, sebastiangaho@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define limiteDeJugadores 10
#define limiteDeHistorial 3

struct historial{
	int numeroDePartida;
	int montoGanado;
	int montoPerdido;
};

struct jugador{
	struct historial historialDelJugador[limiteDeHistorial];
	int topeHistorial;
	int partidasJugadas;
	int edad;
	int monto;
	char nombre[21];
	char apellido[21];
	char cedula[11];
	char alias[6];
};

struct jugadores{
	struct jugador arr[limiteDeJugadores];
	int tope;
};

bool rangoDeXcaracteres(char cadena[], int x){
	int i = 0;
	bool dentroDelRango = true;
	while(cadena[i] != '\0')
		i++;
	
	if(i > x)
		dentroDelRango = false;
		
	return dentroDelRango;
}

bool stringsSonIguales(char aliasElegido[], char aliasExistente[]){
	int i = 0;
	bool sonIguales = true;

  while(aliasElegido[i] != '\0' && aliasExistente[i] != '\0'){
    if(aliasElegido[i] != aliasExistente[i])
      sonIguales = false;

    i++;
  }

  if(aliasElegido[i] != aliasExistente[i])
    sonIguales = false;
  
	return sonIguales;
}

void listadoDeJugadores(struct jugadores js){

	if(js.tope != -1){
		printf("\n*Listado de Jugadores*\n\n");
    int i;
		for(i = 0; i <= js.tope; i++)
			printf("Alias: %s, Monto: %d\n", js.arr[i].alias, js.arr[i].monto);
	}else{
		printf ("\n{Error, revise que todo este en orden.\n");
		printf("No hay jugadores registrados en la lista.}\n\n");
	}
	printf("--------------------\n");
}

void registrarJugadores(struct jugador j, struct jugadores *js){
		
	if(js->tope < 9){		//Solo entra al if si hay espacio para registrar otro jugador (solo se pueden almacenar hasta 10 jugadores)
		printf("\n-Ingrese sus datos-\n\n");
		char cadenaDe5caracteres[6];
    char cadenaDe20caracteres[21];
    char cadenaDe10caracteres[11];
    int i = 0;
    int k = 0;
		
    //cuando el alias es mayor que 8 caracteres ej:SEBASTIAN, despues al ingresar un alias valido tira segmentation fault, y si el alias que puse es mayor que 5 caracteres pero menor que 8 entonces tira el mensaje de ingresar otro alias como planeamos, pero luego al pedir la lista de jugadores dice que no hay jugadores en lista(considerando que fue el primer jugador registrado), osea que el jugador que ingresamos no quedo registrado
		printf("Alias: ");
		scanf("%s", cadenaDe5caracteres);
		while(!rangoDeXcaracteres(cadenaDe5caracteres, 5)){
			printf ("\n{Error, revise que todo este en orden.\n");
			printf("Solo puede ingresar un alias de hasta 5 caracteres.}\n\n");
			scanf(" %s", cadenaDe5caracteres);
		}
    
		if(js->tope >= 0){	//Solo entra al if si hay por lo menos 1 jugador ya registrado
			
			bool esIgual = false;
			while(!esIgual && i <= js->tope){
				esIgual = stringsSonIguales(cadenaDe5caracteres, js->arr[i].alias);
				i++;
				if(esIgual){
					printf ("\n{Error, revise que todo este en orden.\n\n");
					printf("Ese alias ya existe.}\n");
					scanf("%s", cadenaDe5caracteres);
					esIgual = false;
					i = 0;
				}
			
				while(!rangoDeXcaracteres(cadenaDe5caracteres, 5)){
					printf ("\n{Error, revise que todo este en orden.\n");
					printf("Solo puede ingresar un alias de hasta 5 caracteres.}\n\n");
					scanf(" %s", cadenaDe5caracteres);
					i = 0;
				}
			}
		}
    while(cadenaDe5caracteres[k] != '\0')
      k++;

    for(i = 0; i <= k; i++)
		  j.alias[i] = cadenaDe5caracteres[i];

		printf("Nombre: ");
		scanf("%s", cadenaDe20caracteres);
		while(!rangoDeXcaracteres(cadenaDe20caracteres, 20)){
			printf ("\n{Error, revise que todo este en orden.\n");
			printf("Solo puede ingresar un nombre de hasta 20 caracteres.}\n\n");
			scanf(" %s", cadenaDe20caracteres);
		}
    k=0;
    while(cadenaDe20caracteres[k] != '\0')
      k++;

		for(i = 0; i <= k; i++)
		  j.nombre[i] = cadenaDe20caracteres[i];
		
		printf("Apellido: ");
		scanf("%s", cadenaDe20caracteres);
		while(!rangoDeXcaracteres(cadenaDe20caracteres, 20)){
			printf ("\n{Error, revise que todo este en orden.\n");
			printf("Solo puede ingresar un nombre de hasta 20 caracteres.}\n\n");
			scanf(" %s", cadenaDe20caracteres);
		}
    k=0;
    while(cadenaDe20caracteres[k] != '\0')
      k++;

		for(i = 0; i <= k; i++)
		  j.apellido[i] = cadenaDe20caracteres[i];
		
		printf("Cedula: ");
		scanf("%s", cadenaDe10caracteres);
		int p;
		int q;
		bool cedulaValida = false;
		while(!cedulaValida){
			p = 0;
			q = 0;
			cedulaValida = true;
			
			while(!rangoDeXcaracteres(cadenaDe10caracteres, 10)){
				printf ("\n{Error, revise que todo este en orden.\n");
				printf("Solo puede ingresar una cedula de hasta 10 digitos.}\n\n");
				scanf(" %s", cadenaDe10caracteres);
			}
      k=0;
      while(cadenaDe10caracteres[k] != '\0')
        k++;

      for(i = 0; i <= k; i++)
		    j.cedula[i] = cadenaDe10caracteres[i];

			while(j.cedula[q] != '\0')  //q es igual a la cantidad de caracteres del string ingresado por el usuario
				q++;
		
			for(p = 0; p < q; p++){
				if((int)'9' < (int)j.cedula[p] || (int)j.cedula[p] < (int)'0') //Chequea si el usuario ingreso una cedula valida
					cedulaValida = false;
			}
		
			if(!cedulaValida){
				printf ("\n{Error, revise que todo este en orden.\n");
				printf("Ingrese una cedula valida.}\n\n");
				scanf("%s", cadenaDe10caracteres);
			}
		}
	
		printf("Edad: ");
		scanf("%d", &j.edad);
		while(j.edad < 18){
			printf ("\n{Error, revise que todo este en orden.\n");
			printf("ingrese un numero mayor o igual a 18.}\n\n");
			scanf("%d", &j.edad);
		}
		
		printf("Monto: ");
		scanf("%d", &j.monto);
		while(j.monto < 0 || j.monto > 1000){
			printf ("\n{Error, revise que todo este en orden.\n");
			printf("ingrese un numero entre 0 y 1000.}\n\n");
			scanf("%d", &j.monto);
		}
		
		//Inicializa la cantidad de partidas jugadas por el jugador recien creado en 0 y vacia su historial. Luego procede a ingresar el jugador creado en la nueva posicion del arreglo de jugadores
		j.partidasJugadas = 0;
		j.topeHistorial = -1;
		js->tope++;
		js->arr[js->tope] = j;
		printf("--------------------\n");
	}else{
		printf ("\n{Error, revise que todo este en orden.\n");
		printf("Ya no se pueden ingresar mas jugadores.}\n\n");
	}
}

void elegirJugadores(struct jugadores js, int *jugador1, int *jugador2, bool *jugadoresListos){
	char aliasElegido[6];
	int i = 0;
	bool esta;
	
	printf("\nIngrese el alias de quien sera el primer jugador: ");
	scanf("%s", aliasElegido);
	if(rangoDeXcaracteres(aliasElegido, 5)){
		esta = false;
		while(!esta && i <= js.tope){
			esta = stringsSonIguales(aliasElegido, js.arr[i].alias);
			i++;
		}
	
		if(esta){
			*jugador1 = i-1;
			i = 0;
		
			printf("\nIngrese el alias de quien sera el segundo jugador: ");
			scanf("%s", aliasElegido);
			if(rangoDeXcaracteres(aliasElegido, 5)){
				esta = false;
				while(!esta && i <= js.tope){
					esta = stringsSonIguales(aliasElegido, js.arr[i].alias);
					i++;
				}
		
				if(esta && !stringsSonIguales(aliasElegido, js.arr[*jugador1].alias)){
					*jugador2 = i-1;
					*jugadoresListos = true;
					printf("--------------------\n");
				}else{
					printf ("\n{Error, revise que todo este en orden.\n");
					printf("El alias no existe o el jugador1 ya tiene ese alias.}\n\n");
					printf("--------------------\n");
				}
			}else{
				printf ("\n{Error, revise que todo este en orden.\n");
				printf("Ese alias no existe.}\n\n");
				printf("--------------------\n");
			}
		}else{
			printf ("\n{Error, revise que todo este en orden.\n");
			printf("Ese alias no existe.}\n\n");
			printf("--------------------\n");
		}
	}else{
		printf ("\n{Error, revise que todo este en orden.\n");
		printf("Ese alias no existe.}\n\n");
		printf("--------------------\n");
	}
}

void mostrarDatosDelJugador(struct jugadores js){
	char aliasElegido[6];
	int i = 0;
	int j = 0;
	bool esta = false;
	
	printf("\nIngrese el alias a mostrar sus datos: ");
	scanf("%s", aliasElegido);
	if(rangoDeXcaracteres(aliasElegido, 5)){
		while(!esta && i <= js.tope){
			esta = stringsSonIguales(aliasElegido, js.arr[i].alias);
			i++;
		}
		if(esta){
			printf("\nNombre: %s\n", js.arr[i-1].nombre);
		
			printf("Apellido: %s\n", js.arr[i-1].apellido);
		
			printf("Edad: %d\n", js.arr[i-1].edad);
		
			printf("Monto: %d\n", js.arr[i-1].monto);
		
			printf("Partidas jugadas: %d\n\n", js.arr[i-1].partidasJugadas);
			
			j = 0;
			
			//Muestra el historial completo del jugador pedido
			while(j <= js.arr[i-1].topeHistorial){
				printf("En la partida %d ", js.arr[i-1].historialDelJugador[j].numeroDePartida);
				if(js.arr[i-1].historialDelJugador[j].montoGanado != 0)
					printf("gano: %d\n", js.arr[i-1].historialDelJugador[j].montoGanado);
				else
					printf("perdio: %d\n", js.arr[i-1].historialDelJugador[j].montoPerdido);
				j++;
			}
			printf("--------------------\n");
		}else{
		    printf ("\n{Error, revise que todo este en orden.\n");
			printf("Ese alias no existe.}\n\n");
			printf("--------------------\n");
		}
	}else{
		printf ("\n{Error, revise que todo este en orden.\n");
		printf("Ese alias no existe.}\n\n");
		printf("--------------------\n");
	}
}

void actualizarHistorialPartida(struct jugador *j){
	j->partidasJugadas++;
	if(j->topeHistorial < 2){
		//Ingresa el registro en la ultima posicion libre del arreglo historial
		j->topeHistorial++;
		j->historialDelJugador[j->topeHistorial].numeroDePartida = j->partidasJugadas;
	}else{
		//Elimina el primer registro en el arreglo historial, ordena las celdas de menor a mayor e ingresa el nuevo registro en la ultima celda libre
		j->historialDelJugador[0].numeroDePartida = j->historialDelJugador[2].numeroDePartida;
       	j->topeHistorial--;
       	int aux = j->historialDelJugador[0].numeroDePartida;
       	j->historialDelJugador[0].numeroDePartida = j->historialDelJugador[1].numeroDePartida;
       	j->historialDelJugador[1].numeroDePartida = aux;
       	j->topeHistorial++;
       	j->historialDelJugador[2].numeroDePartida = j->partidasJugadas;
	}
}

void actualizarHistorialGano(struct jugador *j, int apuesta, int sumaTotalJ){
	int ganado;
	if(sumaTotalJ == 21)
		ganado = apuesta*3;
	else
		ganado = apuesta*2;
		
	if(j->topeHistorial <= 2 && j->partidasJugadas <= 3){
		//Ingresa el registro en la ultima posicion libre del arreglo historial
		j->historialDelJugador[j->topeHistorial].montoGanado = ganado;
		j->historialDelJugador[j->topeHistorial].montoPerdido = 0;
	}else{
		//Elimina el primer registro en el arreglo historial, ordena las celdas de menor a mayor e ingresa el nuevo registro en la ultima celda libre
		j->historialDelJugador[0].montoGanado = j->historialDelJugador[2].montoGanado;
		j->historialDelJugador[0].montoPerdido = j->historialDelJugador[2].montoPerdido;
       	j->topeHistorial--;
       	int aux1 = j->historialDelJugador[0].montoGanado;
       	int aux2 = j->historialDelJugador[0].montoPerdido;
    	j->historialDelJugador[0].montoGanado = j->historialDelJugador[1].montoGanado;
       	j->historialDelJugador[0].montoPerdido = j->historialDelJugador[1].montoPerdido;
       	j->historialDelJugador[1].montoGanado = aux1;
       	j->historialDelJugador[1].montoPerdido = aux2;
       	j->topeHistorial++;
        j->historialDelJugador[2].montoGanado = ganado;
       	j->historialDelJugador[2].montoPerdido = 0;
	}
}

void actualizarHistorialPerdio(struct jugador *j, int apuesta){		
	if(j->topeHistorial <= 2 && j->partidasJugadas <= 3){
		//Ingresa el registro en la ultima posicion libre del arreglo historial
		j->historialDelJugador[j->topeHistorial].montoGanado = 0;
		j->historialDelJugador[j->topeHistorial].montoPerdido = apuesta;
	}else{
		//Elimina el primer registro en el arreglo historial, ordena las celdas de menor a mayor e ingresa el nuevo registro en la ultima celda libre
		j->historialDelJugador[0].montoGanado = j->historialDelJugador[2].montoGanado;
		j->historialDelJugador[0].montoPerdido = j->historialDelJugador[2].montoPerdido;
       	j->topeHistorial--;
       	int aux1 = j->historialDelJugador[0].montoGanado;
       	int aux2 = j->historialDelJugador[0].montoPerdido;
    	j->historialDelJugador[0].montoGanado = j->historialDelJugador[1].montoGanado;
       	j->historialDelJugador[0].montoPerdido = j->historialDelJugador[1].montoPerdido;
       	j->historialDelJugador[1].montoGanado = aux1;
       	j->historialDelJugador[1].montoPerdido = aux2;
       	j->topeHistorial++;
        j->historialDelJugador[2].montoGanado = 0;
       	j->historialDelJugador[2].montoPerdido = apuesta;
	}
}

void ApuestaInicial (char *nombre, int *apuesta, int *monto){
        printf ("\n-%s, ingresa tu apuesta incial-\n", nombre);
		*apuesta = 0;
		while (*apuesta < 50 || *apuesta > *monto){
	     	scanf ("%d", &*apuesta);
            if (*apuesta < 50 || *apuesta > *monto){
				printf ("\n{Error, revise que todo este en orden.\n");
				printf ("Ingrese un numero entre 50 y %d.}\n\n", *monto);
	      	}
		}
		*monto -= *apuesta;
}  

void revelarCarta(char *nombre, int *monto, int apuesta, bool *abandono, char *opcion, int *sumaTotal, struct jugador *j){
	int carta;
	if(*opcion == 'J' || *opcion == 'j'){
		carta = rand()%9 + 1;
		*sumaTotal += carta;
		printf("\nCarta de %s:\n ___\n|   |\n| %d |\n|___|\n\nApuesta: %d\nSuma Total: %d\n", nombre, carta, apuesta, *sumaTotal);
		//Chequea si el jugador ya gano o perdio
		if(*sumaTotal == 21){
			*monto += apuesta*3;
			*opcion = 't';
			printf("[%s] gana.\n", nombre);
			*abandono = true;
			actualizarHistorialGano(j, apuesta, *sumaTotal);
			printf("--------------------\n");
			
		}else if(*sumaTotal > 21){
			*opcion = 't';
			printf("[%s] pierde.\n", nombre);
			*abandono = true;
			actualizarHistorialPerdio(j, apuesta);
			printf("--------------------\n");
		}
	}
}

void turno(char *opcion, char *nombre, bool *elegido, int *aumentarApuesta, int *cantApuestas, int *monto, int *apuesta){
	if(*opcion == 'J' || *opcion == 'j'){
		printf("--------------------\n");
		printf("*Turno de %s:\n", nombre);
		printf(" ___\n|   |\n| ? |\n|___|\n");
		printf("(J)ugar o (T)erminar?:\n");
	
		*elegido = false;
		*aumentarApuesta = 0;
	
		while(!*elegido){
			scanf(" %c", &*opcion);
			if(*opcion == 'J' || *opcion == 'j'){
				//Mensaje de aumento de apuesta
				if(*cantApuestas < 2 && *monto >= 50){
					printf("En cuanto desea aumentar su apuesta?:\n");
					scanf("%d", &*aumentarApuesta);
					while(*aumentarApuesta != 0){
						if(*aumentarApuesta > *monto || *aumentarApuesta < 0){
							printf("\n{Error, revise que todo este en orden.\n");
							printf("Ingrese un numero entre 0 y %d.}\n\n", *monto);
							scanf("%d", &*aumentarApuesta);
						}else{
							*monto -= *aumentarApuesta;
							*apuesta += *aumentarApuesta;
							(*cantApuestas)++;
							*aumentarApuesta = 0;
						}
					}
				}
  				*elegido = true;
				printf("\n--------------------\n");
			}else if(*opcion == 'T' || *opcion == 't'){
				*elegido = true;
				printf("--------------------\n");
			}else
				printf("\n{Error, revise que todo este en orden.}\n\n");
		}
	}
}

void juegaUnoContraCroupier(int sumaTotalCroupier, int sumaTotalJ, char *nombre, int *monto, int apuesta, struct jugador *j){
	int carta;
	while(sumaTotalCroupier < sumaTotalJ){
		carta = rand()%9 + 1;
		sumaTotalCroupier += carta;
		printf(" ___\n|   |\n| %d |\n|___|\n", carta);
	}
	printf("\nSuma Total croupier: %d\n", sumaTotalCroupier);					
	if(sumaTotalCroupier >= sumaTotalJ && sumaTotalCroupier <= 21){
		printf("[%s] pierde.\n", nombre);
		actualizarHistorialPerdio(j, apuesta);
	}else{
		printf("[%s] gana.\n", nombre);
		*monto += apuesta*2;
		actualizarHistorialGano(j, apuesta, sumaTotalJ);
	}
}

void croupierRobaCarta(int *sumaTotalCroupier){
	int carta;
	carta = rand()%9 + 1;
	*sumaTotalCroupier += carta;
	printf(" ___\n|   |\n| %d |\n|___|\n", carta);
}

void jugadorGana_Pierde(int sumaTotalCroupier, int sumaTotalJ, char *nombre, int *monto, int apuesta, struct jugador *j){
	if(sumaTotalCroupier >= sumaTotalJ && sumaTotalCroupier <= 21){
		printf("[%s] pierde.\n", nombre);
		actualizarHistorialPerdio(j, apuesta);
	}else{
		printf("[%s] gana.\n", nombre);
		*monto += apuesta*2;
		actualizarHistorialGano(j, apuesta, sumaTotalJ);
	}
}

int main(void) {
	srand(time(NULL));
	
	struct jugador j;
	struct jugadores js;
	js.tope = -1;
	
	char opcion = '0';
	bool elegido;
	
	int jugador1 = 0;
	int jugador2 = 0;
	
	bool jugadoresListos;

    int apuestaJ1 = 0;
    int apuestaJ2 = 0;
    
    char opcionJ1;
    char opcionJ2;
    
    int carta;
    int sumaTotalJ1;
    int sumaTotalJ2;
    
    int aumentarApuesta;
    int cantApuestasJ1;
    int cantApuestasJ2;
    
    int sumaTotalCroupier;
    int chanceDelCroupier;
    bool abandonoJ1;
    bool abandonoJ2;
    bool finalCroupier;

//Mensaje de inicio
	printf("Bienvenidos/as a *BLACKJACK*, por favor elijan una opcion:\n\n");
  
  	while(opcion != 'S' && opcion != 's'){
	
		//Mensaje de menu
		printf("\n*Menu Principal*\n\nOpciones:\n-(L)istado de Jugadores:\n-(R)egistrar Jugador:\n-(J)ugar:\n-(D)atos de Jugador:\n-(S)alir:\n");

		elegido = false;
		while(!elegido){
			scanf(" %c", &opcion);
			switch(opcion){
				case 'L': case 'l': elegido = true;
									break;
									
				case 'R': case 'r': elegido = true;
									break;
				
				case 'J': case 'j': elegido = true;
									break;

				case 'D': case 'd': elegido = true;
									break;
									
				case 'S': case 's': elegido = true;
									//Mensaje de despedida
									printf("\n{Nos vemos, que vuelvan pronto!}\n\n");
									break;
									
				default:
						//Mensaje de error
						printf("\n{Error, revise que todo este en orden.}\n\n");
						break;
			}
		}
		
		if(opcion == 'L' || opcion == 'l')
			listadoDeJugadores(js);
		else if(opcion == 'R' || opcion == 'r')
			registrarJugadores(j, &js);
		else if(opcion == 'D' || opcion == 'd')
			mostrarDatosDelJugador(js);
		else if(opcion == 'J' || opcion == 'j'){
			
			//Elegir jugador1 y jugador2 entre los ya registrados
			jugadoresListos = false;
			elegirJugadores(js, &jugador1, &jugador2, &jugadoresListos);
			
			abandonoJ1 = false;
			abandonoJ2 = false;
			if(js.arr[jugador1].monto >= 50 && js.arr[jugador2].monto >= 50 && jugadoresListos){
				//Mensaje de juego
				printf("\n*Empezo la partida*\n");
				
				//Se registra el numero de partida jugada actualmente en el historial
				actualizarHistorialPartida(&js.arr[jugador1]);
				actualizarHistorialPartida(&js.arr[jugador2]);

				//Apuesta inicial jugador 1
				ApuestaInicial (js.arr[jugador1].nombre, &apuestaJ1, &js.arr[jugador1].monto);
				
                //Apuesta inicial jugador 2
				ApuestaInicial (js.arr[jugador2].nombre, &apuestaJ2, &js.arr[jugador2].monto);
				printf("--------------------\n");
			
				//Mensaje de carta revelada
				sumaTotalJ1 = 0;
				sumaTotalJ2 = 0;
				cantApuestasJ1 = 0;
				cantApuestasJ2 = 0;
				opcionJ1 = 'j';
				opcionJ2 = 'j';
				
				while(opcionJ1 == 'J' || opcionJ1 == 'j' || opcionJ2 == 'J' || opcionJ2 == 'j'){

					//Carta del jugador 1 
					revelarCarta(js.arr[jugador1].nombre, &js.arr[jugador1].monto, apuestaJ1, &abandonoJ1, &opcionJ1, &sumaTotalJ1, &js.arr[jugador1]);
					
					//Carta del jugador 2
					revelarCarta(js.arr[jugador2].nombre, &js.arr[jugador2].monto, apuestaJ2, &abandonoJ2, &opcionJ2, &sumaTotalJ2, &js.arr[jugador2]);
				
					//Mensaje de aceptacion
					//Turno jugador 1
					turno(&opcionJ1, js.arr[jugador1].nombre, &elegido, &aumentarApuesta, &cantApuestasJ1, &js.arr[jugador1].monto, &apuestaJ1);
					
					//Turno jugador 2
					turno(&opcionJ2, js.arr[jugador2].nombre, &elegido, &aumentarApuesta, &cantApuestasJ2, &js.arr[jugador2].monto, &apuestaJ2);
					
				}
				
			
				//Mensaje del croupier
				sumaTotalCroupier = 0;
				finalCroupier = false;
				if(!abandonoJ1 || !abandonoJ2){
					printf("\n*El croupier saca:\n");
					while(sumaTotalCroupier < 15){
						carta = rand()%9 + 1;
						sumaTotalCroupier += carta;
						printf(" ___\n|   |\n| %d |\n|___|\n", carta);
					}
					if(abandonoJ2){
						
						juegaUnoContraCroupier(sumaTotalCroupier, sumaTotalJ1, js.arr[jugador1].nombre, &js.arr[jugador1].monto, apuestaJ1, &js.arr[jugador1]);
						
					}else if(abandonoJ1){
						
						juegaUnoContraCroupier(sumaTotalCroupier, sumaTotalJ2, js.arr[jugador2].nombre, &js.arr[jugador2].monto, apuestaJ2, &js.arr[jugador2]);
						
					}else{
						while((sumaTotalCroupier < sumaTotalJ1) && (sumaTotalCroupier < sumaTotalJ2) && !finalCroupier){
							
							croupierRobaCarta(&sumaTotalCroupier);
							if(sumaTotalCroupier > sumaTotalJ1 || sumaTotalCroupier > sumaTotalJ2)
								finalCroupier = true;
					
						}
						if(sumaTotalCroupier > 21){
					
							printf("\nSuma Total croupier: %d\n", sumaTotalCroupier);
							printf("[%s] gana.\n", js.arr[jugador1].nombre);
							js.arr[jugador1].monto += apuestaJ1*2;
							printf("[%s] gana.\n", js.arr[jugador2].nombre);
							js.arr[jugador2].monto += apuestaJ2*2;
							
							actualizarHistorialGano(&js.arr[jugador1], apuestaJ1, sumaTotalJ1);
							actualizarHistorialGano(&js.arr[jugador2], apuestaJ2, sumaTotalJ2);
							
						}else if(sumaTotalCroupier < sumaTotalJ1 || sumaTotalCroupier < sumaTotalJ2){
							//Croupier decide con 50% de chances de robar otra carta
							chanceDelCroupier = rand()%2;
							if(chanceDelCroupier == 1)
								croupierRobaCarta(&sumaTotalCroupier);
					
							printf("\nSuma Total croupier: %d\n", sumaTotalCroupier);	
							//Jugador 1 
							jugadorGana_Pierde(sumaTotalCroupier, sumaTotalJ1, js.arr[jugador1].nombre, &js.arr[jugador1].monto, apuestaJ1, &js.arr[jugador1]);
							
							//Jugador 2
							jugadorGana_Pierde(sumaTotalCroupier, sumaTotalJ2, js.arr[jugador2].nombre, &js.arr[jugador2].monto, apuestaJ2, &js.arr[jugador2]);
						
						}else if(sumaTotalCroupier >= sumaTotalJ1 && sumaTotalCroupier >= sumaTotalJ2){
							
							printf("\nSuma Total croupier: %d\n", sumaTotalCroupier);	
							printf("[%s] pierde.\n", js.arr[jugador1].nombre);
							printf("[%s] pierde.\n", js.arr[jugador2].nombre);
							
							actualizarHistorialPerdio(&js.arr[jugador1], apuestaJ1);
							actualizarHistorialPerdio(&js.arr[jugador2], apuestaJ2);
						}
					}
				}
				printf("\n*Termino la partida*\n\n");
				printf("%s cuenta con: %d.\n", js.arr[jugador1].nombre, js.arr[jugador1].monto);
				printf("%s cuenta con: %d.\n", js.arr[jugador2].nombre, js.arr[jugador2].monto);
				printf("--------------------\n");
			}else if((js.arr[jugador1].monto < 50 || js.arr[jugador2].monto < 50) && jugadoresListos){
				printf ("\n{Error, revise que todo este en orden.\n");
				printf("Los jugadores no cuentan con el monto minimo suficiente.}\n\n");
				printf("--------------------------------------------------------\n");
			}
		}
	}
	return 0;
}
