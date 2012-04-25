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
#include <coding/coding.h>

/**
 * Return the position of the word in the List and move it to the header of the List. 
 * If the word is not in the List, the function returns 0 and adds the word at the end of the List.
 * Returns -1 otherwise.
 *
 * @param *l
 *		The List (pointer on the type List)
 * @param *word
 *		The word (pointer on the type word)
 * @return 
 *	- the position of the word in the List and move it to the header of the List. 
 *	- 0 if the word is not in the List and adds it at the end of the List.
 *	- -1 otherwise.
 */
int codingWordList(Liste *l, char *word) {
	if(word != NULL) {
		if(indexOf(*l, word) > 0) { /* word found in the List. */
			int index = indexOf(*l, word);
			/* moves the word to the header of the List. */
			moveToFirst(l, indexOf(*l, word));
			return index;
		} else { /* word not found in the List. */
			addLast(l, word);
			return 0;
		}
	}
	return -1;
}
