int list_print(node *head) {
  if (head == NULL) {
    printf("Error: list is empty\n");
    return EXIT_FAILURE;
  }
  int i = 1;
  while (head != NULL) {
    char print_str[MAX_ITEM_PRINT_LEN];
    list_item_to_string(head, print_str);
    printf("%d: %s\n", i, print_str);
    head = head->next;
    i++;
  }
  return EXIT_SUCCESS;
}