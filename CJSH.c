/***********************************************************
 * Name of program: project1
 * Author: Tyler Holm
 * Description: custom shell for Linux
 **********************************************************/

//Included libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


//Declarations for functions that get called later
void promptUser(void); //Prompts user for input
int runCommand(char * array[10]); //Runs validated tokens as command
void changeDir(char * path); //Changes the working directory

/* main()
 * Loops for new user input until user enters 'exit'
 * Runs valid commands
 */
int main(int argc, char *argv[]) {
	//initialize variables
    char userInput[80];
    char lcInput[80];
    int pidArray[5];
    char * tokens;
    char * tokenArray[10];
    
	while (1) {
        //Get input from user - Part 1 //
        promptUser(); // Print prompt
        fgets(userInput, sizeof(userInput), stdin); //get input
        strtok(userInput, "\n");
        
        // "exit" built-in - Part 4 //
        if (strncmp(userInput, "exit", 80) == 0) {
            printf("Exiting!\n");
            break;
        }
        
        // "lc" built-in - Part 4 //
        if (strncmp(userInput, "lc", 2) == 0) {
            tokens = strtok(lcInput, " ");
        }
        else {
            tokens = strtok(userInput, " ");
            strcpy(lcInput, userInput);
        }
        

        // Get tokens from input - Part 2 //
        char * tokenArray[10];
        int i = 0;
        for (i=0; tokens != NULL; i++) {
            tokenArray[i] = tokens;
            tokens = strtok(NULL, " ");
        }
        tokenArray[i] = NULL; //Make last element NULL
        
        
        // "cd" built-in - Part 4 //
        if (strncmp(tokenArray[0], "cd", 2) == 0) {
            changeDir(tokenArray[1]);
        }
        
        
        // "showpid" built-in - Part 4 //
        else if (strncmp(tokenArray[0], "showpid", 7) == 0) { //showpid.. ya
            for (i=0; i<=4 && pidArray[i]!=0; i++) {
                printf("%d\n", pidArray[i]);
            }
        }
        
        // Fork and execute Command - Part 3 //
        else {
            int executeFlag = runCommand(tokenArray);
            if (executeFlag == -1) { //kill extra shell and print error if execution fails
                printf("Error: Command could not be executed\n");
                break; //Kill extra shell
            }
            else { // else add to showpid array
                for (i=3; i>=0; --i) {
                    pidArray[i+1] = pidArray[i];
                }
                pidArray[0] = executeFlag;
            }
        }
	}
}


/* promptUser()
 * prints input prompt
 * takes no input,
 * RETURNS nothing
 */
void promptUser(void) {
    // Custom Prompt - Part 5 //
    char user[80];
    char dir[80];
    getlogin_r(user, sizeof(user));
    getcwd(dir, sizeof(dir));
    printf("\033[1;36m");
    printf("%s", user);
    printf("\033[0m");
    printf(":");
    printf("\033[1;34m");
    printf("%s", dir);
    printf("\033[0m");
    printf("$ ");
}


/* runCommand()
 * runs a built-in command or
 * creates a child process which calls execvp()
 * RETURNS -1 to child process if execvp call fails
 * RETURNS pid of new process to parent
 */
int runCommand(char * array[10]){ //Runs validated tokens as command
    //Fork and execute Command - Part 3
    pid_t pid = fork();
    if (pid == 0) { //child
        execvp(array[0], array);
        return -1;
    }

    else { //parent
        waitpid(-1, NULL, 0);
        return pid;
    }
}


/* changeDir()
 * changes the current directory or prints a fail message
 * takes cd path as input
 * RETURNS nothing
 */
void changeDir(char * path) {
    int cdFlag = chdir(path);
    if (cdFlag == -1) {
        printf("cd: no such file or directory: %s\n", path);
    }
    else{
        char cwd[80];
        getcwd(cwd, sizeof(cwd));
        setenv("PWD", cwd, 1);
    }
}
