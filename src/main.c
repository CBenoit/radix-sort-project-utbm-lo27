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

#include <stdio.h> /* printf */
#include <stdlib.h> /* srand, NULL, EXIT_SUCCESS */
#include <time.h> /* time */

#include <input.h>
#include <menu.h>
#include <BaseNIntegerList.h>

int main(int argc, char *argv[]) {
    int i, ans = -1, nbLists = 0, nbListsOfLists = 0;
    BaseNIntegerList* lists = NULL;
    BaseNIntegerListOfList* listsOfLists = NULL;

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
        printf("\t2. Test BigInteger functions.\n");
        printf("\t3. Test BaseNIntegerList functions.\n");
        printf("\t4. Test BaseNIntegerListOfList functions.\n");
        printf("\t5. Perform radix sort.\n\n");

        printf("\t0. Exit.\n");

        ans = getNumber(0, 5, "Choice ");

        switch (ans) {
        case 1:
            enterNewList(&lists, &nbLists);
            break;
        case 2:
            testBigIntegerFunctions(&lists, &nbLists);
            break;
        case 3:
            testListFunctions(&lists, &nbLists);
            break;
        case 4:
            testListOfListFunctions(&listsOfLists, &nbListsOfLists,
                &lists, &nbLists);
            break;
        case 5:
            performRadixSort(&lists, &nbLists);
            break;
        default:
            break;
        }
    }

    for (i = 0; i < nbLists; i++) {
        deleteBaseNIntegerList(&(lists[i]));
    }

    for (i = 0; i < nbListsOfLists; ++i) {
        deleteBucketList(&(listsOfLists[i]));
    }

    free(lists);
    free(listsOfLists);

    return EXIT_SUCCESS;
}

