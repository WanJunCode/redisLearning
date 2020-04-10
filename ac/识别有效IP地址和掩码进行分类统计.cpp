# include <stdio.h>
# include <string.h>
 
int fun(int a)
{
    if (a == 254 || a == 252 || a == 248 ||a == 240 || a == 224 || a == 192 || a == 128 | a == 0)
        return 1;
    return 0;
}

int main()
{
    int ip[8], a = 0, b = 0, c = 0, d = 0, e = 0, pri = 0, err = 0;
    while (scanf("%d.%d.%d.%d~%d.%d.%d.%d",&ip[0], &ip[1], &ip[2], &ip[3], &ip[4], &ip[5], &ip[6], &ip[7]) != EOF){
        int flag=0,number = 0;//flag判断掩码，number判断数字范围在0—255内的个数。
        for (int i = 0; i < 8; i++)
            if (ip[0] >= 0 && ip[0] <= 255)
                number++;
        if (number < 8)
            err++;
        else
        {
            if (ip[7] == 255 || ip[4] == 0)
                err++;
            else
            {
                for (int i = 4; i < 8; i++)
                {
                    if (ip[i] == 255)
                        continue;
                    int sum = 0;
                    for (int j = i + 1; j < 8; j++)
                        sum += ip[j];
                    if (fun(ip[i]) && (0==sum))
                        flag = 1;
                    else
                        err++;
                    break;
                }
            }
            if (flag == 1)
            {
                if (ip[0] >= 1 && ip[0] <= 126) a++;
                else if (ip[0] >= 128 && ip[0] <= 191) b++;
                else if (ip[0] >= 192 && ip[0] <= 223) c++;
                else if (ip[0] >= 224 && ip[0] <= 239) d++;
                else if (ip[0] >= 240 && ip[0] <= 255) e++;
                if (ip[0] == 10 || (ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31) || (ip[0] == 192 && ip[1] == 168)) pri++;
            }
        }
    }
    printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, err, pri);
    return 0;
}