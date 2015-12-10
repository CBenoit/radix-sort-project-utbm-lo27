/////////////////////////////////////////////////////////////////////////
//
// Radix Sort LO27 Project for the UTBM.
// Creation date: November 2015
// Copyright (C) 2015 CORTIER Benoît (benoit.cortier@gmail.com), BOULMIER Jérôme (jerome.boulmier@outlook.fr)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
//////////////////////////////////////////////////////////////////////////
//
// Header file that contains the prototype of the functions, types,
// constants and variables provided for implementing the
// BaseNIntegerList Abstract Data Type.
//
//////////////////////////////////////////////////////////////////////////

#ifndef BASE_NINTEGER_LIST_H
#define BASE_NINTEGER_LIST_H

#include <stdbool.h> // bool

typedef struct {
    char* value;
    int size;
} BigInteger;

typedef struct BaseNIntegerListElement {
    struct BaseNIntegerListElement* prev;
    struct BaseNIntegerListElement* next;

    BigInteger value;

} BaseNIntegerListElement;

typedef struct {
    BaseNIntegerListElement* head;
    BaseNIntegerListElement* tail;
    int size;

    int base;

} BaseNIntegerList;

/**
 * @brief Creates a BaseNIntegerList.
 * @details Creates a new empty BaseNIntegerList for storing integers in the specified base and initialize the fields.
 *
 * @param base : The base of the numbers.
 * @return A new empty list.
 */
BaseNIntegerList createIntegerList(int base);

/**
 * @brief Tests if the list is empty
 * @details Returns true if the specified list is empty, false otherwise.
 *
 * @param list : The list to test.
 * @return true if the list is empty.
 */
bool isEmpty(BaseNIntegerList list);

/**
 * @brief Inserts the value at the beginning of the list.
 * @details Adds the specified integer (char*) represented in the considered base at the end of the specified list.
 *
 * @param list : The list in which insert the value.
 * @param number : A number in the same base than BaseNIntegerList.
 * @return The list modified, with the value at the beginning.
 */
BaseNIntegerList insertHead(BaseNIntegerList list, BigInteger number);

/**
 * @brief Inserts the value at the end of the list.
 * @details Adds the specified integer (char*), represented in the considered base at the end of the specified list.
 *
 * @param list : The list in which insert the value.
 * @param number : A number in the same base than BaseIntegerList.
 * @return The list modified, with the value at the end.
 */
BaseNIntegerList insertTail(BaseNIntegerList list, BigInteger number);

/**
 * @brief Removes the head.
 * @details Removes the first element of the specified list
 *
 * @param list : The list in which remove the head.
 * @return The list modified, without the head.
 */
BaseNIntegerList removeHead(BaseNIntegerList list);

/**
 * @brief Removes the tail.
 * @details Removes the last element of the specified list.
 *
 * @param list : The list in which remove the tail.
 * @return The list modified, without the tail.
 */
BaseNIntegerList removeTail(BaseNIntegerList list);

/**
 * @brief Delete the given integer
 *
 * @param integer : The integer to delete
 */
void deleteBigInteger(BigInteger* integer);
/**
 * @brief Delete the given element.
 * @details Delete the element after having delete the value.
 *
 * @param element : The element to delete.
 */
void deleteBaseNIntegerListElement(BaseNIntegerListElement* element);

#endif // BASE_NINTEGER_LIST_H
