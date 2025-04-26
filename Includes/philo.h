#ifndef PHILO_H
# define PHILO_H

# include "ctx.h"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef enum e_timecode
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_timecode;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	long				meals_counter;
	bool				full;
	long				last_meal_time;
	t_data				*data;
	pthread_t			thread;
	pthread_mutex_t		philo_mutex;
	t_fork				*right_fork;
	t_fork				*left_fork;
}						t_philo;

typedef struct s_data
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				start_simulation;
	long				full_counter;
	bool				end_simulation;
	bool				all_thread_ready;
	t_philo				*philos;
	pthread_t			monitor;
	pthread_mutex_t		data_mutex;
	pthread_mutex_t		write_mutex;
}						t_data;

int						ft_atoi(const char *theString);
long					ft_atol(const char *theString);
int						ft_isdigit(int character);
void					parse_line(char **line, int count);
void					check_each_arguments(int count, char **line);
void					check_one_arg(char *arg);
void					check_special(char *str, int count);
void					data_init(t_data *data, char **av);
void					*routine(void *data);
void					create_table(t_data *data);
void					set_bool(pthread_mutex_t *mtx, bool *dest, bool value);
void					set_long(pthread_mutex_t *mtx, long *dest, long value);
bool					get_bool(pthread_mutex_t *mtx, bool *value);
long					get_long(pthread_mutex_t *mtx, long *value);
long					gettime(void);
void					printf_log(t_philo *philo, char *str);
void					eating(t_philo *philo);
bool					simulation_finish(t_data *data);
void					custom_usleep(t_philo *philo, long time);
void					sleeping(t_philo *philo);
void					thinking(t_philo *philo);
long					gettime_us(void);
void					*monitor(void *arg);
bool					is_full(t_data *data);
#endif
