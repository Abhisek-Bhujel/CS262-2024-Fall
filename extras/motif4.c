#include <stdio.h>

int main() {
    char letters[] = {'A', 'C', 'G', 'T'};
    int n = 4; // number of letters
    int count = 0;
    // Loop through each position in the 4-letter combination
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    printf("%c%c%c%c\n", letters[i], letters[j], letters[k], letters[l]);
                    count++;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}
