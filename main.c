/*
** main.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Wed Jun 12 14:48:50 2013 Marin Alcaraz
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "options.h"
#include "server.h"

void  server_settings_init(t_opt *opt)
{
  opt->port = 3528;
  opt->width = 600;
  opt->height = 600;
  opt->cmax = 2;
  opt->tdelay = 0;
  opt->names = list_init();
}

void                sigint_handler(int sig)
{
    (void) sig;
}

int     main(int argc, char *argv[])
{
  t_opt opt;

  signal(SIGINT, sigint_handler);
  server_settings_init(&opt);
  options_parse(argc, argv, &opt);
  server_start(&opt);
  /** TODO FREE RESOURCES **/
  list_delete(opt.names);
  return (1);
}
