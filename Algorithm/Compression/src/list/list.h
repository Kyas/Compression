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

#ifndef LIST_H
#define LIST_H

/**
 * This structure represents a List, which can store a word of type char*, 
 */
typedef struct cellule {
	char* word;
	struct cellule *next;
} Cellule, * Liste;

/**
 * Test if the List is empty. 
 *
 * @param *l 
 *		The List
 * @return 1 if the List is empty
 */
int isEmpty(const Liste *l);

/**
 * Return the size of the List. 
 *
 * @param *l 
 *		The List
 * @return the size
 */
int size(const Liste *l);

/**
 * Create a cell with the appropriate word inside it. 
 *
 * @param *word
 *		The word
 * @return A pointer on the type Cellule
 */
Cellule* create(char *word);

/**
 * Add the word to the header of the List.
 *
 * @param *l
 *		The List
 * @param *word
 *		The word
 * @return 1 if the addition is a success, 0 otherwise.
 */
int addFirst(Liste *l, char *word);

/**
 * Add the word to the end of the List.
 *
 * @param *l
 *		The List
 * @param *word
 *		The word
 * @return 1 if the addition is a success, 0 otherwise.
 */
int addLast(Liste *l, char *word);

/**
 * Delete the word to the header of the List.
 *
 * @param *l
 *		The List
 * @return 1 if the deletion is a success, 0 otherwise.
 */
int deleteFirst(Liste *l);

/**
 * Delete the word according to its position in the List.
 *
 * @param *l
 *		The List
 * @param index
 *		The index of the List
 * @return 1 if the deletion is a success, 0 otherwise.
 */
int deleteAt(Liste *l, int index);

/**
 * Return the index of a word found in the List.
 *
 * @param *l
 *		The List
 * @param *word
 *		The word
 * @return the index is the word is found in the List, -1 otherwise.
 */
int indexOf(Liste l, char *word);

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
int moveToFirst(Liste *l, int index);

/**
 * Display the List.
 *
 * @param l
 *		The List
 */
void printList(Liste l);

/**
 * Free the cell (pointer on the type Cellule).
 *
 * @param *c
 *		The Cell
 */
void freeCell(Cellule *c);

/**
 * Free the List (pointer on the type Liste).
 *
 * @param *l
 *		The List
 */
void freeList(Liste *l);

#endif
