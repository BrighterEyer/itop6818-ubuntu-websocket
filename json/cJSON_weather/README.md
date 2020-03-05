## 使用C语言调用cJSON库来解析JSON字符串

### json库下载地址
https://sourceforge.net/projects/cjson/

### 心知实时天气api地址
https://api.seniverse.com/v3/weather/now.json?key=pqe1fgv45lrdruq7&location=shangqiu&language=zh-Hans&unit=c

### 标准json格式：
{
	"results": [{
		"location": {
			"id": "WX4FBXXFKE4F",
			"name": "南京",
			"country": "CN",
			"path": "北京,北京,中国",
			"timezone": "Asia/Shanghai",
			"timezone_offset": "+08:00"
		},
		"now": {
			"text": "多云",
			"code": "5",
			"temperature": "34"
		},
		"last_update": "2018-11-13T12:05:00+08:00"
	}]
}


### 在线json格式校验工具

http://www.bejson.com/


运行结果:

{"results":[{"location":{"id":"WW45ZXMVB36N","name":"商丘","country":"CN","path":"商丘,商丘,河南,中国","timezone":"Asia/Shanghai","timezone_offset":"+08:00"},"now":{"text":"阴","code":"9","temperature":"15"},"last_update":"2018-11-13T13:05:00+08:00"}]}


解析后的数据:

城市名:商丘
更新时间:2018-11-13T13:05:00+08:00
天气现象:阴
天气代码:9
温度:15 C

