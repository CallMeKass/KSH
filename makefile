build:
	@echo "Started compiling source code"
	gcc CJSH.c -o CJSH.out
	chmod +x CJSH.out
	@echo "Source code has been compiled"

clean:
	@echo "Removing CJSH.out"
	rm CJSH.out
	@echo "Finished removing CJSH.out"
