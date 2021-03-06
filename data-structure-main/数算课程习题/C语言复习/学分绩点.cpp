/*
总时间限制: 1000ms 内存限制: 65536kB
描述
北京大学对本科生的成绩施行平均学分绩点制（GPA）。既将学生的实际考分根据不同的学科的不同学分按一定的公式进行计算。
公式如下：
实际成绩 绩点
90——100 4.0
85——89 3.7
82——84 3.3
78——81 3.0
75——77 2.7
72——74 2.3
68——71 2.0
64——67 1.5
60——63 1.0
60以下 0
1．一门课程的学分绩点=该课绩点*该课学分
2．总评绩点=所有学科绩点之和/所有课程学分之和
现要求你编写程序求出某人A的总评绩点（GPA）。
输入
第一行 总的课程数n（n<10）；
第二行 相应课程的学分（两个学分间用空格隔开）；
第三行 对应课程的实际得分；
此处输入的所有数字均为整数。
输出
输出有一行，总评绩点，精确到小数点后2位小数。（printf("%.2f",GPA);）
样例输入
5
4 3 4 2 3
91 88 72 69 56
样例输出
2.52
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,point[10]={0},total_point=0;
    float sum=0,score[10]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&point[i]);
    }
    for (i = 0;i < n;i++) {
        scanf("%f",&score[i]);
        if(score[i]>=90){
            score[i]=4.0;
        }
        else if(score[i]>=85){
            score[i]=3.7;
        }
        else if(score[i]>=82){
            score[i]=3.3;
        }
        else if(score[i]>=78){
            score[i]=3.0;
        }
        else if(score[i]>=75){
            score[i]=2.7;
        }
        else if(score[i]>=72){
            score[i]=2.3;
        }
        else if(score[i]>=68){
            score[i]=2.0;
        }
        else if(score[i]>=64){
            score[i]=1.5;
        }
        else if(score[i]>=60){
            score[i]=1.0;
        }
        else{
            score[i]=0;
        }
    }
    for(i=0;i<n;i++){
        sum += point[i] * score[i];
        total_point+=point[i];
    }
    printf("%.2f",sum/total_point);
    return 0;
}
