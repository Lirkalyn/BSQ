/*
** EPITECH PROJECT, 2019
** Day_08
** File description:
** my_show_word_array
*/

#include <unistd.h>

void my_putchar(char *c, int len)
{
    write(1, c, len);
}

int my_show_word_array(char * const *tab, int len)
{
    int i;
    int j;

    for (i = 0; tab[i] != 0; i++) {
        my_putchar(tab[i], len);
        my_putchar("\n", 1);
    }
    return 0;
}
