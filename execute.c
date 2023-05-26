#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <wait.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

/**
 * executeCommand - executes a command
 * @cmd: command passed
 * Return: 0
 */

void executeCommand(char *cmd)
{
	pid_t pid;
	char *args[3];
	int status;
	char *envp[] = {NULL};


	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = cmd;
		args[3] = NULL;

		execve(args[0], args, envp);
		perror("execve");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
