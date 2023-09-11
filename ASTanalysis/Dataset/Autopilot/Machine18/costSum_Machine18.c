int list_cost_sum(node *head, float *total) {
  if (head == NULL) {
    printf("Error: list is empty\n");
    return EXIT_FAILURE;
  }
  node *current = head;
  float sum = 0;
  while (current!= NULL) {
    sum += current->price;
    current = current->next;
  }
  *total = sum;
  return EXIT_SUCCESS;
}