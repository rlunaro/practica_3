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

#include "entrada_salida.h"


int v1[] = {1, 12, 23, 28, 35};
int v2[] = {15, 25, 32, 70, 91};

#define SIZE_1 sizeof(v1)/sizeof(int)
#define SIZE_2 sizeof(v2)/sizeof(int)


int main(int argc, char *argv[]){
    printf("hello\n");
    printf( "%ld\n", SIZE_1 );
}


