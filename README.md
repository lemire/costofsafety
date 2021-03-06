# costofsafety
Quick experiment to see how expensive safety is in C, for research

# Skylake processor

```
$ export CC=gcc-8
$ make
$ ./boundchecking
length = 1048576
scalar(x, y, length)                    	:  2.255 cycles per input byte (best)  2.303 cycles per input byte (avg)
scalar_safe(x, y, length)               	:  2.158 cycles per input byte (best)  2.169 cycles per input byte (avg)
scalar_random_access(indexes, N, x, y, length)	:  17.656 cycles per input byte (best)  17.791 cycles per input byte (avg)
scalar_random_access_safe(indexes, N, x, y, length)	:  19.393 cycles per input byte (best)  19.513 cycles per input byte (avg)
length = 16777216
scalar(x, y, length)                    	:  2.376 cycles per input byte (best)  2.384 cycles per input byte (avg)
scalar_safe(x, y, length)               	:  2.254 cycles per input byte (best)  2.257 cycles per input byte (avg)
scalar_random_access(indexes, N, x, y, length)	:  57.880 cycles per input byte (best)  57.888 cycles per input byte (avg)
scalar_random_access_safe(indexes, N, x, y, length)	:  58.310 cycles per input byte (best)  58.361 cycles per input byte (avg)
length = 67108864
scalar(x, y, length)                    	:  2.366 cycles per input byte (best)  2.374 cycles per input byte (avg)
scalar_safe(x, y, length)               	:  2.271 cycles per input byte (best)  2.274 cycles per input byte (avg)
scalar_random_access(indexes, N, x, y, length)	:  69.434 cycles per input byte (best)  69.519 cycles per input byte (avg)
scalar_random_access_safe(indexes, N, x, y, length)	:  69.329 cycles per input byte (best)  69.347 cycles per input byte (avg)
```

# Cannon Lake processor

```
$ export CC=gcc-8
$ make
$ ./boundchecking
length = 1048576
scalar(x, y, length)                    	:  2.169 cycles per input byte (best)  2.194 cycles per input byte (avg)
scalar_safe(x, y, length)               	:  1.965 cycles per input byte (best)  2.006 cycles per input byte (avg)
scalar_random_access(indexes, N, x, y, length)	:  15.793 cycles per input byte (best)  15.981 cycles per input byte (avg)
scalar_random_access_safe(indexes, N, x, y, length)	:  19.921 cycles per input byte (best)  20.046 cycles per input byte (avg)
length = 16777216
scalar(x, y, length)                    	:  2.169 cycles per input byte (best)  2.178 cycles per input byte (avg)
scalar_safe(x, y, length)               	:  1.969 cycles per input byte (best)  1.978 cycles per input byte (avg)
scalar_random_access(indexes, N, x, y, length)	:  21.869 cycles per input byte (best)  21.924 cycles per input byte (avg)
scalar_random_access_safe(indexes, N, x, y, length)	:  25.429 cycles per input byte (best)  25.452 cycles per input byte (avg)
length = 67108864
scalar(x, y, length)                    	:  2.172 cycles per input byte (best)  2.181 cycles per input byte (avg)
scalar_safe(x, y, length)               	:  1.977 cycles per input byte (best)  1.980 cycles per input byte (avg)
scalar_random_access(indexes, N, x, y, length)	:  21.973 cycles per input byte (best)  21.990 cycles per input byte (avg)
scalar_random_access_safe(indexes, N, x, y, length)	:  25.567 cycles per input byte (best)  25.612 cycles per input byte (avg)
```
