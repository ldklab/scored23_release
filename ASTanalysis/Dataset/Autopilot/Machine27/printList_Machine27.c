int list_print(node *head) {
  int pos = 0;
  while (head != NULL) {
    char str[MAX_ITEM_PRINT_LEN];
    list_item_to_string(head, str);
    printf("%d: %s\n", ++pos, str);
    head = head->next;
  }
  return EXIT_SUCCESS;
}