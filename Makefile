#makefile для converter_CP.c
converter_CP: converter_CP.c
	gcc  -Wall -Wextra -Wpedantic -o converter_CP converter_CP.c -no-pie

