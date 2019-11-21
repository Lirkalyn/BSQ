/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** reverse-desu
*/

#include <stdlib.h>

int **tab_int_maker(int height)
{
    int i;
    int j;
    int **res;

    res = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        res[i] = (int *)malloc(height * sizeof(int));
        for (j = 0; j < height; j++) {
            res[i][j] = 0;
        }
    }
    return res;
}

char *height_finders(char *buf, int *height)
{
    int i = 0;

    while (buf[i] != '\n') {
        *height *= 10;
        *height += (buf[i] - '0');
        i++;
    }
    return (buf + i + 1);
}

int *big_finder(char **tab, int height, int **int_tab)
{
    int i;
    int j;
    int *sqr;// = {[0 ... 2] = 0};

    sqr = (int *)malloc(3 * sizeof(int));
    sqr[0] = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if (int_tab[i][j] > sqr[0]) {
                sqr[0] = int_tab[i][j];
                sqr[1] = i;
                sqr[2] = j;
            }
        }
    }
    return sqr;
}

int angle(int i, int j, char **tab)
{
    if (i == 0 && j == 0 && tab[i][j] == '.')
        return 1;
    else if (i == 0 && j == 0 && tab[i][j] == 'o')
        return 0;
    if (i == 0 && j != 0 && tab[i][j] == '.')
        return 1;
    else if (i == 0 && j != 0 && tab[i][j] == 'o')
        return 0;
    if (j == 0 && i != 0 && tab[i][j] == '.')
        return 1;
    else if (j == 0 && i != 0 && tab[i][j] == 'o')
        return 0;
}

int value_finder(int first, int second, int third)
{
    int tmp = first;

    if (first < tmp)
        tmp = first;
    if (second < tmp)
        tmp = second;
    if (third < tmp)
        tmp = third;
    return (tmp + 1);
}