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

        for (int i = 0; expression[i] != '\0'; i++)
        {
            if (expression[i] == ' ')
            {
                continue;
            }

            if (expression[0] >= 48 && expression[0] <= 57)
            {
                zahl1 = (float)(expression[0] - '0'); // e.g. '2'--> 50 - 48 = 2
            }
            else if (expression[3] >= 48 && expression[3] <= 57)
            {
                zahl2 = (float)(expression[0] - '0');
            }
            else
            {
                if (expression[1] == op[i])
                {
                    operation = expression[1];
                }
            }
        }
        ergebnis = calculateResult(zahl1, operation, zahl2);
        printf("Das ergebnis betraegt: %.2f\n", ergebnis);

        printf("Moechten Sie das program beenden? J/n: ");
        (void)scanf(" %c", &exit);

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
