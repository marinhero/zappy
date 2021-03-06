/*
** proto_commands_net.h for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:35:15 2013 Marin Alcaraz
** Last update Sat Jul 13 18:58:19 2013 ivan ignatiev
*/

#ifndef PROTO_COMMANDS_NET_H_
# define PROTO_COMMANDS_NET_H_

void	expulse_square(t_point *n, t_request_data *rqd,
		       t_world *w, t_server *s);
void	cli_expulse(t_request_data *rqd,
		    t_server *t, t_world *w);
void	cli_incantation(t_request_data *rqd,
			t_server *t, t_world *w);
void	cli_fork_player(t_request_data *rqd,
			t_server *t, t_world *w);
void	cli_connect_nbr(t_request_data *rqd,
			t_server *t, t_world *w);
void	cli_hatch_egg(t_request_data *rqd,
		      t_server *s, t_world *w);

#endif /* !PROTO_COMMANDS_NET_H_ */
