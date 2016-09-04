int lengthOfLongestSubstring(char* s) {
   int maxlen = 0,currlen = 0;
   int table[128], i, j, start = 0;
   memset(table, 0, sizeof(table));
   for (i = 0; s[i] != '\0'; ++i){
       if( (++table[s[i]]) == 2 ){
           if (currlen > maxlen){
               maxlen = currlen;
           }
           for(j = start; j < i; ++j){ //start记录重复的字符后一个位置
               if (s[j] == s[i]){
                   table[s[j]] = 1;
                   start = j+1;
                   break;
               }else{
                   --currlen;
                   table[s[j]] = 0;
               }
           }
       }else{
           ++currlen;
       }
   }
   if (currlen > maxlen){
       maxlen = currlen;
   }
   return maxlen;
}
