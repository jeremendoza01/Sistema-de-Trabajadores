#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct task {
  char descripcion[100];
  int complejidad;
} typedef task;

struct trabajo {
  int DNI;
  char Poder[100];
  task tarea;
  char partidoPolitico[100];
  int cantidadDeTareasQueRealiza;
} typedef trabajo;

task listaDeTareas[5];
trabajo listaDeTrabajo[5];
char PoderJudicial[2] = "PJ";
char Prensa[6] = "PRENSA";
char PoderLegislativo[2] = "PL";

////////////////////////////////////////////////////////////

void calcularEstres(task listaDeTareas[]) {

  for (int i = 0; i < 5; i++) {
    if (listaDeTareas[i].complejidad > 5) {
      printf("\n La tarea Numero %d es estresante porque tiene una complejidad "
             "de %d \n",
             i + 1, listaDeTareas[i].complejidad);
    } else {
      printf("\n La tarea Numero %d se la considera no estresante \n", i + 1);
    }
  }
}

void personasEstresadas(trabajo listaDeTrabajo[]) {
  for (int i = 0; i < 5; i++) {
    
    int resultado = strcmp(listaDeTrabajo[i].Poder, PoderJudicial);
    if ((listaDeTrabajo[i].tarea.complejidad > 5) || (resultado == 0)){
      printf("\n El trabajador Numero %d esta estresado \n", i + 1);
    } else {
      printf("\n El trabajador Numero %d NO esta estresado \n", i + 1); 
    }
  }
}

void personasEnPeligro(trabajo listaDeTrabajo[]) {
  bool es3 = false;
  
  for (int i = 0; i < 5; i++) {
    
    int resultado = strcmp(listaDeTrabajo[i].Poder, Prensa);
    int resultado2 = strcmp(listaDeTrabajo[i].Poder, PoderLegislativo);
    
    if (((listaDeTrabajo[i].tarea.complejidad > 5) && (resultado2 == 0))||(resultado == 0)) {
      printf("\n El trabajador Numero %d esta peligro \n", i + 1);
    } else {
      printf("\n El trabajador Numero %d NO esta en peligro \n", i + 1);
    }
  }
}

void TrabajadoresEnemigos(trabajo listaDeTrabajo[]) {
  
  for (int i = 0; i < 5; i++) {
    
    int resultado = strcmp(listaDeTrabajo[i].Poder, Prensa);
    int resultado2 = strcmp(listaDeTrabajo[i].Poder, PoderLegislativo);
    int resultado3 = strcmp(listaDeTrabajo[i].Poder, PoderJudicial);
    
    if (resultado3 == 0) {
      printf("\n Los enemigos del Poder Judicial son el Poder Ejecutivo - %s ",
             listaDeTrabajo[i].Poder);
    } else if (resultado2 == 0) {
      printf("\n lo enemigos son PJ, y legisladores de otros partidos - %s ",
             listaDeTrabajo[i].Poder);
    } else if (resultado == 0) {
      printf("\n Los enemigos son PJ, PE y legisladores de otros partidos - %s ",
             listaDeTrabajo[i].Poder);
    }
  }
}

void mayorComplejidad(task listaDeTareas[]) {
  int mayor = 0;
  int indice = 0;
  for (int i = 0; i < 5; i++) {
    if (listaDeTareas[i].complejidad > mayor) {
      mayor = listaDeTareas[i].complejidad;
      indice = i;
    }
  }
  printf("El trabajador con mayor complejidad es %d \n", mayor,
         " su DNI es %d ", listaDeTrabajo[indice].DNI);
}

void UnicaTarea(trabajo listaDeTrabajo[]) {
  int trabajador;
  for (int i = 0; i < 5; i++) {
    if (listaDeTrabajo[i].cantidadDeTareasQueRealiza = 1) {
      trabajador += i;
    }
    printf("\n El trabajador Nro %d realiza una unica tarea", i);
  }
  printf("\n");
}

void Inicializar(task listaDeTareas[], int tamanio) {
  for (int i = 0; i < tamanio; i++) {
    for (int f = 0; f < 100; f++) {
      listaDeTareas[i].descripcion[f] = '\0';
      listaDeTareas[i].complejidad = 0;
    }
  }
}

void Inicializar2(trabajo listaDeTrabajo[], int tamanio) {
  for (int i = 0; i < tamanio; i++) {
    for (int f = 0; f < 100; f++) {
      listaDeTrabajo[i].DNI = 0;
      listaDeTrabajo[i].Poder[f] = '\0';
      listaDeTrabajo[i].tarea.complejidad = 0;
      listaDeTrabajo[i].tarea.descripcion[f] = '\0';
      listaDeTrabajo[i].partidoPolitico[f] = '\0';
    }
  }
}

////////////////////////////////////////////////////////////

int main(void) {

  int menu, opcionDeTarea;
  bool bandera;

  menu = 0;
  opcionDeTarea = 0;
  bandera = false;

  /*Fin Inicializar variables*/

  while (menu != -1) {

    printf("\n---Opcion 1 para ingresar todos los datos ---\n");
    printf("\n---Opcion 2 para conocer las tareas estresantes\n");
    printf("\n---Opcion 3 para conocer las personas estresadas\n");
    printf("\n---Opcion 4 para conocer las personas que estan en peligro\n");
    printf("\n---Opcion 5 para mostrar los enemigos de los trabajadores\n");
    printf("\n---Opcion 6 para mostrar al trabajador con mayor complejidad\n");
    printf("\n---Opcion 7 para mostrar aquellos trabajadores con una tarea\n");
    scanf("%d", &menu);

    /*Control de errores menu*/

    while ((menu > 7) || (menu < 0)) {
      system("clear");
      printf("\n--- ERROR ---\n");
      printf("\n---Opcion 1 para ingresar todos los datos ---\n");
      printf("\n---Opcion 2 para conocer las tareas estresantes\n");
      printf("\n---Opcion 3 para conocer las personas estresadas\n");
      printf("\n---Opcion 4 para conocer las personas que estan en peligro\n");
      printf("\n---Opcion 5 para mostrar los enemigos de los trabajadores\n");
      printf(
          "\n---Opcion 6 para mostrar al trabajador con mayor complejidad\n");
      printf(
          "\n---Opcion 7 para mostrar aquellos trabajadores con una tarea\n");
      scanf("%d", &menu);
    }

    /*fin Control de errores menu*/

    switch (menu) {
    case 1:
      system("clear");
      printf("\n --- A seleccionado la opcion 1 --- \n");
      Inicializar(listaDeTareas, 5);

      for (int i = 0; i < 5; i++) {
        printf("Ingrese la Descripcion de la tarea N %d \n", i + 1);
        fflush(stdin);
        scanf("%s", &listaDeTareas[i].descripcion);
        printf("Ingrese la complejidad de la tarea N %d \n", i + 1);
        scanf("%d", &listaDeTareas[i].complejidad);
        while ((listaDeTareas[i].complejidad > 10) ||
               (listaDeTareas[i].complejidad < 0)) {
          system("clear");
          printf("\n---ERROR ingresar valor entre 0 y 10 ---\n");
          printf("Ingrese la complejidad de la tarea N %d \n", i + 1);
          scanf("%d", &listaDeTareas[i].complejidad);
        }
      }

      Inicializar2(listaDeTrabajo, 5);

      for (int i = 0; i < 5; i++) {
        system("clear");
        printf("Ingrese el DNI del trabajador N %d \n", i + 1);
        scanf("%d", &listaDeTrabajo[i].DNI);

        while ((listaDeTrabajo[i].DNI < 00000001) ||
               (listaDeTrabajo[i].DNI > 99999999)) {
          system("clear");
          printf("\n---ERROR---\n");
          printf("Ingrese el DNI del trabajador N %d \n", i + 1);
          scanf("%d", &listaDeTrabajo[i].DNI);
        }

        printf("\n Ingrese el poder en el que trabaja el trabajador N %d \n",
               i + 1);
        fflush(stdin);
        scanf("%s", listaDeTrabajo[i].Poder);
        printf(
            "\n Ingrese el partido politico que milita el trabajador N %d \n",
            i + 1);
        fflush(stdin);
        scanf("%s", listaDeTrabajo[i].partidoPolitico);
        printf("\n Que tarea desarrolla el trabajador N %d elegir entre la "
               "tarea 1 a la 5 \n",
               i + 1);
        scanf("%d", &opcionDeTarea);

        switch (opcionDeTarea) {
        case1:
          listaDeTrabajo[i].tarea.complejidad =
              listaDeTareas[opcionDeTarea - 1].complejidad;
          strcpy(listaDeTrabajo[i].tarea.descripcion,
                 listaDeTareas[opcionDeTarea - 1].descripcion);
          listaDeTrabajo[opcionDeTarea - 1].cantidadDeTareasQueRealiza += 1;

          break;
        case2:
          listaDeTrabajo[i].tarea.complejidad =
              listaDeTareas[opcionDeTarea - 1].complejidad;
          strcpy(listaDeTrabajo[i].tarea.descripcion,
                 listaDeTareas[opcionDeTarea - 1].descripcion);
          listaDeTrabajo[opcionDeTarea - 1].cantidadDeTareasQueRealiza += 1;

          break;
        case3:
          listaDeTrabajo[i].tarea.complejidad =
              listaDeTareas[opcionDeTarea - 1].complejidad;
          strcpy(listaDeTrabajo[i].tarea.descripcion,
                 listaDeTareas[opcionDeTarea - 1].descripcion);
          listaDeTrabajo[opcionDeTarea - 1].cantidadDeTareasQueRealiza += 1;

          break;
        case4:
          listaDeTrabajo[i].tarea.complejidad =
              listaDeTareas[opcionDeTarea - 1].complejidad;
          strcpy(listaDeTrabajo[i].tarea.descripcion,
                 listaDeTareas[opcionDeTarea - 1].descripcion);
          listaDeTrabajo[opcionDeTarea - 1].cantidadDeTareasQueRealiza += 1;

          break;
        case5:
          listaDeTrabajo[i].tarea.complejidad =
              listaDeTareas[opcionDeTarea - 1].complejidad;
          strcpy(listaDeTrabajo[i].tarea.descripcion,
                 listaDeTareas[opcionDeTarea - 1].descripcion);
          listaDeTrabajo[opcionDeTarea - 1].cantidadDeTareasQueRealiza += 1;

          break;
        }
      }

      bandera = true;
      break;
    case 2:
      system("clear");
      printf("\n --- A seleccionado la opcion 2 --- \n");
      if (bandera == true) {
        calcularEstres(listaDeTareas);
        printf("\n \n");

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta "
               "opcion \n");
      }
      break;
    case 3:
      if (bandera == true) {
        system("clear");
        printf("\n --- A seleccionado la opcion 3 --- \n");
        personasEstresadas(listaDeTrabajo);

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta "
               "opcion \n");
      }
      break;
    case 4:
      if (bandera == true) {
        system("clear");
        printf("\n --- A seleccionado la opcion 4 ---\n");
        personasEnPeligro(listaDeTrabajo);

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta "
               "opcion \n");
      }
      break;
    case 5:
      if (bandera == true) {
        system("clear");
        printf("\n --- A seleccionado la opcion 5 ---\n");
        TrabajadoresEnemigos(listaDeTrabajo);
      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta "
               "opcion \n");
      }
      break;
    case 6:
      if (bandera == true) {
        system("clear");
        printf("\n --- A seleccionado la opcion 6 ---\n");
        mayorComplejidad(listaDeTareas);

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta "
               "opcion \n");
      }
      break;
    case 7:
      if (bandera == true) {
        system("clear");
        printf("\n --- A seleccionado la opcion 7 ---\n");
        UnicaTarea(listaDeTrabajo);

      } else {
        printf("\n Debe ingresar primero la opcion 1 para poder usar esta "
               "opcion \n");
      }
      break;
    default:
      printf("\n---Opcion incorrecta---\n");
      break;
    }
  }
  return 0;
}