/*
 * main.cpp
 *
 * Copyright 2020 rluna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * May 6, 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entrada_salida.h"

#define MAX_STRING 1024

int v1[] = {1, 12, 23, 28, 35};
int v2[] = {15, 25, 32, 70, 91};
// only for testing
//int v1[] = {1, 42, 23, 78, 35};
//int v2[] = {15, 25, 32};

#define SIZE1 sizeof(v1)/sizeof(int)
#define SIZE2 sizeof(v2)/sizeof(int)

int menu(){
    printf("\n");
    printf("\n");
    printf("\n");
    printf("   Menu\n");
    printf("   ====\n");
    printf("1. productos de los elementos del vector v1\n");
    printf("2. invertir digitos de un elemento del vector v1\n");
    printf("3. contar pares del vector\n");
    printf("4. combinar vectores v1 y v2 (sin ordenar)\n");
    printf("5. combinar vectores v1 y v2 (ordenado ascendente) (iterativo)\n");
    printf("6. combinar vectores v1 y v2 (ordenado ascendente) (recursivo)\n");
    printf("0. salir\n");
    printf("\n");
    return leer_validar_numero("Selección", "0123456" );
}

void imprimeVector( char *name, int *vector, unsigned long size ){
    unsigned long int i;
    printf("Vector %s:", name );
    for(i = 0; i < size - 1; i++){
        printf("%d, ", vector[i]);
    }
    printf( "%d", vector[i]);
    printf("\n");
}

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


int estaNumeroEnVector( int numero, int *vector, unsigned long size ){
    for( int i = 0; i < size; i++ ){
        if( numero == vector[i] )
            return 1;
    }
    return 0;
}


int eligeNumeroVector( char *name, int *vector, unsigned long size ){
    int numero = 0;
    int estaEnVector = 0;
    imprimeVector( name, vector, size);
    do{
        printf("\n");
        numero = leer_numero("¿Qué número desea considerar?");
        estaEnVector = estaNumeroEnVector( numero, vector, size );
        if( !estaEnVector ){
            printf("El número que ha elegido no está en el vector, \n");
            printf("por favor elija otro.\n");
        }
    }while( !estaEnVector );
    return numero;
}


void invertirCadena( int pos, char *orig, unsigned long size, char *dest ){
    if( pos == size -1 ){
        dest[size-pos-1] = orig[pos];
    }else{
        dest[size-pos-1] = orig[pos];
        invertirCadena( pos+1, orig, size, dest );
    }
}

struct vectorData {
    int *vector;
    unsigned long size;
    char *vectorName;
};

void eligeVector( struct vectorData *vd ){
    int numVector = leer_validar_numero( "De qué vector deseas contar pares?", "12");
    if( numVector == 1 ){
        vd->vector = v1;
        vd->size = SIZE1;
        vd->vectorName = "v1";
    }else{
        vd->vector = v2;
        vd->size = SIZE2;
        vd->vectorName = "v2";
    }
}

int contarParesVector( int pos, int *vector, unsigned long size ){
    if( pos == size - 1 ){
        if( vector[pos] % 2 == 0 )
            return 1;
        else
            return 0;
    }else{
        if( vector[pos] % 2 == 0 )
            return 1 + contarParesVector( pos + 1, vector, size );
        else
            return 0 + contarParesVector( pos + 1, vector, size );
    }
}


void combinarVectores( int pos1,
                       int pos2,
                       int *v1,
                       int *v2,
                       unsigned long size1,
                       unsigned long size2,
                       int posResult,
                       int *resultadoCombinar ){
    // caso base 1: v1 no tiene ya elementos pero v2 sí
    if( pos1 == size1 && pos2 < size2 ){
        while( pos2 < size2 ){
            resultadoCombinar[posResult++] = v2[pos2++];
        }
        return;
    }
    // caso base 2: v2 no tiene ya elementos pero v1 sí
    if( pos1 < size1 && pos2 == size2 ){
        while( pos1 < size1 ){
            resultadoCombinar[posResult++] = v1[pos1++];
        }
        return;
    }
    if( pos1 == size1 && pos2 == size2 ){
        return;
    }
    resultadoCombinar[posResult++] = v1[pos1++];
    resultadoCombinar[posResult++] = v2[pos2++];
    combinarVectores( pos1,
            pos2,
            v1,
            v2,
            size1,
            size2,
            posResult,
            resultadoCombinar );
}

unsigned long max( unsigned long n1, unsigned long n2 ){
    if( n1 > n2 )
        return n1;
    else
        return n2;
}

void combinarOrdenarIter( int *v1,
        int *v2,
        unsigned long size1,
        unsigned long size2,
        int *resultadoCombinar,
        unsigned long combinarSize ){
    int posResult = 0;
    for( int i = 0; i < max( size1, size2 ); i++ ){
        if( i < size1 && i < size2 ){
            if( v1[i] < v2[i] ){
                resultadoCombinar[posResult++] = v1[i];
                resultadoCombinar[posResult++] = v2[i];
            }else{
                resultadoCombinar[posResult++] = v2[i];
                resultadoCombinar[posResult++] = v1[i];
            }
        }else{
            if( i < size1 ){
                resultadoCombinar[posResult++] = v1[i];
            }
            if( i < size2 ){
                resultadoCombinar[posResult++] = v2[i];
            }
        }
    }
}


void combinarOrdenarRec( int pos1,
                       int pos2,
                       int *v1,
                       int *v2,
                       unsigned long size1,
                       unsigned long size2,
                       int posResult,
                       int *resultadoCombinar ){
    // caso base 1: v1 no tiene ya elementos pero v2 sí
    if( pos1 == size1 && pos2 < size2 ){
        while( pos2 < size2 ){
            resultadoCombinar[posResult++] = v2[pos2++];
        }
        return;
    }
    // caso base 2: v2 no tiene ya elementos pero v1 sí
    if( pos1 < size1 && pos2 == size2 ){
        while( pos1 < size1 ){
            resultadoCombinar[posResult++] = v1[pos1++];
        }
        return;
    }
    if( pos1 == size1 && pos2 == size2 ){
        return;
    }
    if( v1[pos1] < v2[pos2] ){
        resultadoCombinar[posResult++] = v1[pos1];
        resultadoCombinar[posResult++] = v2[pos2];
    }else{
        resultadoCombinar[posResult++] = v2[pos2];
        resultadoCombinar[posResult++] = v1[pos1];
    }
    pos1++;
    pos2++;
    combinarOrdenarRec( pos1,
            pos2,
            v1,
            v2,
            size1,
            size2,
            posResult,
            resultadoCombinar );
}

int main(int argc, char *argv[]){

    int opcion = 0;
    do{
        opcion = menu();

        switch( opcion ){
        case 1:
            imprimeVector( "v1", v1, SIZE1 );
            printf( "El producto de los elementos del vector es %ld\n",
                        productoElementos( v1, 0, SIZE1 ) );
            waitForIntro(NULL);
            break;
        case 2:
            int elegido = eligeNumeroVector( "v1", v1, SIZE1 );
            char numeroAsString[MAX_STRING];
            char resultado[MAX_STRING];
            sprintf( numeroAsString, "%d", elegido );
            memset( resultado, '\0', MAX_STRING );
            invertirCadena( 0, numeroAsString, strlen(numeroAsString), resultado );
            printf("El número invertido es: %s\n", resultado );
            waitForIntro(NULL);
            break;
        case 3:
            struct vectorData vd;
            eligeVector( &vd );
            imprimeVector( vd.vectorName, vd.vector, vd.size );
            int numPares = contarParesVector( 0, vd.vector, vd.size );
            printf("Cantidad de pares en el vector: %d\n", numPares );
            waitForIntro(NULL);
            break;
        case 4:
            int resultadoCombinar[SIZE1+SIZE2];
            for( int i = 0; i < SIZE1+SIZE2; i++){
                resultadoCombinar[i] = 0;
            }
            combinarVectores( 0, 0, v1, v2, SIZE1, SIZE2, 0, resultadoCombinar );
            imprimeVector( "combinado", resultadoCombinar, SIZE1+SIZE2 );
            waitForIntro(NULL);
            break;
        case 5:
            int resultadoCombinar2[SIZE1+SIZE2];
            combinarOrdenarIter( v1, v2, SIZE1, SIZE2, resultadoCombinar2, SIZE1+SIZE2 );
            imprimeVector( "combinado", resultadoCombinar2, SIZE1+SIZE2 );
            waitForIntro(NULL);
            break;
        case 6:
            int resultadoCombinar3[SIZE1+SIZE2];
            combinarOrdenarRec( 0, 0, v1, v2, SIZE1, SIZE2, 0, resultadoCombinar3 );
            imprimeVector( "combinado", resultadoCombinar3, SIZE1+SIZE2 );
            waitForIntro(NULL);
            break;        }
    }while( opcion != 0 );

    printf("gracias por usar nuestro programa\n");

    exit(0);

}


