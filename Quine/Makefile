CC=gcc
SOURCE=quine.c
EXE=quine

$(EXE):% : %.o

clean:
	rm -rf *.o
	rm -rf $(EXE)

compare: $(EXE)
	@echo -n "Source code: "
	cat $(SOURCE)
	@echo ""
	@echo -n "Program output: " 
	./$(EXE)
