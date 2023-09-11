int list_save(node *head, char *filename) {
  if (head == NULL || filename == NULL || filename[0] == '\0') {
    return EXIT_FAILURE;
  }
  FILE *fptr;
  fptr = fopen(filename, "w");
  if (fptr == NULL) {
    return EXIT_FAILURE;
  }
  node *curr = head;
  while (curr != NULL) {
    fprintf(fptr, "%s,%.2f,%d\n", curr->item_name, curr->price, curr->quantity);
    curr = curr->next;
  }
  fclose(fptr);
  return EXIT_SUCCESS;
}