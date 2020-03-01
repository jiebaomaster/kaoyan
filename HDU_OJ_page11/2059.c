#include <stdio.h>

// 比赛是设在一条笔直的道路上，长度为L米，规则很简单，谁先到达终点谁就算获胜。
// 为了能够再赢兔子，乌龟不惜花下血本买了最先进的武器——“"小飞鸽"牌电动车。
// 这辆车在有电的情况下能够以VT1 m/s的速度“飞驰”，可惜电池容量有限，每次充满电最多只能行驶C米的距离，以后就只能用脚来蹬了，乌龟用脚蹬时的速度为VT2 m/s。
// 更过分的是，乌龟竟然在跑道上修建了很多很多（N个)的供电站，供自己给电动车充电。其中，每次充电需要花费T秒钟的时间。
// 当然，乌龟经过一个充电站的时候可以选择去或不去充电。
// 比赛马上开始了，兔子和带着充满电的电动车的乌龟并列站在起跑线上。判断乌龟用最佳的方案进军时，能不能赢了一直以恒定速度奔跑的兔子。
// DP[i]为乌龟到达第 i 个充电桩所需最短时间，则 DP[i] = min{ DP[j]+ijTime+chargeTime }，其中 0<=j<i，ijTime 为从 j 到达 i 所需时间，即每次寻找最优的中间充电桩 j。
// http://acm.hdu.edu.cn/showproblem.php?pid=2059

int main() {
    int L;
    int N, C, T;
    int Vr, Vt_car, Vt_foot;
    int length[102] = {0};
    double dp[102] = {0}; // 到达第i个充电桩所需时间，起点为0，终点算最后一个充电桩
    while (scanf("%d", &L) != EOF) {
        scanf("%d%d%d%d%d%d", &N, &C, &T, &Vr, &Vt_car, &Vt_foot);
        int count;
        for (count = 1; count <= N; ++count) {
            scanf("%d", &length[count]);
        }
        length[count] = L;
        for (int j = 1; j <= N + 1; ++j) { // 计算到第 j 个充电桩所用的最短时间
            double minTime = 1e30; // 到第 j 个充电桩所用的最短时间，初值设为一个极大的数
            for (int i = 0; i < j; ++i) {
                double ijTime = dp[i] + (i == 0 ? 0 : 1) * T;
                if (C >= length[j] - length[i]) { // 计算从节点 i 到节点 j 所需时间
                    ijTime += 1.0 * (length[j] - length[i]) / Vt_car;
                } else {
                    ijTime += 1.0 * C / Vt_car + 1.0 * (length[j] - length[i] - C) / Vt_foot;
                }
                if (ijTime < minTime) {
                    minTime = ijTime;
                }
            }
            dp[j] = minTime;
        }
        double Tr = 1.0 * L / Vr; // 兔子跑完全程所用时间
        printf("%s\n", Tr > dp[N + 1] ? "What a pity rabbit!" : "Good job,rabbit!");
    }

    return 0;
}