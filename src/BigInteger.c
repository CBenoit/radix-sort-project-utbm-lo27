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
#include <math.h> /* log10 */

#include <utils.h> /* fmaxi */

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

/* "Private" function */
unsigned int convertBigIntegerIntoNumber(BigInteger n) {
    unsigned int i, k = 0;
    for (i = 0; i < n.size; i++) {
        k = 10 * k + n.value[i];
    }

    return k;
}

BigInteger convertNumberIntoBigInteger(unsigned int number) {
    unsigned int length;
    char* array;
    int i;

    if (number == 0) {
        length = 1;
    } else {
        length = (int)(log10((float)number)) + 1;
    }

    array = (char*)malloc(sizeof(char)*length);
    i = length - 1;

    do {
        array[i] = number % 10;
        number /= 10;
        --i;
    } while (number);

    return createBigInteger(array, length);
}

BigInteger baseNToDecimal(BigInteger n, int base) {
    char* number = (char*)malloc(sizeof(char));
    BigInteger decimalNumber, temp, temp2;
    int i = 0;

    if (base == 10) {
        free(number);
        return n;
    }

    number[0] = 0;
    decimalNumber = createBigInteger(number, 1);

    while (i < n.size) {
        temp = convertNumberIntoBigInteger(n.value[i]*pow(base, n.size - i - 1));
        temp2 = sumBaseNIntegers(temp, decimalNumber, 10);

        deleteBigInteger(&decimalNumber);
        deleteBigInteger(&temp);

        decimalNumber = temp2;

        ++i;
    }

    return decimalNumber;
}

BigInteger decimalToBaseN(BigInteger integer, int base) {
    char* array;
    unsigned int value = convertBigIntegerIntoNumber(integer);
    int arraySize = 1, k = base, i;

    while (value >= k) {
        k = base * k;
        ++arraySize;
    }
    array = (char*)malloc(sizeof(char)*arraySize);
    i = arraySize - 1;

    do {
        array[i] = value % base;
        value /= base;

        --i;
    } while (i >= 0);

    return createBigInteger(array, arraySize);
}

BigInteger convertBaseToBinary(BigInteger n, int base) {
    BigInteger temp = baseNToDecimal(n, base), temp2;

    temp2 = decimalToBaseN(temp, 2);

    deleteBigInteger(&temp);

    return temp2;
}

BigInteger convertBinaryToBase(BigInteger n, int base) {
    BigInteger temp = baseNToDecimal(n, 2), temp2;

    temp2 = decimalToBaseN(temp, base);
    deleteBigInteger(&temp);

    return temp2;
}

BigInteger sumBaseNIntegers(BigInteger a, BigInteger b, int base) {
    int sizeA = a.size;
    int sizeB = b.size;
    int sizeC = fmaxi(sizeA, sizeB);

    char* array = (char*)malloc(sizeof(char) * sizeC);
    int remainder = 0;
    int i = sizeA - 1;
    int j = sizeB - 1;
    int k = sizeC - 1;

    while (i >= 0 && j >= 0) {
        array[k] = a.value[i] + b.value[j] + remainder;
        remainder = array[k] / base;
        array[k] = array[k] % base;

        --i;
        --j;
        --k;
    }

    while (i >= 0) {
        array[k] = a.value[i] + remainder;
        remainder = array[k] / base;
        array[k] = array[k] % base;

        --i;
        --k;
    }

    while (j >= 0) {
        array[k] = b.value[j] + remainder;
        remainder = array[k] / base;
        array[k] = array[k] % base;

        --j;
        --k;
    }

    if (remainder > 0) {
        char* tempArray;
        sizeC++;

        tempArray = (char*)malloc(sizeof(char)*sizeC);
        tempArray[0] = remainder;
        memcpy(tempArray + 1, array, (sizeC - 1) * sizeof(char));

        free(array);
        array = tempArray;
    }

    return createBigInteger(array, sizeC);
}
