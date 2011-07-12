#ifndef STATS_H
#define STATS_H

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define CHECK_LENGTH_OF(s) if (s.length() == 0) throw E_NO_ELEMENTS
#define CHECK_MY_LENGTH if (this->my_length == 0) throw E_NO_ELEMENTS

#define E_NO_ELEMENTS -1

class Statistician
{
public:
  Statistician();
  void next(double r);
  void reset();

  double abs_maximum() const;
  double abs_minimum() const;
  int length() const;
  double maximum() const;
  double mean() const;
  double minimum() const;
  double recent() const;
  double sum() const;

  friend Statistician operator +
    (const Statistician s1, const Statistician s2);

  friend Statistician operator *
    (double scale, const Statistician s);

private:
  double my_abs_maximum;
  double my_abs_minimum;
  int my_length;
  double my_maximum;
  double my_minimum;
  double my_recent;
  double my_sum;
};
#endif
