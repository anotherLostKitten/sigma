runner: sigma.o
	gcc sigma.o -o runner
sigma.o: sigma.c
	gcc -c sigma.c
run: runner
	./runner
clean:
	rm *~* \#*\# *.o *.out runner
