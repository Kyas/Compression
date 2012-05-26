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
#include <getopt.h>
#include "options.h"

int main(int argc, char* argv[]) {

	/**
	 * Command Line Management.
	 */
	const char* short_options = "c::d::t::b::h";
	Options opt;

	const struct option long_options[] = {
		{ "compression", 2, NULL,  'c' },
		{ "decompression", 2, NULL,  'd' },
		{ "text", 2, NULL,  't' },
		{ "bytes", 2, NULL,  'b' },
		{ "help",   0, NULL,  'h' },
		{ NULL,     0, NULL,  0   }
	};
	
	opt.next_option = 0;
	opt.arg_file_input = NULL;
	opt.arg_file_output = NULL;
	opt.compression = ' ';
	opt.mode = 0;

	while (opt.next_option != -1) {
		opt.next_option = getopt_long(argc, argv, short_options, long_options, NULL);
		switch (opt.next_option) {
		case 'c': /* --compression */
			opt.arg_file_input = argv[optind+1];
			opt.arg_file_output = argv[optind+2];
			opt.compression = 'c';
			break;

		case 'd': /* --decompression */
			opt.arg_file_input = argv[optind+1];
			opt.arg_file_output = argv[optind+2];
			opt.compression = 'd';
			break;

		case 't': /* --text */
			opt.mode = 1;
			break;
			
		case 'b': /* --bytes */
			opt.mode = 2;
			break;

		case 'h':  /* --help*/
			printHelp();
			return 0;

		case -1:  /* End of Arguments list. */
			break;

		default:  /* By default. */
			printHelp();
			exit(1);
			return -1;
		}
	}

	/* If we don't have the compression/decompression or the mode (text, bytes) */
	if(opt.compression == ' ' || opt.mode == 0) {
	
		printHelp();
		exit(1);
		return -1;
		
	/* If we don't have the input file or output file */
	} else if(opt.arg_file_input == NULL || opt.arg_file_output == NULL) {
		
		printf("[WARNING] Arguments manquants !\n");
		
	} else {
	
		if(opt.compression == 'c') {
		
			isArgCompression(opt, opt.mode);
			
		} else {
		
			isArgDecompression(opt, opt.mode);
		}
	}

	return 0;
}
