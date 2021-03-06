# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* Revised by Edward Diener (2011) */
#
# /* See http://www.boost.org for most recent version. */
#
# include <boost/preprocessor/tuple.hpp>
# include <boost/preprocessor/array/elem.hpp>
# include <boost/preprocessor/list/at.hpp>
# include <boost/preprocessor/seq/elem.hpp>
# if BOOST_PP_VARIADICS
# include <boost/preprocessor/variadic/size.hpp>
# include <boost/preprocessor/variadic/elem.hpp>
# endif
# include <libs/preprocessor/test/test.h>

# define TUPLE (0, 1, 2, 3, 4, 5)
# define TUPLE_LARGE (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32)
# define TUPLE_VERY_LARGE (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
# define T2 (+3, /2, +6)

#if BOOST_PP_VARIADICS

# define CALC(x) BOOST_PP_TUPLE_ELEM(0, x) BOOST_PP_TUPLE_ELEM(1, x) BOOST_PP_TUPLE_ELEM(2, x)
# define TEST_EAT BOOST_PP_TUPLE_EAT()(1, 2) 4
# define TEST_EAT_LARGE BOOST_PP_TUPLE_EAT()(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32) 6
# define TEST_EAT_VERY_LARGE BOOST_PP_TUPLE_EAT()(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63) 8

#else

# define CALC(x) BOOST_PP_TUPLE_ELEM(3, 0, x) BOOST_PP_TUPLE_ELEM(3, 1, x) BOOST_PP_TUPLE_ELEM(3, 2, x)
# define TEST_EAT BOOST_PP_TUPLE_EAT(2)(1, 2) 4
# define TEST_EAT_LARGE BOOST_PP_TUPLE_EAT(33)(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32) 6
# define TEST_EAT_VERY_LARGE BOOST_PP_TUPLE_EAT(64)(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63) 8

#endif

BEGIN BOOST_PP_TUPLE_ELEM(6, 3, TUPLE) == 3 END
BEGIN BOOST_PP_TUPLE_ELEM(6, 5, TUPLE) == 5 END
BEGIN BOOST_PP_TUPLE_ELEM(33, 15, TUPLE_LARGE) == 15 END
BEGIN BOOST_PP_TUPLE_ELEM(33, 27, TUPLE_LARGE) == 27 END
BEGIN BOOST_PP_TUPLE_ELEM(33, 32, TUPLE_LARGE) == 32 END
BEGIN BOOST_PP_TUPLE_ELEM(64, 22, TUPLE_VERY_LARGE) == 22 END
BEGIN BOOST_PP_TUPLE_ELEM(64, 47, TUPLE_VERY_LARGE) == 47 END
BEGIN BOOST_PP_TUPLE_ELEM(64, 63, TUPLE_VERY_LARGE) == 63 END
BEGIN BOOST_PP_TUPLE_ELEM(6, 2, BOOST_PP_TUPLE_REVERSE(6,TUPLE)) == 3 END
BEGIN BOOST_PP_TUPLE_ELEM(33, 27, BOOST_PP_TUPLE_REVERSE(33,TUPLE_LARGE)) == 5 END
BEGIN BOOST_PP_TUPLE_ELEM(64, 43, BOOST_PP_TUPLE_REVERSE(64,TUPLE_VERY_LARGE)) == 20 END
BEGIN CALC(T2) == 7 END
BEGIN CALC(BOOST_PP_TUPLE_REVERSE(3, T2)) == 6 END
BEGIN TEST_EAT == 4 END
BEGIN TEST_EAT_LARGE == 6 END
BEGIN TEST_EAT_VERY_LARGE == 8 END
BEGIN BOOST_PP_ARRAY_ELEM(3,BOOST_PP_TUPLE_TO_ARRAY(6,TUPLE)) == 3 END
BEGIN BOOST_PP_ARRAY_ELEM(29,BOOST_PP_TUPLE_TO_ARRAY(33,TUPLE_LARGE)) == 29 END
BEGIN BOOST_PP_ARRAY_ELEM(61,BOOST_PP_TUPLE_TO_ARRAY(64,TUPLE_VERY_LARGE)) == 61 END
BEGIN BOOST_PP_LIST_AT(BOOST_PP_TUPLE_TO_LIST(6,TUPLE), 2) == 2 END
BEGIN BOOST_PP_LIST_AT(BOOST_PP_TUPLE_TO_LIST(33,TUPLE_LARGE), 19) == 19 END
BEGIN BOOST_PP_LIST_AT(BOOST_PP_TUPLE_TO_LIST(64,TUPLE_VERY_LARGE), 62) == 62 END
BEGIN BOOST_PP_SEQ_ELEM(4,BOOST_PP_TUPLE_TO_SEQ(6,TUPLE)) == 4 END
BEGIN BOOST_PP_SEQ_ELEM(31,BOOST_PP_TUPLE_TO_SEQ(33,TUPLE_LARGE)) == 31 END
BEGIN BOOST_PP_SEQ_ELEM(55,BOOST_PP_TUPLE_TO_SEQ(64,TUPLE_VERY_LARGE)) == 55 END

#if BOOST_PP_VARIADICS

BEGIN BOOST_PP_TUPLE_ELEM(3, TUPLE) == 3 END
BEGIN BOOST_PP_TUPLE_ELEM(5, TUPLE) == 5 END
BEGIN BOOST_PP_TUPLE_ELEM(15, TUPLE_LARGE) == 15 END
BEGIN BOOST_PP_TUPLE_ELEM(27, TUPLE_LARGE) == 27 END
BEGIN BOOST_PP_TUPLE_ELEM(32, TUPLE_LARGE) == 32 END
BEGIN BOOST_PP_TUPLE_ELEM(22, TUPLE_VERY_LARGE) == 22 END
BEGIN BOOST_PP_TUPLE_ELEM(47, TUPLE_VERY_LARGE) == 47 END
BEGIN BOOST_PP_TUPLE_ELEM(63, TUPLE_VERY_LARGE) == 63 END
BEGIN BOOST_PP_TUPLE_ELEM(2, BOOST_PP_TUPLE_REVERSE(TUPLE)) == 3 END
BEGIN BOOST_PP_TUPLE_ELEM(27, BOOST_PP_TUPLE_REVERSE(TUPLE_LARGE)) == 5 END
BEGIN BOOST_PP_TUPLE_ELEM(43, BOOST_PP_TUPLE_REVERSE(TUPLE_VERY_LARGE)) == 20 END
BEGIN CALC(BOOST_PP_TUPLE_REVERSE(T2)) == 6 END
BEGIN BOOST_PP_VARIADIC_ELEM(2,BOOST_PP_TUPLE_ENUM(BOOST_PP_TUPLE_REVERSE(TUPLE))) == 3 END
BEGIN BOOST_PP_VARIADIC_ELEM(27,BOOST_PP_TUPLE_ENUM(BOOST_PP_TUPLE_REVERSE(TUPLE_LARGE))) == 5 END
BEGIN BOOST_PP_VARIADIC_ELEM(45,BOOST_PP_TUPLE_ENUM(BOOST_PP_TUPLE_REVERSE(TUPLE_VERY_LARGE))) == 18 END
BEGIN BOOST_PP_VARIADIC_SIZE(BOOST_PP_TUPLE_ENUM(TUPLE)) == 6 END
BEGIN BOOST_PP_VARIADIC_SIZE(BOOST_PP_TUPLE_ENUM(TUPLE_LARGE)) == 33 END
BEGIN BOOST_PP_VARIADIC_SIZE(BOOST_PP_TUPLE_ENUM(TUPLE_VERY_LARGE)) == 64 END
BEGIN BOOST_PP_TUPLE_SIZE(TUPLE) == 6 END
BEGIN BOOST_PP_TUPLE_SIZE(TUPLE_LARGE) == 33 END
BEGIN BOOST_PP_TUPLE_SIZE(TUPLE_VERY_LARGE) == 64 END
BEGIN BOOST_PP_ARRAY_ELEM(3,BOOST_PP_TUPLE_TO_ARRAY(TUPLE)) == 3 END
BEGIN BOOST_PP_ARRAY_ELEM(29,BOOST_PP_TUPLE_TO_ARRAY(TUPLE_LARGE)) == 29 END
BEGIN BOOST_PP_ARRAY_ELEM(61,BOOST_PP_TUPLE_TO_ARRAY(TUPLE_VERY_LARGE)) == 61 END
BEGIN BOOST_PP_LIST_AT(BOOST_PP_TUPLE_TO_LIST(TUPLE), 2) == 2 END
BEGIN BOOST_PP_LIST_AT(BOOST_PP_TUPLE_TO_LIST(TUPLE_LARGE), 19) == 19 END
BEGIN BOOST_PP_LIST_AT(BOOST_PP_TUPLE_TO_LIST(TUPLE_VERY_LARGE), 62) == 62 END
BEGIN BOOST_PP_SEQ_ELEM(4,BOOST_PP_TUPLE_TO_SEQ(TUPLE)) == 4 END
BEGIN BOOST_PP_SEQ_ELEM(31,BOOST_PP_TUPLE_TO_SEQ(TUPLE_LARGE)) == 31 END
BEGIN BOOST_PP_SEQ_ELEM(55,BOOST_PP_TUPLE_TO_SEQ(TUPLE_VERY_LARGE)) == 55 END

#endif
