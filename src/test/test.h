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

#ifndef TEST_H
#define TEST_H

/**
 * Notice that the test was successful.
 */
void testSuccessful(const char* filename);

/**
 * Notice that the test has failed.
 */
void testFailed(const char* filename, int line);

#endif
