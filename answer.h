/*
** answer.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Tue Jun 25 17:18:35 2013 ivan ignatiev
** Last update Tue Jun 25 17:40:17 2013 ivan ignatiev
*/

#ifndef ANSWER_H_
# define ANSWER_H_

# define T_ANSWER(answer)           ((t_answer*)(answer->cont))

typedef struct  s_answer
{
    t_user      *user;
    char        *message;
}               t_answer;

t_answer    *cli_answer_create(t_user *user, char *message);
void            cli_answer(t_user *user, t_server *server, char *message);
void            cli_answer_to_graph(t_server *server, char *message);
void        cli_answers_process(t_server *s);

#endif /* !ANSWER_H_ */