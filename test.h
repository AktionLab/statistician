#ifndef TEST_H
#define TEST_H

#define ASSERT(test)\
  if (!(test)) {\
    std::cout << #test << " failed" << std::endl;\
  }

#define ASSERT_THROW(error, test)\
  try {\
    test;\
    std::cout << #test << " should have thrown an exception" << std::endl;\
    return 1;\
  } catch(int err) {\
    ASSERT_EQ(err, error)\
  }

#define ASSERT_NOT_THROW(test)\
  try {\
    test;\
  } catch(...) {\
    std::cout << #test << " should not have thrown an exception" << std::endl;\
    return 1;\
  }

#define ASSERT_EQ(a, b) ASSERT(a == b);

#endif
