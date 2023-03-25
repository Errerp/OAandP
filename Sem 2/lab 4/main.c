#include "func.h"

int main() {
    int task;
    while(1){

        int len = 0;
        Shapes* arr = malloc(sizeof(Shapes));
        menu(&arr, &len);

        free(arr);
        
        printf("Do u wanna repeat task?\n1.Yes\n2.No\n");
        input(&task, 1,2);
        if(task == 2)
            return 0;
    }
}
