#include<stdio.h>
#include<stdlib.h>
#include"cJSON.h"

void Parse_Str1(void);
void Parse_Str2(void);
void Parse_BJ_Time(void);
void Parse_Weather(void);
void parse_seniverse_weather(void);
void parse_heweather(void);

int main()
{
//    Parse_Str1();
//    Parse_Str2();
//    Parse_BJ_Time();
//    parse_seniverse_weather();
    parse_heweather();
}
//解析和风天气，格式和心知天气非常像
void parse_heweather(void)
{
    char heweather_str[] = "{\"HeWeather6\":[{\"basic\":{\"cid\":\"CN101010700\",\"location\":\"昌平\",\"parent_city\":\"北京\",\"admin_area\":\"北京\",\"cnty\":\"中国\",\"lat\":\"40.21808624\",\"lon\":\"116.23590851\",\"tz\":\"+8.00\"},\"update\":{\"loc\":\"2018-11-21 21:45\",\"utc\":\"2018-11-21 13:45\"},\"status\":\"ok\",\"daily_forecast\":[{\"cond_code_d\":\"100\",\"cond_code_n\":\"100\",\"cond_txt_d\":\"晴\",\"cond_txt_n\":\"晴\",\"date\":\"2018-11-21\",\"hum\":\"21\",\"mr\":\"16:02\",\"ms\":\"04:27\",\"pcpn\":\"0.0\",\"pop\":\"0\",\"pres\":\"1030\",\"sr\":\"07:08\",\"ss\":\"16:53\",\"tmp_max\":\"9\",\"tmp_min\":\"-3\",\"uv_index\":\"5\",\"vis\":\"10\",\"wind_deg\":\"323\",\"wind_dir\":\"西北风\",\"wind_sc\":\"1-2\",\"wind_spd\":\"4\"},{\"cond_code_d\":\"100\",\"cond_code_n\":\"101\",\"cond_txt_d\":\"晴\",\"cond_txt_n\":\"多云\",\"date\":\"2018-11-22\",\"hum\":\"21\",\"mr\":\"16:36\",\"ms\":\"05:33\",\"pcpn\":\"0.0\",\"pop\":\"0\",\"pres\":\"1030\",\"sr\":\"07:09\",\"ss\":\"16:52\",\"tmp_max\":\"8\",\"tmp_min\":\"-4\",\"uv_index\":\"3\",\"vis\":\"20\",\"wind_deg\":\"35\",\"wind_dir\":\"东北风\",\"wind_sc\":\"1-2\",\"wind_spd\":\"5\"},{\"cond_code_d\":\"101\",\"cond_code_n\":\"100\",\"cond_txt_d\":\"多云\",\"cond_txt_n\":\"晴\",\"date\":\"2018-11-23\",\"hum\":\"23\",\"mr\":\"17:15\",\"ms\":\"06:41\",\"pcpn\":\"0.0\",\"pop\":\"16\",\"pres\":\"1024\",\"sr\":\"07:10\",\"ss\":\"16:52\",\"tmp_max\":\"7\",\"tmp_min\":\"-2\",\"uv_index\":\"2\",\"vis\":\"20\",\"wind_deg\":\"305\",\"wind_dir\":\"西北风\",\"wind_sc\":\"1-2\",\"wind_spd\":\"3\"}]}]}";

    cJSON *root;
    cJSON *results;
    cJSON *basic_json, *update_json, *forecast_json;
    cJSON *daily_json;

    int i = 0;
    char *basic_tmp, *update_tmp, *status_tmp, *weather_tmp;
    root = cJSON_Parse(heweather_str);
    if(root)
    {
        results = cJSON_GetObjectItem(root, "HeWeather6");      //HeWeather键对应的值，是一个数组
        results = cJSON_GetArrayItem(results,0);
        if(results)
        {
            basic_json = cJSON_GetObjectItem(results, "basic");
            if(basic_json)
            {
                basic_tmp = cJSON_GetObjectItem(basic_json, "cid") -> valuestring;
                printf("城市ID:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "location") -> valuestring;
                printf("县级市:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "parent_city") -> valuestring;
                printf("地级市:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "admin_area") -> valuestring;
                printf("所属省:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "lat") -> valuestring;
                printf("纬度:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "lon") -> valuestring;
                printf("经度:%s\n\n",basic_tmp);
            }
            update_json = cJSON_GetObjectItem(results, "update");
            if(update_json)
            {
                update_tmp = cJSON_GetObjectItem(update_json, "loc") -> valuestring;
                printf("更新时间:%s(所在地时间)\n", update_tmp);
                update_tmp = cJSON_GetObjectItem(update_json, "utc") -> valuestring;
                printf("更新时间:%s(世界时间)\n\n", update_tmp);
            }
            status_tmp = cJSON_GetObjectItem(results, "status") -> valuestring;
            printf("解析状态:%s\n\n", status_tmp);
            daily_json = cJSON_GetObjectItem(results, "daily_forecast");
            if(daily_json)
            {
                for(i = 0; i < 3; i++)
                {
                    forecast_json = cJSON_GetArrayItem(daily_json, i);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "date") -> valuestring;
                    printf("日期:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "cond_txt_d") -> valuestring;
                    printf("白天天气:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "cond_txt_n") -> valuestring;
                    printf("晚上天气:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "tmp_max") -> valuestring;
                    printf("最高温度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "tmp_min") -> valuestring;
                    printf("最低温度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_deg") -> valuestring;
                    printf("风向角度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_dir") -> valuestring;
                    printf("风向:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_sc") -> valuestring;
                    printf("风力:%s\r\n\n", weather_tmp);
                }
            }
        }
    }
    cJSON_Delete(root);
    cJSON_Delete(results);
    cJSON_Delete(basic_json);
    cJSON_Delete(update_json);
    cJSON_Delete(forecast_json);
    cJSON_Delete(daily_json);
}

//解析心知天气数据
void parse_seniverse_weather(void)
{
    char weather_str[] =
        "{\"results\":[{\"location\":{\"id\":\"WS10730EM8EV\",\"name\":\"深圳\",\"country\":\"CN\",\"path\":\"深圳,深圳,广东,中国\",\"timezone\":\"Asia/Shanghai\",\"timezone_offset\":\"+08:00\"},\"daily\":[{\"date\":\"2018-11-18\",\"text_day\":\"多云\",\"code_day\":\"4\",\"text_night\":\"多云\",\"code_night\":\"4\",\"high\":\"26\",\"low\":\"20\",\"precip\":\"\",\"wind_direction\":\"无持续风向\",\"wind_direction_degree\":\"\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"},{\"date\":\"2018-11-19\",\"text_day\":\"小雨\",\"code_day\":\"13\",\"text_night\":\"小雨\",\"code_night\":\"13\",\"high\":\"25\",\"low\":\"20\",\"precip\":\"\",\"wind_direction\":\"无持续风向\",\"wind_direction_degree\":\"\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"},{\"date\":\"2018-11-20\",\"text_day\":\"小雨\",\"code_day\":\"13\",\"text_night\":\"小雨\",\"code_night\":\"13\",\"high\":\"25\",\"low\":\"21\",\"precip\":\"\",\"wind_direction\":\"无持续风向\",\"wind_direction_degree\":\"\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"}],\"last_update\":\"2018-11-18T11:00:00+08:00\"}]}";
    cJSON *root;
    cJSON *results;
    cJSON *last_update;
    cJSON *loc_json, *daily_json;
    cJSON *forecast_json;
    char *loc_tmp, *weather_tmp, *update_tmp;
    int i = 0;

    root = cJSON_Parse((const char*)weather_str);
    if(root)
    {
//        printf("JSON格式正确:\n%s\n\n",cJSON_Print(root));    //输出json字符串
        results = cJSON_GetObjectItem(root, "results");
        results = cJSON_GetArrayItem(results,0);
        if(results)
        {
            loc_json = cJSON_GetObjectItem(results, "location");   //得到location键对应的值，是一个对象

            loc_tmp = cJSON_GetObjectItem(loc_json, "id") -> valuestring;
            printf("城市ID:%s\n",loc_tmp);
            loc_tmp = cJSON_GetObjectItem(loc_json, "name") -> valuestring;
            printf("城市名称:%s\n",loc_tmp);
            loc_tmp = cJSON_GetObjectItem(loc_json, "timezone") -> valuestring;
            printf("城市时区:%s\n\n",loc_tmp);

            daily_json = cJSON_GetObjectItem(results, "daily");
            if(daily_json)
            {
                for(i = 0; i < 3; i++)
                {
                    forecast_json = cJSON_GetArrayItem(daily_json, i);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "date") -> valuestring;
                    printf("日期:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "code_day") -> valuestring;
                    printf("白天天气代码:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "code_night") -> valuestring;
                    printf("晚上天气代码:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "high") -> valuestring;
                    printf("最高温度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "low") -> valuestring;
                    printf("最低温度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_direction_degree") -> valuestring;
                    printf("风向角度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_scale") -> valuestring;
                    printf("风力:%s\r\n\n", weather_tmp);
                }
            }
            else
                printf("daily json格式错误\r\n");
            last_update = cJSON_GetObjectItem(results, "last_update");
            update_tmp = last_update->valuestring;
            if(last_update)
            {
                printf("更新时间:%s\r\n", update_tmp);
            }
        }
        else
        {
            printf("results格式错误:%s\r\n", cJSON_GetErrorPtr());
        }
    }
    else
    {
        printf("JSON格式错误\r\n");
    }
    cJSON_Delete(root);
    cJSON_Delete(results);
}
void Parse_Weather(void)
{
    /*心知天气json数据*/
    char weather_str[] =
        "{\"results\":[{\"location\":{\"id\":\"WX4FBXXFKE4F\",\"name\":\"北京\",\"country\":\"CN\",\"path\":\"北京,北京,中国\",\"timezone\":\"Asia/Shanghai\",\"timezone_offset\":\"+08:00\"},\"daily\":[{\"date\":\"2018-11-18\",\"text_day\":\"晴\",\"code_day\":\"0\",\"text_night\":\"晴\",\"code_night\":\"1\",\"high\":\"11\",\"low\":\"-3\",\"precip\":\"\",\"wind_direction\":\"西北\",\"wind_direction_degree\":\"315\",\"wind_speed\":\"15\",\"wind_scale\":\"3\"},{\"date\":\"2018-11-19\",\"text_day\":\"晴\",\"code_day\":\"0\",\"text_night\":\"晴\",\"code_night\":\"1\",\"high\":\"10\",\"low\":\"-3\",\"precip\":\"\",\"wind_direction\":\"南\",\"wind_direction_degree\":\"180\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"},{\"date\":\"2018-11-20\",\"text_day\":\"多云\",\"code_day\":\"4\",\"text_night\":\"多云\",\"code_night\":\"4\",\"high\":\"10\",\"low\":\"-2\",\"precip\":\"\",\"wind_direction\":\"北\",\"wind_direction_degree\":\"0\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"}],\"last_update\":\"2018-11-18T11:00:00+08:00\"}]}";
    cJSON *root;

    cJSON *results;
    cJSON *last_update;
    cJSON *loc_json, *daily_json;
//    cJSON *today_json, *tomorrow_json, *after_json;
    cJSON *forecast_json;
    int i = 0;
    char *loc_tmp;
    char *weather_tmp;       //只使用一个变量，减少内存使用
    char *update_tmp;

    root = cJSON_Parse(weather_str);
    if(root)
    {
        results = cJSON_GetObjectItem(root, "results");
        results = cJSON_GetArrayItem(results,0);
        results = cJSON_Parse(cJSON_Print(results));      //loc_json字符串创建解析对象
        if(results)
        {
            loc_json = cJSON_GetObjectItem(results, "location");   //得到location键对应的值，是一个对象
            loc_tmp = cJSON_GetObjectItem(loc_json, "id") -> valuestring;
            printf("城市ID:%s\r\n",loc_tmp);
            loc_tmp = cJSON_GetObjectItem(loc_json, "name") -> valuestring;
            printf("城市名称:%s\r\n",loc_tmp);
            loc_tmp = cJSON_GetObjectItem(loc_json, "timezone") -> valuestring;
            printf("城市时区:%s\r\n\n",loc_tmp);
            daily_json = cJSON_GetObjectItem(results, "daily");
            if(daily_json)
            {
                for(i = 0; i < 3; i++)
                {
                    forecast_json = cJSON_GetArrayItem(daily_json, i);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "date") -> valuestring;
                    printf("日期:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "code_day") -> valuestring;
                    printf("白天天气代码:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "code_night") -> valuestring;
                    printf("晚上天气代码:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "high") -> valuestring;
                    printf("最高温度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "low") -> valuestring;
                    printf("最低温度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_direction_degree") -> valuestring;
                    printf("风向角度:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_scale") -> valuestring;
                    printf("风力:%s\r\n\n\n", weather_tmp);
                }

                /*
                            today_json = cJSON_GetArrayItem(daily_json, 0);
                            tomorrow_json = cJSON_GetArrayItem(daily_json, 1);
                            after_json = cJSON_GetArrayItem(daily_json, 2);

                            printf("今天天气的json字符串:\n%s\r\n",cJSON_Print(today_json));
                            weather_tmp = cJSON_GetObjectItem(today_json, "date") -> valuestring;
                            printf("今天日期:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "code_day") -> valuestring;
                            printf("今天白天天气代码:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "code_night") -> valuestring;
                            printf("今天晚上天气代码:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "high") -> valuestring;
                            printf("今天最高温度:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "low") -> valuestring;
                            printf("今天最低温度:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "wind_direction_degree") -> valuestring;
                            printf("今天风向角度:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "wind_scale") -> valuestring;
                            printf("今天风力:%s\r\n", weather_tmp);

                            printf("明天天气的json字符串:\n%s\r\n",cJSON_Print(tomorrow_json));
                            printf("后天天气的json字符串:\n%s\r\n",cJSON_Print(after_json));
                */
            }
            last_update = cJSON_GetObjectItem(results, "last_update");
            update_tmp = last_update->valuestring;
            if(last_update)
            {
                printf("最后更新时间:%s\r\n", update_tmp);
            }
        }
    }
    cJSON_Delete(root);
    cJSON_Delete(results);
    printf("天气数据解析成功\r\n\n");

}


/*
http://api.k780.com:88/?app=life.time&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json
*/
void Parse_BJ_Time(void)
{
    /*
    {
    	"success": "1",
    	"result": {
    		"timestamp": "1542456793",
    		"datetime_1": "2018-11-17 20:13:13",
    		"datetime_2": "2018年11月17日 20时13分13秒",
    		"week_1": "6",
    		"week_2": "星期六",
    		"week_3": "周六",
    		"week_4": "Saturday"
    	}
    }
    */
    char bj_time_str[] = "{\"success\":\"1\",\"result\":{\"timestamp\":\"1542456793\",\"datetime_1\":\"2018-11-17 20:13:13\",\"datetime_2\":\"2018年11月17日 20时13分13秒\",\"week_1\":\"6\",\"week_2\":\"星期六\",\"week_3\":\"周六\",\"week_4\":\"Saturday\"}}";

    cJSON *root;
    cJSON *result_json;
    char *datetime, *week;

    root = cJSON_Parse(bj_time_str);
    if(root)
    {
        printf("json格式正确:\n%s\n\n", cJSON_Print(root));
        result_json =  cJSON_GetObjectItem(root, "result");  //获取result键对应的值
        if(result_json)
        {
            datetime = cJSON_GetObjectItem(result_json, "datetime_2")->valuestring;
            printf("北京时间: %s \r\n", datetime);
            week = cJSON_GetObjectItem(result_json, "week_2")->valuestring;
            printf("星期: %s \r\n", week);
        }
    }
    cJSON_Delete(root);
    cJSON_Delete(result_json);
}


void Parse_Str2(void)
{
    /*
    {
    	"location": [{
    			"name": "Faye",
    			"address": "北京"
    		},
    		{
    			"name": "Andy",
    			"address": "香港"
    		}
    	],
    	"time": "2018-11-17"
    }
    */
    char str2[] = "{\"location\":[{\"name\":\"Faye\",\"address\":\"北京\"},{\"name\":\"Andy\",\"address\":\"香港\"}],\"time\":\"2018-11-17\"}";

    cJSON *root = 0;
    cJSON *loc_json = 0;
    cJSON *name1_json,*name2_json;
    char *time_str, *str_tmp;

    root = cJSON_Parse(str2);
    if(!root)
        printf("str2 JSON格式错误:%s \r\n", cJSON_GetErrorPtr());
    else
    {
        printf("str2 JSON格式正确:\n%s\n",cJSON_Print(root));
        time_str = cJSON_GetObjectItem(root,"time")->valuestring;//time键值对
        printf("time:%s\n", time_str);

        loc_json = cJSON_GetObjectItem(root,"location");
        if(loc_json)
        {
            name1_json = cJSON_GetArrayItem(loc_json,0);        //数组第0个元素
            str_tmp = cJSON_GetObjectItem(name1_json, "name")->valuestring;//name键对应的值
            printf("name1 is : %s \r\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(name1_json, "address")->valuestring;//addr1键对应的值
            printf("addr1 is : %s \r\n", str_tmp);

            name2_json = cJSON_GetArrayItem(loc_json,1);       //数组第1个元素
            str_tmp = cJSON_GetObjectItem(name2_json, "name")->valuestring;
            printf("name2 is : %s \r\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(name2_json, "address")->valuestring;
            printf("addr2 is : %s \r\n", str_tmp);
        }
    }
    cJSON_Delete(loc_json);
}


void Parse_Str1(void)
{
    /*
    {
    	"name": "Andy",      //键值对1
    	"age": 20              //键值对2
    }
    */
    char str1[] = "{\"name\":\"Andy\",\"age\":20}";
    cJSON *str1_json, *str1_name, *str1_age;
    printf("str1:%s\n\n",str1);
    str1_json = cJSON_Parse(str1);   //判断json格式是否正确
    if (!str1_json)
    {
        printf("JSON格式错误:%s\n\n", cJSON_GetErrorPtr()); //输出json格式错误信息
    }
    else
    {
        printf("JSON格式正确:\n%s\n\n",cJSON_Print(str1_json) );
        str1_name = cJSON_GetObjectItem(str1_json, "name"); //获取name键对应的值的信息
        if (str1_name->type == cJSON_String)
        {
            printf("姓名:%s\r\n", str1_name->valuestring);
        }
        str1_age = cJSON_GetObjectItem(str1_json, "age");   //获取age键对应的值的信息
        if(str1_age->type==cJSON_Number)
        {
            printf("年龄:%d\r\n", str1_age->valueint);
        }
        cJSON_Delete(str1_json);//释放内存
    }

}
