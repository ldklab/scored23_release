int list_save(node *head, char *filename) {
  FILE *fp;
  char *str;
  int i = 0;
  if (!head) {
    return EXIT_FAILURE;
  }
  if ((fp = fopen(filename, "w")) == NULL) {
    return EXIT_FAILURE;
  }
  str = malloc(MAX_ITEM_PRINT_LEN * sizeof(char));
  list_item_to_string(head, str);
  fprintf(fp, "%s\n", str);
  while (head) {
    head = head->next;
    if (head) {
      list_item_to_string(head, str);
      fprintf(fp, "%s\n", str);
    }
  }
  free(str);
  fclose(fp);
  return EXIT_SUCCESS;
}