/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:10:27 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/19 10:49:20 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define PRF "\033["
# define SUF "m"
# define RESET PRF "0" SUF

# define BLACK PRF "30" SUF
# define RED PRF "31" SUF
# define GREEN PRF "32" SUF
# define YELLOW PRF "33" SUF
# define BLUE PRF "34" SUF
# define MAGENTA PRF "35" SUF
# define CYAN PRF "36" SUF
# define WHITE PRF "37" SUF
# define BRIGHT_BLACK PRF "90" SUF
# define BRIGHT_RED PRF "91" SUF
# define BRIGHT_GREEN PRF "92" SUF
# define BRIGHT_YELLOW PRF "93" SUF
# define BRIGHT_BLUE PRF "94" SUF
# define BRIGHT_MAGENTA PRF "95" SUF
# define BRIGHT_CYAN PRF "96" SUF
# define BRIGHT_WHITE PRF "97" SUF

# define BG_BLACK PRF "40" SUF
# define BG_RED PRF "41" SUF
# define BG_GREEN PRF "42" SUF
# define BG_YELLOW PRF "43" SUF
# define BG_BLUE PRF "44" SUF
# define BG_MAGENTA PRF "45" SUF
# define BG_CYAN PRF "46" SUF
# define BG_WHITE PRF "47" SUF
# define BG_BRIGHT_BLACK PRF "100" SUF
# define BG_BRIGHT_RED PRF "101" SUF
# define BG_BRIGHT_GREEN PRF "102" SUF
# define BG_BRIGHT_YELLOW PRF "103" SUF
# define BG_BRIGHT_BLUE PRF "104" SUF
# define BG_BRIGHT_MAGENTA PRF "105" SUF
# define BG_BRIGHT_CYAN PRF "106" SUF
# define BG_BRIGHT_WHITE PRF "107" SUF

# define BOLD PRF "1" SUF
# define ITALIC PRF "3" SUF
# define FRAMED PRF "51" SUF
# define ENCIRCLED PRF "52" SUF
# define OVERLINED PRF "53" SUF
#endif