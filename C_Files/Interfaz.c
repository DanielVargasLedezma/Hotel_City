/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interfaz.c
 * Author: Dani
 * 
 * Created on August 29, 2021, 7:51 PM
 */

#include "../Headers/Interfaz.h"

void iniciarPrograma()
{
    iniciarHotelInterfaz();
    inicializarHabitaciones();
    
    // if (cargarHabitaciones() == -1)
    // {
    //     iniciarHotelInterfaz();
    //     inicializarHabitaciones();
    // }

    initList();

    // if (cargarLista() == -1)
    // {
    //     initList();
    // }

    menu();

    guardarHabitaciones(hotel);
    guardarLista(lista);

    liberarMemoria();
}

void iniciarHotelInterfaz()
{
    int n = 0, m = 0;
    char continuar[50];

    printf("Digite el numero de pisos que desea que hotel tenga: ");
    while (scanf("%d", &m) != 1)
    {
        printf("\n   Usted digito una respuesta invalida");
        printf("\n   Ingrese cualquier caracter y enter para continuar: ");
        scanf("%s", &continuar);
        return;
    }

    printf("Digite el numero de cuartos por piso que desea que hotel tenga por piso: ");
    while (scanf("%d", &n) != 1)
    {
        printf("\n   Usted digito una respuesta invalida");
        printf("\n   Ingrese cualquier caracter y enter para continuar: ");
        scanf("%s", &continuar);
        return;
    }

    if (n == m)
    {
        n++;
    }

    iniciarHotel(n, m);
}

void printHabitaciones()
{

    int numc;

    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            numc = hotel->habitaciones[i][j].numCamas;
            printf("La habitacion %s", (hotel->habitaciones[i][j].identificador));
            printf(" tiene las siguientes camas: %d", numc);
            printf(", Clasificacion: %s \n", (hotel->habitaciones[i][j].clasificacion));
        }
    }
}

void realizarReservacion()
{

    char nombreCliente[50];
    char continuar[50];
    int identificacion = 0, modoDePago = 0, numeroTelefono = 0, numAdultos = 0, numInfantes = 0, dias = 0, todoIncluido = 0, p = 0, n = 0;

    printf("\n   Ingrese el numero de piso de la habitacion: (Rango de Pisos: 1 a %d) -> ", hotel->col_count);
    if (scanf("%d", &p) != 1)
    {
        printf("\n   Usted digito una respuesta invalida");
        printf("\n   Ingrese cualquier caracter y enter para continuar: ");
        return;
    }

    if (p < 1 || p > hotel->col_count)
    {
        printf("\n   Usted digito un piso que no existe");
        return;
    }

    printf("\n   Ingrese el numero de la habitacion: (Rango de habitaciones: 1 a %d) -> ", hotel->row_count);
    if (scanf("%d", &n) != 1)
    {
        printf("\n   Usted digito una respuesta invalida");
        printf("\n   Ingrese cualquier caracter y enter para continuar: ");
        return;
    }

    if (n < 1 || n > hotel->row_count)
    {
        printf("\n   Usted digito una habitacion que no existe");
        return;
    }

    p--;
    n--;

    if (estadoHabitacion(n, p) == 1)
    {
        printf("\n   La habitacion no está disponible:");
    }
    else
    {
        printf("\n   Ingrese el nombre del cliente: ");
        scanf("%s", nombreCliente);

        printf("\n   Ingrese la identificacion del cliente: ");
        if (scanf("%d", &identificacion) != 1)
        {
            printf("\n   Usted digito una respuesta invalida");
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            return;
        }
        //Validacion Entero

        printf("\n   Ingrese el numero de adultos: ");
        if (scanf("%d", &numAdultos) != 1)
        {
            printf("\n   Usted digito una respuesta invalida");
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            return;
        }
        //Validacion Entero

        printf("\n   Ingrese el numero de infantes: ");
        if (scanf("%d", &numInfantes) != 1)
        {
            printf("\n   Usted digito una respuesta invalida");
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            return;
        }
        //Validacion Entero

        if (numAdultos + numInfantes > hotel->habitaciones[n][p].numCamas)
        {
            printf("\n   La habitacion no tiene suficientes camas");
            return;
        }
        //Validacion Cantidad Camas, retornar cantidad de camas en i j desde hotel.c

        printf("\n   Ingrese la cantidad de dias: ");
        if (scanf("%d", &dias) != 1)
        {
            printf("\n   Usted digito una respuesta invalida");
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            return;
        }
        //Validacion Entero

        printf("\n   Desea adquirir el servicio todo incluido?");
        printf("\n   1. Si");
        printf("\n   2. No");
        printf("\n Su respuesta -> ");
        if (scanf("%d", &todoIncluido) != 1 || 1 > todoIncluido || todoIncluido > 2)
        {
            printf("\n   Usted digito una respuesta invalida");
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            return;
        }
        //Validacion Entero

        printf("\n   Los metodos de pago son:");
        printf("\n   1. Efectivo");
        printf("\n   2. Tarjeta de debito");
        printf("\n   3. Tarjeta de credito");
        printf("\n   Ingrese el numero correspondiente al metodo de pago: ");
        scanf("%d", &modoDePago);
        if (scanf("%d", &modoDePago) != 1 || 1 > modoDePago || modoDePago > 3)
        {
            printf("\n   Usted digito una respuesta invalida");
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            return;
        }
        printf("\n   Ingrese cualquier caracter y enter para continuar: ");
        scanf("%s", &continuar);
        //Validacion Entero

        Informacion *inf = (Informacion *)malloc(sizeof(Informacion));
        Cliente *c = (Cliente *)malloc(sizeof(Cliente));

        inf->numOfAdults = numAdultos;
        inf->numOfDays = dias;
        inf->numOfKids = numInfantes;
        inf->typeOfInstance = todoIncluido;

        memcpy(c->nombreCliente, nombreCliente, sizeof c->nombreCliente);

        c->numeroTelefono = numeroTelefono;
        c->identificacion = identificacion;
        c->modoDePago = modoDePago;

        checkIn(c, inf, p, n);
    }
}

void cantidadHabitacionesLibresConNCamas(int numeroDeCamas)
{

    int contadorPC = 0, contadorSC = 0, contadorTC = 0;
    char PC[3] = "PC";
    char SC[3] = "SC";
    char TC[3] = "TC";
    //For class 1

    printf("\nHabitaciones de primera clase con %d camas: \n", numeroDeCamas);

    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            if (hotel->habitaciones[i][j].estado == 'L' && hotel->habitaciones[i][j].numCamas == numeroDeCamas && (strcmp(hotel->habitaciones[i][j].clasificacion, PC) == 0))
            {
                contadorPC++;
                printf(" La habitacion %s \n", (hotel->habitaciones[i][j].identificador));
            }
        }
    }

    if (contadorPC == 0)
    {
        printf(" No hay ninguna habitacion disponible \n");
    }

    //For class 2

    printf("\nHabitaciones de segunda clase con %d camas: \n", numeroDeCamas);
    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            if (hotel->habitaciones[i][j].estado == 'L' && hotel->habitaciones[i][j].numCamas == numeroDeCamas && (strcmp(hotel->habitaciones[i][j].clasificacion, SC) == 0))
            {
                contadorSC++;
                printf(" La habitacion %s \n", (hotel->habitaciones[i][j].identificador));
            }
        }
    }

    if (contadorSC == 0)
    {
        printf(" No hay ninguna habitacion disponible \n");
    }

    //For class 3

    printf("\nHabitaciones de tercera clase con %d camas: \n", numeroDeCamas);
    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            if (hotel->habitaciones[i][j].estado == 'L' && hotel->habitaciones[i][j].numCamas == numeroDeCamas && (strcmp(hotel->habitaciones[i][j].clasificacion, TC) == 0))
            {
                contadorTC++;
                printf(" La habitacion %s \n", (hotel->habitaciones[i][j].identificador));
            }
        }
    }

    if (contadorTC == 0)
    {
        printf(" No hay ninguna habitacion disponible \n");
    }
}

void menu()
{
    int opcion = 0;
    char continuar[50];
    do
    {

        printf("\e[1;1H\e[2J");
        printHabitaciones();
        printf("  ---------------Menu del Hotel_City---------------\n");
        printf("  01. Cuantas habitaciones estan libres");
        printf("\n  02. Cuantas habitaciones estan en mantenimiento");
        printf("\n  03. Cuantas habitaciones ocupadas");
        printf("\n  04. Cuantas hay desocupadas por cantidad de camas");
        printf("\n  05. Check in");
        printf("\n  06. Pagar la habitacion ");
        printf("\n  07. Liberar la habitacion");
        printf("\n  08. Cuantas personas adultas hay el dia de hoy. ");
        printf("\n  09. Cuantos infantes existen al dia de hoy en el hotel");
        printf("\n  10. Recaudacion del dia");
        printf("\n  00. Salir");
        printf("\n\n   Introduzca una opcion (0-10): ");

        if (scanf("%d", &opcion) != 1)
        {
            printf("\n   Usted digito una respuesta invalida");
            printf("\n   Ingrese cualquier caracter y enter para continuar \n");
        }

        switch (opcion)
        {
        case 1:
            printf("\e[1;1H\e[2J");
            printf("\n   1. Cuantas habitaciones estan libres");
            printf("\n   Numero de habitaciones desocupadas: %d", cantidadHabitacionesLibres());
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            break;

        case 2:
            printf("\e[1;1H\e[2J");
            printf("\n   2. Cuantas habitaciones estan en mantenimiento");
            printf("\n   Habitaciones en mantenimiento: %d", cantidadHabitacionesEnMant());
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            break;

        case 3:
            printf("\e[1;1H\e[2J");
            printf("\n   3. Cuantas habitaciones ocupadas");
            printf("\n   Las siguientes habitachioes estan ocupadas: %d", cantidadHabitacionesOcupadas());
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            break;

        case 4:
        {
            int numc = 0;

            printf("\e[1;1H\e[2J");
            printf("\n   4. Cuántas hay desocupadas por cantidad de camas.");
            printf("\n   Ingrese la cantidad de camas deseada: ");

            if (scanf("%d", &numc) != 1)
            {
                printf("\n   Usted digito un caracter no numerico y eso es lo que se espera");
                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                break;
            }

            if (numc > 5 || numc < 1)
            {
                printf("\n Cantidad de camas no valida");
                break;
            }
            else
            {
                printf("\n   Cantidad de habitaciones desocupadas por cantidad de camas: \n");
                cantidadHabitacionesLibresConNCamas(numc);
            }

            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);

            break;
        }

        case 5:
            printf("\e[1;1H\e[2J");
            printf("\n   5. Check in ");
            realizarReservacion();
            break;

        case 6:
        {
            printf("\e[1;1H\e[2J");
            int ced = 0, i = 0, j = 0;
            printf("\n   6. Pagar la habitacion ");

            printf("\n   Ingrese el numero de piso de la habitacion: (Rango de Pisos: 1 a %d) -> ", hotel->col_count);

            if (scanf("%d", &j) != 1)
            {
                printf("\n   Usted digito un caracter no numerico y eso es lo que se espera");
                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                break;
            }

            if (j < 1 || j > hotel->col_count)
            {
                printf("\n   Usted digito un piso que no existe");
                break;
            }

            printf("\n   Ingrese el numero de la habitacion: (Rango de habitaciones: 1 a %d) -> ", hotel->row_count);

            if (scanf("%d", &i) != 1)
            {
                printf("\n   Usted digito un caracter no numerico y eso es lo que se espera");
                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                break;
            }

            if (i < 1 || i > hotel->row_count)
            {
                printf("\n   Usted digito una habitacion que no existe");
                break;
            }

            j--;
            i--;

            printf("\n   Digite el numero de cedula: ");
            scanf("%d", &ced);

            double response = pagarHabitacion(ced, i, j);

            if ((int)response == -1)
            {
                printf("\n  La habitacion ya ha sido pagada y esta pendiente de liberar");
            }
            else if ((int)response == 0)
            {
                printf("\n  La habitacion no esta ocupada");
            }
            else
            {
                printf("\n  El cargo total de la reservacion es de: %lf \n", response);
            }

            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            break;
        }

        case 7:
        {
            int ced = 0;

            printf("\e[1;1H\e[2J");
            printf("\n   7. Liberar la habitacion por numero de cedula");
            printf("\n   Ingrese el numero de cedula: ");

            if (scanf("%d", &ced) != 1)
            {
                printf("\n   Usted digito una respuesta invalida");
                printf("\n   Ingrese cualquier caracter y enter para continuar \n");
            }

            if (liberarHabitacionCedula(ced) == 1)
            {
                printf("Habitacion liberada con exito");
            }
            else
            {
                printf("Ocurrio un error al liberar esta habitacion");
            }
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);

            break;
        }

        case 8:
            printf("\e[1;1H\e[2J");
            printf("\n   8. Cuantas personas adultas hay el dia de hoy. ");
            printf("\n   Cantidad de adultos en el hotel hoy: %d", cantidadAdultosHoy());
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            break;

        case 9:
            printf("\e[1;1H\e[2J");
            printf("\n   9. Cuantos niños existen al dia de hoy en el hotel");
            printf("\n   Cantidad de niños en el hotel hoy: %d", cantidadInfantesHoy());
            printf("\n   Ingrese cualquier caracter y enter para continuar: ");
            scanf("%s", &continuar);
            break;

        case 10:
        {
            printf("\e[1;1H\e[2J");
            int opcion2;

            do
            {
                printf("\e[1;1H\e[2J");
                printf("\n  Recaudacion del dia: ");
                printf("\n   1. Con los clientes, “TODO INCLUIDO”");
                printf("\n   2. Con los clientes, “Sin TODO INCLUIDO”");
                printf("\n   3. Con todos los clientes  que hay en el hotel");
                printf("\n   0. Salir");
                printf("\n   Introduzca una opcion (0-3): ");

                if (scanf("%d", &opcion2) != 1)
                {
                    printf("\n   Usted digito un caracter no numerico y eso es lo que se espera");
                    printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                    scanf("%s", &continuar);
                }

                switch (opcion2)
                {

                case 1:
                    printf("\e[1;1H\e[2J");
                    printf(" El total recaudado hoy en reservaciones todo incluido: %d", totalRecaudadoHoyTI());
                    printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                    scanf("%s", &continuar);
                    break;

                case 2:
                    printf("\e[1;1H\e[2J");
                    printf(" El total recaudado hoy en reservaciones normales: %d", totalRecaudadoHoyNTI());
                    printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                    scanf("%s", &continuar);
                    break;

                case 3:
                    printf("\e[1;1H\e[2J");
                    printf(" El total recaudado hoy en reservaciones normales: %d", totalRecaudadoHoy());
                    printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                    scanf("%s", &continuar);
                    break;

                case 0:
                    break;
                }
            } while (opcion2 != 0);
            break;
        }
        case 0:
            break;

        default:
            break;
        }
    } while (opcion != 0);
}