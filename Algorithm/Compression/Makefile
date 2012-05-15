CC?=gcc
AR?=ar

CFLAGS_INCLUDE = -I./src/ -I./src/list/ -I./src/coding/ -I./src/decoding/ -I./src/alpha/file/ -I./src/alpha/compression/
CFLAGS += $(CFLAGS_INCLUDE) -Wall -Wextra -Werror
CFLAGS_DEBUG = $(CFLAGS) -O0 -g $(CFLAGS_DEBUG_EXTRA)
CFLAGS_FAST = $(CFLAGS) -Os $(CFLAGS_FAST_EXTRA) -pedantic -march=native \
 -mtune=generic -pipe -fstack-protector --param=ssp-buffer-size=4  \
 -D_FORTIFY_SOURCE=2

all: Compresse test

test: test_list test_coding test_decoding test_file_alpha test_compression_alpha
	./bin/test_list
	./bin/test_coding
	./bin/test_decoding
	./bin/test_file_alpha
	./bin/test_compression_alpha
	
test_valgrind: test_list test_coding test_decoding test_file test_compression
	valgrind ./bin/test_list
	valgrind ./bin/test_coding
	valgrind ./bin/test_decoding
	valgrind ./bin/test_file_alpha
	valgrind ./bin/test_compression_alpha

Compresse: src/main.o src/options.o \
	src/alpha/compression/debug-compression_alpha.o src/coding/debug-coding.o src/decoding/debug-decoding.o \
	src/list/debug-list.o src/alpha/file/debug-file_alpha.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_FAST) $(CFLAGS_FAST) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_list: src/list/debug-list.o src/test/test_list.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_coding: src/list/debug-list.o src/coding/debug-coding.o src/test/test_coding.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_decoding: src/list/debug-list.o src/decoding/debug-decoding.o src/test/test_decoding.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_file_alpha: src/list/debug-list.o src/alpha/file/debug-file_alpha.o src/test/test_file_alpha.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_compression_alpha: src/list/debug-list.o src/alpha/file/debug-file_alpha.o src/coding/debug-coding.o src/decoding/debug-decoding.o src/alpha/compression/debug-compression_alpha.o \
	src/test/test_compression_alpha.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
flags:
	@echo CFLAGS: $(CFLAGS)
	@echo CFLAGS_DEBUG: $(CFLAGS_DEBUG)
	@echo CFLAGS_FAST: $(CFLAGS_FAST)
	@echo CFLAGS_DEBUG_EXTRA: $(CFLAGS_DEBUG_EXTRA)
	@echo CFLAGS_FAST_EXTRA: $(CFLAGS_FAST_EXTRA)

clean: 
	rm -f src/list/*.o
	rm -f src/coding/*.o
	rm -f src/decoding/*.o
	rm -f src/alpha/file/*.o
	rm -f src/alpha/compression/*.o
	rm -f src/test/*.o
	rm -rf bin/*
	
src/list/debug-%.o: src/list/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/coding/debug-%.o: src/coding/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/decoding/debug-%.o: src/decoding/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/alpha/file/debug-%_alpha.o: src/alpha/file/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/alpha/compression/debug-%_alpha.o: src/alpha/compression/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@

src/test/%.o: src/test/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS_FAST) $(CFLAGS_FAST) -c -ansi $< -o $@

