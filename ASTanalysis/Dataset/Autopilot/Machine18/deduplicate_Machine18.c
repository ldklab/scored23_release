int list_deduplicate(node **head) {
  if (head == NULL) {
    printf("Error: list is empty\n");
    return EXIT_FAILURE;
  }
  node *current = *head;
  node *next = current->next;
  node *prev = current;
  while (next != NULL) {
    if (strcmp(current->item_name, next->item_name) == 0) {
      current->quantity += next->quantity;
      current->price += next->price;
      prev->next = next->next;
      free(next);
    } else {
      prev = current;
      current = current->next;
    }
    next = current->next;
  }
  return EXIT_SUCCESS;
}