#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ftdef.h"

/*!
 * \struct vector
 * \brief dynamic size array with auto reallocations
 * \param size size of current array (byte size = size * cell_size)
 * \param capacity size of allocated array (byte size = capacity * cell_size)
 * \param cell_size size of one cell
 */
typedef struct s_vector {
	size_t	size;
	size_t	capacity;
	void	*array;
	t_uint	cell_size;
}					t_vector;

/*!
 * \fn t_bool ft_vec_realloc(t_vector *vec, size_t new_capacity)
 * \brief reallocate array to new reserv size
 * \details if allocated failes, vector remains in state of preceding reallocation
 * \param new_capacity new reserv size of array
 * \return return false if allocation failes. In other cases return true
 */
extern t_bool		ft_vec_realloc(t_vector *vec, size_t new_capacity);
/*!
 * \fn t_bool ft_vec_realloc(t_vector *vec, size_t new_capacity)
 * \brief dublicate behavior of ft_vec_realloc()
 * \see ft_vec_realloc()
 */
extern t_bool		ft_vec_resize(t_vector *vec, size_t new_capacity);


/*!
 * \fn void ft_vec_construct(t_vector *vec, t_uint cell_size)
 * \brief construct vector
 * \param cell_size cell of the single cell
 */
extern void			ft_vec_construct(t_vector *vec, t_uint cell_size);

/*!
 * \fn void ft_vec_destructor(t_vector *vec, void (*fr)(void *))
 * \brief construct vector
 * \param fr destructor for single cell (may be NULL)
 */
extern void			ft_vec_destructor(t_vector *vec, void (*fr)(void *));

/*!
 * \fn void ft_vec_pop_back(t_vector *vec, void (*del)(void *));
 * \see ft_vec_remove_at()
 * \brief destruct last element and remove it
 * \param del destructor for single cell (may be NULL)
 */
extern void			ft_vec_pop_back(t_vector *vec, void (*del)(void *));

/*!
 * \fn void ft_vec_pop_front(t_vector *vec, void (*del)(void *));
 * \see ft_vec_remove_at()
 * \brief destruct first element and remove it
 * \param del destructor for single cell (may be NULL)
 */
extern void			ft_vec_pop_front(t_vector *vec, void (*del)(void *));

/*!
 * \fn t_bool ft_vec_push_back(t_vector *vec, void *data);
 * \see ft_vec_pop_back() ft_vec_pop_front()
 * \brief destruct pos element and remove it
 * \param pos position to destruct and delete
 * \param del destructor for single cell (may be NULL)
 */
extern void			ft_vec_remove_at(t_vector *vec, \
						size_t pos, void (*del)(void*));

/*!
 * \fn t_bool ft_vec_push_reserv(t_vector *vec);
 * \brief reserv capacity for next element push
 * \details reallocate array if capacity is not enough for next push element.
 * capacity doubles
 * \return return false if allocation failes. In other cases return true
 */
extern t_bool		ft_vec_push_reserv(t_vector *vec);

/*!
 * \fn t_bool ft_vec_push_back(t_vector *vec, void *data);
 * \brief push element to array end by copying it in 'cell_size' byte
 * \return return false if allocation failes. In other cases return true
 */
extern t_bool		ft_vec_push_back(t_vector *vec, void *data);

extern void			*ft_vec_at(t_vector *vec, size_t pos);
extern void			*ft_vec_front(t_vector *vec);
extern void			*ft_vec_back(t_vector *vec);

/*!
 * \fn void *ft_vec_fetch_array(t_vector *vec, size_t *out_size);
 * \brief releases array from vector and return it to valid state
 * \param out_size save size of vector
 * \return a pointer to array memory area
 */
extern void			*ft_vec_fetch_array(t_vector *vec, size_t *out_size);

/*!
 * \fn t_bool ft_vec_copy(t_vector *copy, t_vector *sample);
 * \brief construct copy vector from sample
 * \param copy pointer to non valid vector
 * \param sample pointer to valid copied vector
 * \return return false if allocation failes. In other cases return true
 */
extern t_bool		ft_vec_copy_construct(t_vector *copy, t_vector *sample);

extern void			ft_vec_foreach(t_vector *vec, void (*f)(void *));

#endif
