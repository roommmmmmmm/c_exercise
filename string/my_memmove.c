#include <stdio.h>
#include <stdlib.h>

/**
 * 字符串内存的拷贝，实现memmove函数
 */

char *my_memmove(char *dst,char *src,int cout){
  char *ret = dst;
  if (dst == NULL || src == NULL) {
    return NULL;
  }
  if (dst <= src || dst >= (src+count)) {
    //如果dst和sec区域没有重叠，那么从开始处逐一拷贝
    while (count--) {
      *dst = *src;
      dst++;
      src++;
    }
  }else{
    //如果dst和sec区域有重叠，那么从尾部开始向起始位置拷贝，这样避免数据重叠
    dst = dst + count-1;
    src = src + count-1;
    while (count--) {
      *dst = *src;
      dst--;
      src--;
    }
  }
  return ret;
}
