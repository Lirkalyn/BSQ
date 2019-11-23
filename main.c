/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** main-desu
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int main3(char **tab, int height[], int **int_tab)
{
    int *sqr;
    int i;
    int j;

    sqr = big_finder(tab, height, int_tab);
    for (i = 0; i < sqr[0]; i++) {
        for (j = 0; j < sqr[0]; j++) {
            tab[(sqr[1] - i)][(sqr[2] - j)] = 'x';
        }
    }
    my_show_word_array(tab, height[1]);
    return 0;
}

int main2(char **tab, int height[])
{
    int **int_tab;
    int fst[3];

    int_tab = tab_int_maker(height);
    for (int i = 0; i < height[0]; i++)
        for (int j = 0; j < height[1]; j++) {
            if (i == 0 || j == 0)
                int_tab[i][j] = angle(i, j, tab);
            if (i != 0 && j != 0 && tab[i][j] == '.') {
                fst[0] = int_tab[i][(j - 1)];
                fst[1] = int_tab[(i - 1)][j];
                fst[2] = int_tab[(i - 1)][(j - 1)];
                int_tab[i][j] = value_finder(fst[0], fst[1], fst[2]);
            }
            else if (i != 0 && j != 0 && tab[i][j] == 'o')
                int_tab[i][j] = 0;
        }
    return main3(tab, height, int_tab);
}

int main(int argc, char **argv)
{
    struct stat fileStat;
    char *buf;
    int adre_readedbyte[2];
    int height[3] = {[0 ... 2] = 0};
    char **tab;

    if (argc != 2)
        return 84;
    if (stat(argv[1], &fileStat) < 0)
        return 84;
    buf = (char *)malloc((fileStat.st_size + 1) * sizeof(char));
    adre_readedbyte[0] = open(argv[1], O_RDONLY);
    if (adre_readedbyte[0] == -1 || adre_readedbyte[0] > 3)
        return 84;
    adre_readedbyte[1] = read(adre_readedbyte[0], buf, fileStat.st_size);
    buf[fileStat.st_size] = '\0';
    buf = height_finders(buf, height);
    tab = my_str_to_word_array(buf);
    return (height[0] != height[2]) ? 84 : main2(tab, height);
}