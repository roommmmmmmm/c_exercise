// 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
// 思路：
// 从后往前插入，即遇到一个空格替换时每个单词只需要移动一次
class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(str == NULL || length < 0) return ;

        int i = 0;
        int oldnumber = 0; // 记录替换前的长度
        int renumber = 0; // 需要替换的空格数量
        //循环一次，查找空格的数量
        while(str[i] != '\0'){
            oldnumber++;
            if(str[i] == ' '){
                renumber++;
            }
            i++;
        }
        int newlength = oldnumber + renumber * 2; // 计算替换后的长度
        if(newlength > length) return ; //如果计算后的长度小于字符串最大长度就无法替换
        int pOldlength = oldnumber;
        int pNewlength = newlength;
        while(pOldlength >= 0 && pNewlength > pOldlength){
            if(str[pOldlength] == ' '){ //遇到空格就替换
                str[pNewlength--] = '0';
                str[pNewlength--] = '2';
                str[pNewlength--] = '%';
            }else{
              //不是空格就把pOldlength指向的字符装入pNewlength指向的位置
                str[pNewlength--] = str[pOldlength];
            }
            pOldlength--;//不管是if还是elsr都要把pOldlength前移 
        }
	}
};
