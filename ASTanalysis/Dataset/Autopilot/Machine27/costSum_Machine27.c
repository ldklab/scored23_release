int list_cost_sum(node *head, float *total) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }
  *total = 0;
  while (head != NULL) {
    *total += head->price * head->quantity;
    head = head->next;
  }
  return EXIT_SUCCESS;
}