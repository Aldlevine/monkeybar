#include <check.h>
#include "trie/trie.h"

START_TEST (check_trie)
{
  char *str = "Go ahead and trie me";
  trie_node_t *trie = trie_create();
  trie_set(trie, "here-I-am", str);
  ck_assert_str_eq(str, trie_get(trie, "here-I-am"));
  free(trie);
}
END_TEST

Suite * trie_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("trie");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, check_trie);
  suite_add_tcase(s, tc_core);

  return s;
}

int main (void)
{
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = trie_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
