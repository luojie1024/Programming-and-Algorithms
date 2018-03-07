#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
char* process(int file_num, int input_size, char** input) {
    //？？？input[]  里面存的啥？？依赖的文件名 ？
    char* firstfile=0;
    string str;
    //遍历文件
    for(int i=0;i<input_size;i++)
    {
        //从第一个文件开始找依赖
        firstfile=input[i];
        for (int j = 1; j < input_size; ++j) {
            //两个文件相等的时候,找到依赖
            if(strcmp(firstfile,input[j])==0)
            {
                //将循环的文件放到一个string中连起来
                for(int k=i;k<=j;i++)
                    str+=input[k];
            }
        }
    }

    //返回输出结果
    return const_cast<char *>(str.c_str());
}

int main() {
    char* res;

    int _file_num;
    scanf("%d", &_file_num);

    int _input_size = 0;
    int _input_i;
    scanf("%d\n", &_input_size);
    char* _input[_input_size];
    for(_input_i = 0; _input_i < _input_size; _input_i++) {
        char* _input_item;
        _input_item = (char *)malloc(512000 * sizeof(char));
        scanf("\n%[^\n]", &_input_item);

        _input[_input_i] = _input_item;
    }

    res = process(_file_num, _input_size, _input);
    printf("%s\n", res);

    return 0;

}