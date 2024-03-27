/*Erstellen Sie ein kleines Programm in C, welches die folgende Funktionalität besitzt:

- Es nimmt Benutzereingaben entgegen
- Wenn die Benutzereingabe eine Formel mit zwei Zahlen und einem Rechenoperator (Grundrechenarten +, -, *, /) ist,  wird das Ergebnis der daraus resultierenden Operation berechnet und ausgegeben
- Ansonsten wird eine Fehlermeldung ausgegeben
- Im Anschluss wartet es wieder auf Eingaben
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

float calculateResult(float zahl1, char op, float zahl2);

int main(void)
{
    bool beenden = false;
    char op[] = "+-*/";
    char operation, exit;
    float zahl1 = 0.0f, zahl2 = 0.0f, ergebnis;
    int size = 100;

    char *expression = (char *)malloc(size * sizeof(char)); // 100 * 1B
    if (expression == NULL)
    {
        printf("Der Speicher im Heap konnte nicht zugewiesen werden.\n");
        free(expression);
        return -1;
    }

    while (!beenden)
    {
        printf("Bitte gib deine Formel ein: ");
        fgets(expression, size, stdin);

        size_t len = strlen(expression);
        if (len > 0 && expression[len - 1] == '\n')
        {
            expression[len - 1] = '\0';
        }

        int isParsed = sscanf(expression, "%f %c %f", &zahl1, &operation, &zahl2);
        if (isParsed != 3 || strchr(op, operation) == NULL)
        {
            printf("Bitte machen Sie eine gueltige Eingabe!\n");
            return -1;
        }

        ergebnis = calculateResult(zahl1, operation, zahl2);
        printf("Das Ergebnis betraegt: %f\n", ergebnis);

        printf("Moechten Sie das program beenden? J/n: ");
        (void)scanf(" %c", &exit);
        while ((getchar()) != '\n');

        if (exit == 'J' || exit == 'j')
        {
            beenden = true;
        }
    }

    free(expression);
    return 0;
}

float calculateResult(float zahl1, char op, float zahl2)
{
    float result = 0.0f;

    switch (op)
    {
    case '+':
        result = zahl1 + zahl2;
        break;
    case '-':
        result = zahl1 - zahl2;
        break;
    case '*':
        result = zahl1 * zahl2;
        break;
    case '/':
        if (zahl2 == 0)
        {
            printf("Division durch null ist nicht erlaubt.\n");
            return NAN;
        }
        result = zahl1 / zahl2;
        break;

    default:
        break;
    }

    return result;
}
