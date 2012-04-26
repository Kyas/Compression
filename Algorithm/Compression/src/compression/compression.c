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
#include <file/file.h>

int compression(FILE *in, FILE *out) {
	if(in != NULL) {
		Liste tmp = NULL;
		Liste l = readFileIntoList(in); /* Result : deux -> et -> deux -> quatre -> quatre -> et -> quatre -> huit */
		
		/* Doesn't work -___- */
		while(l != NULL) {
			printf("%d\n", codingWordList(&tmp,l->word) );
			l = l->next;
		}
		
		/* Doesn't work too */
/*		printf("%d\n", codingWordList(&tmp,l->word) );*/
/*		printf("%d\n", codingWordList(&tmp,l->next->word) );*/
/*		printf("%d\n", codingWordList(&tmp,l->next->next->word) );*/
/*		printf("%d\n", codingWordList(&tmp,l->next->next->next->word) );*/
/*		printf("%d\n", codingWordList(&tmp,l->next->next->next->next->word) );*/
		
		/* This example works...*/
/*		printf("%d\n", codingWordList(&tmp,l->word) );*/
/*		printf("%d\n", codingWordList(&tmp,l->next->word) );*/
/*		printf("%d\n", codingWordList(&tmp,l->word) );*/
/*		printf("%d\n", codingWordList(&tmp,l->next->next->word) );*/
/*		printf("%d\n", codingWordList(&tmp,l->next->next->word) );*/


		/* PS Thomas : Je démontre bien que le mot "deux" sont égaux dans la liste, donc pas de problème de lecture à mon avis */
		/* PS 2 : J'ai fait un test unitaire pour codingWordList */
		
		/* Pour faire marcher ceci, commenter le reste sauf Liste l */
/*		if(strcmp(l->word, l->next->next->word) == 0) {*/
/*			printf("ok\n\n");*/
/*		} else {*/
/*			printf("non\n\n");*/
/*		}*/
		
		fclose(in);
		fclose(out);
		return 1;
	}
	return 0;
}
