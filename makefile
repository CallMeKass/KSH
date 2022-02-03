build:
	@echo "Started compiling source code"
	gcc KSH.c -o KSH.out
	chmod +x KSH.out
	@echo "Source code has been compiled"

clean:
	@echo "Removing KSH.out"
	rm KSH.out
	@echo "Finished removing KSH.out"
