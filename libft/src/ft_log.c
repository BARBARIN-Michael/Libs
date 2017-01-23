/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 22:01:18 by barbare           #+#    #+#             */
/*   Updated: 2016/09/08 15:14:26 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

/* *********
 * ft_log("Je suis une erreur", "warning");
 * ********* */

void ft_log(const char *content, const char *error)
{
	int fd_file;
	char *fileName;
	char datetime[200];
	time_t rawtime;
	struct tm *timeinfo;

	time (&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(datetime, sizeof(datetime) - 1, "%d.%m.%y", timeinfo);
	fileName = ft_multi_strjoin(3, "log/[", datetime, "].log");
	strftime(datetime, sizeof(datetime) - 1, "%d.%m.%y_%H:%M:%S", timeinfo);
	if ((fd_file = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
		return ;
	free(fileName);
	fileName = ft_multi_strjoin(7, "[", error, " - ", datetime, "] ", content, "\n");
	ft_putstr_fd(fileName, fd_file);
	free(fileName);
	close(fd_file);
}
