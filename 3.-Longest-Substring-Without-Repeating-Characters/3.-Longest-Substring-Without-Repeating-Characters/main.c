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
    uint8_t w_flag = 0;
    char* index = s;
    char* index_2 =s;
    uint16_t end;
    unsigned int char_number, ascii_block, bit;
    end = strlen(s);
    while(*index)
    {
        index_2 = index;
        while(*index_2)
        {
            char_number = (int)*(index_2);//search_char_number(*(s+index));
            ascii_block = char_number/(unsigned int)32;
            bit = 1U << char_number % (unsigned int)32;
            
            if(map[ascii_block] & bit)
            {
                if(ret < cnt)
                {
                    ret = cnt;
                }
                cnt = 0;
                memset(&map,0,sizeof(map));
                break;
            }
            else
            {
                w_flag = 1;
                cnt++;
                map[ascii_block] |= bit;
            }
            if(ret>=end) break;
            index_2++;
            
        }
        if(w_flag==0) break;
        else w_flag = 0;
        if(ret>=end) break;
        index++;
    }
    
    if(ret < cnt)
    {
        ret = cnt;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char s[]="eeydgwdykpv";
    printf("result1 = %d\n",strlen(s));
    int result = lengthOfLongestSubstring(s);
    printf("result = %d\n",result);
    return 0;
}
