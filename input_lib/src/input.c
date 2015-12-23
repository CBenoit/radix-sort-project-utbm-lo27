/*
* @Author: Jérôme BOULMIER
* @Date:   2015-04-28 13:11:43
* @Last Modified by:   Jérôme BOULMIER
* @Last Modified time: 2015-04-28 13:13:20
*/
#include <stdio.h> /* scanf, printf, EOF, fgets */
#include <stdbool.h> /* bool */
#include <string.h> /* strchr */
#include <ctype.h> /* toupper, tolower */

#include <input.h>

void clean_stdin()
{
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int getNumber(int min, int max, const char* message)
{
    int answer;
    bool numberOk = false;

    do
    {
        printf("%s\n>>> ", message);
        if (scanf("%d%*[^\n]", &answer) != 1)
        {
            printf("Invalid number.\n");
            clean_stdin();
        }
        else
        {
            getchar();
            if (answer >= min && answer <= max)
                numberOk = true;
        }

    } while (!numberOk);

    return answer;
}

int getMinNumber(int min, const char* message)
{
    int answer;
    bool numberOk = false;

    do
    {
        printf("%s\n>>> ", message);
        if (scanf("%d%*[^\n]", &answer) != 1)
        {
            printf("Invalid number.\n");
            clean_stdin();
        }
        else
        {
            getchar();
            if (answer >= min)
                numberOk = true;
        }

    } while (!numberOk);

    return answer;
}

char getCharacter(char c1, char c2, const char* message)
{
    char answer;

    do
    {
        printf("%s\n>>> ", message);

        answer = (char)getchar();
        clean_stdin();

        answer = (char)toupper((int)answer);

    } while (answer != c1 && answer != c2);

    return answer;
}

void getString(int length, char* answer, const char* message)
{
    char *endPosition;

    printf("%s\n>>> ", message);

    if(fgets(answer, length, stdin) != NULL)
    {
        endPosition = strchr(answer, '\n');
        if (endPosition != NULL)
        {
            *endPosition = '\0';
        }
    }
}

void pause()
{
    printf("Press any key to continue...\n");

    getchar();
}

void lower(char chaine[])
{
    size_t i = 0;

    while (chaine[i] != '\0')
    {
        chaine[i] = tolower(chaine[i]);
        ++i;
    }
}

void upper(char chaine[])
{
    size_t i = 0;

    while (chaine[i] != '\0')
    {
        chaine[i] = toupper(chaine[i]);
        ++i;
    }
}

