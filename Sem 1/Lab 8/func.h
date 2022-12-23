#include <stdio.h>
#include <stdlib.h>
#include "locale.h"

int count_chet_words(const char* string);
void quick_sort(char** strings, int left, int right, int(*compareFunc)(char*));
void type(int argc, char** argv);