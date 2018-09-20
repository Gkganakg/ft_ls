/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:12:53 by gkganakg          #+#    #+#             */
/*   Updated: 2018/09/07 15:18:38 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <pwd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <grp.h>
# include <pwd.h>

struct dirent			t_dirent;
typedef	struct stat		t_stat;
struct passwd			*pwd;
struct group			*grp;
struct s_info			*node;

typedef	struct			s_fla
{
	int	r;
	int	rr;
	int	l;
	int	a;
	int	t;
	int	d;

}						t_fla;
typedef struct			s_info
{
	char				name[50];
	char				date[50];
	struct s_info		*next;
}						t_info;

int						main(int ac, char **av);
int						is_valid(char c);
int						time_cmp(const char *time1, \
		const char *time2);
void					print_user_groupid(t_stat stat);
void					print_grid(gid_t gid);
void					print_userid(uid_t uid);
int						check_path(int n, char **s);
void					ft_names(char *str);
void					beat_norm(char *av, t_fla *fla);
void					print_error(char c);
void					set_flags(char c, t_fla *fla);
t_info					*reverse(t_info *head);
void					check_args(int ac, char **av, t_fla *fla);
void					print_cdir(char *path);
void					print_long(char *dpath);
void					ft_storage(char *str, char *tmp);
void					display_list(t_info *list);
void					sort_function(t_info *list);
void					ft_storage(char *str, char *tmp);
int						save_lines(char *str);
void					print_permission(mode_t file_mode);
void					ft_storage(char *str, char *tmp);
char					*trim_time(char *timed);
void					*print_time(char *timed);
int						save_lines(char *str);
void					space_saver(char c);
void					print_size(t_stat stat);
void					print_mode(mode_t mode);
void					ft_strdupp(char *str, char *s);
static void				print_user(uid_t uid);
static void				print_group(gid_t gid);
void					print_user_group(t_stat stat);
void					print_all(char *dpath);
void					print_rev(char *dpath);
void					time_sort(char *dpath);
#endif
