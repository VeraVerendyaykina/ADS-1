bool CheckPrime(uint64_t value) {
    if (value <= 1) {
        return false; 
    }
    
    if (value == 2) {
        return true; 
    }
    
    if (value % 2 == 0) {
        return false; // четные числа, кроме 2, не являются простыми
    }
    
    for (uint64_t i = 3; i <= value/2; i ++) {
        if (value % i == 0) {
            return false; // число делится на число
        }
    }
    
    return true;
}

uint64_t findNthPrime(uint64_t n) {
    uint64_t count = 0;
    uint64_t number = 2;
    
    while (count < n) {
        if (CheckPrime(number)) {
            count++;
        }
        number++;
    }
    
    return number - 1; // последнее простое число
}

int findNextPrime(int value) {
    int number = value + 1;
    
    while (true) {
        if (CheckPrime(number)) {
            return number;
        }
        number++;
    }
}

int sumOfPrimes(int hbound) {
    int sum = 0;
    
    for (int i = 2; i < hbound; i++) {
        if (CheckPrime(i)) {
            sum += i;
        }
    }
    
    return sum;
}

int main() {
    uint64_t number = 18; // проверяемое число
    if (CheckPrime(number)) {
        std::cout << number << " - простое число" << std::endl;
    } else {
        std::cout << number << " - не простое число" << std::endl;
    }

    uint64_t n = 19; // порядковый номер искомого простого числа
    uint64_t nthPrime = findNthPrime(n);
    std::cout << "Простое число под номером " << n << ": " << nthPrime << std::endl;

    int value = 11; // проверяемое число
    int nextPrime = findNextPrime(value);
    std::cout << "Ближайшее простое число к " << value << ": " << nextPrime << std::endl;

    int hbound = 3; 
    int result = sumOfPrimes(hbound);
    std::cout << "Сумма простых чисел до " << hbound << ": " << result << std::endl;

    return 0;
}

