#include "func.h"

int main() {
    FILE *inp;
    fopen_s(&inp, "input.txt", "r");
    if (inp == NULL) {
        return 0;
    }
    FILE *out;
    fopen_s(&out, "output.txt", "w");
    if (out == NULL) {
        return 0;
    }
    char tmp[100];
    while (fgets(tmp, 100, inp)) {
        int pos = find_error(tmp);
        if (pos != -1) {
            char posC[100];
            snprintf(posC, 100, "%d", pos);
            fputs("Error in position: ", out);
            fputs(posC, out);
            fputs("\n", out);
        } else {
            char result[10];
            snprintf(result, 10, "%f", decision(tmp));
            fputs("Result: ", out);
            fputs(result, out);
        }
    }
    fclose(inp);
    fclose(out);
    return 0;
}