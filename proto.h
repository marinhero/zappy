/*
** proto.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Thu Jun 20 18:59:54 2013 ivan ignatiev
*/

#ifndef PROTO_H_
# define PROTO_H_

# include "server.h"
# include "select.h"
# include "request.h"
# include "cli_command_parse.h"

# define PROTO_BUFFER               256

void        cli_parse(t_user *u, t_server *s, t_world *);
void        graph_parse(t_user *u, t_server *s, t_world *);
int         proto_parse(t_user *u, t_server *s, t_world *w);
int         proto_define(t_user *u, t_world *w);

#endif /* !PROTO_H_ */