#include <stdio.h>
#include <stdbool.h>

void subtract(int num1, int num2) {
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
}

void add(int num1, int num2) {
    printf("%d + %d = %d\n", num1, num2, num1 + num2);
}

void multiply(int num1, int num2) {
    printf("%d * %d = %d\n", num1, num2, num1 * num2);
}

void divide(int num1, int num2) {
    if (num2 != 0) {
        printf("%d / %d = %.2f\n", num1, num2, (float)num1 / num2);
    } else {
        printf("Error: It is not possible to divide by zero.\n");
    }
}

void menu() {
    printf("\nSelect an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
}

void title(const char* msg) {
    printf("===============================\n");
    printf("\t%s\n", msg);
    printf("===============================\n");
}

int main() {
    bool continueCalc = true;

    while (continueCalc) {
        int number1, number2;
        char operator;

        title("C Calculator");
        menu();

        scanf(" %c", &operator);

        if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '5') {
            printf("Error: Enter a valid operator!\n");
            continue;
        }

        if (operator == '5') {
            printf("See you later, maybe!\n");
            break;
        }

        printf("Enter the first number:\n");
        scanf("%d", &number1);

        printf("Enter the second number:\n");
        scanf("%d", &number2);

        switch (operator) {
            case '+':
                add(number1, number2);
                break;
            case '-':
                subtract(number1, number2);
                break;
            case '*':
                multiply(number1, number2);
                break;
            case '/':
                divide(number1, number2);
                break;
            default:
                printf("Error: Invalid operator!\n");
                break;
        }

        char answer;
        printf("Do you want to calculate again? (y/n):\n");
        scanf(" %c", &answer);

        if (answer == 'y' || answer == 'Y') {
            continueCalc = true;
        } else {
            continueCalc = false;
            printf("See you later, maybe!\n");
        }
    }

    return 0;
}
