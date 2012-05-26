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

/**
 * Test if the List is empty. 
 *
 * @param *l 
 *		The List
 * @return 1 if the List is empty
 */
int isEmpty(const Liste *l) {
	if(*l == NULL) {
		return 1;
	}
	return 0;
}

/**
 * Return the size of the List. 
 *
 * @param *l 
 *		The List
 * @return the size
 */
int size(const Liste *l) {
	if(isEmpty(l)) {
		return 0;
	} else {
		int res = 1;
		while((*l)->next != NULL) {
			res += 1;
			l = &((*l)->next);
		}
		return res;
	}
	return 0;
}

/**
 * Create a cell with the appropriate word inside it. 
 *
 * @param *word
 *		The word
 * @return A pointer on the type Cellule
 */
Cellule* createCell(char *word) {
	Cellule *cell = (Cellule *) malloc(sizeof(Cellule));
	if(cell != NULL) {
		cell->word = word;
		cell->next = NULL;
	}
	return cell;
}

/**
 * Add the word to the header of the List.
 *
 * @param *l
 *		The List
 * @param *word
 *		The word
 * @return 1 if the addition is a success, 0 otherwise.
 */
int addFirst(Liste *l, char *word) {

	Cellule* cell = NULL;

	if((cell = createCell(word)) != NULL) {
		cell->next = *l;
		*l = cell;
		return 1;
	}

	return 0;
}

/**
 * Add the word to the end of the List.
 *
 * @param *l
 *		The List
 * @param *word
 *		The word
 * @return 1 if the addition is a success, 0 otherwise.
 */
int addLast(Liste *l, char *word) {

	Cellule* cell = NULL;

	if(!isEmpty(l)) {

		while((*l)->next != NULL) {
			l = &((*l)->next);
		}

		if((cell = createCell(word)) != NULL) {
			(*l)->next = cell;
			return 1;
		}

	} else if(addFirst(l, word)) {
		return 1;
	}

	return 0;
}

/**
 * Delete the word to the header of the List.
 *
 * @param *l
 *		The List
 * @return 1 if the deletion is a success, 0 otherwise.
 */
int deleteFirst(Liste *l) {

	if(isEmpty(l)) {
		return 0;
	}

	Cellule *c = *l;
	*l = (*l)->next;

	freeCell(c);
	return 1;
}

/**
 * Delete the word according to its position in the List.
 *
 * @param *l
 *		The List
 * @param index
 *		The index of the List
 * @return 1 if the deletion is a success, 0 otherwise.
 */
int deleteAt(Liste *l, int index) {

	if(isEmpty(l)) {
		return 0;
	}
	if(index > 0) {

		if(index == 1) {
			return deleteFirst(l);
		}

		Liste tmp = *l;
		Cellule *c = NULL;
		while(index > 1) {
			index--;
			tmp = tmp->next;
		}
		c = tmp->next;
		tmp->next = c->next;
		freeCell(c);
		
		return 1;
	}
	return 0;
}

/**
 * Return the index of a word found in the List.
 *
 * @param *l
 *		The List
 * @param *word
 *		The word
 * @return the index is the word is found in the List, -1 otherwise.
 */
int indexOf(Liste l, char *word) {

	int cursor = 1;

	while(!isEmpty(&l)) {
		if(!strcmp(l->word, word)) {
			return cursor;
		}
		cursor++;
		l = l->next;
	}
	return -1;
}

/**
 * Move the word selected by its index in the List 
 * to move to go the header of the List. 
 *
 * @param *l
 *		The List
 * @param index
 *		The index in the List
 * @return 1 if the moving is a success, 0 otherwise.
 */
int moveToFirst(Liste *l, int index) {
	
	if(index > 0) {
	
		if(index == 1) {
			return 1;
		}
		
		int pos = index; /* To keep the index after the addFirst */
		
		Liste *tmp = l;
		
		while(index > 1) {
		
			index--;
			
			tmp = &((*tmp)->next);
			
		}
		
		addFirst(l, (*tmp)->word);
		
		deleteAt(l, pos);
		
		return 1;
	}
	return 0;
}

/**
 * Display the List.
 *
 * @param l
 *		The List
 */
void printList(Liste l) {

	while(!isEmpty(&l)) {
	
		if(l->next != NULL) {
			printf("%s -> ", l->word);
		} else {
			printf("%s\n", l->word);
		}
		
		l = l->next;
	}
}

/**
 * Free the cell (pointer on the type Cellule).
 *
 * @param *c
 *		The Cell
 */
void freeCell(Cellule *c) {
	if(!isEmpty(&c)) {
		free(c);
	}
}

/**
 * Free the List (pointer on the type Liste).
 *
 * @param *l
 *		The List
 */
void freeList(Liste *l) {
	if(!isEmpty(l)) {
		freeList(&((*l)->next));
		freeCell(*l);
	}
	*l = NULL;
}

