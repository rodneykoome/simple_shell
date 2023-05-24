#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void handle_command(char *cmd, char **env);
void handle_arguments(char *cmd);
char *get_path(const char *cmd);
void print_environment(char **env);
char *create_full_path(const char* dir, const char* cmd);
char *get_environment_variable(const char *name, char **env);
int set_environment_variable(const char *name, const char *value);

#endif