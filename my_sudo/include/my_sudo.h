/*
** EPITECH PROJECT, 2025
** header
** File description:
** my_sudo
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <termios.h>
#include <string.h>

#ifndef MY_SUDO
    #define MY_SUDO

typedef struct try {
    int try;
    int flags_u;
    int flags_g;
    char *user;
    char *groups;
} try_t;

int my_exec(char *arg0, char **argv1, try_t *user_get);
int check_password(try_t *essai);
int my_strstr(const char *str, const char *to_f);
int my_strlen_mdp(const char *str, int start);
int my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);
int my_strlen_salt(const char *str);
int check_error(int argc, char **argv);
char *my_getsalt(const char *password_hash);
char *my_getpass(void);
char *find_passwd(char *file);
int enable_raw_mode(struct termios *old_tio);
void disable_raw_mode(struct termios *old_tio);
char *my_getsudoers(void);
char *my_getpasswd(void);
int my_getuid(const char *user);
int my_getnbr(char const *str);
int my_str_uid(const char *str, int start);
int my_getgid(const char *user);
void my_setuid(int uid, try_t *essai);
void my_setgid(int uid, try_t *essai);
int check_sudoers(void);
char *my_getusername(void);
void print_help(void);
void print_flags(void);
int my_exec_root(char *arg0, char **argv1);
int my_exec_root_flags(char *arg2, char **argv3, try_t *user_get);
#endif
