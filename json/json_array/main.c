#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"
#define MAX_LINE 1024*5 


int main() {

	char buf[MAX_LINE];  /*缓冲区*/
	FILE *fp;            /*文件指针*/
	int len;             /*行字符个数*/
	if((fp = fopen("test.json","r")) == NULL) {
		perror("fail to read");
		exit (1) ;
	}
	while(fgets(buf,MAX_LINE,fp) != NULL) {
		len = strlen(buf);
		buf[len-1] = '\0';  /*去掉换行符*/
		printf("%s %d \n",buf,len - 1);
	}

	//用char* 模拟一个JSON字符串
	char* json_string;
	strcpy(json_string,buf);


	//第一步打包JSON字符串
	cJSON * cjson = cJSON_Parse(json_string);

	//判断是否打包成功
	if (cjson == NULL) {
		printf("cjson error…");
	} else { //打包成功调用cJSON_Print打印输出
		cJSON_Print(cjson);
	}

	//获取数组对象
	cJSON* test_arr = (cJSON*)cJSON_GetObjectItemCaseSensitive(cjson, "test_arr");

	//获取数组对象个数便于循环
	int arr_size = cJSON_GetArraySize(test_arr);//return arr_size 2

	//获取test_arr数组对象孩子节点
	cJSON* arr_item = test_arr->child;//子对象

	//循环获取数组下每个字段的值并使用cJSON_Print打印
	int i;
	for ( i = 0; i <= (arr_size - 1); ++i) {
		cJSON_Print(cJSON_GetObjectItem(arr_item, "test_1"));
		cJSON_Print(cJSON_GetObjectItem(arr_item, "test_2"));
		cJSON_Print(cJSON_GetObjectItem(arr_item, "test_3"));
		arr_item = arr_item->next;//下一个子对象
	}

	//delete cjson 这里只需要释放cjson即可，因为其它的都指向它
	cJSON_Delete(cjson);
}
