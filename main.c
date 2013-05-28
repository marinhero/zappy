#include <stdlib.h> // atoi
#include <stdio.h> // printf
#include <unistd.h> // getopt
#include "options.h"

static void dump_string(void *content, int size)
{
  printf(" %s\n", (char*)content);
}

void  server_settings_init(t_opt *opt)
{
  opt->port = 0; 
  opt->width = 0; 
  opt->height = 0; 
  opt->nclients = 0; 
  opt->tdelay = 0;
  opt->names = new_list_by_default();
}

void  usage_display(char *str)
{
  printf("Usage: %s [option] argument(s)\n", str);
  printf("Server options :\n");
  printf("-p port\n-x width of the world\n");
  printf("-y height of the world\n-n name_of_team_1 name_of_team_2 ...\n");
  printf("-c number of clients allowed at the game beginning\n");
  printf("-t time delay for executing actions.\n");
  exit(0);
}

int   main(int argc, char *argv[])
{
  t_opt g_opt;
  
  server_settings_init(&g_opt);
  options_parse(argc, argv, &g_opt);

  printf("-p=%d, -x=%d, -y=%d, -c=%d, -t=%d\n", 
    g_opt.port, g_opt.width, g_opt.height, g_opt.nclients, g_opt.tdelay);
  printf("Teams (%d):\n", g_opt.names->len);
  list_iter(g_opt.names, &dump_string);

  delete_list(g_opt.names);
  return 1;
}