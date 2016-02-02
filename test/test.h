/*
 * This file is part of Susa.

 * Susa is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.

 * Susa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.

 * You should have received a copy of the Lesser GNU General Public License
 * along with Susa.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file test.h
 * @brief Unit Test Suit
 * @author Behrooz Aliabadi
 * @version 1.0.0
 */

#include <iostream>
#include <cstdlib>
#include <susa.h>

unsigned int uint_passed = 0;
unsigned int uint_failed = 0;
unsigned int uint_total = 0;

inline void susa_test(bool res, const char* arga, const char* argb, const char* msg) {

  uint_total++;

  if (res) {
    uint_passed++;
    std::cout << std::endl << " TEST # (" << uint_total << ") :\033[1;32m PASSED\033[0m";
  }
  else
  {
    uint_failed++;
    std::cout << std::endl << " TEST # (" << uint_total << ") :\033[1;31m FAILED\033[0m";
    std::cout << std::endl << "   message : " << msg;
    std::cout << std::endl << "   value : " << arga;
    std::cout << std::endl << "   expected : " << argb;
  }
}

#define SUSA_TEST_EQ(ARGA,ARGB,MSG) (susa_test(ARGA == ARGB,#ARGA,#ARGB,#MSG))
#define SUSA_TEST_EQ_DOUBLE(ARGA,ARGB,MSG) (susa_test(std::abs(ARGA - ARGB) < 1e-4,#ARGA,#ARGB,#MSG))