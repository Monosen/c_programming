#include <stdlib.h>
#include <stdio.h>

#define RESERVAR_MAS 1
#define TIPO_NUM 1

int main()
{
   //declaración de un el arreglo dinámico de enteros:
   int *int_dyn_arr;
   float *int_dyn_arr_float;

   int tam_inicial; //tamanio inicial
   int incremento;
   
   float tam_inicial_float;
   float incremento_float;

   int opt = TIPO_NUM;

   //incremento de memoria (entero):
   tam_inicial = 1;
   tam_inicial_float = 1.1;
   

   printf("\nEl dato va a ser [0]:flotante o [1]:entero ? ");
   scanf("%d", &opt);

   //reserve un espacio en memoria inicial para 5 enteros:
   if(opt == TIPO_NUM) {
            int_dyn_arr = (int*)malloc(sizeof(int) * tam_inicial);
   } else {
            int_dyn_arr_float = (float*)malloc(sizeof(float) * tam_inicial_float);
   }

   if (int_dyn_arr == NULL || int_dyn_arr_float == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
   }

   
   int sel = RESERVAR_MAS;
   int aumento_reserva = 0;

   do
   {
        printf("\nDesea reservar más espacio? ");
         scanf("%d",&sel);
         if(sel == RESERVAR_MAS)
         {
            
            printf("\nCuantos elementos desea agregar? ");
            if(opt == TIPO_NUM) {
               scanf("%d", &incremento);  
            } else {
               scanf("%f", &incremento_float);  
            }
            
         }
         
         if(sel != 0) {
            if(opt == TIPO_NUM) {
               tam_inicial += incremento;
               printf("su tamaño es [%d]", tam_inicial);
            } else {
               tam_inicial_float += incremento_float;
               printf("su tamaño es [%f]", tam_inicial_float);
            }
         }
         //reasignar memoria:
         if(sel != 0) {
            if(opt == TIPO_NUM) {
               int_dyn_arr = realloc(int_dyn_arr, tam_inicial);
            } else {
               int_dyn_arr_float = realloc(int_dyn_arr_float, tam_inicial_float);
            }
         }
   
   }while(sel == RESERVAR_MAS);


   if(opt == TIPO_NUM) {
            for (int i = 0; i < tam_inicial; i++) {
               int_dyn_arr[i] = i + 1;
            }

            for(int i = 0; i < tam_inicial; i++) {
               printf("\narray number %d index [%d]", int_dyn_arr[i], i);
            }

            free(int_dyn_arr);
   } else {
            for (int i = 0; i < tam_inicial_float; i++) {
               int_dyn_arr_float[i] = i + 1.1;
            }

            for(int i = 0; i < tam_inicial_float; i++) {
               printf("\narray number %f index [%d]", int_dyn_arr_float[i], i);
            }

            free(int_dyn_arr_float);
   }

   return 0;
}