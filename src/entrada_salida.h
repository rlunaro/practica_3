#pragma once

#ifndef ENTRADA_SALIDA_H
#define ENTRADA_SALIDA_H

char* leer_string(char* prompt, char* buffer, unsigned int size);

char leer_numero(char* prompt);

int leer_validar_numero(char* prompt, char *validos);

char leer_validar_char(char* prompt, char* validos);

#endif  // ENTRADA_SALIDA_H


