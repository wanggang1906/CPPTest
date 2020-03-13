# include <iostream>
# include <algorithm> // 引入函数库，包含常用函数，如取最大，最小值，交换
using namespace std;

typedef struct stu {
    char name[20];
    int score;
    int i;
}Stu; // 定义结构体

// 比较函数
int cmp1(struct stu a, struct stu b) {
    if (a.score != b.score) {
        return a.score < b.score;
    }
    else {
        return a.i < b.i;
    }
}
// 比较函数
int cmp2(struct stu a, struct stu b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    else {
        return a.i < b.i;
    }
}
int main20_1() {
    int num;
    int flag;
    while (scanf("%d%d", &num, &flag) != EOF) {
        Stu* a = new Stu[num];
        for (int i = 0; i < num; ++i) {
            scanf("%s %d", &a[i].name, &a[i].score);
            a[i].i = i;
        }
        if (flag == 0) {
            sort(a, a + num, cmp2); // 默认递增排序，若要递减，则增加比较函数cmp
        }
        else {
            sort(a, a + num, cmp1);
        }
        for (int i = 0; i < num; ++i) {
            printf("%s %d\n", a[i].name, a[i].score);
        }

    }
    return 0;
}