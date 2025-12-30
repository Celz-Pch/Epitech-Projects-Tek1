/*
** EPITECH PROJECT, 2025
** check_life
** File description:
** check_life
*/

#include "../../include/csfml.h"

sfMusic *init_game_music(void)
{
    sfMusic *music = sfMusic_createFromFile("./assets/song.ogg");

    if (music) {
        sfMusic_setLoop(music, sfTrue);
        sfMusic_setVolume(music, 10.0f);
        sfMusic_play(music);
    }
    return music;
}

sfMusic *attack_song(void)
{
    sfMusic *music = sfMusic_createFromFile("./assets/attack.ogg");

    if (music) {
        sfMusic_setVolume(music, 50.0f);
        sfMusic_play(music);
    }
    return music;
}
