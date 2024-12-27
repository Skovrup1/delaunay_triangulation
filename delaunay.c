#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("points.txt", "r");

    fseek(file, 0, SEEK_END);

    size_t file_size = ftell(file);
    printf("file size = %zu\n", file_size);

    fseek(file, 0, 0);

    char *file_buf = malloc(file_size * sizeof(char));

    fread(file_buf, sizeof(char), file_size, file);

    uint32_t n = 1000;
    double val_buf[n];

    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t start = 0;
    while (i < file_size) {
        switch (file_buf[i]) {
        case '\n':
        case ' ':
            start = i + 1;
            break;
        case '.':
        case 'e':
        case '-':
        case '0' ... '9':
            if (file_buf[i + 1] == ' ' || file_buf[i + 1] == '\n') {
                val_buf[j++] = strtod(file_buf + start, NULL);
            }
            break;
        }
        i++;
    }

    // brute_force_delaunay(val_buf, n);

    return 0;
}
