CC?=gcc
AR?=ar

CFLAGS_INCLUDE = -I./src/ -I./src/list/ -I./src/coding/
CFLAGS += $(CFLAGS_INCLUDE) -Wall -Wextra -Werror
CFLAGS_DEBUG = $(CFLAGS) -O0 -g $(CFLAGS_DEBUG_EXTRA)
CFLAGS_FAST = $(CFLAGS) -Os $(CFLAGS_FAST_EXTRA) -pedantic -march=native \
 -mtune=generic -pipe -fstack-protector --param=ssp-buffer-size=4  \
 -D_FORTIFY_SOURCE=2

all: compress test

test: test_list test_coding
	./bin/test_list
	./bin/test_coding
	
test_valgrind: test_list test_coding
	valgrind ./bin/test_list
	valgrind ./bin/test_coding

compress: src/main.o
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
	
flags:
	@echo CFLAGS: $(CFLAGS)
	@echo CFLAGS_DEBUG: $(CFLAGS_DEBUG)
	@echo CFLAGS_FAST: $(CFLAGS_FAST)
	@echo CFLAGS_DEBUG_EXTRA: $(CFLAGS_DEBUG_EXTRA)
	@echo CFLAGS_FAST_EXTRA: $(CFLAGS_FAST_EXTRA)

clean: 
	rm -f src/list/*.o
	rm -f src/coding/*.o
	rm -f src/test/*.o
	rm -rf bin/*
	
src/list/debug-%.o: src/list/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/coding/debug-%.o: src/coding/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@
	
src/test/%.o: src/test/%.c
	$(CC) $(CPPFLAGS_DEBUG) $(CFLAGS_DEBUG) -c -ansi $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS_FAST) $(CFLAGS_FAST) -c -ansi $< -o $@

