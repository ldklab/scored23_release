int list_print(node *head) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }
  int count = 1;
  char str[MAX_ITEM_PRINT_LEN];
  while (head != NULL) {
    list_item_to_string(head, str);
    printf("%d: %s\n", count, str);
    head = head->next;
    count++;
  }
  return EXIT_SUCCESS;
}