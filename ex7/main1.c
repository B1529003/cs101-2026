#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SETS 5
#define PICK_COUNT 7
#define MIN_NUM 1
#define MAX_NUM 69

void generate_set(int arr[PICK_COUNT]) {
    int used[MAX_NUM + 1] = {0};
    int count = 0;

    while (count < PICK_COUNT) {
        int num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        if (!used[num]) {
            used[num] = 1;
            arr[count++] = num;
        }
    }
}

int main(void) {
    int n = 3; 

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩:%d\n", n);

    srand((unsigned int)time(NULL));

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        perror("無法開啟 lotto.txt");
        return 1;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    if (time_str != NULL) {
        size_t len = strlen(time_str);
        if (len > 0 && time_str[len - 1] == '\n') {
            time_str[len - 1] = '\0';
        }
    }

    fprintf(fp, "= lotto649 =\n");
    fprintf(fp, "= %s =\n", time_str ? time_str : "");

    for (int i = 1; i <= MAX_SETS; i++) {
        fprintf(fp, "[%d]: ", i);
        if (i <= n) {
            int nums[PICK_COUNT];
            generate_set(nums);
            for (int j = 0; j < PICK_COUNT; j++) {
                fprintf(fp, "%02d", nums[j]);
                if (j < PICK_COUNT - 1) {
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "-- -- -- -- -- -- --\n");
        }
    }

    fprintf(fp, "= csie@CGU =\n");
    fclose(fp);

    printf("以為您購買的%d組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
