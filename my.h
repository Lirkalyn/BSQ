/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** .h-desu
*/

#ifndef _MY_H_
#define _MY_H_

int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
int value_finder(int first, int second, int third);
int angle(int i, int j, char **tab);
int *big_finder(char **tab, int height[], int **int_tab);
char *height_finders(char *buf, int height[]);
int **tab_int_maker(int height[]);

#endif