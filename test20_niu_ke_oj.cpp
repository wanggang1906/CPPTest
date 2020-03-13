# include <iostream>
# include <algorithm> // ���뺯���⣬�������ú�������ȡ�����Сֵ������
using namespace std;

typedef struct stu {
    char name[20];
    int score;
    int i;
}Stu; // ����ṹ��

// �ȽϺ���
int cmp1(struct stu a, struct stu b) {
    if (a.score != b.score) {
        return a.score < b.score;
    }
    else {
        return a.i < b.i;
    }
}
// �ȽϺ���
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
            sort(a, a + num, cmp2); // Ĭ�ϵ���������Ҫ�ݼ��������ӱȽϺ���cmp
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