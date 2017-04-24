#include <check.h>
#include "vector/include/vector_iterator.h"

START_TEST (check_vector_iterator_order)
{
  Vector *v = vector_create(5, "a", "b", "c", "d", "e");
  uint8_t i = 0;
  VECTOR_EACH (v, data)
  {
    switch (i++)
    {
      case 0:
        ck_assert_str_eq("a", data);
        break;
      case 1:
        ck_assert_str_eq("b", data);
        break;
      case 2:
        ck_assert_str_eq("c", data);
        break;
      case 3:
        ck_assert_str_eq("d", data);
        break;
      case 4:
        ck_assert_str_eq("e", data);
        break;
      default:
        ck_assert_msg(1==0, "invalid vector index");
    }
  }
  END_VECTOR_EACH;
  vector_free(v);
}
END_TEST

Suite * vector_iterator_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("vector_iterator");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, check_vector_iterator_order);
  suite_add_tcase(s, tc_core);

  return s;
}

int main (void)
{
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = vector_iterator_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
