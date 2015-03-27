#!/bin/bash
# Compila o teste para a suite de testes

gcc -Wall TST_suite.c BEN_benchmark.c HEA_heap.c heap_test.c -o heap_test.out
