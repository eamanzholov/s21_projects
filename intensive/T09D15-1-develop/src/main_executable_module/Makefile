CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

all: Quest_3

Quest_3: main_executable_module.o data_io.o data_stat.o data_process.o decision.o data_sort.o
	$(CC) $(CFLAGS) -o ../build/Quest_3 $^ $(LDFLAGS)

main_executable_module.o: ../main_executable_module/main_executable_module.c
	$(CC) $(CFLAGS) -c $< -o $@

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c $< -o $@

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c $< -o $@

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c $< -o $@

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c $< -o $@

data_sort.o: data_sort.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o ../build/Quest_3 ../build/Quest_4 ../build/Quest_5 data_stat.a

rebuild: clean all

build_with_macro: CC += -DUSE_MACRO_IO
build_with_macro: Quest_4

Quest_4: main_executable_module.o data_io.o data_stat.o data_process.o decision.o data_sort.o ../data_libs/data_io_macro.h
	$(CC) $(CFLAGS) -o ../build/Quest_4 $^ $(LDFLAGS)

data_stat.a: data_stat.o
	ar rcs data_stat.a data_stat.o

build_with_static: Quest_5

Quest_5: main_executable_module.o data_io.o data_process.o decision.o data_sort.o data_stat.a
	$(CC) $(CFLAGS) -o ../build/Quest_5 $^ $(LDFLAGS)

.PHONY: all clean rebuild build_with_macro build_with_static
