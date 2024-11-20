#include <stdio.h>

int main() {
    double balance, deposit, withdraw, interest_rate, interest_after_1_year;
    int account_type;

    // 初始账户余额
    double regular_balance = 2000, savings_balance = 1000;

    // 账户类型提示
    printf("选择账户类型（1：定期账户，2：活期账户）：");
    scanf("%d", &account_type);

    // 2.2 输入存款金额
    printf("请输入存款金额：");
    scanf("%lf", &deposit);

    // 根据选择的账户类型进行存款处理
    if (account_type == 1) {
        balance = regular_balance + deposit;
        interest_rate = 0.05;  // 定期账户利率为5%
    } else if (account_type == 2) {
        balance = savings_balance + deposit;
        interest_rate = 0.01;  // 活期账户利率为1%
    } else {
        printf("无效的账户类型\n");
        return 0;
    }

    // 2.3 计算余额和利息
    interest_after_1_year = balance * interest_rate;

    printf("账户余额：%.2lf元\n", balance);
    printf("1年后的利息：%.2lf元\n", interest_after_1_year);

    // 2.4 取款功能
    printf("请输入取款金额：");
    scanf("%lf", &withdraw);

    // 判断取款是否合法
    if (withdraw > balance) {
        printf("余额不足，无法取款\n");
    } else {
        balance -= withdraw;  // 扣除取款金额
        interest_after_1_year = balance * interest_rate;  // 更新利息

        printf("取款后账户余额：%.2lf元\n", balance);
        printf("取款后1年后的利息：%.2lf元\n", interest_after_1_year);
    }

    return 0;
}
