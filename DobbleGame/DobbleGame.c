#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number or letter pair
char generatePair() {
    int choice = rand() % 2;  // 0 for number, 1 for letter
    if (choice == 0) {
        return '0' + rand() % 10;  // Random number between '0' and '9'
    } else {
        return 'A' + rand() % 26;  // Random uppercase letter
    }
}

// Function to create a Dobble-like card
void generateCard(char card[5][5]) {
    char usedPairs[25] = {0};  // To avoid duplicate pairs

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            char pair;
            do {
                pair = generatePair();
            } while (usedPairs[pair - '0']++);  // Mark the pair as used
            card[i][j] = pair;
        }
    }
}

// Function to display the Dobble-like card
void displayCard(char card[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%c ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the player found a matching pair
int isMatch(char card1[5][5], char card2[5][5], int row1, int col1, int row2, int col2) {
    return card1[row1][col1] == card2[row2][col2];
}

int main() {
    srand(time(NULL));  // Seed for random number generation

    char card1[5][5];
    char card2[5][5];

    generateCard(card1);
    generateCard(card2);

    printf("Card 1:\n");
    displayCard(card1);

    printf("\nCard 2:\n");
    displayCard(card2);

    int row1, col1, row2, col2;

    // Get player input for matching pair
    printf("\nEnter the row and column of the first pair (e.g., 1 3): ");
    scanf("%d %d", &row1, &col1);

    printf("Enter the row and column of the second pair (e.g., 2 4): ");
    scanf("%d %d", &row2, &col2);

    // Check if the input pairs match
    if (isMatch(card1, card2, row1, col1, row2, col2)) {
        printf("\nCongratulations! You found a matching pair!\n");
    } else {
        printf("\nOops! The pairs do not match.\n");
    }

    return 0;
}
