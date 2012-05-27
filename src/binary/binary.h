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

#ifndef BINARY_H
#define BINARY_H

/**
 * Display the integer into a binary. 
 *
 * @param n 
 *		The unsigned int.
 */
void displayBinary(unsigned int n);

int getNbOctet(unsigned int nbr);

int putBinary(int c);

void displayByte(char n);

void displayValue(unsigned int n);

unsigned int** transformInt(unsigned int n);

void displayTransformInt(unsigned int** tab, unsigned int n);

void freeBytes(unsigned int **tab);

#endif
