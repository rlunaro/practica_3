

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

**Consideraciones de estilo**

Todas las variables serán ```camelCase```
excepto las definidas en ```entrada_salida.h``` 
que por haberlas usado con anterioridad, 
las preservaremos como están. 

Además, se observa que la sugerencia de implementación de la 
práctica apunta a que el estilo a considerar es camelCase. 

## Opcion 1: productoElementosVector (recursivo)

### Diseño del algoritmo

**Caso base**: si el vector contiene únicamente un 
elemento, el resultado del producto es ése elemento

**Caso general**: si el vector contiene más de un 
elemento, el producto de todos los elementos será 
el primer elemento multiplicado por el resto de 
elementos del vector. 

Para su implementación consideraremos crear el parámetro
```curElem``` de tipo entero que apunta al elemento 
que estamos tratando en el array en una iteración 
dada. 

Una primera implementación nos queda así: 

    unsigned long int productoElementos( int *vector, int curElem, unsigned long size ){
        if( curElem == size-1 )
            return vector[curElem]; // caso base
        else
            return vector[curElem] * productoElementos( vector, curElem+1, size );
    }

### Mejora del caso base para que soporte vectores de tamaño cero

Sin embargo, esta solución adolece de un problema 
si el vector que se presenta es de cero elementos. 
Para evitar ese problema, añadiremos un caso base 
especial ```curElem == size``` que sólo se ejecutaría 
en la eventualidad de que se llamara en un vector con 
cero elementos:

    unsigned long int productoElementos( int *vector, int curElem, unsigned long size ){
        if( curElem == size ) 
            return 0;
        else{
            if( curElem == size-1 )
                return vector[curElem]; // caso base
            else
                return vector[curElem] * productoElementos( vector, curElem+1, size );
        }
    }



### Qué tipo de recursivad se implementa

### Analisis del código fuente


## Opcion 2: invertirDigitos

### Diseño del algoritmo

Primero solicitaremos al usuario que elija un número de la lista que se le presenta. 
Para ello entiendo que no es preciso usar recursividad. A continuación, 
con el número dado, se invertirán los dígitos. 

La aproximación más simple consiste en convertir el número en un array de dígitos
y darle la vuelta recursivamente. 

He explorado una solución matemática consistente en dividir por diez sucesivamente
y obtener los restos (que nos daría la última cifra del número), pero la 
reconstrucción del dígito inverso de esta forma se complica mucho. 

**Caso base**: cuando tenemos sólo un dígito, ya hemos acabado: el inverso 
es el propio dígito.

**Caso general**: cuando tenemos más de un dígito deberemos invertir todos los
dígitos menos el primero y poner al final el primer dígito. 




  

### Qué tipo de recursivad se implementa

### Analisis del código fuente



## Opcion 3: contar pares vector

### Diseño del algoritmo

**Caso base**: cuando sólo queda un elemento por tratar en 
el vector, si éste es par, retornaremos 1, si no, retornaremos
un 0. 

**Caso general**: dado un n-ésimo elemento, si éste es par, 
retornaremos ```1 + contar_pares( resto del vector )```. 
Si éste es impar, retornaremos ```0 + contar_pares( resto del vector )```.


  
### Qué tipo de recursivad se implementa

### Analisis del código fuente


## Opcion 4: combinarVectores

### Diseño del algoritmo

El problema se nos presenta con _dos vectores del mismo tamaño_; 
no obstante vamos a suponer que ésto no tiene porqué ser así y 
vamos a tratar un caso mucho más general en el que el tamaño de 
los vectores de entrada no coincide.

**Caso base 1**: no quedan elementos en v1, pero sí en v2: 
añadiremos todos los elementos que nos queden en v2 a la lista
y hemos terminado.

**Caso base 2**: no quedan elementos en v2, pero sí en v1: 
añadiremos todos los elementos que nos queden en v1 a la lista
 y hemos terminado. 

**Caso base 3**: no quedan elementos ni en v1 ni en v2: hemos
terminado.

**Caso general**: el número de elementos por tratar en v1 y en v2 
es mayor que cero **en ambos casos**. En ese caso, trataremos el 
elemento actual de v1, el elemento actual de v2 y moveremos una posición ambos punteros. 



  
### Qué tipo de recursivad se implementa

### Analisis del código fuente
 

## Opcion 5: combinarOrdenarIter

### Diseño del algoritmo

Igual que en el caso anterior vamos a suponer que los dos vectores
no tienen porqué ser del mismo tamaño. 

Lo que haremos será iterar desde cero hasta ```max(size(v1), size(v2))``` (es decir: el tamaño del mayor de los vectores), 
añadiendo elementos al vector resultado pero ordenando. 

**Importante**: vamos a presuponer que los vectores ```v1``` y
```v2``` vienen pre-ordenados ascendentemente.



  
### Qué tipo de recursivad se implementa

### Analisis del código fuente
 

## Opcion 6: combinarOrdenarRec

### Diseño del algoritmo

Este algoritmo es una modificación del ```combinarVectores```
realizado en la opción 4. La única salvedad es que además
de combinar ambos vectores debemos introducirlos en el 
vector resultado ordenados. 


  
### Qué tipo de recursivad se implementa

### Analisis del código fuente
 
 