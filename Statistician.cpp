#include "Statistician.h"
#include <stdlib.h>

using namespace std;

Statistician::Statistician()
{
  reset();
}

void Statistician::reset()
{
  my_abs_maximum = 0.0;
  my_abs_minimum = 0.0;
  my_length = 0;
  my_maximum = 0.0;
  my_minimum = 0.0;
  my_recent = 0.0;
  my_sum = 0.0;
}

void Statistician::next(double number)
{
  double abs_number = abs(number);
  if (my_length > 0) {
    my_abs_maximum = MAX(my_abs_maximum, abs_number);
    my_abs_minimum = MIN(my_abs_minimum, abs_number);
    my_length++;
    my_maximum = MAX(my_maximum, number);
    my_minimum = MIN(my_minimum, number);
    my_recent = number;
    my_sum += number;
  } else {
    my_abs_maximum = my_abs_minimum = abs_number;
    my_maximum = my_minimum = my_recent = my_sum = number;
    my_length = 1;
  }
}

Statistician operator+(const Statistician s1, const Statistician s2)
{
  CHECK_LENGTH_OF(s1);
  CHECK_LENGTH_OF(s2);
  Statistician s3;
  s3.my_abs_maximum = MAX(s1.abs_maximum(), s2.abs_maximum());
  s3.my_abs_minimum = MIN(s1.abs_minimum(), s2.abs_minimum());
  s3.my_length = s1.length() + s2.length();
  s3.my_maximum = MAX(s1.maximum(), s2.maximum());
  s3.my_minimum = MIN(s1.minimum(), s2.minimum());
  s3.my_recent = s2.recent();
  s3.my_sum = s1.sum() + s2.sum();
  return s3;
}

Statistician operator*(double scale, const Statistician s1)
{
  CHECK_LENGTH_OF(s1);
  Statistician s2;
  s2.my_abs_maximum = scale * s1.abs_maximum();
  s2.my_abs_minimum = scale * s1.abs_minimum();
  s2.my_length = s1.length();
  s2.my_maximum = scale * s1.maximum();
  s2.my_minimum = scale * s1.minimum();
  s2.my_recent = s1.recent();
  s2.my_sum = scale * s1.sum();
  return s2;
}

double Statistician::abs_maximum() const
{
  CHECK_MY_LENGTH;
  return my_abs_maximum;
}

double Statistician::abs_minimum() const
{
  CHECK_MY_LENGTH;
  return my_abs_minimum;
}

int Statistician::length() const
{
  return my_length;
}

double Statistician::maximum() const
{
  CHECK_MY_LENGTH;
  return my_maximum;
}

double Statistician::mean() const
{
  CHECK_MY_LENGTH;
  return my_sum / my_length;
}

double Statistician::minimum() const
{
  CHECK_MY_LENGTH;
  return my_minimum;
}

double Statistician::recent() const
{
  CHECK_MY_LENGTH;
  return my_recent;
}

double Statistician::sum() const
{
  CHECK_MY_LENGTH;
  return my_sum;
}

