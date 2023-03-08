#include "func.h"

int main(int argc, char **argv) {
    if(argv[1] == NULL){
        printf("\nFilename not found\n");
        return 0;
    }

    char* filename = argv[1];
    int t = 0;

    FILE* f;
    fopen_s(&f, filename, "wt+");

    printf("Fill file: \n");
    fill_file(f);

    while(t != 2) {
        int choose;
        printf("\n1.Use the keyboard to fill in the file with words.");
        printf("\n2.Find words in the file whose length is equal to the number entered from the keyboard.");
        printf("\n3.Make a reverse of all words with a length greater than the specified one.");
        printf("\nChoose task: ");
        choose = input(1, 3);

        if (choose == 1) {
            task1(f);
        }
        else if (choose == 2) {
            task2(f);
        }
        else{
            task3(f);
        }

        printf("\n\nChoose another task?\n1.Yes\n2.No\n");
        t = input(1,2);
    }

    fclose(f);
    return 0;
}