// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
	if (value == 1)
		return false;
	if ((value == 2) || (value == 3) || (value == 5))
		return true;
	if (!(value % 2))
		return false;
	else {
		for (int i = 3; i < value / 2; i += 2) {
			if (!(value / i))
				return false;
		}
		return true;
	}
}

uint64_t nPrime(uint64_t n) {
	int s = 0;
	for (int i = 1;; i++) {
		if (checkPrime(i))
			s++;
		if (s == n)
			return i;
	}
}

uint64_t nextPrime(uint64_t value) {
	if (value <= 1)
		return nextPrime(value + 1);
	if (checkPrime(value)) {
		int q = 0;
		for (int j = 1;; j++) {
			if (nPrime(j) == value)
				q = j;
			return nPrime(q + 1);
		}
	}
	else
		return nextPrime(value - 1);
}

uint64_t sumPrime(uint64_t hbound) {
	if (hbound <= 1)
		return 0;
	else {
		int summ = 0;
		for (int i = 1; i < hbound - 1; i++) {
			if (checkPrime(i))
				summ += i;
		}
		return summ;
	}
}
