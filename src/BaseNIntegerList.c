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
// about the BaseNIntegerList Abstract Data Type.
//
//////////////////////////////////////////////////////////////////////////

#include <stdlib.h> // NULL, malloc
#include <stdbool.h> // bool

#include <BaseNIntegerList.h>

BigInteger createBigInteger(char* value, int size) {
    BigInteger integer;
    integer.value = value;
    integer.size = size;

    return integer;
}

BaseNIntegerList createIntegerList(int base) {
    BaseNIntegerList list;

    list.head = NULL;
    list.tail = NULL;
    list.base = base;
    list.size = 0;

    return list;
}

bool isEmpty(BaseNIntegerList list) {
    return list.head == NULL;
}

BaseNIntegerList insertHead(BaseNIntegerList list, BigInteger number) {
    BaseNIntegerListElement* element = (BaseNIntegerListElement*)malloc(sizeof(BaseNIntegerListElement));

    element->value = number;

    element->prev = NULL;

    if (isEmpty(list)) {
        element->next = NULL;
        list.tail = element;
    } else {
        element->next = list.head;
        list.head->prev = element;
    }

    list.head = element;
    list.size += 1;

    return list;
}

BaseNIntegerList insertTail(BaseNIntegerList list, BigInteger number) {
    BaseNIntegerListElement* element = (BaseNIntegerListElement*)malloc(sizeof(BaseNIntegerListElement));

    element->value = number;

    element->next = NULL;

    if (isEmpty(list)) {
        element->prev = NULL;
        list.head = element;
    } else {
        element->prev = list.tail;
        list.tail->next = element;
    }

    list.tail = element;
    list.size += 1;

    return list;
}

BaseNIntegerList removeHead(BaseNIntegerList list) {
    if (isEmpty(list)) {
        return list;
    }

    BaseNIntegerListElement* oldElement = list.head;

    list.head = list.head->next;

    deleteBaseNIntegerListElement(oldElement);
    list.size -= 1;

    if (isEmpty(list)) {
        list.tail = NULL;
    } else {
        list.head->prev = NULL;
    }

    return list;
}

BaseNIntegerList removeTail(BaseNIntegerList list) {
    if (isEmpty(list)) {
        return list;
    }

    BaseNIntegerListElement* oldElement = list.tail;

    list.tail = list.tail->prev;

    deleteBaseNIntegerListElement(oldElement);
    list.size -= 1;

    if (list.tail == NULL) {
        list.head = NULL;
    } else {
        list.tail->next = NULL;
    }

    return list;
}

void deleteBigInteger(BigInteger* value) {
    free(value->value);
    value->value = NULL;
}

void deleteBaseNIntegerListElement(BaseNIntegerListElement* element) {
    deleteInteger(&(element->value));
    free(element);
}
