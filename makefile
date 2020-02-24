CPP = main.cpp Lexer.cpp Symbole.cpp Automate.cpp State.cpp
COMP = g++
OUT = analyser

release: $(CPP)
	@echo "Building release version, do 'make debug' to build debug version"
	$(COMP) -o $(OUT) $(CPP)

debug:
	@echo "Building debug version"
	$(COMP) -g -D VERBOSE -o $(OUT) $(CPP)