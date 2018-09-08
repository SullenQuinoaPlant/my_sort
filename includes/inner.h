#ifndef INNER_H
# define INNER_H

# include "mysort.h" 

typedef enum			e_more_or_less {
	e_less,
	e_more,
	e_mol_sz
}						t_e_mol;

void					swap(
	void		*a,
	void		*b,
	void		*buf,
	size_t		sz);

#endif
