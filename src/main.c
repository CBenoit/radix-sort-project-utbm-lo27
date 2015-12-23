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

void enterNewList(BaseNIntegerList* lists, int* nbLists);

BaseNIntegerList enterList();

void generateList(BaseNIntegerList* lists, int* nbLists);

void testListFunctions(BaseNIntegerList* lists, int* nbLists);

void testListOfListFunctions(BaseNIntegerList* lists, int* nbLists);

void performRadixSort(BaseNIntegerList* lists, int* nbLists);

int main(int argc, char *argv[])
{
    int ans = -1;
    int nbLists = 0;
    BaseNIntegerList lists;

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

bool checkNumberBase(char* number, int size, int base) {
    int i;
    for (i = 0; i < size; ++i) {
        if (toupper(number[i]) > (char)(base + '/')) {
            /* : ; < = > ? @ aren't checked because we assume that
            the number is a valid number in a base N. */
            return false;
        }
    }

    return true;
}

void enterNewList(BaseNIntegerList* lists, int* nbLists) {
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
            *lists = enterList();
            break;
        default:
            printf("Not yet implemented.\n");
            pause();
            break;
        }
    }
}

BaseNIntegerList enterList() {
    BaseNIntegerList list;
    BigInteger integer;
    char number[100];

    int base = getMinNumber(1, "What is the base of your list.");
    list = createIntegerList(base);

    printf("Enter 00 to end the input\n");
    /* "%99[0-9a-zA-Z]s%*c" */
    do {
        printf(">>> ");
        getValidString("%99[0-9a-zA-Z]s%*[^\n]", number);
        if (checkNumberBase(number, strlen(number), base)) {
            integer = createBigInteger(number, strlen(number));
            list = insertTail(list, integer);
        } else {
            printf("Your number is invalid.\n");
        }
    } while (strcmp(number, "00"));

    return list;
}

void testListFunctions(BaseNIntegerList* lists, int* nbLists) {
    int ans = -1;

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
        printf("\t7. sumIntegerList\n\n");

        printf("\t0. Back to main menu.\n");

        ans = getNumber(0, 7, "Choice ");

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

void testListOfListFunctions(BaseNIntegerList* lists, int* nbLists) {
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

void performRadixSort(BaseNIntegerList* lists, int* nbLists) {
    printf("Not yet implemented.\n");
    pause();
}

