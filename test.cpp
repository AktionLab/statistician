#include "Statistician.h"
#include "test.h"
#include <iostream>

void statistician_test(Statistician s, double abs_min, double abs_max, int length, double min, double max, double mean, double sum)
{
  ASSERT_EQ(s.abs_maximum(), abs_max);
  ASSERT_EQ(s.abs_minimum(), abs_min);
  ASSERT_EQ(s.length()     , length);
  ASSERT_EQ(s.maximum()    , max);
  ASSERT_EQ(s.minimum()    , min);
  ASSERT_EQ(s.mean()       , mean);
  ASSERT_EQ(s.sum()        , sum);
}
  

int main()
{
  Statistician s1;
  Statistician s2;

  s1.next(1.0);
  s1.next(2.0);
  s2.next(-4.0);
  s2.next(-6.0);
  s2.next(-8.0);

  Statistician s3 = s1 + s2;
  Statistician s4 = 5 * s3;

  // abs_min, abs_max, length, min, max, mean, sum

  statistician_test(s1, 1.0, 2.0, 2, 1.0, 2.0, 1.5, 3.0);
  statistician_test(s2, 4.0, 8.0, 3, -8.0, -4.0, -6.0, -18.0);
  statistician_test(s3, 1.0, 8.0, 5, -8.0, 2.0, -3.0, -15.0);
  statistician_test(s4, 5.0, 40.0, 5, -40.0, 10.0, -15.0, -75.0);

  Statistician sfail1;
  Statistician sfail2;
  
  ASSERT_THROW(E_NO_ELEMENTS, sfail1 + sfail2)
  ASSERT_THROW(E_NO_ELEMENTS, 5 * sfail1)
  ASSERT_THROW(E_NO_ELEMENTS, sfail1.abs_maximum())
  ASSERT_THROW(E_NO_ELEMENTS, sfail1.abs_minimum())
  ASSERT_THROW(E_NO_ELEMENTS, sfail1.maximum())
  ASSERT_THROW(E_NO_ELEMENTS, sfail1.minimum())
  ASSERT_THROW(E_NO_ELEMENTS, sfail1.mean())
  ASSERT_THROW(E_NO_ELEMENTS, sfail1.sum())
  ASSERT_THROW(E_NO_ELEMENTS, sfail1.recent())

  ASSERT_NOT_THROW(sfail1.length())

  std::cout << "Tests Passed" << std::endl;
}

