hash: benchmark.h boundchecking.c
	cc -O3 -o boundchecking boundchecking.c -Wall -Wextra 


clean:
	rm  -f boundchecking
