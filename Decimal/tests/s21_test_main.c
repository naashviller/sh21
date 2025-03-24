#include "s21_test_decimal.h"

int main(void) {
  int failed = 0;
  Suite *s21_decimal_test[] = {lorentmi_operators(), irvingsc_test(),
                               angelica_test(), luannkla_test(), NULL};
  for (int i = 0; s21_decimal_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_decimal_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return 0;
}