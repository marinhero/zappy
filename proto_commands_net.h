/*
** proto_commands_net.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:35:15 2013 Marin Alcaraz
** Last update Thu Jun 13 16:47:45 2013 Marin Alcaraz
*/

#ifndef PROTO_COMMANDS_NET_H_
# define PROTO_COMMANDS_NET_H_

#include "server.h"

void    cli_expulse(t_server *t, t_world *w);
void    cli_incantation(t_server *t, t_world *w);
void    cli_fork_player(t_server *t, t_world *w);
void    cli_connect_nbr(t_server *t, t_world *w);
void    cli_death(t_server *t, t_world *w);

#endif /* !PROTO_COMMANDS_NET_H_ */
