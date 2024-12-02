#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[100];  // Buffer to store the input string
    int firstDie, secondDie; // Variables to store the sides of the two dice
    int validInput; // Variable to track if the input is valid

    while (1) {
        // Prompt the user for input
        printf("Enter the number of sides for two dice (e.g., 3x3): ");
        fgets(buffer, sizeof(buffer), stdin); // Read the entire line

        // Use sscanf to extract the two integer values, ignoring the 'x' and whitespace
        validInput = sscanf(buffer, "%d x %d", &firstDie, &secondDie);
        
        // Check if validInput is successful and within the range [1, 5]
        if (validInput == 2 && firstDie >= 1 && firstDie <= 5 && secondDie >= 1 && secondDie <= 5) {
            // Valid input received
            break; // Exit the loop
        } else {
            // Invalid input; prompt again
            printf("Invalid input! Please enter valid dice sides in the format '# x #' (between 1 and 5).\n");
        }
    }

    // Now, firstDie and secondDie hold valid values
    printf("Dice sides: %d and %d\n", firstDie, secondDie);

    return 0;
}
