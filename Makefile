CC?=gcc
AR?=ar

CFLAGS_INCLUDE = -I./src/ -I./src/list/ -I./src/binary/ -I./src/coding/ -I./src/decoding/ -I./src/v1/file/ -I./src/v1/compression/ -I./src/v2/file/ -I./src/v2/compression/
CFLAGS += $(CFLAGS_INCLUDE) -Wall -Wextra -Werror
CFLAGS_DEBUG = $(CFLAGS) -O0 -g $(CFLAGS_DEBUG_EXTRA)
CFLAGS_FAST = $(CFLAGS) -Os $(CFLAGS_FAST_EXTRA) -pedantic -march=native \
 -mtune=generic -pipe -fstack-protector --param=ssp-buffer-size=4  \
 -D_FORTIFY_SOURCE=2

all: Compresse test
 
test: test_list test_binary test_coding test_decoding test_file_v1 test_compression_v1 test_file_v2 test_compression_v2
	./bin/test_list
	./bin/test_binary
	./bin/test_coding
	./bin/test_decoding
	./bin/test_file_v1
	./bin/test_compression_v1
	./bin/test_file_v2
	./bin/test_compression_v2
	
test_valgrind: test_list test_binary test_coding test_decoding test_file_v1 test_compression_v1 test_file_v2 test_compression_v2
	valgrind ./bin/test_list
	valgrind ./bin/test_binary
	valgrind ./bin/test_coding
	valgrind ./bin/test_decoding
	valgrind ./bin/test_file_v1
	valgrind ./bin/test_compression_v1
	valgrind ./bin/test_file_v2
	valgrind ./bin/test_compression_v2

Compresse: src/main.o src/options.o \
	src/v2/compression/debug-compression_v2.o \
	src/coding/debug-coding.o src/decoding/debug-decoding.o \
	src/list/debug-list.o src/v2/file/debug-file_v2.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_FAST) $(CFLAGS_FAST) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_list: src/list/debug-list.o src/test/test_list.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_binary: src/binary/debug-binary.o src/test/test_binary.o src/test/test.o
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
	
test_file_v1: src/list/debug-list.o src/v1/file/debug-file_v1.o src/test/test_file_v1.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_compression_v1: src/list/debug-list.o src/v1/file/debug-file_v1.o src/coding/debug-coding.o \
	src/decoding/debug-decoding.o src/v1/compression/debug-compression_v1.o \
	src/test/test_compression_v1.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_file_v2: src/list/debug-list.o src/v2/file/debug-file_v2.o src/test/test_file_v2.o src/test/test.o
	@mkdir -p bin/
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) $^ -o bin/$@
	@echo Compilation of $@ [DONE]
	
test_compression_v2: src/list/debug-list.o src/v2/file/debug-file_v2.o src/coding/debug-coding.o \
	src/decoding/debug-decoding.o src/v2/compression/debug-compression_v2.o \
	src/test/test_compression_v2.o src/test/test.o
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
	rm -f src/binary/*.o
	rm -f src/coding/*.o
	rm -f src/decoding/*.o
	rm -f src/v1/file/*.o
	rm -f src/v1/compression/*.o
	rm -f src/v2/file/*.o
	rm -f src/v2/compression/*.o
	rm -f src/test/*.o
	rm -rf bin/*
	
src/list/debug-%.o: src/list/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/binary/debug-%.o: src/binary/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/coding/debug-%.o: src/coding/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/decoding/debug-%.o: src/decoding/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/v1/file/debug-%_v1.o: src/v1/file/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/v1/compression/debug-%_v1.o: src/v1/compression/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/v2/file/debug-%_v2.o: src/v2/file/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/v2/compression/debug-%_v2.o: src/v2/compression/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@

src/test/%.o: src/test/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS_FAST) $(CFLAGS_FAST) -c -ansi $< -o $@

