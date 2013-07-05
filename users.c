/*
** users.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:16:14 2013 ivan ignatiev
** Last update Fri Jul 05 18:34:55 2013 ivan ignatiev
*/

#include    "main.h"
#include    "list.h"
#include    "options.h"
#include    "trantor.h"
#include    "server.h"
#include	"users.h"

t_user      *user_create()
{
    t_user  *user;

    if ((user = (t_user*)malloc(sizeof(t_user))) != NULL)
    {
        user->protocol = NONE_PROTO;
        user->connected = PRE_CONNECTED;
        user->request = NULL;
        user->addrlen = sizeof(struct sockaddr_in);
    }
    return (user);
}

t_user_player       *user_player_init(t_user *user, t_team *team, t_world *w, t_server *s)
{
    int             i;
    t_user_player   *player;

    if ((player = realloc(user, sizeof(t_user_player))) != NULL)
    {
        player->connected = CONNECTED;
        player->protocol = CLI_PROTO;
        player->posx = rand() % s->options.width;
        player->posy = rand() % s->options.height;
        player->direction = rand() % 8;
        player->tick = 0;
        player->level = 1;
        player->request_counter = 0;
        player->team = team;
        i = 0;
        while (i < ARTICLES_LIMIT)
        {
            player->inventory[i] = 0;
            ++i;
        }
        player->inventory[FOOD] = 10; //1260 * t sec
        item_pf(w->surface[player->posy][player->posx].players, (void*)player, sizeof(t_user_player));
    }
    return (player);
}

t_user_graph        *user_graph_init(t_user *user)
{
    t_user_graph    *graph;

    if ((graph = realloc(user, sizeof(t_user_graph))) != NULL)
    {
        graph->protocol = GRAPHIC_PROTO;
        graph->connected = CONNECTED;
    }
    return (graph);
}

void        user_destroy(t_user *user)
{
    (void) user;
}

t_team      *team_create(char *name)
{
    t_team  *team;

    if ((team = (t_team*)malloc(sizeof(t_team))) != NULL)
    {
        strcpy(team->name, name);
        team->members = 0;
        printf("Team created : '%s' \n", team->name);
    }
    return (team);
}

t_team          *team_search(t_list *team_list, char *team_name)
{
    t_item      *current;

    current = team_list->head;
    while (current != NULL)
    {
        if (strcmp(T_TEAM(current)->name, team_name) == 0)
            return (T_TEAM(current));
        current = current->next;
    }
    return (NULL);
}

t_list      *team_list_init(t_list *team_list, t_list *team_names)
{
    t_team  *team;
    t_item  *current;

    team_list = list_init();
    current = team_names->head;
    while (current != NULL)
    {
        team = team_create((char*)(current->cont));
        item_pf(team_list, (void*)team, sizeof(t_team));
        current = current->next;
    }
    return (team_list);
}

void        team_destroy(t_team *team)
{
    (void) team;
}
