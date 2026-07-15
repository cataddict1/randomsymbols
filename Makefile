build:
	@cc src/main.c -o randomsymbols -lncurses 

install:
	@echo "copying binary into /usr/bin/"
	@sudo cp randomsymbols /usr/bin/

all:
	@cc src/main.c -o randomsymbols -lncurses
	@echo "copying binary into /usr/bin/"
	@sudo cp randomsymbols /usr/bin/

clean:
	@rm -rf randomsymbols

uninstall:
	@sudo rm /usr/bin/randomsymbols
