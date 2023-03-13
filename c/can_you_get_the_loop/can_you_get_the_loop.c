typedef struct node_t {
  struct node_t* next;
} Node;

int loop_size(Node *node) {
  Node *slow_p = node, *fast_p = node;
  int result = 1;
  if (node == node->next) return result;
  for (slow_p = slow_p->next, fast_p = fast_p->next->next;
       slow_p != fast_p;
       slow_p = slow_p->next, fast_p = fast_p->next->next);
  for (fast_p = fast_p->next;
       fast_p != slow_p;
       result++, fast_p = fast_p->next);
  return result;
}
