#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "benchmark.h"

__attribute__((noinline)) uint32_t scalar_random_access(uint32_t *indexes,
                                                        size_t N, uint32_t *x,
                                                        uint32_t *y,
                                                        size_t length) {
  uint32_t sum = 0;
  for (size_t i = 0; i < N; i++) {
    uint32_t idx = indexes[i];
    sum += x[idx] * y[idx];
  }
  return sum;
}

__attribute__((noinline)) uint32_t
scalar_random_access_safe(uint32_t *indexes, size_t N, uint32_t *x, uint32_t *y,
                          size_t length) {
  unsigned long sum = 0;
  unsigned long mul = 0;

  for (size_t i = 0; i < N; i++) {
    uint32_t idx = indexes[i];
    if (idx >= length) {
      printf("bug\n");
      abort();
    }
    if (__builtin_umull_overflow(x[idx], y[idx], &mul)) {
      printf("bug\n");
      abort();
    }

    if (__builtin_uaddl_overflow(sum, mul, &sum)) {
      printf("bug\n");
      abort();
    }
  }

  return sum;
}

__attribute__((noinline)) uint32_t scalar(uint32_t *x, uint32_t *y,
                                          size_t length) {
  uint32_t sum = 0;
  for (size_t i = 0; i < length; i++) {
    sum += x[i] * y[i];
  }
  return sum;
}

__attribute__((noinline)) uint32_t scalar_safe(uint32_t *x, uint32_t *y,
                                               size_t length) {
  unsigned long sum = 0;
  unsigned long mul;
  for (size_t i = 0; i < length; i++) {

    if (__builtin_umull_overflow(x[i], y[i], &mul)) {
      printf("bug\n");
      abort();
    }
    if (__builtin_uaddl_overflow(sum, mul, &sum)) {
      printf("bug\n");
      abort();
    }
  }
  return sum;
}

void demo(size_t length) {
  bool verbose = true;
  int repeat = 5;
  printf("length = %zu \n", length);
  uint32_t *x = (uint32_t *)malloc(length * sizeof(uint32_t));
  uint32_t *y = (uint32_t *)malloc(length * sizeof(uint32_t));
  for (size_t i = 0; i < length; i++) {
    x[i] = i % 10;
    y[i] = i % 13;
  }
  size_t N = length;
  uint32_t *indexes = (uint32_t *)malloc(N * sizeof(uint32_t));
  for (size_t i = 0; i < N; i++) {
    indexes[i] = rand() % length;
  }
  uint32_t expected = scalar(x, y, length);
  uint32_t rexpected = scalar_random_access(indexes, N, x, y, length);
  BEST_TIME(scalar(x, y, length), expected, , repeat, length, verbose);
  BEST_TIME(scalar_safe(x, y, length), expected, , repeat, length, verbose);
  BEST_TIME(scalar_random_access(indexes, N, x, y, length), rexpected, , repeat,
            N, verbose);
  BEST_TIME(scalar_random_access_safe(indexes, N, x, y, length), rexpected, ,
            repeat, N, verbose);
}

int main() {
  demo(1024 * 1024);
  demo(16 * 1024 * 1024);
  demo(64 * 1024 * 1024);
}
