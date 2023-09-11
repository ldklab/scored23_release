int list_save(node *head, char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    return EXIT_FAILURE;
  }

  while (head != NULL) {
    fprintf(file, "%s,%.2f,%d\n", head->item_name, head->price, head->quantity);
    head = head->next;
  }
  fclose(file);
  return EXIT_SUCCESS;
}