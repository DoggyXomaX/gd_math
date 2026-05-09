tests:
	mkdir -p bin/tests
	clang \
		-Iinclude \
		-std=c11 -Wall -Wextra \
		-O3 \
		-o bin/tests/index tests/index.c \
		-lm

test:
	./bin/tests/index

.PHONY: test, tests
