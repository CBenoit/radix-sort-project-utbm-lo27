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
 * about the BigInteger Data Type.
 *
 ***********************************************************************/

#include <stdio.h> /* printf */
#include <stdlib.h> /* NULL, malloc */
#include <string.h> /* memcpy */

#include <BigInteger.h>

BigInteger createBigInteger(char* value, int size) {
    BigInteger integer;
    integer.value = value;
    integer.size = size;

    return integer;
}

BigInteger copyBigInteger(BigInteger intToCopy) {
    char* value = (char*)malloc(intToCopy.size * sizeof(char));
    memcpy(value, intToCopy.value, intToCopy.size * sizeof(char));
    return createBigInteger(value, intToCopy.size);
}

void deleteBigInteger(BigInteger* value) {
    free(value->value);
    value->value = NULL;
}

char* BigIntegerToStr(BigInteger integer) {
    int i;
    int iToSTab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char* str = (char*)malloc(sizeof(char) * (integer.size + 1));

    for (i = 0; i < integer.size; ++i) {
        str[i] = iToSTab[(int) integer.value[i]]; /* cast to suppress "array subscript has type 'char' warning. */
    }
    str[integer.size] = '\0';

    return str;
}

void printBigInteger(const char* message, BigInteger integer) {
    char* str = BigIntegerToStr(integer);

    printf(message, str);

    free(str);
}

