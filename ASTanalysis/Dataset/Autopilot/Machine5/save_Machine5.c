int list_save(node *head, char *filename) {
	node *curr = head;
	FILE *fptr = fopen(filename, "w");
	
	if (!fptr) return EXIT_FAILURE;
	
	if (curr) {
		fprintf(fptr, "%s,%f,%d\n", curr->item_name, curr->price, curr->quantity);
	}
	
	while (curr->next) {
		curr = curr->next;
		fprintf(fptr, "%s,%f,%d\n", curr->item_name, curr->price, curr->quantity);
	}
	
	fclose(fptr);
	return EXIT_SUCCESS;
}