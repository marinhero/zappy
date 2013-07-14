/*
** trantor.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 20 17:33:58 2013 Marin Alcaraz
** Last update Sun Jul 14 12:15:24 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"error.h"
#include	"trantor.h"

int		init_world(t_world *w, int width, int height)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  w->surface = (t_square_unit **) calloc(height, sizeof(t_square_unit *));
  while (i < height)
    {
      if ((w->surface[i] = calloc(width, sizeof(t_square_unit))) == NULL)
	return (error_show("init_world", "init_world",
			   "Error: can't allocate (width) game board\n"));
      while (j < width)
	{
	  w->surface[i][j].players = list_init();
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  w->width = width;
  w->height = height;
  return (0);
}

void		world_destroy(t_world *w)
{
  int		i;
  int		j;

  i = 0;
  while (i < w->height)
    {
      j = 0;
      while (j < w->width)
	{
	  list_delete(w->surface[i][j].players);
	  ++j;
	}
      free(w->surface[i]);
      ++i;
    }
  free(w->surface);
}

int		mineral_checker(t_square_unit *sq)
{
  int		i;

  i = 0;
  while (i < RES_TYPES_COUNT)
    {
      if (sq->resources[i] != 0)
	return (1);
      i = i + 1;
    }
  return (0);
}

int		display_world(t_world *w, int width, int height)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  printf("\n\n");
  while (i < height)
    {
      while (j < width)
        {
            if (mineral_checker(&w->surface[i][j]) != 0)
	      printf(" R ");
            else if (list_get_head((w->surface[i][j]).players) != NULL)
                printf(" P ");
            else
	      printf(" * ");
            j = j + 1;
        }
      printf("\n");
      i = i + 1;
      j = 0;
    }
  printf("\n\n");
  return (0);
}

int		generate_resource(t_world *w, int width, int height)
{
  int		amount;
  int		minx;
  int		miny;
  int		resource;

  amount = 0;
  srand(time(NULL));
  while (amount < RESOURCE_LIMIT)
    {
      minx = _MOD(rand(), width);
      miny = _MOD(rand(), height);
      resource = _MOD(rand(), 7);
      (w->surface[miny][minx]).resources[resource]++;
      amount = amount + 1;
    }
  log_show("generate_resource", "", "Resources ready to use");
  return (0);
}
