build:
	@cc src/main.c -o randomsymbols -lncurses 

install:
	@echo "copying binary into /usr/local/bin/"
	@sudo cp randomsymbols /usr/local/bin/

clean:
	@rm -rf /build

uninstall:
	@sudo rm /usr/local/bin/randomsymbols
