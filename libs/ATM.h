#ifndef __IMD_ATM_
#define __IMD_ATM_

#include <ctime>
#include <deque>
#include <random>

namespace IMD
{
    using ullong = unsigned long long;

    enum operation_type
    {
        Withdrawal,    // Снятие
        Deposit,       // Внесение
        Transfer,      // Перевод
        BalanceInquiry // Проверка баланса

    };

    struct transaction
    {
    private:
        std::time_t __transaction_time;
        ullong __volume;

    public:
        transaction(operation_type op_type, ullong volume) : __volume(volume)
        {
            this->__transaction_time = std::time(NULL);
        }

        std::time_t transaction_time() const noexcept
        {
            return this->__transaction_time;
        }
    };

    class account
    {
    private:
        static constexpr ullong mask = 0x9E3779B97F4A7C15; // phi

        ullong __id;
        ullong __pincode; // hash representation
        ullong __balance;

        std::deque<transaction> __transactions;

        static ullong generate_unique_id()
        {
            static ullong counter = 0;
            return counter++;
        }

    public:
        account(ullong pincode, ullong balance = 0) : __id(generate_unique_id()), __pincode(hash(pincode)), __balance(balance) {}

        static ullong hash(ullong value)
        {
            ullong res = value ^ mask;
            res = (res << 21) | (res >> 43);
            return res;
        }

        bool check_pincode(ullong pincode)
        {
            return this->__pincode == hash(pincode);
        }
    };

    class ATM
    {
    };
}

#endif