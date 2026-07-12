class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        const int unreachable = amount + 1;

        std::vector<int> min_coins(amount + 1, unreachable);
        min_coins[0] = 0;

        for (int current_amount = 1; current_amount <= amount; ++current_amount) {
            for (int coin : coins) {
                if (coin > current_amount) {
                    continue;
                }

                min_coins[current_amount] =
                    std::min(min_coins[current_amount], min_coins[current_amount - coin] + 1);
            }
        }

        return min_coins[amount] == unreachable ? -1 : min_coins[amount];
    }
};
