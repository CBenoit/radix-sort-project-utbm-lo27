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
 * about the BaseNIntegerListOfList Abstract Data Type.
 *
 ***********************************************************************/

#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */

#include <utils.h> /* fmaxi */

#include <BigInteger.h> /* BigInteger, copyBigInteger */
#include <BaseNIntegerList.h> /* BaseNIntegerListElement, BaseNIntegerList, createIntegerList */
#include <BaseNIntegerListOfList.h>

BaseNIntegerListOfList createBucketList(int base) {
    int i;
    BaseNIntegerListOfList bucketList;

    bucketList.base = base;
    bucketList.array = (BaseNIntegerList*)malloc(sizeof(BaseNIntegerList) * base);

    for (i = 0; i < base; ++i) {
        bucketList.array[i] = createIntegerList(base);
    }

    return bucketList;
}

BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList list,
        BigInteger integer,
        int index) {
    assert(index < list.base);

    list.array[index] = insertTail(list.array[index], integer);

    return list;
}

BaseNIntegerListOfList buildBucketList(BaseNIntegerList list, int position) {
    BaseNIntegerListOfList listOfList = createBucketList(list.base);
    BaseNIntegerListElement* element = list.head;
    int bucketIndex;

    while (element != NULL) {
        bucketIndex = 0;

        if (position < element->value.size) {
            bucketIndex = element->value.value[element->value.size - position - 1];
        }

        listOfList = addIntegerIntoBucket(listOfList, element->value, bucketIndex);
        element = element->next;
    }

    return listOfList;
}

BaseNIntegerList buildIntegerList(BaseNIntegerListOfList listOfList) {
    BaseNIntegerList list = createIntegerList(listOfList.base);

    BaseNIntegerListElement* element;
    int i = 0;
    for (; i < listOfList.base; ++i) {
        element = listOfList.array[i].head;

        while (element != NULL) {
            list = insertTail(list, element->value);
            element = element->next;
        }
    }

    return list;
}

void deleteBucketList(BaseNIntegerListOfList* list) {
    int i = 0;
    for (; i < list->base; ++i) {
        deleteBaseNIntegerList(&(list->array[i]));
    }

    free(list->array);
}

BaseNIntegerList copyList(BaseNIntegerList list) {
    BaseNIntegerList newList = createIntegerList(list.base);
    BaseNIntegerListElement* elem = list.head;

    while (elem != NULL) {
        newList = insertTail(newList, copyBigInteger(elem->value));

        elem = elem->next;
    }

    return newList;
}

BaseNIntegerList radixSort(BaseNIntegerList list) {
    int maxIterations = 0, i;
    BaseNIntegerListElement* element = list.head;
    BaseNIntegerListOfList bucketList;

    list = copyList(list);

    while (element != NULL) {
        maxIterations = fmaxi(maxIterations, element->value.size - 1);
        element = element->next;
    }

    ++maxIterations;

    for (i = 0; i < maxIterations; ++i) {
        bucketList = buildBucketList(list, i);
        deleteBaseNIntegerList(&list);

        list = buildIntegerList(bucketList);
        deleteBucketList(&bucketList);
    }

    return list;
}
