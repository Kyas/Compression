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

void displayString(char** s, int numberOfWords);

char** readAlphabIntoArray(FILE* in, int* numberOfWords);

char** readPunctIntoArray(FILE* in, int* numberOfWords);

int readPunctIntoList(FILE* in, Liste *lp);

int readAlphabIntoList(FILE* in, Liste *la);

#endif
