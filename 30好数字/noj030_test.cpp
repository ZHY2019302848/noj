#include <iostream>

using namespace std;

const long long MOD = 1000000007;

// ������ȡģ
long long fastPow(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return result;
}

int countGoodNumbers(long long N) {
    // 5���ݴ�
    long long pow5 = N / 2;
    // 4���ݴ�
    long long pow4 = N / 2;

    // ���NΪ��������Ҫ�������5
    if (N % 2 == 1) {
        pow5++;
    }

    long long result = (fastPow(5, pow5) * fastPow(4, pow4)) % MOD;

    return static_cast<int>(result);
}

int main() {
    long long N;
    cout << "���������� N��1 �� N �� 10^15����";
    cin >> N;

    int result = countGoodNumbers(N);
    cout << "����Ϊ " << N << " �ĺ����ֵ������ǣ�" << result << endl;

    return 0;
}
