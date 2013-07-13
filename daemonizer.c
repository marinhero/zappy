/*
** daemonizer.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Jul 12 15:58:27 2013 Marin Alcaraz
** Last update Fri Jul 12 19:41:14 2013 Marin Alcaraz
*/

#include "main.h"
#include    "list.h"
#include    "options.h"
#include    "trantor.h"
#include    "server.h"
#include    "users.h"
#include    "request.h"
#include    "proto_commands_items.h"

static int  *g_server_result;

void        server_settings_init(t_opt *opt)
{
  opt->port = 3528;
  opt->width = 10;
  opt->height = 11;
  opt->cmax = 10;
  opt->tdelay = 100;
  opt->names = list_init();
}

void        sigint_handler(int sig)
{
    (void) sig;
    *g_server_result = 1;
}

void        output_redirection()
{
    int i_fd;
    int o_fd;
    int e_fd;

    i_fd = open("/dev/null", O_RDWR, 0);
    o_fd = open("out.log", O_WRONLY | O_APPEND | O_CREAT, 0644);
    e_fd = open("err.log", O_WRONLY | O_APPEND | O_CREAT, 0644);
    dup2(i_fd, STDIN_FILENO);
    dup2(o_fd, STDOUT_FILENO);
    dup2(e_fd, STDERR_FILENO);
    if (i_fd == -1 || o_fd == -1 || e_fd == -1)
    {
        perror("output_redirection:");
        exit(EXIT_FAILURE);
    }
}

int daemonize()
{
    int     fd;
    int     pid;
    char    buf[20];

    if ((pid = fork()) == -1)
        return (-1);
    else if (pid != 0 && pid != 1)
    {
        fd = open ("zappy.pid", O_WRONLY | O_CREAT, 0644);
        if (fd == -1)
            return (-1);
        sprintf(buf, "PID:%d", pid);
        write(fd, buf, strlen(buf));
        exit (EXIT_SUCCESS);
    }
    output_redirection();
    if (setsid() == -1)
        return (-1);
    return (0);
}

int             main(int argc, char **argv)
{
    t_server    s;
    t_world     w;

    daemonize();
    s.result = 0;
    g_server_result = &s.result;
    signal(SIGINT, sigint_handler);
    server_settings_init(&(s.options));
    options_parse(argc, argv, &(s.options));
    init_world(&w,s.options.width, s.options.height);
    generate_resource(&w,s.options.width, s.options.height);
    server_start(&s, &w);
    return 0;
}
