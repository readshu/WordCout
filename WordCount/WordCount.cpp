
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
int count(char a[3],char b[30]);
int main()
{


    char a[3], b[30];
    int i;
    scanf("%s", a);
    scanf("%s", b);
    i = count(a, b);
    if (i == -1)
      printf("输入-c或者-w错误");
}
int count(char a[3], char b[30])
{
    char buf[MAX];
    FILE* fp;
    int len = 0;
    int count=0;
    int i;

    if ((strcmp(a,"-c"))==0)
    {
     
        if ((fp = fopen(b,"r")) == NULL)//打开文件
        {
            printf("打开文件错误\n");
            exit(1);
        }
        while (fgets(buf, MAX, fp) != NULL)//得到字符数量
        {
            len = strlen(buf);
            printf("字符数：%d\n", len-1);
            return 1;
        }


    }
    else if ((strcmp(a, "-w")) == 0)
    {
        if ((fp = fopen(b,"r")) == NULL)//打开文件
        {
            printf("打开文件错误\n");
            exit(1);
        }
        while (fgets(buf, MAX, fp) != NULL)
        {
            len = strlen(buf);

            if (len > 0)//判断是否有单词
                count++;

            for (i = 0; i < len; i++) //得到单词数量
            {
                if (buf[i] == ' ' || buf[i] == ',')
                    count++;
            }
            printf("单词数：%d\n", count);
            return 1;
        }
    }
    else
        return -1;
 }



