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

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "options.h"
#include <alpha/compression/compression.h>
#include <no_alpha/compression/compression.h>

void printHelp() {
	printf("\nUsage:\n");
	printf("\nPremière partie : les options (compression/décompression)\n");

	printf("\t-c (--compression) : le programme effectuera\n\tla compression du fichier entree\n\tet écrira le résultat dans le fichier sortie.\n");
	printf("\t-d (--decompression) : le programme effectuera\n\tla compression du fichier entree\n\tet écrira le résultat dans le fichier sortie.\n\n");

	printf("\nDeuxième partie : les modes d'écriture (compression/décompression)\n");
	printf("\t-t (--text) : indique une écriture en mode texte\n");
	printf("\t-b (--bytes) : indique une écriture des entiers\n\tsur un nombre variable d'ocets.\n");

	printf("\nArguments obligatoires\n");
	printf("\tentree : Fichier en entrée.\n");
	printf("\tsortie : Fichier en sortie.\n");

	printf("\n-h (--help): affiche le message help.\n");

	printf("\nEXEMPLE : Compresse -[cd] [tb] entree sortie\n\n");
}

int isArgCompression(Options opt, int mode) {
	if (opt.arg_file_input != NULL && opt.arg_file_output != NULL) {

		if (opt.arg_file_input == NULL && opt.arg_file_output == NULL) {
			printf("[COMPRESSION] Fichier introuvable !\n\n");
			return 0;
			
		} else if(mode == 1) {
		
			isArgTexte(opt.arg_file_input, opt.arg_file_output, 1);
			
		} else if(mode == 2) {
			isArgBits(opt.arg_file_input, opt.arg_file_output, 1);
			
		} else {
		
			return 0;
		}

		return 1;

	}
	return 0;
}

int isArgDecompression(Options opt, int mode) {
	if (opt.arg_file_input != NULL && opt.arg_file_output != NULL) {

		if (opt.arg_file_input == NULL && opt.arg_file_output == NULL) {
			printf("[DECOMPRESSION] Fichier introuvable !\n\n");
			return 0;
			
		} else if(mode == 1) {
			isArgTexte(opt.arg_file_input, opt.arg_file_output, 2);
			
		} else if(mode == 2) {
			isArgBits(opt.arg_file_input, opt.arg_file_output, 2);
			
		} else {
		
			return 0;
		}

	}
	return 0;
}

int isArgTexte(const char *file_input, const char *file_output, int comp) {

	FILE *file_i = NULL;
	FILE *file_o = NULL;

	file_i = fopen(file_input, "r");
	file_o = fopen(file_output, "w");

	if (file_i == NULL && file_o == NULL) {
		printf("[TEXTE] Fichier introuvable !\n\n");
		return 0;
		
	} else if (comp == 1) {
	
		compression(file_i, file_o);
		printf("[TEXTE] Mode Texte avec compression effectuée.\n\n");
		
	} else if (comp == 2) {
	
		decompression(file_i, file_o);
		printf("[TEXTE] Mode Texte avec décompression effectuée.\n\n");
		
	} else {
		return 0;
	}

	fclose(file_i);
	fclose(file_o);
	return 1;

}

int isArgBits(const char *file_input, const char *file_output, int comp) {

	FILE *file_i = NULL;
	FILE *file_o = NULL;
	
	file_i = fopen(file_input, "r");
	file_o = fopen(file_output, "w");

	if (file_i == NULL && file_o == NULL) {
		printf("[BITS] Fichier introuvable !\n\n");
		return 0;
	} else if (comp == 1) {
	
		compression(file_i, file_o);
		printf("[BITS] Mode Octets avec compression effectuée.\n\n");
		
	} else if (comp == 2) {
	
		decompression(file_i, file_o);
		printf("[BITS] Mode Octets avec décompression effectuée.\n\n");
		
	} else {
		return 0;
	}

	fclose(file_i);
	fclose(file_o);
	return 1;
	
}
