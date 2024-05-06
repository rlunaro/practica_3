/*
 * entrada_salida.c - clases de entrada / salida
 * 
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
 //leer_string("text", supuesto_dni, MAX_DNI);
char* leer_string(char* prompt, char* buffer, unsigned int size) {
	printf("%s: ", prompt);
	return fgets(buffer, size, stdin);
}

int leer_numero(char* prompt) {
	char buffer[MAX_BUFFER];
	printf("%s: ", prompt);
	fgets(buffer, MAX_BUFFER, stdin);
	return atoi(buffer);
}
  //leer_validar_numero("\n\n Elija opción: ", "1, 2, 3, 4, 0");
int leer_validar_numero(char* prompt, char* validos) {
	char buffer[MAX_BUFFER];
	printf("%s: ", prompt);
	fgets(buffer, MAX_BUFFER, stdin);
	//comprueba si el imput está en la lista de admitidos con strstr
	while (strstr(validos, buffer) == NULL) {
		printf("Opción no válida. Opciones válidas son: %s\n", validos);
		printf("%s: ", prompt);
		fgets(buffer, MAX_BUFFER, stdin);
	}
	return atoi(buffer);
}

   //leer_validar_char("\n\n\t �Quieres seguir introduciendo socios? (Y/N)", "yYnN");
char leer_validar_char(char* prompt, char* validos) {
	char buffer[MAX_BUFFER];
	printf("%s: ", prompt);
	fgets(buffer, MAX_BUFFER, stdin);
	while (strstr(validos, buffer) == NULL) {
		printf("Opción no válida. Las opciones válidas son: %s\n", validos);
		printf("%s: ", prompt);
		fgets(buffer, MAX_BUFFER, stdin);
	}
	return buffer[0];
}


