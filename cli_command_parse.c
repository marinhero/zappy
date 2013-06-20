/*
** cli_command_parse.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 13 17:27:55 2013 ivan ignatiev
** Last update Thu Jun 20 18:52:20 2013 ivan ignatiev
*/

#include        "proto.h"
#include        "cli_command_parse.h"

#include        "proto_commands_net.h"
#include        "proto_commands_movement.h"
#include        "proto_commands_items.h"

t_request_type  cli_commands[] =
{
    {"avance", 7, 0, cli_parse_avance, cli_avance },
    {"droite", 7, 0, cli_parse_droite, cli_droite },
    {"gauche", 7, 0, cli_parse_gauche, cli_gauche  },
    {"voir", 7, 0, cli_parse_voir, cli_voir },
    {"inventaire", 7, 0, cli_parse_inventaire, cli_inventaire },
    {"prend", 7, 1, cli_parse_prend, cli_prend },
    {"pose", 7, 1, cli_parse_pose, cli_pose },
    {"expluse", 7, 0, cli_parse_expulse, cli_expulse },
    {"broadcast", 7, 1, cli_parse_broadcast, cli_broadcast  },
    {"incantation", 300, 0, cli_parse_incantation, cli_incantation },
    {"fork", 42, 0, cli_parse_fork, cli_fork_player },
    {"connect_nbr", 0, 0, cli_parse_connect_nbr, cli_connect_nbr },
    {NULL, 0, 0, NULL, NULL }
};

t_request_data          *request_data_init(char *message, int argc)
{
    t_request_data      *rqd;

    if((rqd = (t_request_data*)malloc(sizeof(t_request_data))) != NULL)
    {
        rqd->message = message;
        rqd->argv = NULL;
        if (argc > 0
            && (rqd->argv = (void**)malloc(sizeof(void*) * argc)) == NULL)
        {
            free(rqd);
            return (NULL);
        }
    }

    return (rqd);
}

t_request               *request_init()
{
    t_request           *request;

    if ((request = (t_request*)malloc(sizeof(t_request))) != NULL)
    {
    }

    return (request);
}

t_request               *cli_parse_request(t_user *user)
{
    t_request           *request;
    int                 i;

    if ((request = request_init()) != NULL)
    {
        i = 0;
        while (cli_commands[i].cmd)
        {
            if (strncmp(cli_commands[i].cmd, user->request, strlen(cli_commands[i].cmd)) == 0)
            {
                request->type = &cli_commands[i];
                request->current_time = request->type->delay;
                if (request->type->parse != NULL)
                {
                    if ((request->data = request->type->parse(request->type, user->request)) != NULL)
                        request->data->user = user;
                }
                else
                    request->data = NULL;
                return (request);
            }
            ++i;
        }
        free(request);
    }
    return (NULL);
}

t_request_data          *cli_parse_avance(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_droite(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_gauche(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_voir(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_inventaire(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_prend(t_request_type *type, char *message)
{
    t_request_data      *rqd;
    char                *object;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {
        if ((object = (char*)malloc(sizeof(char) * (strlen(message) - 5))) != NULL)
        {
            sscanf(message, "prend %s\n", object);
            rqd->argv[0] = (void*)object;

            printf("prend '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }

    return (rqd);
}

t_request_data          *cli_parse_pose(t_request_type *type, char *message)
{
    t_request_data      *rqd;
    char                *object;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {
        if ((object = (char*)malloc(sizeof(char) * (strlen(message) - 4))) != NULL)
        {
            sscanf(message, "pose %s\n", object);
            rqd->argv[0] = (void*)object;

            printf("pose '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }
    return (rqd);
}

t_request_data          *cli_parse_expulse(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_broadcast(t_request_type *type, char *message)
{
    t_request_data      *rqd;
    char                *text;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {
        if ((text = (char*)malloc(sizeof(char) * (strlen(message) - 9))) != NULL)
        {
            sscanf(message, "broadcast %s\n", text);
            rqd->argv[0] = (void*)text;

            printf("broadcast '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }

    return (rqd);
}

t_request_data          *cli_parse_incantation(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_fork(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_connect_nbr(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}