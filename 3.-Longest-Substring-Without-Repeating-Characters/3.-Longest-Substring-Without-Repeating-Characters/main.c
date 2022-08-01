//
//  main.c
//  3.-Longest-Substring-Without-Repeating-Characters
//
//  Created by 夏蜃詰 on 2022/7/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    unsigned int map[8] = {0};
    uint16_t ret = 0;
    uint16_t cnt = 0;
    char* index = s;
    char* index_2 =s;
    unsigned int char_number, ascii_block, bit,bit2;

    while(*index_2)
    {
        char_number = (int)*(index_2);//search_char_number(*(s+index));
        ascii_block = char_number/(unsigned int)32;
        bit = 1U << char_number % (unsigned int)32;
        
        if(map[ascii_block] & bit)
        {
            cnt = index_2-index;
            if(ret < cnt)
            {
                ret = cnt;
            }
            while(*index != *index_2)
            {
                char_number = (int)*(index);
                ascii_block = char_number/(unsigned int)32;
                bit2 = 1U << char_number % (unsigned int)32;
                map[ascii_block] ^= bit2;
                index++;
                
            }
            index++;
        }
        else
        {
            map[ascii_block] |= bit;
        }
        index_2++;
    }
    cnt = index_2-index;
    if(ret < cnt)
    {
        ret = cnt;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char s[]=" ";
    int result = lengthOfLongestSubstring(s);
    printf("result = %d\n",result);
    return 0;
}
