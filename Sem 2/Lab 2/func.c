#include "func.h"

int input(int min, int max){
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void fill_file(FILE** f){
    int i = 0;
    char *line = (char*)malloc(1);
    char temp;
    while((temp = getchar()) != '\n' && temp != EOF){
        line = (char*) realloc(line, (i + 1) * sizeof(char));
        line[i] = temp;
        i++;
    }
    line = (char*) realloc(line, (i + 1) * sizeof(char));
    line[i] = '\0';

    fwrite(line, sizeof(char), i + 1, f);
    fflush(f);

}

void read_file(FILE** f){
    rewind(f);

    char word = fgetc(f);
    while (!feof(f)){
        printf("%c", word);
        word = fgetc(f);
    }
    rewind(f);
}

void task1(FILE** f){
    printf("\n\nFile state: ");
    read_file(f);
}

void task2(FILE** f){
    printf("\n\nFile state: ");
    read_file(f);

    int k;
    printf("\n\nInput k: ");
    k = input(1, INT_MAX);

    int start = 0, end = 0,i = 0, s = - 1, e;
    char line = fgetc(f);
    char str = line;
    while (!feof(f)){
        if(i > s){
            if (letter(line) && !letter(str)) {
                start = i;
            }
            if (!letter(line) && letter(str)) {
                end = i - 1;
                s = start;
                e = end;
                start = 0, end = 0;
            }
       }
        i++;
        str = line;
        line = fgetc(f);
        if(e - s + 1  == k){
            printf("\nWord: ");
            rewind(f);
            int j = 0;
            char word = fgetc(f);
            while (!feof(f)){
                if(j >= s && j < e + 1) {
                    printf("%c", word);
                }
                j++;
                word = fgetc(f);
            }
            e = 0;
            rewind(f);
            line = fgetc(f);
            str = line;
            i = 0;
        }
    }
}

void task3(FILE** f){
    printf("\n\nTask not ready!");
    /*printf("\n\nFile state: ");
    read_file(f);

    int k;
    printf("\n\nInput k: ");
    k = input(1, INT_MAX);

    int start = 0, end = 0,i = 0, s = - 1, e;
    char line = fgetc(f);
    char str = line;
    while (!feof(f)){
        if(i > s){
            if (letter(line) && !letter(str)) {
                start = i;
            }
            if (!letter(line) && letter(str)) {
                end = i - 1;
                s = start;
                e = end;
                start = 0, end = 0;
            }
        }
        i++;
        str = line;
        line = fgetc(f);
        if(e - s + 1  > k){
            rewind(f);
            int j = 0;
            char word = fgetc(f);
            while (!feof(f)){
                if(j >= s && j < e + 1) {

                }
                j++;
                word = fgetc(f);
            }
            e = 0;
            rewind(f);
            line = fgetc(f);
            str = line;
            i = 0;
        }
    }*/
}
int letter(char line) {
    if ((line  >= 'a' && line <= 'z') || (line  >= 'A' && line <= 'Z'))
        return 1;
    return 0;
}
