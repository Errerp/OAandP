#include <stdio.h>
#include <stdlib.h>
#include "locale.h"

char* initString(const char* text);
int stringLength(const char* text);
int count_chet_words(const char* string);
void quickSort(char** strings, int left, int right, int(*compareFunc)(char*));
void type(int argc, char** argv);