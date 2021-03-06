#include <stdio.h>
#include <time.h>
#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"
#include "libaux.h"

#include "libmysort.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	int			*ref_ar;
	size_t		i;

	#define SZ 3 
	ref_ar = ((int[SZ]){0, 1, 2});
	#define SZM1 (SZ - 1)

	T(tiny_ar,
		int				ar[SZ];
		size_t			i;
		t_s_sort_ard	ard;

		time_t			time_1;
		time_t			time_2;

		for (i = 0; i < SZ; i++)
			ar[i] = i;
		ard = ((t_s_sort_ard){sizeof(int), ar, ar + SZM1});
		time(&time_1);
		sort_ar_ip(&int_ord, &ard);
		time(&time_2);
		printf("sorted in %llu\nseconds", (unsigned long long)(time_2 - time_1));
		assert_memory_equal(ar, ref_ar, SZ * sizeof(int));
	)
	#undef SZ
	#define SZ 20
	ref_ar = ((int[SZ]){
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
			10, 11, 12, 13, 14, 15, 16, 17, 18, 19});

	T(ar,
		int				ar[SZ];
		size_t			i;
		t_s_sort_ard	ard;

		time_t			time_1;
		time_t			time_2;

		for (i = 0; i < SZ; i++)
			ar[i] = i;
		ard = ((t_s_sort_ard){sizeof(int), ar, ar + SZM1});
		time(&time_1);
		sort_ar_ip(&int_ord, &ard);
		time(&time_2);
		printf("sorted in %llu\nseconds", (unsigned long long)(time_2 - time_1));
		assert_memory_equal(ar, ref_ar, SZ * sizeof(int));
	)

	T(rev_ar,
		int				ar[SZ];
		size_t			i;
		t_s_sort_ard	ard;

		time_t			time_1;
		time_t			time_2;

		for (i = 0; i < SZ; i++)
			ar[i] = SZ - i - 1;
		ard = ((t_s_sort_ard){sizeof(int), ar, ar + SZM1});
		time(&time_1);
		sort_ar_ip(&int_ord, &ard);
		time(&time_2);
		printf("sorted in %llu\nseconds", (unsigned long long)(time_2 - time_1));
		assert_memory_equal(ar, ref_ar, SZ * sizeof(int));
	)
	#undef SZ
	#define SZ 10000
	ref_ar = ((int[SZ]){});
	for (i = 0; i < SZ; i++)
		ref_ar[i] = i;
	
	T(medium_ar,
		int				ar[SZ];
		size_t			i;
		t_s_sort_ard	ard;

		time_t			time_1;
		time_t			time_2;

		for (i = 0; i < SZ; i++)
			ar[i] = i;
		ard = ((t_s_sort_ard){sizeof(int), ar, ar + SZM1});
		time(&time_1);
		sort_ar_ip(&int_ord, &ard);
		time(&time_2);
		printf("sorted in %llu\nseconds", (unsigned long long)(time_2 - time_1));
		assert_memory_equal(ar, ref_ar, SZ * sizeof(int));
	)

	T(medium_rev_ar,
		int				ar[SZ];
		size_t			i;
		t_s_sort_ard	ard;

		time_t			time_1;
		time_t			time_2;

		for (i = 0; i < SZ; i++)
			ar[i] = SZ - i - 1;
		ard = ((t_s_sort_ard){sizeof(int), ar, ar + SZM1});
		time(&time_1);
		sort_ar_ip(&int_ord, &ard);
		time(&time_2);
		printf("sorted in %llu\nseconds", (unsigned long long)(time_2 - time_1));
		assert_memory_equal(ar, ref_ar, SZ * sizeof(int));
	)

	return(run_test_arr(all_of, these));
}
