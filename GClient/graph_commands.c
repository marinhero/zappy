/*
** graph_command.c for zappy in /home/hero/zappy
** 
** Made by Ivan Ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Sun Jul 14 21:49:58 2013 ivan ignatiev
*/

#include	<string.h>
#include	"graph_commands.h"
#include	"gclient_auth.h"
#include	"gclient_ping.h"
#include	"gclient_funcs.h"

static t_gcmd	g_graph_cmd[] =
{
  {"msz", gcmd_msz},
  {"bct", gcmd_bct},
  {"tna", gcmd_tna},
  {"pnw", gcmd_pnw},
  {"ppo", gcmd_ppo},
  {"plv", gcmd_plv},
  {"pin", gcmd_pin},
  {"pex", gcmd_pex},
  {"pbc", gcmd_pbc},
  {"pic", gcmd_pic},
  {"pie", gcmd_pie},
  {"pfk", gcmd_pfk},
  {"pdr", gcmd_pdr},
  {"pgt", gcmd_pgt},
  {"pdi", gcmd_pdi},
  {"enw", gcmd_enw},
  {"eht", gcmd_eht},
  {"ebo", gcmd_ebo},
  {"edi", gcmd_edi},
  {"sgt", gcmd_sgt},
  {"seg", gcmd_seg},
  {"smg", gcmd_smg},
  {"suc", gcmd_suc},
  {"sbp", gcmd_sbp},
  {NULL, NULL}
};

int	cmd_process(char *cmd, t_pm *pm)
{
  int	i;

  i = 0;
  if (pm->auth == -1)
    return (ll_auth(cmd, pm));
  while (g_graph_cmd[i].scmd)
    {
      if (strncmp(cmd, g_graph_cmd[i].scmd, 3) == 0)
	return (g_graph_cmd[i].func(cmd, pm));
      ++i;
    }
  cmd_put(-1, cmd);
  return (-1);
}

int	gcmd_msz(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 2)
    {
      cmd_put(-1, cmd);
      cmd_send(pm, "mct\n");
      return (-1);
    }
  ping_save(pm);
  cmd_put(1, cmd);
  return (1);
}

int	gcmd_bct(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 9)
    {
      cmd_put(-1, cmd);
      cmd_send(pm, "mct\n");
      return (-1);
    }
  ping_save(pm);
  cmd_put(1, cmd);
  return (1);
}

int	gcmd_tna(char *cmd, t_pm *pm)
{
  ping_save(pm);
  cmd_put(1, cmd);
  return (1);
}
