#include <check.h>
#include "trie/trie.h"

START_TEST (check_trie_get_set)
{
  char *str1 = "Go ahead and trie me";
  char *str2 = "Trie if you dare";
  char *str3 = "Trie, trie again";
  TrieNode *trie = trie_create();

  trie_set(trie, "here", str1);
  trie_set(trie, "here-I", str2);
  trie_set(trie, "here-I-am", str3);

  ck_assert_str_eq(str1, trie_get(trie, "here"));
  ck_assert_str_eq(str2, trie_get(trie, "here-I"));
  ck_assert_str_eq(str3, trie_get(trie, "here-I-am"));

  ck_assert(trie_get(trie, "he") == NULL);
  ck_assert(trie_get(trie, "here-") == NULL);
  ck_assert(trie_get(trie, "here-I-a") == NULL);

  trie_free(trie);
}
END_TEST

START_TEST (check_trie_delete)
{
  char *str = "You can't get rid of me that easily";
  TrieNode *trie = trie_create();

  trie_set(trie, "im-gonna-trie", str);
  ck_assert(trie_delete(trie, "im-gonna-trie"));

  char *result = trie_get(trie, "im-gonna-trie");
  ck_assert(result == NULL);

  trie_free(trie);
}
END_TEST

Suite * trie_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("trie");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, check_trie_get_set);
  tcase_add_test(tc_core, check_trie_delete);
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

  srunner_run_all(sr, CK_ENV);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
