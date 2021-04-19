
# CJSH
#### Custom Linux shell

#### FILES:
- [README.md]: this file! Contains information about the project
- [makefile]: used with make to automate compiling of source code
- [CJSH.c]: Source code for shell
- [requirements.txt]: list of CLI utilities needed in order to compile and run the shell

#### COMPILING AND RUNNING:
1. Clone the repository
2. Navigate into cloned repository using bash
3. Run the following command in bash: 'make'
4. Run the command ./CJSH.out
5. CJSH will take over as the active shell!

#### MAKE FUNCTIONS:
 - build: The default make function. Compiles source code and makes it executable.
 - clean: Removes the compiled version of CJSH from the source directory

#### UPCOMING MAKE FUNCTIONS:
 - install: Installs CJSH into /bin
 - uninstall: Removes CJSH from /bin
 - update: Pulls latest source code from repo. Does not compile source code.
