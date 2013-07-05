/*
** trantor.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 20 17:38:38 2013 Marin Alcaraz
** Last update Fri Jul 05 13:14:06 2013 ivan ignatiev
*/

#ifndef TRANTOR_H_
# define TRANTOR_H_

#define FOOD        0
#define LINEMATE    1
#define DERAUMERE   2
#define SIBUR       3
#define MENDIANE    4
#define PHIRAS      5
#define THYSTAME    6

typedef struct  s_square_unit
{
    t_list      *players;
    int         resources[7];
}               t_square_unit;

typedef struct      s_world
{
    t_square_unit   **surface;
    int             width;
    int             height;
}                   t_world;

int        init_world(t_world *w, int width, int height);
int        display_world(t_world *w, int width, int height);
int        generate_resource(t_world *w, int width, int height);
int        mineral_checker(t_square_unit sq);
void       random_number(int *container, int limit);

#endif /* !TRANTOR_H_ */
