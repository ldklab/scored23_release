int list_save(node *head, char *filename) {
  if (head == NULL) {
    printf("Error: list is empty\n");
    return EXIT_FAILURE;
  }
  FILE *fp;
  if ((fp = fopen(filename, "w")) == NULL) {
    printf("Error: file cannot be opened\n");
    return EXIT_FAILURE;
  }
  while (head!= NULL) {
    char print_str[MAX_ITEM_PRINT_LEN];
    list_item_to_string(head, print_str);
    fprintf(fp, "%s", print_str);
    head = head->next;
  }
  fclose(fp);
  return EXIT_SUCCESS;
}