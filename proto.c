/*
** proto.c for zappy in /home/ignati_i/zappy/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 16:34:40 2013 Marin Alcaraz
** Last update Sun Jul 14 12:44:48 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"item.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"select.h"
#include	"request.h"
#include	"answer.h"
#include	"cli_command_parse.h"
#include	"graph_command.h"
#include	"proto.h"
#include	"error.h"
#include	"str.h"

int		proto_flud_detect(t_user *u, char *buf)
{
  if (strchr(buf, '\n') == NULL)
    {
      u->connected = DISCONNECTED;
      return (error_show("clu_parse", "", "Flud client detected"));
    }
  return (0);
}

int		graph_parse(t_user_graph *u, t_server *s, t_world *w)
{
  int		rb;
  char		buf[PROTO_BUFFER + 1];

  if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb] = '\0';
        if (proto_flud_detect(T_USER(u), buf) < 0)
            return (-1);
        u->request_buf = stralloccat(u->request_buf, buf);
        while ((u->request = getnextline(u->request_buf)) != NULL)
	  {
            log_show("graph_parse", "", "GFX Request '%s' accepted",
		     u->request);
            graph_command_exec(u, s, w, u->request);
            free(u->request);
	  }
        return (0);
    }
  u->connected = DISCONNECTED;
  return (-1);
}

int		proto_parse(t_user *u, t_server *s, t_world *w)
{
  if (u->protocol == CLI_PROTO)
    return (cli_parse((t_user_player*)u, s, w));
  return (graph_parse((t_user_graph*)u, s, w));
}

t_user		*proto_define_transform(t_user *u,
					t_server *s, t_world *w)
{
  t_team	*team;
  t_user_player	*tmp;

  if (strcmp(u->request, "GRAPHIC") == 0)
    {
      u =  ((t_user*)user_graph_init(u));
      free(u->request);
      return (u);
    }
  else if ((team = team_search(s->team_list, u->request)) != NULL
	   && team->limit > 0)
    {
      tmp = user_player_egg(u, team, w, s);
      u = T_USER(tmp == NULL ? user_player_init(u, team, w, s) : tmp);
      free(u->request);
      return (u);
    }
  error_show("proto_define", "", "Limit of players or undefined team");
  server_send(u->clientfd, "ko\n");
  u->connected = DISCONNECTED;
  return (u);
}

t_user		*proto_define(t_user *u, t_server *s, t_world *w)
{
  int		rb;
  char		buf[PROTO_BUFFER + 1];

  if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
      buf[rb] = '\0';
      if (proto_flud_detect(u, buf) < 0)
	return (u);
      u->request_buf = stralloccat(u->request_buf, buf);
      if ((u->request = getnextline(u->request_buf)) != NULL)
	return (proto_define_transform(u, s, w));
    }
  u->connected = DISCONNECTED;
  return (u);
}
