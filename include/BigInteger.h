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

#ifndef LIB_BIG_INTEGER_H
#define LIB_BIG_INTEGER_H

/**
 * @file BigInteger.h
 * @brief Defines functions and structures associated to BigInteger.
 *
 * @author Jérôme BOULMIER
 * @author Benoît CORTIER
 * @version 0.1
 *
 * Header file that contains the prototype of the functions, types,
 * constants and variables provided for implementing the
 * BigInteger Data Type.
 */

/**
 * @struct BigInteger
 * @brief An unsigned integer coded using an array of char.
 *
 * In this structure, each digit of the number (in a base N) is stored in a single char
 * and put in an array of char (where a char is considered as an integer).
 * The size of the array is also stored in this structure.
 *
 */
typedef struct {
    char* value; /*!< Each digit is stored in a single char of this array */
    int size; /*!< The number of digit of the number */
} BigInteger;

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
 * @brief Deletes the given integer.
 *
 * @param integer integer to delete.
 */
void deleteBigInteger(BigInteger* integer);

/**
 * @brief Convert the given BigInteger into a displayable string.
 *
 * @param integer integer to convert.
 *
 * @return Pointer to the string.
 */
char* BigIntegerToStr(BigInteger integer);

/**
 * @brief Print a BigInteger.
 *
 * @param message message containing %s to display the BigInteger.
 * @param integer BigInteger to print.
 *
 */
void printBigInteger(const char* message, BigInteger integer);

/**
 * @brief Converts a number into a BigInteger
 *
 * @param number a number
 * @return A big integer.
 */
BigInteger convertNumberIntoBigInteger(unsigned int number);

/**
 * @brief Converts a number from base N to base 10.
 *
 * @param n a number
 * @param base number base.
 *
 * @return The number in base 10.
 */
BigInteger baseNToDecimal(BigInteger n, int base);

/**
 * @brief Converts a number from base 10 to base N. Works only with number <= 2^32 - 1
 *
 * @param integer - a big integer
 * @param base - base of the return.
 *
 * @return The number in the given base.
 */
BigInteger decimalToBaseN(BigInteger integer, int base);

/**
 * @brief Convert a number in binary. Works only with number <= 2^32 - 1
 *
 * @param n number to convert.
 * @param base number base.
 *
 * @return The number in binary.
 */
BigInteger convertBaseToBinary(BigInteger n, int base);

/**
 * @brief Converts the specified BigInteger represented
 * in binary into a corresponding BigInteger in the given base.
 *
 * @param n number to convert.
 * @param base base of the return.
 *
 * @return The number in the given base
 */
BigInteger convertBinaryToBase(BigInteger n, int base);

/**
 * @fn BigInteger sumBaseNIntegers(BigInteger a, BigInteger b, int base)
 * @brief Sums two integers
 * @details Sums two integers, they should be in the same base.
 *
 * @param a a BigInteger in the base @p baseN
 * @param b a BigInteger in the base @p baseN
 * @param base integer's base.
 * @return A BigInteger containing the result.
 */
BigInteger sumBaseNIntegers(BigInteger a, BigInteger b, int base);

#endif

