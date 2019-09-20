namespace fib
{
    int fibGen(int n) {
        int num = 1;
        int prev_num = 0;
        while (n > 0) {
            int temp = num;
            num = num+prev_num;
            prev_num = temp;
            n--;
        }
        return prev_num;
    }

    int recFibGen(int n) {
        if (n < 2) {
            return n;
        }else {
            return recFibGen(n-2)+ recFibGen(n-1);
        }
    }
}