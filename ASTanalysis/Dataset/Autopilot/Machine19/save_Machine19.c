int list_save(node *head, char *filename) {
	if(head == NULL || filename == NULL) {
		return EXIT_FAILURE;
	}

	FILE *fptr = fopen(filename, "w");
	if(fptr == NULL) {
		return EXIT_FAILURE;
	}

	node *temp = head;
	while(temp!= NULL) {
		fprintf(fptr, "%s,%f,%d\n", temp->item_name, temp->price, temp->quantity);
		temp = temp->next;
	}

	fclose(fptr);
	return EXIT_SUCCESS;
}