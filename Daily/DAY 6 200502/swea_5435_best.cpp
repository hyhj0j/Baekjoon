#include <stdio.h>
#include <string.h>

char input[100005];

int main(void)
{
    int T;
    setbuf(stdout, NULL);
    scanf("%d\n", &T);
    for (register int test_case = 1; test_case <= T; test_case++)
    {
        unsigned int check = 0;
        unsigned int count = 0;

        scanf("%s", input);
        register int len = strlen(input);

        int answer = 0;
        for (register int i = 0; i < len; i++)
        {
            if (input[i] == '(')
            {
                check = 1;
                count++;
            }
            else if (input[i] == ')' && check == 1)
            {
                count--;
                answer += count;
                check = 0;
            }
            else
            {
                count--;
                answer += 1;
                check = 0;
            }
        }
        printf("#%d %d\n", test_case, answer);
    }
    return 0;
}