int list_deduplicate(node **head) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }
  node *curr = *head;
  while (curr != NULL) {
    node *curr2 = curr->next;
    while (curr2 != NULL) {
      if (strcmp(curr->item_name, curr2->item_name) == 0) {
        curr->quantity += curr2->quantity;
        curr2->quantity = 0;
      }
      curr2 = curr2->next;
    }
    curr = curr->next;
  }
  curr = *head;
  node *curr2 = curr->next;
  while (curr2 != NULL) {
    if (curr2->quantity == 0) {
      curr->next = curr2->next;
      curr2->next = NULL;
      free(curr2->item_name);
      free(curr2);
      curr2 = curr->next;
    } else {
      curr = curr->next;
      curr2 = curr2->next;
    }
  }
  return EXIT_SUCCESS;
}