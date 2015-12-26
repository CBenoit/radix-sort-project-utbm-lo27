/************************************************************************
 *
 * Radix Sort LO27 Project for the UTBM.
 * Creation date: November 2015
 * Copyright (C) 2015 CORTIER Benoît (benoit.cortier@gmail.com), BOULMIER Jérôme (jerome.boulmier@outlook.fr)
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it freely,
 * subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 * you must not claim that you wrote the original software.
 * If you use this software in a product, an acknowledgment
 * in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such,
 * and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ***********************************************************************/
/************************************************************************
 *
 * A program to use the radix sort library.
 *
 ***********************************************************************/

#include <stdbool.h> /* bool */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strcmp */
#include <ctype.h> /* toupper, tolower */
#include <time.h> /* time */

#include <input.h>
#include <BaseNIntegerList.h>

bool checkNumberBase(char* number, int size, int base);

void enterNewList(BaseNIntegerList** lists, int* nbLists);

void generateList(BaseNIntegerList** lists, int* nbLists);

void testListFunctions(BaseNIntegerList** lists, int* nbLists);

void testListOfListFunctions(BaseNIntegerList** lists, int* nbLists);

void performRadixSort(BaseNIntegerList** lists, int* nbLists);

BaseNIntegerList* selectList(BaseNIntegerList** lists, int* nbLists);

bool checkNumberBase(char* number, int size, int base);

char* convertToNumber(char* number, int size);

BaseNIntegerList enterList();

int main(int argc, char *argv[]) {
    int ans = -1;
    int nbLists = 0;
    BaseNIntegerList* lists = NULL;

    /* initialize random seed: */
    srand(time(NULL));

    printf("~\t==================\t~\n");
    printf("~\tRadix Sort Project\t~\n");
    printf("~\t==================\t~\n\n\n");

    while (ans != 0) {
        printf("=============\n");
        printf("= Main menu =\n");
        printf("=============\n\n");

        printf("\t1. Enter a new list.\n");
        printf("\t2. Test BaseNIntegerList functions.\n");
        printf("\t3. Test BaseNIntegerListOfList functions.\n");
        printf("\t4. Perform radix sort.\n\n");

        printf("\t0. Exit.\n");

        ans = getNumber(0, 4, "Choice ");

        switch (ans) {
        case 1:
            enterNewList(&lists, &nbLists);
            break;
        case 2:
            testListFunctions(&lists, &nbLists);
            break;
        case 3:
            testListOfListFunctions(&lists, &nbLists);
            break;
        case 4:
            performRadixSort(&lists, &nbLists);
            break;
        default:
            break;
        }
    }

    return EXIT_SUCCESS;
}

void enterNewList(BaseNIntegerList** lists, int* nbLists) {
    int ans = -1;

    while (ans != 0) {
        printf("=================\n");
        printf("= New list menu =\n");
        printf("=================\n\n");

        printf("\t1. Generate (pseudo-)randomly.\n");
        printf("\t2. Enter manually.\n\n");

        printf("\t0. Back to main menu.\n");

        ans = getNumber(0, 2, "Choice ");

        switch (ans) {
        case 0:
            break;
        case 2:
            ++(*nbLists);
            *lists = (BaseNIntegerList*)realloc(*lists, sizeof(BaseNIntegerList) * (*nbLists));
            (*lists)[*nbLists - 1] = enterList();
            break;
        default:
            printf("Not yet implemented.\n");
            pause();
            break;
        }
    }
}

void testListFunctions(BaseNIntegerList** lists, int* nbLists) {
    int ans = -1;
    BaseNIntegerList* ptrSelectedList;

    while (ans != 0) {
        printf("==============================\n");
        printf("= BaseNIntegerList functions =\n");
        printf("==============================\n\n");

        printf("\t1. isEmpty\n");
        printf("\t2. insertHead\n");
        printf("\t3. insertTail\n");
        printf("\t4. removeHead\n");
        printf("\t5. removeTail\n");
        printf("\t6. deleteIntegerList\n");
        printf("\t7. sumIntegerList\n");
        printf("\t8. printBaseNIntegerList\n\n");

        printf("\t0. Back to main menu.\n");

        ans = getNumber(0, 8, "Choice ");

        switch (ans) {
        case 0:
            break;
        case 8:
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                printBaseNIntegerList(*ptrSelectedList);
            }

            pause();
            break;
        default:
            printf("Not yet implemented.\n");
            pause();
            break;
        }
    }
}

void testListOfListFunctions(BaseNIntegerList** lists, int* nbLists) {
    int ans = -1;

    while (ans != 0) {
        printf("====================================\n");
        printf("= BaseNIntegerListOfList functions =\n");
        printf("====================================\n\n");

        printf("\t1. createBucketList\n");
        printf("\t2. addIntegerIntoBucket\n");
        printf("\t3. buildBucketList\n");
        printf("\t4. buildIntegerList\n");
        printf("\t5. deleteBucketList\n");

        printf("\t0. Back to main menu.\n");

        ans = getNumber(0, 5, "Choice ");

        switch (ans) {
        case 0:
            break;
        default:
            printf("Not yet implemented.\n");
            pause();
            break;
        }
    }
}

void performRadixSort(BaseNIntegerList** lists, int* nbLists) {
    printf("Not yet implemented.\n");
    pause();
}

BaseNIntegerList* selectList(BaseNIntegerList** lists, int* nbLists) {
    int ans;

    if (*nbLists == 0) {
        printf("No list has been created.\n");
        return NULL;
    } else if (*nbLists == 1) {
        return &(*lists)[0];
    } else {
        printf("Select a list (0-%d).\n", *nbLists - 1);
        do {
            ans = getNumber(0, *nbLists - 1, "Choice ");
        } while (ans < 0 || ans >= *nbLists);

        return &(*lists)[ans];
    }
}

bool checkNumberBase(char* number, int size, int base) {
    int i;
    if (base < 10) {
        for (i = 0; i < size; ++i) {
            if (toupper(number[i]) > (char)(base + '/')) {
                return false;
            }
        }
    } else {
        for (i = 0; i < size; ++i) {
            if (toupper(number[i]) > (char)(base + '/' + 7)) {
                /* : ; < = > ? @ aren't checked because we assume that
                the number is a valid number in a base N. */
                return false;
            }
        }
    }

    return true;
}

char* convertToNumber(char* number, int size) {
    int i;
    char* newNumber = (char*)malloc(sizeof(char)*size);

    for (i = 0; i < size; ++i) {
        if (number[i] <= '9') {
            newNumber[i] = number[i] - '0';
        } else {
            newNumber[i] = number[i] - 'A' + 10;
        }
    }

    free(number);
    number = NULL;

    return newNumber;
}

BaseNIntegerList enterList() {
    BaseNIntegerList list;
    BigInteger integer;
    char* number;
    bool finished = false;

    int base = getMinNumber(1, "What is the base of your list.");
    list = createIntegerList(base);

    printf("Type 'end' to end the input.\n");
    /* "%99[0-9a-zA-Z]s%*c" */
    do {
        number = (char*)malloc(sizeof(char) * 100);
        printf(">>> ");
        getValidString("%99[0-9a-zA-Z]s%*[^\n]", number);
        if (strcmp(number, "end")) {
            if (checkNumberBase(number, strlen(number), base)) {
                char size = strlen(number);

                number = convertToNumber(number, size);
                integer = createBigInteger(number, size);
                list = insertTail(list, integer);
            } else {
                printf("Your number is invalid.\n");
            }

        } else {
            finished = true;
            free(number);
            number = NULL;
        }
    } while (finished == false);

    return list;
}

