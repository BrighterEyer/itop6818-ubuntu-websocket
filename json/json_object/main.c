#include <stdio.h>
#include <stdlib.h>
#include"cJSON.h"
int main() {
	/*************
	    json的解析
	***************************/
	char data[] = "{\"name\":\"邱于涵\",\"age\":20}";
	//json是json对象指针,json_name是 name对象的指针,json_age是age对象的指针
	cJSON *json=0, *json_name=0, *json_age=0;
	//解析数据包
	json = cJSON_Parse(data);
	//如果解析失败
	if (!json) {
		printf("Error Before:", cJSON_GetErrorPtr());
	} else {
		json_age = cJSON_GetObjectItem(json, "age");
		//如果类型是 数字
		if(json_age->type==cJSON_Number) {
			
			printf("年龄:%d\n", json_age->valueint);
		}
		json_name = cJSON_GetObjectItem(json, "name");
		//如果类型是 字符串
		if (json_name->type == cJSON_String) {
			printf("姓名：%s\n", json_name->valuestring);
		}
		//释放内存
		cJSON_Delete(json);
	}
	/**************************
	    json的生成
	**********************************/
	cJSON * jsonroot=0;
	char * jsonout=0;
	//创建根节点对象
	jsonroot = cJSON_CreateObject();
	//向根节点加入数字对象
	cJSON_AddNumberToObject(jsonroot, "age", 19);
	//向根节点加入字符串对象
	cJSON_AddStringToObject(jsonroot, "name", "山楂");
	//解析成字符串
	jsonout=cJSON_Print(jsonroot);
	printf("%s", jsonout);
	//释放json对象的空间
	cJSON_Delete(jsonroot);
	//释放jsonout的空间
	free(jsonout);
	system("pause");
	return 0;
}

