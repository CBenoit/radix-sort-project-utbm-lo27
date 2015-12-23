/*
* @Author: Jérôme BOULMIER
* @Date:   2015-04-28 13:11:43
* @Last Modified by:   Jérôme BOULMIER
* @Last Modified time: 2015-04-28 13:13:20
*/
#ifndef LIB_ACQUISITION_H
#define LIB_ACQUISITION_H

/**
 * @brief Requests a number to the user.
 *
 * @param min the minimum accepted.
 * @param max the maximum accepted.
 * @param message a message to display to the user.
 * @return a valid number. (min <= number <= max)
 */
int getNumber(int min, int max, const char message[]);

/**
 * @brief Requests a number to the user.
 *
 * @param min the minimum accepted.
 * @param message a message to display to the user.
 * @return a valid number. (min <= number)
 */
int getMinNumber(int min, const char* message);

/**
 * @brief Ask user to choose a character between c1 and c2.
 *
 * @param c1 a character
 * @param c2 a character
 * @param message a message to display to the user.
 * @return c1 if the user typed c1, c2 if the user typed c2.
 */
char getCharacter(char c1, char c2, const char* message);

/**
 * @brief Ask user to enter a string
 *
 * @param length maximum length of the string.
 * @param answer answer of the user.
 * @param message a message to display to the user.
 */
void getString(int length, char* answer, const char* message);

/**
 * @brief Make a pause in the program.
 */
void pause();

/**
 * @brief convert a string into a lower case string.
 *
 * @param str a string
 */
void lower(char* str);

/**
 * @brief convert a string into a upper case string.
 *
 * @param str a string
 */
void upper(char*);

#endif

