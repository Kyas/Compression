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
#include <decoding/decoding.h>
#include <alpha/file/file.h>

/**
 * Make the compression of a uncrypted file.
 *
 * @param *in
 *		The input file (uncrypted file)
 * @param *out
 *		The output file (the uncrypted file becomes crypted)
 * @return 1 if the compression is a success, 0 otherwise.
 */
int compression(FILE *in, FILE *out) {
	if(in != NULL) {
		Liste tmp = NULL;
		Liste l = readNoEncodedFileIntoList(in);
		int n = 0;		
		
		while(l != NULL) {
		
			n = codingWordList(&tmp, l->word);
			
			if(n == 0) {
			
				fprintf(out, "%d ", n);
				fprintf(out, "%d ", strlen(l->word));
				
				/* To make sure that the end of the line doesn't contain SPACES ! */
				if(strcmp(l->next->word, "\n") != 0) {
					fprintf(out, "%s ", l->word);
				} else {
					fprintf(out, "%s", l->word);
				}
				
			} else if(n > 0) {
				
				if(strcmp(l->next->word, "\n") != 0) {
					fprintf(out, "%d ", n);
				} else {
					fprintf(out, "%d", n);
				}
				
			} else if(n == -2) {
				fprintf(out, "\n");
			} else {
			
				return 0;
			}
			
			l = l->next;
		}
		return 1;
	}
	return 0;
}

/**
 * Make the decompression of a crypted file.
 *
 * @param *in
 *		The input file (crypted file)
 * @param *out
 *		The output file (the crypted file becomes uncrypted)
 * @return 1 if the decompression is a success, 0 otherwise.
 */
int decompression(FILE *in, FILE *out) {
	if(in != NULL) {
	
		Liste tmp = NULL;
		Liste l = readNoEncodedFileIntoList(in);
		int n = 0;
		
		while(l != NULL) {
			
			if(strcmp(l->word, "0") == 0) { /* If the current word is the digit 0 */
			
				n = decodingWordList(&tmp, l->next->next->word, 0);
				
				/* To make sure that the end of the line doesn't contain SPACES ! */
				if(strcmp(l->next->next->next->word, "\n") != 0) {
					fprintf(out, "%s ", l->next->next->word);
				} else {
					fprintf(out, "%s", l->next->next->word);
				}
					
				l = l->next->next;
				
			} else if(strcmp(l->word, "\n") == 0) { /* If the current word is '\n' */
			
				n = decodingWordList(&tmp, NULL, -2);
				
				fprintf(out, "\n");
				
			} else if(strcmp(l->word, "") == 0) { /* If the current word is the space */
			
				n = decodingWordList(&tmp, NULL, -1);
				
			} else if(atoi(l->word) > 0) {
			
				n = decodingWordList(&tmp, NULL, atoi(l->word));
				
				if(strcmp(l->next->word, "\n") != 0) {
					fprintf(out, "%s ", tmp->word);
				} else {
					fprintf(out, "%s", tmp->word);
				}
				
			} else {
				return -1;
			}
			l = l->next;
		}
		
		return 1;
	}
	
	return 0;

}
