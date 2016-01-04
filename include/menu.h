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

#ifndef MENU_H
#define MENU_H

/**
 * @file menu.h
 * @brief Defines functions that handle the various menus in the main application.
 *
 * @author Jérôme BOULMIER
 * @author Benoît CORTIER
 * @version 0.1
 */

#include <stdbool.h> /* bool */

#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>

/**
 * @brief New list menu.
 *
 * @param lists pointer on an array of lists.
 * @param nbLists lists size.
 */
void enterNewList(BaseNIntegerList** lists, int* nbLists);

/**
 * @brief BigInteger functions menu.
 */
void testBigIntegerFunctions();

/**
 * @brief BaseNIntegerList functions menu.
 *
 * @param lists pointer on an array of lists.
 * @param nbLists lists size.
 */
void testListFunctions(BaseNIntegerList** lists, int* nbLists);

/**
 * @brief BaseNIntegerListOfList functions menu.
 *
 * @param listsOfLists pointer on an array of lists of lists.
 * @param nbListsOfList listsOfLists size.
 * @param lists pointer on an array of lists.
 * @param nbLists lists size.
 */
void testListOfListFunctions(BaseNIntegerListOfList** listsOfLists, int* nbListsOfList,
    BaseNIntegerList** lists, int* nbLists);

/**
 * @brief Performs Radix sort on a list.
 *
 * @param lists pointer on an array of lists.
 * @param nbLists lists size.
 */
void performRadixSort(BaseNIntegerList** lists, int* nbLists);

/**
 * @brief Asks user to select a list.
 *
 * @param lists pointer on an array of lists.
 * @param nbLists lists size.
 */
BaseNIntegerList* selectList(BaseNIntegerList** lists, int* nbLists);

/**
 * @brief Asks user to select a list of lists.
 *
 * @param listsOfLists pointer on an array of lists.
 * @param nbListsofLists listsOfLists size.
 */
BaseNIntegerListOfList* selectListOfLists(BaseNIntegerListOfList** listsOfLists,
    int* nbListsofLists);


/**
 * @brief Checks if a number is in the given base.
 *
 * @param number number to test.
 * @param size number size.
 * @param base base
 * @return true is the number is in the given base, false otherwise.
 */
bool checkNumberBase(char* number, int size, int base);

/**
 * @brief Converts a string into a number.
 *
 * @param number number to convert.
 * @param size number size.
 *
 * @return an array of digits.
 */
char* convertToNumber(char* number, int size);

/**
 * @brief Asks user to enter a list.
 *
 * @return The list entered by the user.
 */
BaseNIntegerList enterList();

/**
 * @brief Generate a random list in the given base.
 *
 * @param base numbers base.
 * @param nbIntegers numbers of integer to generate.
 * @param maxDigits max number of digits of each integer.
 * @return The list generated.
 */
BaseNIntegerList generateRandomList(int base, int nbIntegers, int maxDigits);

#endif

