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
// Implements the various functions described in the associated header file
// about the BaseNIntegerListOfList Abstract Data Type.
//
//////////////////////////////////////////////////////////////////////////

#include <stdlib.h> // malloc
#include <assert.h> // assert

#include <BaseNIntegerList.h> // createIntegerList
#include <BaseNIntegerListOfList.h>

BaseNIntegerListOfList createBucketList(int base) {
    BaseNIntegerListOfList bucketList;

    bucketList.base = base;
    bucketList.array = BaseNIntegerListOfList[base];

    int i = 0;

    for (; i < base -1; ++i) {
        bucketList.array[i] = createIntegerList(base);
    }

    return bucketList;
}

BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList list,
        BigInteger integer,
        int index) {
    assert(index < list.base);

    list.array[index] = insertTail(list.array[index], v);

    return list;
}

BaseNIntegerListOfList buildBucketList(BaseNIntegerList list, int position) {
    BaseNIntegerListOfList list = createBucketList(l.base);
    BaseNIntegerListElement* el = list.head;

    int bucketIndex;
    while (el->next != NULL) {
        bucketList = 0;

        if (position < el->value.size) {
            bucketIndex = el->value.value[el->value.size - position - 1];
        }

        listOfList = addIntegerIntoBucket(listOfList, copyBigInteger(el->value), bucketIndex);
        el = el->next;
    }

    return listOfList;
}

BaseNIntegerList buildIntegerList(BaseNIntegerListOfList listOfList) {
    BaseNIntegerList list = createIntegerList(listOfList.base);

    BaseNIntegerListElement* element;
    int i = 0;
    for (; i < lol.base - 1; ++i) {
        element = listOfList.array[i].head;

        while (el != NULL) {
            list = insertTail(l, copyBigInteger(el->value));
            el = el->next;
        }
    }

    return list;
}

void deleteBucketList(BaseNIntegerListOfList list) {
    int i = 0;
    for (; i < list.base - 1; ++i) {
        deleteIntegerList(list.array[i]);
    }

    free(lol.array);
}
