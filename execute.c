#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <wait.h>
#include <stddef.h>

/**
 * executeCommand - executes a command
 * @cmd: command passed
 * Return: 0
 */

void executeCommand(char *cmd)
{
	pid_t pid;
	char *args[70];
	char *token;
	int i;


	pid = fork();
	i = 0;

	if (pid == 0)
	{

		token = strtok(cmd, " ");
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		execve(args[0], args, NULL);
		perror("Command execution failed");
		exit(1);
	}
	else if (pid == -1)
	{
		perror("Forking failed");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
