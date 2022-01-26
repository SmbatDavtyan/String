EXE:=exe

$(EXE): main.cpp string.cpp 
	g++ $^ -o $@

clean: 
	rm $(EXE)
