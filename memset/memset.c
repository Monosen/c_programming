#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RESERVAR_MAS 1
#define TIPO_NUM 1

/*
* malloc
*/

int main()
{
    //declaración de un el arreglo dinámico de enteros:
    int *int_dyn_arr;
    float *float_dyn_arr;

    int tam_inicial; //tamanio inicial
    int incremento;

    float tam_inicial_float;
    float incremento_float;

    int opt = TIPO_NUM;

    //incremento de memoria (entero):
    tam_inicial = 5;
    tam_inicial_float = 5.0;


    printf("\nEl dato va a ser [0]:flotante o [1]:entero ? ");
    scanf("%d", &opt);

   //reserve un espacio en memoria inicial para 5 enteros:
    if(opt == TIPO_NUM) {
            int_dyn_arr = (int*)malloc(sizeof(int) * tam_inicial);
    } else {
            float_dyn_arr = (float*)malloc(sizeof(float) * tam_inicial_float);
    }

    if (int_dyn_arr == NULL || float_dyn_arr == NULL) {
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

         //reasignar memoria:
            if(opt == TIPO_NUM) {
                int_dyn_arr = (int*)realloc(int_dyn_arr, sizeof(int)*tam_inicial);
                memset(int_dyn_arr, 0, sizeof(int)*tam_inicial);
            } else {
                float_dyn_arr = (float*)realloc(float_dyn_arr, sizeof(float)*tam_inicial_float);
                memset(float_dyn_arr, 0.0,sizeof(float)*tam_inicial_float);
            }
        }

    }while(sel == RESERVAR_MAS);

    if(opt == TIPO_NUM) {
            for(int i = 0; i < tam_inicial; i++) {
               printf("\narray number %d index [%d]", *(int_dyn_arr+i), i);
            }
            free(int_dyn_arr);
    } else {
            for(int i = 0; i < tam_inicial_float; i++) {
               printf("\narray number %f index [%d]", *(float_dyn_arr+i), i);
            }
            free(float_dyn_arr);
    }

    return 0;
}