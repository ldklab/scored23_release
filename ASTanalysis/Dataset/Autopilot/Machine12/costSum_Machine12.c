int list_cost_sum(node *head, float *total) {
  if (head == NULL || total == NULL) {
    return EXIT_FAILURE;
  }
  *total = 0;
  node *curr = head;
  while (curr != NULL) {
    *total += curr->price * curr->quantity;
    curr = curr->next;
  }
  return EXIT_SUCCESS;
}