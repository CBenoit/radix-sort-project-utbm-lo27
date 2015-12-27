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

bool checkNumberBase(char* number, int size, int base);

void enterNewList(BaseNIntegerList** lists, int* nbLists);

void generateList(BaseNIntegerList** lists, int* nbLists);

void testListFunctions(BaseNIntegerList** lists, int* nbLists);

void testListOfListFunctions(BaseNIntegerList** lists, int* nbLists);

void performRadixSort(BaseNIntegerList** lists, int* nbLists);

BaseNIntegerList* selectList(BaseNIntegerList** lists, int* nbLists);

bool checkNumberBase(char* number, int size, int base);

char* convertToNumber(char* number, int size);

BaseNIntegerList enterList();

#endif

