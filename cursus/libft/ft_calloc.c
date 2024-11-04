/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:11:33 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:29 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_bzero(str,nmemb*size);
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = malloc(nmemb * size);
	if (str == NULL)
	{
		return (NULL);
	}
	ft_memset(str, 0, nmemb * size);
	return (str);
}
/*
int	main(void)
{
	char	*s;
	char	*_s;
	char	*__s;

	//hna size nmb 0 we size 0
	char *ss =(char*)calloc(0,0);
	s = (char *)ft_calloc(0,0);
	printf("[%x][%p]\n[%x][%p] \n",s,s,ss,ss);
	if(s!= NULL &&ss != NULL)
	{
		printf("machi null akhay  l'hackor\n\n");
	}
	//hna size nmb 4 we size 0
	char *_ss =(char*)calloc(4,0);
	_s = (char *)ft_calloc(4,0);
	printf("[%x][%p]\n[%x][%p] \n",_s,_s,_ss,_ss);
	if(_s!= NULL && _ss != NULL)
	{
		printf("machi null akhay  l'hackor\n\n");
	}
	//hna size nmb 4 we size of int
	char *__ss =(char*)calloc(0,sizeof(int));
	__s = (char *)ft_calloc(4,sizeof(int));
	printf("[%x][%p]\n[%x][%p] \n",__s,__s,__ss,__ss);
	if(__s!= NULL && __ss != NULL)
	{
		printf("machi null akhay  l'hackor\n\n");
	}
	return(0);
}
*/
