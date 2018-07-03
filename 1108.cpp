#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main() 
{
    int N;
	cin >> N;

	int	counter = 0;
    char a[50];
	char b[50];

    double temp; 
	double sum = 0.0;
    
    for(int i = 0; i < N; i++) 
	{
        scanf("%s", a); // %s 读入一个字符串

        sscanf(a, "%lf", &temp); // 从一个字符串中读进与指定格式相符的数据
        sprintf(b, "%.2lf",temp); // sprintf与printf函数的区别：二者功能相似，但是sprintf函数打印到字符串中，而printf函数打印输出到屏幕上。

        bool flag = true;
        for(int j = 0; j < strlen(a); j++) 
		{
            if(a[j] != b[j]) 
			{
                flag = false;
            }
        }

        if(flag==false || temp < -1000 || temp > 1000) 
		{
            printf("ERROR: %s is not a legal number\n", a);
        } 
		else 
		{
            sum += temp;
            counter++;
        }

    }

    if(counter == 1) 
	{
        double average = sum;
		cout<<"The average of 1 number is ";
		printf("%.2f", average);
    } 
	else if(counter > 1) 
	{
		double average = sum / counter;
        cout<<"The average of "<<counter<<" numbers is ";
		printf("%.2f", average);
    } 
	else 
	{		
        cout<<"The average of 0 numbers is Undefined";
    }




    return 0;
}







