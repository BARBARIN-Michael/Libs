/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 10:58:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/20 19:53:18 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKING_H
# define FT_CHECKING_H

# include <ft_printf.h>
# include <libft.h>
# include <stdio.h>
# include <errno.h>

# define LECT_LINE() ft_printf("DEBUG : %s:%d: ", __FILE__, __LINE__)
# define DEBUG(D, ...) LECT_LINE(); ft_printf(D "\n", ##__VA_ARGS__)

# define LECT_FCT(F, E) ft_printf(" Fonction( "F" ) : " E "\n")
# define N_ERR(E, F)  ft_printf(C_RED"[N_ERR]"C_NONE); LECT_FCT(F, E); exit(-1); 
# define F_ERR(E, F)  ft_printf(BRED"[F_ERR]"C_NONE); LECT_FCT(F, E); exit(-2); 
# define INFO(I, F) ft_printf(C_GREEN"[INFO] "C_NONE"Fct( " F " ) :" I "\n")
# define CHECK(C, S, ...) if(!(C)) ft_printf(S "\n", ##__VA_ARGS__)
# define CHECK_F(C, S, ...) if(!(C)) ft_printf(S "\n", ##__VA_ARGS__); exit(-3);

#endif
