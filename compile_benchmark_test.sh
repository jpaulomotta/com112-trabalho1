#!/bin/bash
# Compila o teste para o benchmark

gcc -Wall BEN_benchmark.c TST_suite.c benchmark_test.c -o benchmark_test.out
