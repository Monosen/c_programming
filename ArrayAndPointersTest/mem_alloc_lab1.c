#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RESERVAR_MAS 1

int main()
{
   //declaración de un el arreglo dinámico de enteros:
   int *int_dyn_arr;

   int tam_inicial; //tamanio inicial
   int incremento;
   

   //incremento de memoria (entero):
   tam_inicial = 5;
   

   //reserve un espacio en memoria inicial para 5 enteros:
   int_dyn_arr = (int*)malloc(sizeof(int) * tam_inicial);



   
   int sel = RESERVAR_MAS;
   int aumento_reserva = 0;

   do
   {
        printf("\nDesea reservar más espacio? ");
         scanf("%d",&sel);
         if(sel == RESERVAR_MAS)
         {
            printf("\nCuantos elementos desea agregar? ");
             scanf("%d", &incremento);  
         
            tam_inicial += incremento;
            printf("su tamaño es [%d]", tam_inicial);


            //reasignar memoria:
            int_dyn_arr = (int*)realloc(int_dyn_arr, sizeof(int)*tam_inicial);
            memset(int_dyn_arr, -1, sizeof(int)*tam_inicial);
         }
   
   }while(sel == RESERVAR_MAS);

            // for (int i = 0; i < tam_inicial; i++) {
            //    int_dyn_arr[i] = i + 1;
            // }

            for(int i = 0; i < tam_inicial; i++) {
               printf("\narray number %d index [%d]", *(int_dyn_arr+i), i);
            }

            free(int_dyn_arr);


   return 0;
}