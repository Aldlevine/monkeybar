#include <check.h>
#include "vector.h"

START_TEST (check_vector_get)
{
  Vector *v = vector_create(5, "a", "b", "c", "d", "e");
  ck_assert_str_eq("a", vector_get(v, 0));
  ck_assert_str_eq("b", vector_get(v, 1));
  ck_assert_str_eq("c", vector_get(v, 2));
  ck_assert_str_eq("d", vector_get(v, 3));
  ck_assert_str_eq("e", vector_get(v, 4));
}
END_TEST

START_TEST (check_vector_push)
{
  Vector *v = vector_create(0);
  ck_assert_uint_eq(0, vector_push(v, "a"));
  ck_assert_uint_eq(1, vector_push(v, "b"));
  ck_assert_uint_eq(2, vector_push(v, "c"));
  ck_assert_uint_eq(3, vector_push(v, "d"));
  ck_assert_uint_eq(4, vector_push(v, "e"));
  ck_assert_str_eq("a", vector_get(v, 0));
  ck_assert_str_eq("b", vector_get(v, 1));
  ck_assert_str_eq("c", vector_get(v, 2));
  ck_assert_str_eq("d", vector_get(v, 3));
  ck_assert_str_eq("e", vector_get(v, 4));
  ck_assert_uint_eq(5, v->length);
}
END_TEST

START_TEST (check_vector_pop)
{
  Vector *v = vector_create(5, "a", "b", "c", "d", "e");
  ck_assert_str_eq("e", vector_pop(v));
  ck_assert_str_eq("d", vector_pop(v));
  ck_assert_str_eq("c", vector_pop(v));
  ck_assert_str_eq("b", vector_pop(v));
  ck_assert_str_eq("a", vector_pop(v));
  ck_assert_uint_eq(0, v->length);
  ck_assert_ptr_eq(NULL, vector_pop(v));
  ck_assert_uint_eq(0, v->length);
}
END_TEST

START_TEST (check_vector_unshift)
{
  Vector *v = vector_create(0);
  ck_assert_uint_eq(1, vector_unshift(v, "e"));
  ck_assert_uint_eq(2, vector_unshift(v, "d"));
  ck_assert_uint_eq(3, vector_unshift(v, "c"));
  ck_assert_uint_eq(4, vector_unshift(v, "b"));
  ck_assert_uint_eq(5, vector_unshift(v, "a"));
  ck_assert_str_eq("a", vector_get(v, 0));
  ck_assert_str_eq("b", vector_get(v, 1));
  ck_assert_str_eq("c", vector_get(v, 2));
  ck_assert_str_eq("d", vector_get(v, 3));
  ck_assert_str_eq("e", vector_get(v, 4));
  ck_assert_uint_eq(5, v->length);
}
END_TEST

START_TEST (check_vector_shift)
{
  Vector *v = vector_create(5, "e", "d", "c", "b", "a");
  ck_assert_str_eq("e", vector_shift(v));
  ck_assert_str_eq("d", vector_shift(v));
  ck_assert_str_eq("c", vector_shift(v));
  ck_assert_str_eq("b", vector_shift(v));
  ck_assert_str_eq("a", vector_shift(v));
  ck_assert_uint_eq(0, v->length);
  ck_assert_ptr_eq(NULL, vector_shift(v));
  ck_assert_uint_eq(0, v->length);
}
END_TEST

START_TEST (check_vector_insert)
{
  Vector *v = vector_create(5, "0", "1", "2", "3", "4");
  ck_assert_uint_eq(8, vector_insert(v, 2, 3, "a", "b", "c"));
  ck_assert_uint_eq(8, v->length);
  ck_assert_str_eq("0", vector_shift(v));
  ck_assert_str_eq("1", vector_shift(v));
  ck_assert_str_eq("a", vector_shift(v));
  ck_assert_str_eq("b", vector_shift(v));
  ck_assert_str_eq("c", vector_shift(v));
  ck_assert_str_eq("2", vector_shift(v));
  ck_assert_str_eq("3", vector_shift(v));
  ck_assert_str_eq("4", vector_shift(v));
  ck_assert_uint_eq(0, v->length);
  ck_assert_ptr_eq(NULL, vector_shift(v));
  ck_assert_uint_eq(0, v->length);
}
END_TEST

START_TEST (check_vector_extract)
{
  Vector *v = vector_create(10, "0", "1", "2", "3", "4", "5", "6", "7", "8", "9");
  Vector *e = vector_extract(v, 3, 3);
  ck_assert_uint_eq(7, v->length);
  ck_assert_uint_eq(3, e->length);

  ck_assert_str_eq("0", vector_shift(v));
  ck_assert_str_eq("1", vector_shift(v));
  ck_assert_str_eq("2", vector_shift(v));
  ck_assert_str_eq("6", vector_shift(v));
  ck_assert_str_eq("7", vector_shift(v));
  ck_assert_str_eq("8", vector_shift(v));
  ck_assert_str_eq("9", vector_shift(v));
  ck_assert_uint_eq(0, v->length);
  ck_assert_ptr_eq(NULL, vector_shift(v));
  ck_assert_uint_eq(0, v->length);

  ck_assert_str_eq("3", vector_shift(e));
  ck_assert_str_eq("4", vector_shift(e));
  ck_assert_str_eq("5", vector_shift(e));
  ck_assert_uint_eq(0, e->length);
  ck_assert_ptr_eq(NULL, vector_shift(e));
  ck_assert_uint_eq(0, e->length);
}
END_TEST

void check_vector_each_fn (size_t i, void *data, Vector *v)
{
  ck_assert(i >= 0 && i < v->length);
  switch (i) {
    case 0: ck_assert_str_eq("0", data); break;
    case 1: ck_assert_str_eq("1", data); break;
    case 2: ck_assert_str_eq("2", data); break;
    case 3: ck_assert_str_eq("3", data); break;
    case 4: ck_assert_str_eq("4", data); break;
    case 5: ck_assert_str_eq("5", data); break;
    case 6: ck_assert_str_eq("6", data); break;
    case 7: ck_assert_str_eq("7", data); break;
    case 8: ck_assert_str_eq("8", data); break;
    case 9: ck_assert_str_eq("9", data); break;
    default: ck_assert_msg(1==0, "Invalid index");
  }
}
START_TEST (check_vector_each)
{
  Vector *v = vector_create(10, "0", "1", "2", "3", "4", "5", "6", "7", "8", "9");
  vector_each(v, check_vector_each_fn);
}
END_TEST

Suite * vector_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("vector");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, check_vector_get);
  tcase_add_test(tc_core, check_vector_push);
  tcase_add_test(tc_core, check_vector_pop);
  tcase_add_test(tc_core, check_vector_unshift);
  tcase_add_test(tc_core, check_vector_shift);
  tcase_add_test(tc_core, check_vector_insert);
  tcase_add_test(tc_core, check_vector_extract);
  tcase_add_test(tc_core, check_vector_each);
  suite_add_tcase(s, tc_core);

  return s;
}

int main (void)
{
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = vector_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
