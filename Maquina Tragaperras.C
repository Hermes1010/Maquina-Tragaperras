    #include <stdio.h>
    #include <stdlib.h> //Se utiliza la funcion rand para generar numeros aleatoriosz
    #include <unistd.h> //Se utiliza para pausar la ejecucion y usar la función sleep
    #include <ctype.h> //Se utiliza para la funcion touper
    #include <details.h> //Aqui se encuentran las funciones mostrarMenu, loadingBarWithLogo y el resto que creamos para este proyecto

    int main() {
        int numeros[3] = {0, 0, 0}; //Arreglo para guardar los 3 numeros
        int opcion;
        int numerosComprados = 0; 
        int juegoRealizado = 0;


        system("cls"); 

        int duration = 1;
        loadingBarWithLogo(duration); //Muestra la barra de carga.

        sleep(4);
        system("cls"); 

        //Muestra el Mensaje en mayusculas despues de la barra de carga.
        char message[] = "Loteria UNI";
        for (int i = 0; message[i]; i++) { 
            message[i] = toupper(message[i]);
        }
        printCenteredMessage(message, "\033[0;34m"); 

        sleep(4);

        do {
            system("cls"); 
            mostrarMenu();
            scanf("%d", &opcion);

            //Switch para el menu de opciones y sus distintos mensajes para las validaciones.
            switch (opcion) {
                case 1:
                    if (numerosComprados) {
                        system("cls");
                        printf("\n");
                        printf("Ya compraste los 3 numeros. Usa la opcion 'Volver a jugar' para comenzar una nueva sesion.\n");
                        sleep(2);
                    } else {
                        system("cls");
                        comprarNumeros(numeros);
                        numerosComprados = 1;
                        juegoRealizado = 0;
                    }
                    break;
                case 2:
                    if (!numerosComprados) {
                        system("cls");
                        printf("\n");
                        printf("Primero debes comprar 3 numeros antes de jugar.\n");
                        sleep(2);
                    } else if (juegoRealizado) {
                        system("cls");
                        printf("\n");
                        printf("Ya jugaste con estos numeros. Usa la opcion 'Volver a jugar' para comprar otros 3 numeros y jugar de nuevo.\n");
                        sleep(2);
                    } else {
                        system("cls");
                        jugar(numeros);
                        juegoRealizado = 1;
                    }
                    break;
                case 3:
                    if (!juegoRealizado) {
                        system("cls");
                        printf("\n");
                        printf("No puedes volver a jugar sin antes haber jugado.\n");
                        sleep(2);
                    } else {
                        system("cls");
                        printf("\n");
                        printf("La maquina se ha reseteado. Ahora puedes comprar tres nuevos numeros y volver a jugar.\n");
                        numerosComprados = 0;
                        juegoRealizado = 0;
                        sleep(2);
                    }
                    break;
                case 4:
                    system("cls");
                    printf("\n");
                    printf("Saliendo del juego...\n");
                    presentacion();
                    break;
                default:
                    printf("\n");
                    printf("Opcion invalida. Intente de nuevo.\n");
                    break;
            }

            if (opcion != 5) {
                printf("\n");
                printf("Presione Enter para continuar...\n");
                getchar();
                getchar();
            }

        } while (opcion != 4);

        return 0;
}