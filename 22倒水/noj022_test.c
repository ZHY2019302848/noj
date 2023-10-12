#include <stdio.h>
#include <stdbool.h>

int m, n;
int d;
int minOperations = -1;

// ��¼�Ѿ����ʹ���״̬
bool visited[101][101] = {false};

void dfs(int x, int y, int steps) {
    if (steps >= minOperations && minOperations != -1) {
        return; // ����Ѿ��ҵ���С�Ĳ��������Ͳ�������
    }
    
    if (x == d || y == d) {
        if (minOperations == -1 || steps < minOperations) {
            minOperations = steps; // ������С������
        }
        return;
    }
    
    if (visited[x][y]) {
        return; // �Ѿ����ʹ����״̬�������������
    }
    
    visited[x][y] = true;
    
    // ����һ������
    dfs(0, y, steps + 1);
    dfs(x, 0, steps + 1);
    
    // װ��һ������
    dfs(m, y, steps + 1);
    dfs(x, n, steps + 1);
    
    // ��ˮ��һ�����ӵ�����һ������
    int pour = x + y;
    int new_x = (pour > n) ? (pour - n) : 0;
    int new_y = (pour > n) ? n : pour;
    dfs(new_x, new_y, steps + 1);
    
    pour = x + y;
    new_x = (pour > m) ? m : pour;
    new_y = (pour > m) ? (pour - m) : 0;
    dfs(new_x, new_y, steps + 1);
    
    visited[x][y] = false; // �ָ�״̬�Թ�����·��ʹ��
}

int main() {
    printf("�������������ӵ��ݻ���m��n��0 < m < n����");
    scanf("%d %d", &m, &n);
    
    printf("������Ŀ��ˮ��d��d < n����");
    scanf("%d", &d);
    
    dfs(0, 0, 0);
    
    if (minOperations == -1) {
        printf("�޷��õ�%d��ˮ\n", d);
    } else {
        printf("�õ�%d��ˮ����Ҫ����С������Ϊ��%d\n", d, minOperations);
    }
    
    return 0;
}
