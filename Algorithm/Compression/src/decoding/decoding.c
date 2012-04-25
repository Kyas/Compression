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
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <list/list.h>
#include <decoding/decoding.h>

/* Partie décodage */
int decodingWordList(Liste *l, char *word, int n) {
	if(n >= 0) {
		if(n == 0) {
			addLast(l, word);
			return 1;
		} else {
			moveToFirst(l, n);
			return 1;
		}
	}
	return 0;
}

