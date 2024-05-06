

# Práctica 3, recursividad

## Consideraciones iniciales: modelo de datos

A pesar de la obviedad del enunciado (se presentan dos vectores de cinco 
enteros cada uno), considero que es conveniente establecer ciertas 
asunciones: 1) **Los vectores se facilitarán ordenados**: consideramos 
que los vectores ya vienen ordenados (en los ejemplos que se facilita 
así es), ya que de lo contrario algunos de los ejercicios exigirían 
un ordenado previo de los mismos y 2) **Se ha optado por la siguiente 
implementación**: 


    int v1[] = {1, 12, 23, 28, 35};
    int v2[] = {15, 25, 32, 70, 91};
    
    #define SIZE_1 sizeof(v1)/sizeof(int)
    #define SIZE_2 sizeof(v2)/sizeof(int)

    
Esta implementación tiene la ventaja de que  al usar la 
inicialización de arrays de C, basta con añadir un elemento 
a la lista inicial para que el programa pueda usarse: 
hemos definido un ```#define SIZE_?``` que calcula 
automáticamente el tamaño de nuestro array.


  
 