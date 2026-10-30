var := $(patsubst %.c, %.o, $(wildcard *.c))

cal.exe:$(var)
	gcc -o calc.exe $(var)

clean:
	rm *.o *.out