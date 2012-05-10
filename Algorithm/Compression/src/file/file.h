/*****************************************************************************
 * 
 * Copyright 2012 
 * LE ROUX Thomas <thomas@november-eleven.fr>
 * LOR Jérémy <jeremyk.lor@gmail.com>
 * 
 * This file is part of the Algorithm Project : Compression.
 * 
 * Compression is free software: you can redistribute it and/or modify
 * it under the terms of the zlib license. See the COPYING file.
 * 
 *****************************************************************************/

#include <stdio.h>

#ifndef FILE_H
#define FILE_H

/*******************************************/
/*		Unencrypted file management       */
/*****************************************/

/**
 * Read the file and return an array of characters.
 *
 * @param *in 
 *		The file
 * @param *numberOfWords
 *		Word counter
 * @return the Array of characters
 */
Liste readNoEncodedFileIntoList(FILE* in);

/**
 * Read the file and return an array of characters.
 *
 * @param *in 
 *		The file
 * @param *numberOfWords
 *		Word counter
 * @return the Array of characters
 */
char** readNoEncodedFileIntoArray(FILE* in, int* numberOfWords);

/**
 * Display the array of characters.
 *
 * @param **s 
 *		An array of characters
 */
void displayString(char** s, int numberOfWords);

#endif
