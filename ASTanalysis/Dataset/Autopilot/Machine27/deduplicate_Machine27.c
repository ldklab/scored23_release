int list_deduplicate(node **head) {
  node *curr = *head;
  node *prev = NULL;
  while (curr != NULL) {
    int found = 0;
    node *inner_curr = curr->next;
    node *inner_prev = curr;
    while (inner_curr != NULL) {
      if (strcmp(curr->item_name, inner_curr->item_name) == 0) {
        curr->quantity += inner_curr->quantity;
        inner_prev->next = inner_curr->next;
        free(inner_curr);
        inner_curr = inner_prev->next;
        found = 1;
      } else {
        inner_prev = inner_curr;
        inner_curr = inner_curr->next;
      }
    }
    if (found) {
      if (prev == NULL) {
        *head = curr->next;
        free(curr);
        curr = *head;
      } else {
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
      }
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
  return EXIT_SUCCESS;
}