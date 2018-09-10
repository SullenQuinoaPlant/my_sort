#include <stdio.h>
#include <time.h>
#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"
#include "libaux.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(nop,
		printf("int arrays\n");
		assert_true(1);
	)


	#define SZ 20
	int			*ref_ar_SZ;
	ref_ar_SZ = ((int[SZ]){
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
		ard = {sizeof(int), SZ, ar};
		time(&time_1);
		sort_ar_ip(&int_ord, &ard);
		time(&time_2);
		printf("sorted in %llu\n", (unsigned long long)(time_2 - time_1));
		assert_memory_equal(ar, ref_ar_SZ, SZ * sizeof(int));
	)

	T(rev_ar,
		int				ar[SZ];
		size_t			i;
		t_s_sort_ard	ard;

		time_t			time_1;
		time_t			time_2;

		for (i = 0; i < SZ; i++)
			ar[i] = SZ - i - 1;
		ard = {sizeof(int), SZ, ar};
		time(&time_1);
		sort_ar_ip(&int_ord, &ard);
		time(&time_2);
		printf("sorted in %llu\n", (unsigned long long)(time_2 - time_1));
		assert_memory_equal(ar, ref_ar_SZ, SZ * sizeof(int));
	)

	return(run_test_arr(all_of, these));
}
