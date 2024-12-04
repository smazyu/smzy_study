
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ACCOUNTS 5

void generateAccounts(double accounts[NUM_ACCOUNTS][2], double interestRate)
{
    for (int i = 0; i < NUM_ACCOUNTS; i++)
    {
        accounts[i][0] = (rand() % 10000) + 1000;       // 随机生成存款金额，范围为1000到10999
        accounts[i][1] = accounts[i][0] * interestRate; // 计算1年后的利息
    }
}

void printAccounts(double accounts[NUM_ACCOUNTS][2])
{
    for (int i = 0; i < NUM_ACCOUNTS; i++)
    {
        printf("账户 %d: 存款金额 = %.2f, 1年后的利息 = %.2f\n", i + 1, accounts[i][0], accounts[i][1]);
    }
}

int main()
{
    srand(time(NULL)); // 初始化随机数种子

    double fixedAccounts[NUM_ACCOUNTS][2];   // 定期账户
    double currentAccounts[NUM_ACCOUNTS][2]; // 活期账户

    double fixedInterestRate = 0.03;   // 定期账户利率
    double currentInterestRate = 0.01; // 活期账户利率

    printf("生成定期账户信息:\n");
    generateAccounts(fixedAccounts, fixedInterestRate);
    printAccounts(fixedAccounts);

    printf("\n生成活期账户信息:\n");
    generateAccounts(currentAccounts, currentInterestRate);
    printAccounts(currentAccounts);

    return 0;
}