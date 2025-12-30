/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** bootstrap
*/

#include "../../include/my_sudo.h"

ssize_t read_password_input(char **buffer, size_t *bufsize,
    struct termios *old_tio)
{
    int echo_disabled;
    ssize_t characters;

    printf("[my_sudo] password for %s: ", my_getusername());
    fflush(stdout);
    echo_disabled = (enable_raw_mode(old_tio) == 0);
    characters = getline(buffer, bufsize, stdin);
    if (echo_disabled)
        disable_raw_mode(old_tio);
    return characters;
}

int validate_password_input(char *buffer, ssize_t characters)
{
    if (characters == -1)
        return 0;
    if (characters > 0 && buffer[characters - 1] == '\n')
        buffer[characters - 1] = '\0';
    return 1;
}

int check_password_match(char *crypt_passwd, char *real_hash,
    try_t *essai)
{
    if (my_strcmp(crypt_passwd, real_hash) == 0) {
        setuid(0);
        setgid(0);
        return 1;
    }
    essai->try++;
    printf("Sorry, try again.\n");
    if (essai->try >= 3) {
        printf("my_sudo: 3 incorrect password attempts");
        exit(84);
    }
    return 0;
}

int check_password(try_t *essai)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;
    char *crypt_passwd;
    struct termios old_tio;

    while (essai->try < 3) {
        characters = read_password_input(&buffer, &bufsize, &old_tio);
        if (!validate_password_input(buffer, characters)) {
            free(buffer);
            return 1;
        }
        crypt_passwd = crypt(buffer, my_getsalt(find_passwd(my_getpass())));
        if (check_password_match(crypt_passwd, find_passwd(my_getpass()),
                essai) == 1) {
            free(buffer);
            return 1;
        }
    }
    return 0;
}
