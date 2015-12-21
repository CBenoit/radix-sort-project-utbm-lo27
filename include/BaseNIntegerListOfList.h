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

#ifndef BASE_NINTEGER_LIST_OF_LIST_H
#define BASE_NINTEGER_LIST_OF_LIST_H

/**
 * @file BaseNIntegerListOfList.h
 * @brief Defines functions associated to BaseNIntegerListOfList.
 *
 * @author Jérôme BOULMIER
 * @author Benoît CORTIER
 * @version 0.1
 *
 * Header file that contains the prototype of the functions, types,
 * constants and variables provided for implementing the
 * BaseNIntegerListOfList Abstract Data Type.
 *
 */

 /**
 * @struct BaseNIntegerListOfList
 *
 * This structure defines a list of BaseNIntegerList
 * implemented using a continuous approach.
 */
typedef struct {
    int base; /*!< integers' base in this list. base <= 16 */
    BaseNIntegerList* array; /*!< an array of list */
} BaseNIntegerListOfList;

/**
 * @brief Creates a BaseNIntegerListOfList
 * @details Creates a BaseNIntegerListOfList for storing list of integers in base N.
 *
 * @param base list's base.
 * @return An empty list of list.
 */
BaseNIntegerListOfList createBucketList(int base);

/**
 * @brief Adds an integer into the list.
 * @details Adds a new integer (BigInteger) at the end of the specified list in bucket index.
 *
 * @param list list in which insert the integer.
 * @param integer integer to insert.
 * @param index index of the bucket between 0 and base of the list.
 * @return The list with the new integer.
 */
BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList list, BigInteger integer, int index);

/**
 * @brief Builds a bucketList.
 * @details Buils a new BaseNIntegerListOfList
 * according to the specified BaseNIntegerList and considering the specfied digit position.
 *
 * @param list list used to build the bucket list.
 * @param position position of the digit.
 *
 * @return A BaseNIntegerListOfList.
 */
BaseNIntegerListOfList buildBucketList(BaseNIntegerList list, int position);

/**
 * @brief Builds an integer's list.
 * @details Builds a new integer's list from the specified list of list.
 * (respecting the ascending order on the buckets)
 *
 * @param list list used to build the integer's list.
 * @return A BaseNIntegerList.
 */
BaseNIntegerList buildIntegerList(BaseNIntegerListOfList list);

/**
 * @brief Deletes the specified BaseNIntegerListOfList.
 * @details free the previously allocated memory.
 *
 * @param list list to delete.
 */
void deleteBucketList(BaseNIntegerListOfList* list);

/**
 * @brief Sorts an integer's list.
 * @details Sort the specified BaseNIntegerList using radix sort.
 *
 * @param list list to sort.
 * @return The given list sorted.
 */
BaseNIntegerList radixSort(BaseNIntegerList list);

#endif
