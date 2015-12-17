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

#ifndef BASE_NINTEGER_LIST_H
#define BASE_NINTEGER_LIST_H

/**
 * @file BaseNIntegerList.h
 * @brief Defines functions associated to BaseNIntegerList.
 *
 * @author Jérôme BOULMIER
 * @author Benoît CORTIER
 * @version 0.1
 *
 * Header file that contains the prototype of the functions, types,
 * constants and variables provided for implementing the
 * BaseNIntegerList Abstract Data Type.
 */

#include <stdbool.h> /* bool */

/**
 * @struct BaseNIntegerListElement
 * @brief Defines an element of the list.
 *
 * This structure defines an element of the linked list BaseNIntegerList.
 *
 */
typedef struct BaseNIntegerListElement {
    struct BaseNIntegerListElement* prev; /*!< Previous element in the List. */
    struct BaseNIntegerListElement* next; /*!< Next element in the List. */

    BigInteger value; /*!< Value of this element. */

} BaseNIntegerListElement;

/**
 * @struct BaseNIntegerList
 * @brief Defines a list of BigInteger in a base N.
 *
 * A BaseNIntegerList is a linked list of BigInteger.
 * The integers' base should be inferior or equal to 16.
 *
 */
typedef struct {
    BaseNIntegerListElement* head; /*!< The head of the list. */
    BaseNIntegerListElement* tail; /*!< The tail of the list. */
    int size; /*!< Size of the list. */

    int base; /*!< integers' base in this list. base ≤ 16 */

} BaseNIntegerList;

/**
 * @brief Creates a BigInteger.
 * @details Creates a new BigInteger of the given size containing the given value.
 *
 * @param value pointer to the char* representing the value.
 * @param size integer, the number of digits of the value.
 *
 * @return A new BigInteger.
 */
BigInteger createBigInteger(char* value, int size);

/**
 * @brief Copy a BigInteger.
 * @details Creates a new BigInteger identical to the given one.
 *
 * @param intToCopy BigInteger to copy.
 *
 * @return A copy of the BigInteger.
 */
BigInteger copyBigInteger(BigInteger intToCopy);

/**
 * @brief Creates a BaseNIntegerList.
 * @details Creates a new empty BaseNIntegerList for storing integers in the specified base and initialize the fields.
 *
 * @param base numbers' base.
 * @return A new empty list.
 */
BaseNIntegerList createIntegerList(int base);

/**
 * @brief Tests if the list is empty
 * @details Returns true if the specified list is empty, false otherwise.
 *
 * @param list list to test.
 * @return true if the list is empty.
 */
bool isEmpty(BaseNIntegerList list);

/**
 * @brief Inserts the value at the beginning of the list.
 * @details Adds the specified integer (char*) represented in the considered base at the end of the specified list.
 *
 * @param list list in which insert the value.
 * @param number a number in the same base than BaseNIntegerList.
 * @return The list modified, with the value at the beginning.
 */
BaseNIntegerList insertHead(BaseNIntegerList list, BigInteger number);

/**
 * @brief Inserts the value at the end of the list.
 * @details Adds the specified integer (char*), represented in the considered base at the end of the specified list.
 *
 * @param list list in which insert the value.
 * @param number a number in the same base than BaseIntegerList.
 * @return The list modified, with the value at the end.
 */
BaseNIntegerList insertTail(BaseNIntegerList list, BigInteger number);

/**
 * @brief Removes the head.
 * @details Removes the first element of the specified list
 *
 * @param list list in which remove the head.
 * @return The list modified, without the head.
 */
BaseNIntegerList removeHead(BaseNIntegerList list);

/**
 * @brief Removes the tail.
 * @details Removes the last element of the specified list.
 *
 * @param list list in which remove the tail.
 * @return The list modified, without the tail.
 */
BaseNIntegerList removeTail(BaseNIntegerList list);

/**
 * @brief Deletes the given integer
 *
 * @param integer integer to delete
 */
void deleteBigInteger(BigInteger* integer);
/**
 * @brief Deletes the given element.
 * @details Deletes the element after having deletes the value.
 *
 * @param element element to delete.
 */
void deleteBaseNIntegerListElement(BaseNIntegerListElement* element);

/**
 * @fn BigInteger sumBaseNIntegers(BigInteger a, BigInteger b, int base)
 * @brief Sums two integers
 * @details Sums two integers, they should be in the same base.
 *
 * @param a a BigInteger in the base @p baseN
 * @param b a BigInteger in the base @p baseN
 * @param baseN integer's base.
 * @return A BigInteger containing the result.
 */
BigInteger sumBaseNIntegers(BigInteger a, BigInteger b, int baseN);

/**
 * @fn BigInteger sumIntegerList(BaseNIntegerList list)
 * @brief Sums all numbers in a list
 * @details Sums all the integers defined in the specified list using
 * the binary addition and returns
 * the corresponding results as an integer (BigInteger)
 * represented in the base of the list.
 *
 * @param list list to sum.
 * @return The result of the sum represented in the base of the list.
 */
BigInteger sumIntegerList(BaseNIntegerList list);

#endif
