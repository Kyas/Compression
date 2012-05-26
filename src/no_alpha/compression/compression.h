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

#ifndef COMPRESSION_H
#define COMPRESSION_H

#define SIZE_MAX 128

/**
 * Make the compression of a uncrypted file.
 *
 * @param *in
 *		The input file (uncrypted file)
 * @param *out
 *		The output file (the uncrypted file becomes crypted)
 * @return 1 if the compression is a success, 0 otherwise.
 */
int newCompression(FILE *in, FILE *out);

/**
 * Make the decompression of a crypted file.
 *
 * @param *in
 *		The input file (crypted file)
 * @param *out
 *		The output file (the crypted file becomes uncrypted)
 * @return 1 if the decompression is a success, 0 otherwise.
 */
int newDecompression(FILE *in, FILE *out); 

#endif
