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
 * Implements the various functions described in the associated header file
 * about the menu functions.
 *
 ***********************************************************************/

#include <stdbool.h> /* bool */
#include <stdio.h> /* printf */
#include <stdlib.h> /* NULL, malloc, realloc, rand */
#include <string.h> /* strcmp */
#include <ctype.h> /* toupper, tolower */

#include <input.h>
#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>
#include <menu.h>

void enterNewList(BaseNIntegerList** lists, int* nbLists) {
    int ans = -1;
    int base, nbIntegers, maximumOfDigits;

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
        case 1:
            base = getNumber(2, 16, "What is the base of your list. (beetween 2 and 16)");
            nbIntegers = getMinNumber(1, "How many integers do you want in the list.");
            maximumOfDigits = getMinNumber(1, "Please enter the maximum number of digits of each element");
            ++(*nbLists);
            *lists = (BaseNIntegerList*)realloc(*lists, sizeof(BaseNIntegerList) * (*nbLists));
            (*lists)[*nbLists - 1] = generateRandomList(base, nbIntegers, maximumOfDigits);
            printBaseNIntegerList((*lists)[*nbLists - 1]);
            printf("This list is the list %d\n", *nbLists - 1);
            break;
        case 2:
            ++(*nbLists);
            *lists = (BaseNIntegerList*)realloc(*lists, sizeof(BaseNIntegerList) * (*nbLists));
            (*lists)[*nbLists - 1] = enterList();
            printf("This list is the list %d\n", *nbLists - 1);
            break;
        default:
            printf("Answer invalid.\n");
            pause();
            break;
        }
    }
}

void testBigIntegerFunctions() {
    int ans = -1;
    int base;
    BigInteger integer;
    BigInteger convertedInteger;

    while (ans != 0) {
        printf("========================\n");
        printf("= BigInteger functions =\n");
        printf("========================\n\n");

        printf("\t1. convertBaseToBinary\n");
        printf("\t2. convertBinaryToBase\n\n");

        printf("\t0. Back to main menu.\n");

        ans = getNumber(0, 2, "Choice ");

        switch (ans) {
        case 0:
            break;
        case 1:
            base = getNumber(2, 16, "What is the base of your number ? (beetween 2 and 16)");
            printf("Enter a base-%d number:\n", base);
            integer = enterBigInteger(base);
            convertedInteger = convertBaseToBinary(integer, base);
            printBigInteger("Binary representation: %s\n", convertedInteger);
            deleteBigInteger(&integer);
            deleteBigInteger(&convertedInteger);
            pause();
            break;
        case 2:
            printf("Enter a binary number:\n");
            integer = enterBigInteger(base);
            base = getNumber(2, 16, "What is the target base ? (beetween 2 and 16)");
            convertedInteger = convertBinaryToBase(integer, base);
            printf("Base-%d representation: ", base);
            printBigInteger("%s\n", convertedInteger);
            deleteBigInteger(&integer);
            deleteBigInteger(&convertedInteger);
            pause();
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
    char* number;
    bool isValid = false;

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
        case 1:
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                if (isEmpty(*ptrSelectedList)) {
                    printf("The list is empty.\n");
                } else {
                    printf("The list is not empty.\n");
                }
            }
            pause();
            break;
        case 2:
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                printf("The selected list is in base %d.\nPlease enter a number in the same base.\n>>> ", ptrSelectedList->base);
                do {
                    number = (char*)malloc(sizeof(char)*100);
                    getValidString("%99[0-9a-zA-Z]s%*[^\n]", number);
                    if (checkNumberBase(number, strlen(number), ptrSelectedList->base)) {
                        BigInteger integer;
                        char size = strlen(number);

                        number = convertToNumber(number, size);
                        integer = createBigInteger(number, size);
                        *ptrSelectedList = insertHead(*ptrSelectedList, integer);
                        isValid = true;
                    } else {
                        free (number);
                        number = NULL;
                        printf("Your number is invalid.\n>>> ");
                    }
                } while (!isValid);
                printf("insertHead function has been applied to the list.\n");
            }
            pause();
            break;
        case 3:
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                printf("The selected list is in base %d.\nPlease enter a number in the same base.\n>>> ", ptrSelectedList->base);
                do {
                    number = (char*)malloc(sizeof(char)*100);
                    getValidString("%99[0-9a-zA-Z]s%*[^\n]", number);
                    if (checkNumberBase(number, strlen(number), ptrSelectedList->base)) {
                        BigInteger integer;
                        char size = strlen(number);

                        number = convertToNumber(number, size);
                        integer = createBigInteger(number, size);
                        *ptrSelectedList = insertTail(*ptrSelectedList, integer);
                        isValid = true;
                    } else {
                        free (number);
                        number = NULL;
                        printf("Your number is invalid.\n>>> ");
                    }
                } while (!isValid);
                printf("insertTail function has been applied to the list.\n");
            }
            pause();
            break;
        case 4:
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                *ptrSelectedList = removeHead(*ptrSelectedList);
                printf("removeHead function has been applied to the list.\n");
            }
            pause();
            break;
        case 5:
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                *ptrSelectedList = removeTail(*ptrSelectedList);
                printf("removeTail function has been applied to the list.\n");
            }
            pause();
            break;
        case 6:
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                deleteBaseNIntegerList(ptrSelectedList);
                printf("deleteBaseNIntegerList function has been applied to the list.\n");
                --(*nbLists);
            }
            pause();
            break;
        case 7:
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                printBigInteger("The sum of the list is equal to: %s\n", sumIntegerList(*ptrSelectedList));
            }
            pause();
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

BaseNIntegerListOfList* selectListOfLists(BaseNIntegerListOfList** listsOfLists,
    int* nbListsofLists) {
    int ans;

    if (*nbListsofLists == 0) {
        printf("No list of lists has been created.\n");
        return NULL;
    } else if (*nbListsofLists == 1) {
        return &(*listsOfLists)[0];
    } else {
        printf("Select a list (0-%d).\n", *nbListsofLists - 1);
        ans = getNumber(0, *nbListsofLists - 1, "Choice ");
        return &(*listsOfLists)[ans];
    }
}

void testListOfListFunctions(BaseNIntegerListOfList** listsOfLists, int* nbListsOfLists,
    BaseNIntegerList** lists, int* nbLists) {
    BaseNIntegerList* ptrSelectedList = NULL;
    BaseNIntegerListOfList* ptrSelectedListOfLists = NULL;
    int ans = -1;

    while (ans != 0) {
        printf("====================================\n");
        printf("= BaseNIntegerListOfList functions =\n");
        printf("====================================\n\n");

        printf("\t1. buildBucketList\n");
        printf("\t2. addIntegerIntoBucket\n");
        printf("\t3. buildIntegerList\n");
        printf("\t4. deleteBucketList\n");
        printf("\t5. printBucketList\n");

        printf("\t0. Back to main menu.\n");

        ans = getNumber(0, 5, "Choice ");

        switch (ans) {
        case 0:
            break;
        case 1:
            ++(*nbListsOfLists);
            *listsOfLists = (BaseNIntegerListOfList*)realloc(*listsOfLists, sizeof(BaseNIntegerListOfList) * (*nbListsOfLists));
            ptrSelectedList = selectList(lists, nbLists);
            if (ptrSelectedList != NULL) {
                int position = getMinNumber(0, "Please enter the digit position used to build the bucket list.");
                (*listsOfLists)[*nbListsOfLists - 1] = buildBucketList(*ptrSelectedList, position);
            }
            pause();
            break;
        case 2:
            ptrSelectedListOfLists = selectListOfLists(listsOfLists, nbListsOfLists);
            if (ptrSelectedListOfLists != NULL) {
                bool isValid = false;
                char* number = NULL;
                int position = getMinNumber(0, "Please enter the digit position used to add the integer into the bucket list.");
                printf("The selected list is in base %d.\nPlease enter a number in the same base.\n>>> ", ptrSelectedListOfLists->base);
                do {
                    number = (char*)malloc(sizeof(char)*100);
                    getValidString("%99[0-9a-zA-Z]s%*[^\n]", number);
                    if (checkNumberBase(number, strlen(number), ptrSelectedListOfLists->base)) {
                        BigInteger integer;
                        char size = strlen(number);

                        number = convertToNumber(number, size);
                        integer = createBigInteger(number, size);
                        if (position < size) {
                            *ptrSelectedListOfLists = addIntegerIntoBucket(*ptrSelectedListOfLists, integer, position);
                        } else {
                            *ptrSelectedListOfLists = addIntegerIntoBucket(*ptrSelectedListOfLists, integer, 0);
                        }
                        isValid = true;
                    } else {
                        free (number);
                        number = NULL;
                        printf("Your number is invalid.\n>>> ");
                    }
                } while (!isValid);
            }
            pause();
            break;
        case 3:
            ptrSelectedListOfLists = selectListOfLists(listsOfLists, nbListsOfLists);
            if (ptrSelectedListOfLists != NULL) {
                ++(*nbLists);
                *lists = (BaseNIntegerList*)realloc(*lists, sizeof(BaseNIntegerList) * (*nbLists));
                (*lists)[*nbLists - 1] = buildIntegerList(*ptrSelectedListOfLists);
                printf("The new list is the list %d.\n", *nbLists - 1);
            }
            pause();
            break;
        case 4:
            ptrSelectedListOfLists = selectListOfLists(listsOfLists, nbListsOfLists);
            if (ptrSelectedListOfLists != NULL) {
                deleteBucketList(ptrSelectedListOfLists);
                printf("deleteBucketList function has been applied to the list.\n");
                --(*nbListsOfLists);
            }
            break;
        case 5:
            ptrSelectedListOfLists = selectListOfLists(listsOfLists, nbListsOfLists);
            if (ptrSelectedListOfLists != NULL) {
                printListOfList(*ptrSelectedListOfLists);
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

void performRadixSort(BaseNIntegerList** lists, int* nbLists) {
    BaseNIntegerList* ptrSelectedList;
    BaseNIntegerList sortedList;

    ptrSelectedList = selectList(lists, nbLists);
    if (ptrSelectedList != NULL) {
        sortedList = radixSort(*ptrSelectedList);
        printBaseNIntegerList(sortedList);
        deleteBaseNIntegerList(&sortedList);
    }

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
        ans = getNumber(0, *nbLists - 1, "Choice ");
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

BigInteger enterBigInteger(int base) {
    BigInteger integer;
    char* number = (char*)malloc(sizeof(char) * 100);

    bool valid = false;
    while (valid == false) {
        printf(">>> ");
        getValidString("%99[0-9a-zA-Z]s%*[^\n]", number);
        if (checkNumberBase(number, strlen(number), base)) {
            char size = strlen(number);

            number = convertToNumber(number, size);
            integer = createBigInteger(number, size);
            valid = true;
        } else {
            printf("Your number is invalid.\n");
        }
    }

    return integer;
}

BaseNIntegerList enterList() {
    BaseNIntegerList list;
    BigInteger integer;
    char* number;
    bool finished = false;

    int base = getNumber(2, 16, "What is the base of your list ? (beetween 2 and 16)");
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

BaseNIntegerList generateRandomList(int base, int nbIntegers, int maxDigits) {
    BaseNIntegerList list = createIntegerList(base);
    BigInteger integer;
    char* number;
    int i, j, nbDigits;

    for(i = 0; i < nbIntegers; ++i) {
        nbDigits = rand()%maxDigits + 1; /* avoid a number with 0 digit */
        number = (char*)malloc(nbDigits*sizeof(char));
        number[0] = (char)(rand()%(base - 1) + 1); /* avoid a number starting with 0 */


        for (j = 1; j < nbDigits; ++j) {
            number[j] = (char)(rand()%base);
        }

        integer = createBigInteger(number, nbDigits);
        list = insertTail(list, integer);
    }

    return list;
}

