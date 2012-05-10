/*****************************************************************************
 * 
 * Copyright 2012 
 * LE ROUX Thomas <thomas@november-eleven.fr>
 * LOR Jérémy <jeremyk.lor@gmail.com>
 * 
 * This file is part of Challenger.
 * 
 * Challenger is free software: you can redistribute it and/or modify
 * it under the terms of the zlib license. See the COPYING file.
 * 
 *****************************************************************************/

#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <getopt.h>

typedef struct options {
   int next_option;
   const char* arg_file_input;
   const char* arg_file_output;
   char compression;
   int mode;
} Options;

void printHelp();

int isArgCompression(Options opt, int mode);

int isArgDecompression(Options opt, int mode);

int isArgTexte(const char* file_input, const char* file_output, int comp);

int isArgBits(const char* file_input, const char* file_output, int comp);

#endif
