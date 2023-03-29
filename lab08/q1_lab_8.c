
printf("Enter %d elemetnts \n",n);
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		thread_args_t args = {0, n-1};
		merge_sort(&args);

		printf("21k-4783-------------ABDULLAH---------------------------------------- \n");
		 printf("\n\n");
		printf("Sorted array: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	   printf("21k-4783-------------ABDULLAH---------------------------------------- ");
