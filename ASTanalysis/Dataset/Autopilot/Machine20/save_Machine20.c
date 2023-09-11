int list_save(node *head, char *filename) {
	int status = EXIT_FAILURE;
	if (head!= NULL && filename!= NULL && strlen(filename)>0) {
		FILE *file = fopen(filename, "w");
		if (file!= NULL) {
			node *current = head;
			while (current->next!= NULL) {
				fprintf(file, "%s,%.2f,%d\n", current->item_name, current->price, current->quantity);
				current = current->next;
			}
			fclose(file);
			status = EXIT_SUCCESS;
		}
	}
	return status;
}