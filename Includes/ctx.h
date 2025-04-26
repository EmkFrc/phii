/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:49:22 by efranco           #+#    #+#             */
/*   Updated: 2025/03/25 16:01:46 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include <stdio.h>
# include <stdlib.h>

# define MAX_CONTEXT 255

typedef struct s_ctx_lst
{
	void				*address;
	struct s_ctx_lst	*next;
}						t_ctx_lst;

typedef struct s_ctx
{
	unsigned char		level;
	t_ctx_lst			*contexts[MAX_CONTEXT];

}						t_ctx;

t_ctx					*get_ctx(void);
void					*safe_malloc(size_t size);
t_ctx_lst				*create_ctx_lst(void *ptr);
void					add_to_ctx(t_ctx_lst *lst, unsigned char level);
void					free_all(void);
t_ctx_lst				**get_ctx_lst(unsigned char level);
unsigned char			get_ctx_level(void);
void					safe_free(void *ptr);
void					enter_malloc_ctx(void);
void					exit_malloc_ctx(void);
void					free_level(unsigned char level);
void					send_to_upper_context(void *ptr);
void					send_to_main_context(void *ptr);

#endif
