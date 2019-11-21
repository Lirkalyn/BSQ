/*
** EPITECH PROJECT, 2019
** Day_08
** File description:
** my_show_word_array
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_show_word_array(char * const *tab)
{
    int i;
    int j;

    for (i = 0; tab[i] != 0; i++) {
        for (j = 0; tab[i][j] != '\0'; j++)
            my_putchar(tab[i][j]);
        my_putchar('\n');
    }
    return 0;
}
