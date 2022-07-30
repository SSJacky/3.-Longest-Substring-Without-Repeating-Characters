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
    uint16_t index,index_2;
    unsigned int char_number, ascii_block, bit;
    
    
    for(index = 0;*(s+index)!='\0';index++)
    {
         for(index_2 = index;*(s+index_2)!='\0';index_2++)
        {
            char_number = (int)*(s+index_2);//search_char_number(*(s+index));
            ascii_block = char_number/(unsigned int)32;
            bit = 1 << char_number % (unsigned int)32;
            
            if(map[ascii_block] & bit)
            {
                if(ret < cnt)
                {
                    ret = cnt;
                }
                cnt = 0;
                memset(&map,0,sizeof(map));
                //map[char_number] = 1;
                break;
            }
            else
            {
                cnt++;
                map[ascii_block] |= bit;
            }
        }
    }
    if(ret < cnt)
    {
        ret = cnt;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char s[]="?";
    int result = lengthOfLongestSubstring(s);
    printf("result = %d\n",result);
    return 0;
}
