int list_print(node *head) {
  int pos = 1;
  node *current_node = head;
  char print_str[MAX_ITEM_PRINT_LEN];
  while (current_node != NULL) {
    list_item_to_string(current_node, print_str);
    printf("%d: %s", pos, print_str);
    pos++;
    current_node = current_node->next;
  }
  return EXIT_SUCCESS;
}